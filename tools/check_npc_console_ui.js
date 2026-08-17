#!/usr/bin/env node
"use strict";

const fs = require("fs");
const path = require("path");

const root = path.resolve(__dirname, "..");
const files = {
    hpp: path.join(root, "addons/npc/CfgNpcConsole.hpp"),
    update: path.join(root, "addons/npc/functions/fnc_consoleUpdateInspector.sqf"),
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
const component = read(files.component);

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

if (!hpp.includes("IDC_CONSOLE_PROFILE")) {
    fail("compact profile control missing");
} else {
    pass("compact profile control present");
}

if (update.includes("NPC Console —") || update.includes("NPC Console -")) {
    fail("title still prefixes NPC Console");
} else if (!update.includes("ctrlSetText") || !update.includes("personaName")) {
    fail("title does not set selected NPC name");
} else {
    pass("title uses selected NPC name");
}

const forbiddenOld = [
    "Talkable / alive",
    "Mood / emote",
    "Address decision",
    "Move / topic",
    "Concern / ambiguous",
    "Band / warning / burned",
    "Eligible / blocked",
    "Classify / reply",
];
const leftover = forbiddenOld.filter((label) => update.includes(label));
if (leftover.length) {
    fail(`old grouped labels remain: ${leftover.join(", ")}`);
} else {
    pass("old grouped labels removed");
}

const requiredLabels = [
    "Current status",
    "Alive",
    "Can talk",
    "Looking at this NPC",
    "Speech",
    "Last mood",
    "Last gesture",
    "Conversation progress",
    "Cooperation",
    "Warning",
    "Conversation",
    "Facts revealed",
    "Address check",
    "Spoken to",
    "Player intent",
    "Heard as",
    "Topic",
    "Concern addressed",
    "Clear",
    "Why",
    "Information",
    "Fact allowed",
    "Facts held back",
    "Decision evidence",
    "Response",
    "AI used",
    "Understanding",
    "Reply",
];
const missing = requiredLabels.filter((label) => !update.includes(label));
if (missing.length) {
    fail(`missing labels: ${missing.join(", ")}`);
} else {
    pass("required visible labels present");
}

if (!update.includes("This NPC") ||
    !update.includes("Not this NPC") ||
    !update.includes("Uncertain - checking with AI") ||
    !update.includes("Threat warning active")) {
    fail("address/warning mappings missing");
} else {
    pass("address and warning mappings present");
}

if (!update.includes("Open") || !update.includes("Ended")) {
    fail("conversation Open/Ended mapping missing");
} else {
    pass("conversation Open/Ended mapping present");
}

if (!update.includes("lastMarkup") || (update.match(/ctrlSetStructuredText/g) || []).length !== 1) {
    fail("structured-text updates are not last-markup cached");
} else {
    pass("last-markup cache guards structured-text updates");
}

const factsRevealedInExchange = /Last exchange[\s\S]*Facts revealed/.test(update);
if (update.includes("_fnc_state") && update.includes("_fnc_exchange")) {
    const stateFn = update.slice(update.indexOf("_fnc_state"), update.indexOf("_fnc_exchange"));
    const exchangeFn = update.slice(update.indexOf("_fnc_exchange"));
    if (!stateFn.includes("Facts revealed")) fail("Facts revealed missing from State");
    if (stateFn.includes("Fact allowed") || stateFn.includes("Facts held back")) {
        fail("Fact allowed/held back leaked into State");
    }
    if (!exchangeFn.includes("Fact allowed") || !exchangeFn.includes("Facts held back")) {
        fail("Fact allowed/held back missing from Last exchange");
    }
    if (exchangeFn.includes("Facts revealed")) fail("Facts revealed leaked into Last exchange");
    pass("fact fields stay in the correct panels");
} else if (factsRevealedInExchange) {
    fail("Facts revealed appears to leak into Last exchange");
} else {
    fail("could not verify State vs Last exchange fact separation");
}

if (update.includes("_fnc_row") && /format \["<t color='#94a3b8'>%1<\/t><br\/>/.test(update)) {
    fail("rows still stack label above value");
} else if (!update.includes("%1") || !update.includes("%2")) {
    fail("compact same-line rows missing");
} else {
    pass("compact same-line rows used");
}

const escapedField = (label, needle) => {
    if (!needle.test(update)) fail(`${label} is not escaped before parseText`);
};
escapedField("mood", /getOrDefault \["mood"[\s\S]{0,80}call _fnc_escape/);
escapedField("emote/Last gesture", /getOrDefault \["emote"[\s\S]{0,40}call _fnc_escape/);
escapedField("cooperation", /getOrDefault \["cooperation"[\s\S]{0,40}call _fnc_escape/);
escapedField("tag/Heard as", /getOrDefault \["tag"[\s\S]{0,40}call _fnc_escape/);
escapedField("topic", /getOrDefault \["topicSlot"[\s\S]{0,40}call _fnc_escape/);
escapedField("reason", /getOrDefault \["reason"[\s\S]{0,40}call _fnc_escape/);
escapedField("evidence", /getOrDefault \["evidence"[\s\S]{0,40}call _fnc_escape/);
escapedField("Facts revealed", /_factsRevealed call _fnc_escape/);
escapedField("Fact allowed", /_factAllowed call _fnc_escape/);
escapedField("Facts held back", /_factsHeldBack call _fnc_escape/);
escapedField("transcript speaker", /\[_who\] call FUNC\(consoleEscape\)/);
escapedField("transcript text", /\[_text\] call FUNC\(consoleEscape\)/);
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
