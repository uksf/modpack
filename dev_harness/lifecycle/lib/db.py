import os
import json
import sys
from collections import Counter
from datetime import datetime

from bson import ObjectId
from pymongo import MongoClient

TEST_SERVER = "LifecycleTest"


def connection_string(settings_path):
    with open(settings_path, encoding="utf-8") as handle:
        settings = json.load(handle)
    return settings["appSettings"]["connectionStrings"]["database"]


def database(settings_path):
    uri = connection_string(settings_path)
    name = uri.rsplit("/", 1)[1].split("?", 1)[0]
    if name != "devLocal":
        raise SystemExit(f"refusing to touch database {name}: the lifecycle harness only uses devLocal")
    return MongoClient(uri)[name]


def plain(value):
    if isinstance(value, ObjectId):
        return str(value)
    if isinstance(value, datetime):
        return value.isoformat() + "Z"
    if isinstance(value, dict):
        return {key: plain(item) for key, item in value.items()}
    if isinstance(value, list):
        return [plain(item) for item in value]
    return value


def get_variables(db, keys):
    return {key: (db.variables.find_one({"key": key}) or {}).get("item") for key in keys}


def set_variable(db, key, value):
    db.variables.update_one({"key": key}, {"$set": {"item": value}})
    return {"key": key}


def upsert_test_server(db, uksf_path, mod_root, port, api_port, headless_clients):
    dev = db.gameServers.find_one({"name": "Dev"})
    api_ports = set(range(api_port, api_port + headless_clients + 1))
    for other in db.gameServers.find({"name": {"$ne": TEST_SERVER}}):
        other_api = set(range(other["apiPort"], other["apiPort"] + other.get("numberHeadlessClients", 0) + 1))
        if other["port"] == port or api_ports & other_api:
            raise SystemExit(f"test server ports {port}/{api_port} collide with server {other['name']} ({other['port']}/{other['apiPort']})")
    mods = [dict(mod, path=uksf_path if mod["name"] == "@uksf" else os.path.join(mod_root, mod["name"]) if mod_root else mod["path"]) for mod in dev["mods"]]
    missing = [mod["path"] for mod in mods if not os.path.isdir(mod["path"])]
    if missing:
        raise SystemExit(f"mod folders missing: {missing}")
    fields = {
        "name": TEST_SERVER,
        "profileName": "LifecycleTestServer",
        "hostName": "UKSF Lifecycle Test",
        "port": port,
        "apiPort": api_port,
        "numberHeadlessClients": headless_clients,
        "mods": mods,
        "serverMods": [],
        "environment": dev["environment"],
        "serverOption": dev["serverOption"],
        "verifySignatures": dev.get("verifySignatures", 0),
        "allowedFilePatching": dev.get("allowedFilePatching", 2),
        "password": dev.get("password", ""),
        "adminPassword": dev.get("adminPassword", ""),
        "order": 99,
        "processId": None,
        "processStartedAt": None,
        "headlessClientProcessIds": [],
        "status": dict(dev["status"], running=False, launching=False, stopPhase=0, players=[]),
    }
    existing = db.gameServers.find_one({"name": TEST_SERVER})
    if existing:
        db.gameServers.update_one({"_id": existing["_id"]}, {"$set": fields})
        return {"id": str(existing["_id"]), "password": fields["password"], "mods": [mod["path"] for mod in mods]}
    result = db.gameServers.insert_one(fields)
    return {"id": str(result.inserted_id), "password": fields["password"], "mods": [mod["path"] for mod in mods]}


def delete_test_server(db):
    return {"deleted": db.gameServers.delete_many({"name": TEST_SERVER}).deleted_count}


def test_server(db):
    return plain(db.gameServers.find_one({"name": TEST_SERVER}))


def persistence(db, key):
    session = db.persistenceSessions.find_one({"key": key})
    if session is None:
        return None
    players = session.get("players") or {}
    objects = session.get("objects") or []
    return {
        "key": key,
        "objectCount": len(objects),
        "typeCounts": dict(Counter(item.get("type") for item in objects if isinstance(item, dict))),
        "objectIds": sorted(str(item.get("_id")) for item in objects if isinstance(item, dict)),
        "positions": {str(item.get("type")): item.get("position") for item in objects if isinstance(item, dict) and item.get("type") != "Box_NATO_Ammo_F"},
        "markerCount": len(session.get("markers") or []),
        "markerTexts": [m.get("text") for m in (session.get("markers") or []) if isinstance(m, dict)],
        "players": {uid: {"position": state.get("position"), "animation": state.get("animation")} for uid, state in players.items()},
        "savedAt": plain(session.get("savedAt")),
        "saveEnqueuedAt": plain(session.get("saveEnqueuedAt")),
        "sessionIds": plain(session.get("missionSessionIds") or []),
    }


def delete_persistence(db, prefix):
    return {"deleted": db.persistenceSessions.delete_many({"key": {"$regex": f"^{prefix}"}}).deleted_count}


def mission_session(db, session_id):
    return plain(db.missionSessions.find_one({"sessionId": session_id}))


OPERATIONS = {
    "vars": lambda db, args: get_variables(db, args["keys"]),
    "setvar": lambda db, args: set_variable(db, args["key"], args["value"]),
    "upsert-server": lambda db, args: upsert_test_server(db, args["uksf"], args.get("modRoot"), args["port"], args["apiPort"], args["headlessClients"]),
    "delete-server": lambda db, args: delete_test_server(db),
    "server": lambda db, args: test_server(db),
    "persistence": lambda db, args: persistence(db, args["key"]),
    "delete-persistence": lambda db, args: delete_persistence(db, args["prefix"]),
    "mission-session": lambda db, args: mission_session(db, args["sessionId"]),
}

if __name__ == "__main__":
    settings, operation, arguments = sys.argv[1], sys.argv[2], json.loads(sys.argv[3] if len(sys.argv) > 3 else "{}")
    print(json.dumps(OPERATIONS[operation](database(settings), arguments), default=str))
