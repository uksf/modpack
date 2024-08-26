#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs at mission PostInit, AFTER all mission objects are loaded.
        Use this to perform operations at mission start, for example:
            - Modifying mission objects
            - Adding ACE interactions
            - Starting any long running per frame handlers

    Parameters:
        Nothing

    Return value:
        Nothing
*/
