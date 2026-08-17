#!/usr/bin/env node
"use strict";

const fs = require("fs");
const path = require("path");

const root = path.resolve(__dirname, "..");
const files = {
    hpp: path.join(root, "addons/npc/CfgNpcConsole.hpp"),
    update: path.join(root, "addons/npc/functions/fnc_consoleUpdateInspector.sqf"),
    render: path.join(root, "addons/npc/functions/fnc_consoleRenderInspector.sqf"),
    prep: path.join(root, "addons/npc/XEH_PREP.hpp"),
    component: path.join(root, "addons/npc/script_component.hpp"),
};

function fail(message) {
    console.error(`FAIL: ${message}`);
    process.exitCode = 1;
}

function pass(message) {
    console.log(`OK: ${message}`);
}

function read(filePath) {
    if (!fs.existsSync(filePath)) {
        fail(`missing file ${path.relative(root, filePath)}`);
        return "";
    }
    return fs.readFileSync(filePath, "utf8");
}

function extractWidths(source) {
    const groups = [];
    const re = /class (\w+) : RscControlsGroup \{[\s\S]*?w = "([0-9.]+) \* safeZoneW"/g;
    let match;
    while ((match = re.exec(source))) {
        groups.push({ name: match[1], width: Number(match[2]) });
    }
    return groups;
}

const hpp = read(files.hpp);
const update = read(files.update);
const render = read(files.render);
const prep = read(files.prep);
const component = read(files.component);
const allSqf = `${update}\n${render}`;

if (hpp.includes("IdentityGroup") || hpp.includes("PipelineGroup")) {
    fail("layout still uses Identity/Pipeline groups");
} else {
    pass("identity/pipeline groups removed");
}

if (!/class StateGroup : RscControlsGroup/.test(hpp) ||
    !/class ExchangeGroup : RscControlsGroup/.test(hpp) ||
    !/class TranscriptGroup : RscControlsGroup/.test(hpp)) {
    fail("expected StateGroup, ExchangeGroup, TranscriptGroup");
} else {
    pass("three named panels present");
}

const widths = extractWidths(hpp);
const named = Object.fromEntries(widths.map((item) => [item.name, item.width]));
const stateW = named.StateGroup;
const exchangeW = named.ExchangeGroup;
const transcriptW = named.TranscriptGroup;
if (!(stateW && exchangeW && transcriptW)) {
    fail(`could not read panel widths: ${JSON.stringify(named)}`);
} else {
    const total = stateW + exchangeW + transcriptW;
    const ratios = [stateW / total, exchangeW / total, transcriptW / total];
    const expected = [0.30, 0.32, 0.38];
    const ok = expected.every((value, index) => Math.abs(ratios[index] - value) <= 0.03);
    if (!ok) {
        fail(`panel ratios ${ratios.map((n) => n.toFixed(3)).join("/")} not ~30/32/38`);
    } else {
        pass(`panel ratios ${ratios.map((n) => n.toFixed(3)).join("/")}`);
    }
}

const blobIdcs = ["IDC_CONSOLE_DETAILS", "IDC_CONSOLE_PIPELINE", "IDC_CONSOLE_TRANSCRIPT"];
const leftoverBlobs = blobIdcs.filter((idc) => {
    const re = new RegExp(`${idc}(?!_BODY)`);
    return re.test(hpp) || re.test(component);
});
if (leftoverBlobs.length) {
    fail(`old static blob IDCs remain: ${leftoverBlobs.join(", ")}`);
} else {
    pass("old static blob IDCs removed");
}

if (/class \w+ : RscStructuredText/.test(hpp)) {
    fail("hpp still declares static RscStructuredText blobs");
} else {
    pass("hpp has no static structured-text blobs");
}

if (!/class StateHeader : RscText/.test(hpp) ||
    !/class ExchangeHeader : RscText/.test(hpp) ||
    !/class TranscriptHeader : RscText/.test(hpp)) {
    fail("static panel header controls missing");
} else {
    pass("static panel headers present");
}

if (!hpp.includes("IDC_CONSOLE_STATE_BODY") ||
    !hpp.includes("IDC_CONSOLE_EXCHANGE_BODY") ||
    !hpp.includes("IDC_CONSOLE_TRANSCRIPT_BODY")) {
    fail("empty panel body groups missing");
} else {
    pass("empty panel body groups present");
}

if (!hpp.includes("IDC_CONSOLE_PROFILE")) {
    fail("compact profile control missing");
} else {
    pass("compact profile control present");
}

if (!render.includes("ctrlCreate")) {
    fail("renderer does not use ctrlCreate");
} else {
    pass("ctrlCreate renderer present");
}

if (!prep.includes("PREP(consoleRenderInspector)")) {
    fail("consoleRenderInspector not registered in XEH_PREP");
} else {
    pass("renderer registered in XEH_PREP");
}

if (!update.includes("FUNC(consoleRenderInspector)")) {
    fail("update inspector does not call renderer");
} else {
    pass("update inspector calls renderer");
}

const primitives = ["leds", "strip", "chip", "transcript", "row", "heading"];
const missingPrimitives = primitives.filter((kind) => !allSqf.includes(`"${kind}"`));
if (missingPrimitives.length) {
    fail(`element spec missing kinds: ${missingPrimitives.join(", ")}`);
} else {
    pass("strip/chip/transcript/leds/row/heading element kinds present");
}
if ((update.match(/\["led"/g) || []).length) {
    fail("vertical single-led elements remain");
} else {
    pass("status LEDs use one grouped leds primitive");
}
if (!render.includes("ctrlTextHeight")) {
    fail("row/transcript heights are not measured with ctrlTextHeight");
} else {
    pass("ctrlTextHeight measures row and transcript heights");
}

if (!render.includes("ctrlDelete") || !allSqf.includes("lastSpec")) {
    fail("spec cache or recreate-on-change missing");
} else {
    pass("spec cache and recreate-on-change present");
}
const lastSpecIdx = render.lastIndexOf("lastSpec");
const dynIdx = render.lastIndexOf("dynControls");
const deleteIdx = render.indexOf("ctrlDelete");
if (lastSpecIdx < 0 || dynIdx < 0 || lastSpecIdx < dynIdx || lastSpecIdx < deleteIdx) {
    fail("lastSpec is assigned before successful render");
} else {
    pass("lastSpec assigned after render beside dynControls");
}

if (!render.includes("#(argb") && !update.includes("#(argb")) {
    fail("procedural colour-square LED texture missing");
} else {
    pass("procedural colour-square LED texture used");
}

if (!allSqf.includes("0.03") || !allSqf.includes("0.18")) {
    fail("transcript zebra backgrounds missing");
} else {
    pass("transcript zebra backgrounds present");
}

if (!update.includes("ctrlSetTextColor") || !update.includes("ctrlSetBackgroundColor")) {
    fail("profile badge colour/background missing");
} else {
    pass("profile badge colour and background applied");
}
if (!/class Profile : RscText[\s\S]*?w = "0\.0[0-9] \* safeZoneW"[\s\S]*?colorBackground/.test(hpp)) {
    fail("profile control is not a compact badge");
} else {
    pass("profile control is a compact badge");
}

if (update.includes("NPC Console —") || update.includes("NPC Console -")) {
    fail("title still prefixes NPC Console");
} else if (!update.includes("ctrlSetText") || !update.includes("personaName")) {
    fail("title does not set selected NPC name");
} else {
    pass("title uses selected NPC name");
}

const forbiddenOld = [
    "Talkable / alive", "Mood / emote", "Address decision", "Move / topic",
    "Concern / ambiguous", "Band / warning / burned", "Eligible / blocked", "Classify / reply",
];
const leftover = forbiddenOld.filter((label) => update.includes(label));
if (leftover.length) fail(`old grouped labels remain: ${leftover.join(", ")}`);
else pass("old grouped labels removed");
require("./check_npc_console_ui_content").checkContent({ update, allSqf, fail, pass });
if (!process.exitCode) pass("parseText-bound untrusted values are escaped");

if (!component.includes("IDC_CONSOLE_PROFILE")) {
    fail("IDC_CONSOLE_PROFILE not defined");
} else {
    pass("IDC_CONSOLE_PROFILE defined");
}

if (process.exitCode) {
    console.error("NPC console UI contract RED");
    process.exit(process.exitCode);
}
console.log("NPC console UI contract GREEN");
