class CUP_L39_DYN_Base;
class CUP_B_L39_CZ : CUP_L39_DYN_Base {
    class Components;
};
class UKSF_B_L39 : CUP_B_L39_CZ {
    author = "UKSF";
    displayName = "Fast Air Trainer (Armed)";
    faction = "CUP_B_GB";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_B_L39.jpg);
    hiddenSelectionsTextures[] = { QPATHTOF(data\l39\l_39_body_raf.paa),QPATHTOF(data\l39\l_39_body_1_raf.paa) };
    crew = "UKSF_B_Pilot_617";
    typicalCargo[] = { "UKSF_B_Pilot_617", "UKSF_B_Pilot_617" };
    class Components : Components {
        class TransportPylonsComponent;
    };
    INVENTORY_AIRCRAFT
};
class UKSF_B_L39_Unarmed : UKSF_B_L39 {
    author = "UKSF";
    displayName = "Fast Air Trainer";
    faction = "CUP_B_GB";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_B_L39_Unarmed.jpg);
    crew = "UKSF_B_Pilot_617";
    typicalCargo[] = { "UKSF_B_Pilot_617", "UKSF_B_Pilot_617" };
    weapons[] = {};
    magazines[] = {};
    class Components : Components {
        class TransportPylonsComponent : TransportPylonsComponent {
            class presets {};
            class pylons {};
        };
    };
    INVENTORY_AIRCRAFT
};
