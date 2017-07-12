// Car bomb
class Laraka_CarBomb: Laraka_Hilux_Unarmed {
    faction = "UKSF_Laraka";
    displayName = "Hilux Car Bomb";
    crew = "Afghan_Civilian5";
    typicalCargo[] = {};
    weapons[] = { "CarHorn" };
    class EventHandlers {
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// Empty
class Laraka_CarBomb_Empty: Laraka_CarBomb {
    faction = "UKSF_Laraka";
    displayName = "Hilux Car Bomb (Empty)";
    crew = "Afghan_Civilian5";
    typicalCargo[] = {};
    class EventHandlers {
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// Deadman
class Laraka_CarBomb_Deadman: Laraka_CarBomb {
    faction = "UKSF_Laraka";
    displayName = "Hilux Car Bomb (Deadman)";
    crew = "Afghan_Civilian5";
    typicalCargo[] = {};
    class EventHandlers {
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// Car bomb
class Azaadi_CarBomb: Laraka_CarBomb {
    faction = "UKSF_Azaadi";
    side = 2;
};

// Empty
class Azaadi_CarBomb_Empty: Laraka_CarBomb_Empty {
    faction = "UKSF_Azaadi";
    side = 2;
};

// Deadman
class Azaadi_CarBomb_Deadman: Laraka_CarBomb_Deadman {
    faction = "UKSF_Azaadi";
    side = 2;
};
