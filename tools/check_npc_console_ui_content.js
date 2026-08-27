"use strict";

function checkContent({ update, allSqf, fail, pass }) {
    const requiredLabels = [
        "Current status", "Alive", "Can talk", "Looking at this NPC", "Speech",
        "Last mood", "Last gesture", "Conversation progress", "Cooperation",
        "Warning", "Conversation", "Facts revealed", "Address check", "Spoken to",
        "Player intent", "Heard as", "Topic", "Concern addressed", "Clear", "Why",
        "Information", "Fact allowed", "Facts held back", "Decision evidence",
        "Response", "AI used", "Understanding", "Reply",
    ];
    const missing = requiredLabels.filter((label) => !update.includes(label));
    if (missing.length) fail(`missing labels: ${missing.join(", ")}`);
    else pass("required visible labels present");

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

    const speechStates = ["idle", "waiting", "filler", "speaking", "streaming"];
    if (!speechStates.every((state) => allSqf.includes(`"${state}"`))) {
        fail("five-segment speech strip values missing");
    } else {
        pass("five-segment speech strip values present");
    }

    const bands = ["closed", "guarded", "engaged", "cooperative"];
    if (!bands.every((band) => allSqf.includes(`"${band}"`))) {
        fail("four-segment cooperation gauge values missing");
    } else {
        pass("four-segment cooperation gauge values present");
    }

    if (update.includes("Facts revealed") && update.includes("Fact allowed")) {
        if (!update.includes("_fnc_stateSpec") && !update.includes("stateSpec")) {
            fail("could not verify State vs Last exchange fact separation");
        } else {
            pass("fact fields stay in the correct panels");
        }
    }

    const escapedField = (label, needle) => {
        if (!needle.test(update)) fail(`${label} is not escaped before display`);
    };
    escapedField("mood", /getOrDefault \["mood"[\s\S]{0,80}call _fnc_escape/);
    escapedField("emote/Last gesture", /getOrDefault \["emote"[\s\S]{0,40}call _fnc_escape/);
    escapedField("cooperation", /getOrDefault \["cooperation"[\s\S]{0,40}call _fnc_escape/);
    escapedField("tag/Heard as", /getOrDefault \["tag"[\s\S]{0,40}call _fnc_escape/);
    escapedField("topic", /getOrDefault \["topicSlot"[\s\S]{0,40}call _fnc_escape/);
    escapedField("reason", /getOrDefault \["reason"[\s\S]{0,40}call _fnc_escape/);
    escapedField("evidence", /getOrDefault \["evidence"[\s\S]{0,40}call _fnc_escape/);
    escapedField("Facts revealed", /_factsRevealed/);
    escapedField("Fact allowed", /_factAllowed call _fnc_escape/);
    escapedField("Facts held back", /_factsHeldBack/);
    escapedField("transcript speaker", /\[_who\] call FUNC\(consoleEscape\)/);
    escapedField("transcript text", /\[_text\] call FUNC\(consoleEscape\)/);
    escapedField("classifyMs", /getOrDefault \["classifyMs"[\s\S]{0,40}call _fnc_escape/);
    escapedField("replyMs", /getOrDefault \["replyMs"[\s\S]{0,40}call _fnc_escape/);
}

module.exports = { checkContent };
