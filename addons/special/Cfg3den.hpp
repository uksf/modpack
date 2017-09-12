class Cfg3DEN {
    class Object {
        class AttributeCategories {
            class uksf_attributes {
                class Attributes {
                    class GVAR(setSuicideBomber) {
                        property = QGVAR(setSuicideBomber);
                        control = "Checkbox";
                        displayName = QUOTE(Set Suicide Bomber);
                        tooltip = QUOTE(Sets unit as a suicide bomber);
                        expression = QUOTE(if (!is3DEN && {!(_this getVariable [ARR_2(QQGVAR(isBomber),false)])}) then {[_this] call FUNC(suicide)};);
                        typeName = "BOOL";
                        defaultValue = "(false)";
                        condition = "objectBrain * (1 - objectVehicle)";
                    };
                    class GVAR(setSuicideBomberDeadman) {
                        property = QGVAR(setSuicideBomberDeadman);
                        control = "Checkbox";
                        displayName = QUOTE(Set Deadman Suicide Bomber);
                        tooltip = QUOTE(Sets unit as a deadman suicide bomber);
                        expression = QUOTE(if (!is3DEN && {!(_this getVariable [ARR_2(QQGVAR(isBomber),false)])}) then {[ARR_2(_this,true)] call FUNC(suicide)};);
                        typeName = "BOOL";
                        defaultValue = "(false)";
                        condition = "objectBrain * (1 - objectVehicle)";
                    };
                    class GVAR(setCarBomb) {
                        property = QGVAR(setCarBomb);
                        control = "Checkbox";
                        displayName = QUOTE(Set Car Bomb);
                        tooltip = QUOTE(Sets vehicle as an empty car bomb);
                        expression = QUOTE(if (!is3DEN && {!(_this getVariable [ARR_2(QQGVAR(isBomber),false)])}) then {[_this] call FUNC(carBomb)};);
                        typeName = "BOOL";
                        defaultValue = "(false)";
                        condition = "(1 - objectBrain) * objectVehicle";
                    };
                };
            };
        };
    };
};
