// DSHKM
class Genfor_Uaz_DSHKM;
class Laraka_Uaz_DSHKM: Genfor_Uaz_DSHKM {
    faction = "UKSF_Laraka";
    displayName = "UAZ DSHKM";
    crew = "Laraka_AK";
    typicalCargo[] = {
        "Laraka_AK"
    };
};

// Unarmed
class Genfor_Uaz_Unarmed;
class Laraka_Uaz_Unarmed: Genfor_Uaz_Unarmed {
    faction = "UKSF_Laraka";
    displayName = "UAZ Unarmed";
    crew = "Laraka_AK";
    typicalCargo[] = {
        "Laraka_L",
        "Laraka_AK",
        "Laraka_AK",
        "Laraka_PKM",
        "Laraka_RPG",
        "Laraka_Warlord"
    };
};
class Laraka_Uaz_Unarmed_Populated: Genfor_Uaz_Unarmed {
    faction = "UKSF_Laraka";
    displayName = "UAZ Unarmed (Populated)";
    crew = "Laraka_AK";
    typicalCargo[] = {
        "Laraka_L",
        "Laraka_AK",
        "Laraka_AK",
        "Laraka_PKM",
        "Laraka_RPG",
        "Laraka_Warlord"
    };
    class EventHandlers {
        class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
    };
};

// DSHKM
class Azaadi_Uaz_DSHKM: Laraka_Uaz_DSHKM {
    faction = "UKSF_Azaadi";
    side = 2;
    crew = "Azaadi_AK";
    typicalCargo[] = {
        "Azaadi_AK"
    };
};

// Unarmed
class Azaadi_Uaz_Unarmed: Laraka_Uaz_Unarmed {
    faction = "UKSF_Azaadi";
    side = 2;
    crew = "Azaadi_AK";
    typicalCargo[] = {
        "Azaadi_L",
        "Azaadi_AK",
        "Azaadi_AK",
        "Azaadi_PKM",
        "Azaadi_RPG",
        "Azaadi_Warlord"
    };
};
class Azaadi_Uaz_Unarmed_Populated: Laraka_Uaz_Unarmed {
    faction = "UKSF_Azaadi";
    displayName = "UAZ Unarmed (Populated)";
    side = 2;
    crew = "Azaadi_AK";
    typicalCargo[] = {
        "Azaadi_L",
        "Azaadi_AK",
        "Azaadi_AK",
        "Azaadi_PKM",
        "Azaadi_RPG",
        "Azaadi_Warlord"
    };
};
