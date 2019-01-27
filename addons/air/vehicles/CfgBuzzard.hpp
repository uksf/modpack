class CUP_B_L39_CZ;
class UKSF_B_L39 : CUP_B_L39_CZ {
    author = "UKSF";
    displayName = "Fast Air Trainer (Armed)";
    faction = "CUP_B_GB";
    editorPreview = QPATHTOEF(common, data\previews\UKSF_B_L39_CAP.jpg);
    crew = "UKSF_B_Pilot_617";
    typicalCargo[] = { "UKSF_B_Pilot_617", "UKSF_B_Pilot_617" };
    hiddenSelectionsTextures[] = { QPATHTOF(data\l_39_body_raf.paa), QPATHTOF(data\l_39_body_1_raf.paa) };
    INVENTORY_AIRCRAFT
    class Components;
};
class UKSF_B_L39_Unarmed : CUP_B_L39_CZ {
    author = "UKSF";
    displayName = "Fast Air Trainer";
    faction = "CUP_B_GB";
    editorPreview = QPATHTOEF(common, data\previews\UKSF_B_L39_CAP.jpg);
    crew = "UKSF_B_Pilot_617";
    typicalCargo[] = { "UKSF_B_Pilot_617", "UKSF_B_Pilot_617" };
    hiddenSelectionsTextures[] = { QPATHTOF(data\l_39_body_raf.paa), QPATHTOF(data\l_39_body_1_raf.paa) };
    weapons[] = {};
    magazines[] = {};
    class Components : Components {
        class TransportPylonsComponent {
            class presets {};
            class pylons {};
        };
    };
    INVENTORY_AIRCRAFT
};
