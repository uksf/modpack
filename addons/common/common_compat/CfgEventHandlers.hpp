// The Russen model has no boat_L point, so HAFM attached its boat at the hull origin. It now carries none.
class Extended_InitPost_EventHandlers {
    class HAFM_Russen {
        class HAFM_XEH_InitializeShip {
            init = "[_this select 0, ["""", 0], ""Exocet-MM40"",  """",  ["""", 0], [[[4], 9003, [20, 180, 340], false, objNull, objNull, ""Back Turret"", ""ramTurret""]], [[], ""B_G_Boat_Transport_01_F""], true] call HAFM_fnc_ShipInit";
        };
    };
};
