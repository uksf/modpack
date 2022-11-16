// Mi35
class CUP_B_Mi35_Dynamic_CZ_Dark;
class GVAR(Mi35): CUP_B_Mi35_Dynamic_CZ_Dark {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Mi35";
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_Heli_AW101.jpg);
    crew = QGVAR(Heli_Pilot);
    typicalCargo[] = {
        QGVAR(Heli_Pilot)
    };
    // hiddenSelections[] = { "camo1", "camo2", "camo3" };
    hiddenSelectionsTextures[] = {"cup\airvehicles\cup_airvehicles_mi24\data\textures\cz_dark_001_co.paa","cup\airvehicles\cup_airvehicles_mi24\data\textures\cz_dark_002_co.paa"};

    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// AH1Z
class CUP_B_AH1Z_Dynamic_USMC;
class GVAR(AH1Z): CUP_B_AH1Z_Dynamic_USMC {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "AH1Z";
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_Heli_AW101.jpg);
    crew = QGVAR(Heli_Pilot);
    typicalCargo[] = {
        QGVAR(Heli_Pilot)
    };
    // hiddenSelections[] = { "camo1", "camo2", "camo3" };
    hiddenSelectionsTextures[] = {"cup\airvehicles\cup_airvehicles_ah1z\data\aaf_ah1z_body_co.paa","cup\airvehicles\cup_airvehicles_ah1z\data\aaf_ah1z_engines_co.paa"};

    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// Mi17
class CUP_B_Mi171Sh_Unarmed_ACR;
class GVAR(Mi17): CUP_B_Mi171Sh_Unarmed_ACR {
    scope = 2;
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Mi17";
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_Heli_AW101.jpg);
    crew = QGVAR(Heli_Pilot);
    typicalCargo[] = {
        QGVAR(Heli_Pilot)
    };
    // hiddenSelections[] = { "camo1", "camo2", "camo3" };
    hiddenSelectionsTextures[] = {
        "cup\airvehicles\cup_airvehicles_mi8\data\mi_171_dark_co.paa",
        "cup\airvehicles\cup_airvehicles_mi8\data\mi17_det_acr_dark_co.paa",
        "cup\airvehicles\cup_airvehicles_mi8\data\mi17_decals2_acr_ca.paa",
        "cup\airvehicles\cup_airvehicles_mi8\data\mi8_decals_ca.paa"
    };

    INVENTORY_EMPTY;
};
