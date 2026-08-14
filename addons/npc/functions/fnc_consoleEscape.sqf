#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Escapes untrusted text before it enters a structured-text control.
*/
params [["_text", "", [""]]];

_text = (_text splitString "&") joinString "&amp;";
_text = (_text splitString "<") joinString "&lt;";
(_text splitString ">") joinString "&gt;"
