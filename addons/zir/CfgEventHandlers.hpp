class Extended_InitPost_EventHandlers {
    class GVAR(hilux_full) {
        class ADDON {
            init = QUOTE([ARR_2(_this select 0,[ARR_6(QQGVAR(Militia_akn),QQGVAR(Militia_gp25),QQGVAR(Militia_MG),QQGVAR(Militia_LAT),QQGVAR(Militia_sks),QQGVAR(Militia_aa))])] call EFUNC(common,populate));
        };
    };
    class GVAR(praga_full) {
        class ADDON {
            init = QUOTE([ARR_2(_this select 0,[ARR_12(QQGVAR(Militia_akn),QQGVAR(Militia_gp25),QQGVAR(Militia_MG),QQGVAR(Militia_LAT),QQGVAR(Militia_sks),QQGVAR(Militia_aa),QQGVAR(Militia_akn),QQGVAR(Militia_gp25),QQGVAR(Militia_MG),QQGVAR(Militia_LAT),QQGVAR(Militia_sks),QQGVAR(Militia_aa))])] call EFUNC(common,populate));
        };
    };
    class GVAR(praga_covered_full) {
        class ADDON {
            init = QUOTE([ARR_2(_this select 0,[ARR_12(QQGVAR(Militia_akn),QQGVAR(Militia_gp25),QQGVAR(Militia_MG),QQGVAR(Militia_LAT),QQGVAR(Militia_sks),QQGVAR(Militia_aa),QQGVAR(Militia_akn),QQGVAR(Militia_gp25),QQGVAR(Militia_MG),QQGVAR(Militia_LAT),QQGVAR(Militia_sks),QQGVAR(Militia_aa))])] call EFUNC(common,populate));
        };
    };
    // dont allow fleeing on puritan guard

    // add surrender check on unit killed
    class GVAR(Soldier_Base) {
        class ADDON {
            init = (_this select 0) addMPEventHandler ["MPKilled", {
                params ["_unit", "_killer", "_instigator", "_useEffects"];

                if (typeOf _unit == QGVAR(Soldier_Base_Puritan_Guard)) exitWith {};
                if (!isPlayer _killer) exitWith {};

                private _unitsLeft = units group _unit;
                find
            }];
        };
    };
};
