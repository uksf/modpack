#!/usr/bin/env python3

import os
import sys
import re

def update_player_count():
    missionpath = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "UKSFTemplate.VR"))
    missionfile = os.path.join(missionpath, "mission.sqm")
    if not os.path.exists(missionfile):
        print("Could not find: {}".format(missionfile))

    print("Reading: {}".format(missionfile))

    players = 0
    with open(missionfile, encoding="utf8") as mission:
        try:
            for line in mission:
                if "isPlayable=1" in line:
                    players += 1
        except UnicodeDecodeError:
            pass

    changed = False
    descriptionfile = os.path.join(missionpath, "description.ext")
    with open(descriptionfile, "r") as description_input:
        filelines = description_input.readlines()
        linenum = 0
        try:
            for line in filelines:
                if "maxPlayers =" in line:
                    old_players = int(re.findall(r"\d+", line)[0])
                    if old_players != players:
                        filelines[linenum] = "    maxPlayers = {};\n".format(players)
                        changed = True
                linenum += 1
        except UnicodeDecodeError:
            pass

    if changed:
        with open(descriptionfile, "w") as description_output:
            description_output.writelines(filelines)
        print("Max players '{}' written to description.ext".format(players))

if __name__ == "__main__":
    sys.exit(update_player_count())
