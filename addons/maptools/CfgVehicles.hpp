#define EXCEPTIONS exceptions[] = {"isNotDragging", "notOnMap", "isNotInside", "isNotSitting"}

class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_MapTools {
                class GVAR(shapeMenu) {
                    displayName = "Shape Draw";
                    condition = QUOTE(call FUNC(canDrawShape));
                    statement = "";
                    icon = "";
                    modifierFunction = QUOTE(_this select 3 set [ARR_2(1,format [ARR_2('Shape Draw: %1',GVAR(currentModeLabel))])]);
                    EXCEPTIONS;
                    showDisabled = 0;

                    class GVAR(modeCircle) {
                        displayName = "Circle";
                        condition = QUOTE(GVAR(currentMode) isNotEqualTo 'circle');
                        statement = QUOTE(['circle'] call FUNC(setMode));
                        icon = "";
                        EXCEPTIONS;
                        showDisabled = 0;
                    };
                    class GVAR(modeEllipse) {
                        displayName = "Ellipse";
                        condition = QUOTE(GVAR(currentMode) isNotEqualTo 'ellipse');
                        statement = QUOTE(['ellipse'] call FUNC(setMode));
                        icon = "";
                        EXCEPTIONS;
                        showDisabled = 0;
                    };
                    class GVAR(modeRaceTrack) {
                        displayName = "Race-track";
                        condition = QUOTE(GVAR(currentMode) isNotEqualTo 'racetrack');
                        statement = QUOTE(['racetrack'] call FUNC(setMode));
                        icon = "";
                        EXCEPTIONS;
                        showDisabled = 0;
                    };
                    class GVAR(modeCone) {
                        displayName = "Cone";
                        condition = QUOTE(GVAR(currentMode) isNotEqualTo 'cone');
                        statement = QUOTE(['cone'] call FUNC(setMode));
                        icon = "";
                        EXCEPTIONS;
                        showDisabled = 0;
                    };
                };
                class GVAR(wipeShapes) {
                    displayName = "Wipe my shapes";
                    condition = QUOTE(count GVAR(playerShapes) > 0);
                    statement = QUOTE(call FUNC(wipeShapes));
                    icon = "";
                    EXCEPTIONS;
                    showDisabled = 1;
                };
            };
        };
    };
};
