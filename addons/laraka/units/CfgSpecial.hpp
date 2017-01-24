//Special
class Laraka_Special_HVT: Haji_Matin {
    scope = 2;
    scopeCurator = 2;
    faction = "UKSF_Laraka";
    displayName = "Mullah Omar";
    editorSubcategory = QEGVAR(common,special);
    editorPreview = QPATHTOEF(common,data\previews\Laraka_Special_HVT.jpg);
    weapons[] = {};
    respawnWeapons[] = {};
    magazines[] = {};
    respawnMagazines[] = {};
    items[] = {};
    respawnItems[] = {};
    linkedItems[] = {};
    respawnLinkedItems[] = {};
};
class Laraka_Special_Suicide: Laraka_AK {
    displayName = "Suicide Bomber";
    editorSubcategory = QEGVAR(common,special);
    faction = "UKSF_Laraka";
    editorPreview = QPATHTOEF(common,data\previews\Laraka_Special_Suicide.jpg);
    weapons[] = {};
    respawnWeapons[] = {};
    magazines[] = {};
    respawnMagazines[] = {};
    items[] = {};
    respawnItems[] = {};
    linkedItems[] = {};
    respawnLinkedItems[] = {};
    class EventHandlers {
        class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
    };
};
class Laraka_Special_SuicideDeadman: Laraka_AK {
    displayName = "Suicide Bomber (Deadman)";
    editorSubcategory = QEGVAR(common,special);
    editorPreview = QPATHTOEF(common,data\previews\Laraka_Special_SuicideDeadman.jpg);
    faction = "UKSF_Laraka";
    weapons[] = {};
    respawnWeapons[] = {};
    magazines[] = {};
    respawnMagazines[] = {};
    items[] = {};
    respawnItems[] = {};
    linkedItems[] = {};
    respawnLinkedItems[] = {};
    class EventHandlers {
        class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
    };
};
class Laraka_Special_SuicideDiscrete: Laraka_Special_Suicide {
    displayName = "Suicide Bomber (Discrete)";
    editorSubcategory = QEGVAR(common,special);
    uniformClass = "U_Afghan03";
    editorPreview = QPATHTOEF(common,data\previews\Laraka_Special_SuicideDiscrete.jpg);
    class EventHandlers {
        class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
    };
};
class Laraka_Special_SuicideDiscreteDeadman: Laraka_Special_Suicide {
    displayName = "Suicide Bomber (Discrete Deadman)";
    editorSubcategory = QEGVAR(common,special);
    uniformClass = "U_Afghan03";
    editorPreview = QPATHTOEF(common,data\previews\Laraka_Special_SuicideDiscreteDeadman.jpg);
    class EventHandlers {
        class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
    };
};

class Azaadi_Special_HVT : Laraka_Special_HVT {
    side = 2;
    faction = "UKSF_Azaadi";
    displayName = "Shah Massoud";
};
class Azaadi_Special_Suicide : Laraka_Special_Suicide {
    faction = "UKSF_Azaadi";
    side = 2;
};
class Azaadi_Special_SuicideDeadman : Laraka_Special_SuicideDeadman {
    faction = "UKSF_Azaadi";
    side = 2;
};
class Azaadi_Special_SuicideDiscrete : Laraka_Special_SuicideDiscrete {
    faction = "UKSF_Azaadi";
    side = 2;
};
class Azaadi_Special_SuicideDiscreteDeadman : Laraka_Special_SuicideDiscreteDeadman {
    faction = "UKSF_Azaadi";
    side = 2;
};