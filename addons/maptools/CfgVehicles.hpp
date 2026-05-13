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
                    modifierFunction = QUOTE(_this select 3 set [ARR_2(2,format [ARR_2('Shape: %1',GVAR(currentMode))])]);
                    EXCEPTIONS;
                    showDisabled = 0;

                    class GVAR(modeCircle) {
                        displayName = "Circle";
                        condition = "true";
                        statement = QUOTE(['circle'] call FUNC(setMode));
                        EXCEPTIONS;
                        showDisabled = 0;
                    };
                    class GVAR(modeEllipse) {
                        displayName = "Ellipse";
                        condition = "true";
                        statement = QUOTE(['ellipse'] call FUNC(setMode));
                        EXCEPTIONS;
                        showDisabled = 0;
                    };
                    class GVAR(modeRaceTrack) {
                        displayName = "Race-track";
                        condition = "true";
                        statement = QUOTE(['racetrack'] call FUNC(setMode));
                        EXCEPTIONS;
                        showDisabled = 0;
                    };
                    class GVAR(modeCone) {
                        displayName = "Cone";
                        condition = "true";
                        statement = QUOTE(['cone'] call FUNC(setMode));
                        EXCEPTIONS;
                        showDisabled = 0;
                    };
                };
                class GVAR(wipeShapes) {
                    displayName = "Wipe my shapes";
                    condition = QUOTE(count GVAR(playerShapes) > 0);
                    statement = QUOTE(call FUNC(wipeShapes));
                    EXCEPTIONS;
                    showDisabled = 1;
                };
            };
        };
    };
};
