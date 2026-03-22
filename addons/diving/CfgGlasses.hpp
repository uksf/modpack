class CfgGlasses {
    class None;
    class GVAR(divingMask) : None {
        author = "UKSF";
        scope = 2;
        ace_color[] = {0, 0, -1};
        ace_tintAmount = 0;
        ace_resistance = 1;
        ace_protection = 0;
        ACE_Overlay = "\z\ace\addons\goggles\textures\HUD\DivingGoggles.paa";
        ACE_OverlayCracked = "\z\ace\addons\goggles\textures\HUD\DivingGogglesCracked.paa";
        model = "\A3\characters_f\Heads\glasses\g_diving";
        displayName = "Diving Mask (Adv)";
        descriptionShort = "Shockproof diving goggles made of tempered glass.";
        picture = "\A3\characters_F\data\ui\icon_G_Diving_CA.paa";
        mass = 0;
        identityTypes[] = {
            "NoGlasses",
            "G_NATO_default",
            "G_NATO_casual",
            "G_NATO_pilot",
            "G_NATO_recon",
            "G_NATO_SF",
            "G_NATO_sniper",
            "G_NATO_diver",
            "G_IRAN_default",
            "G_IRAN_diver",
            "G_GUERIL_default",
            "G_HAF_default",
            "G_CIVIL_female",
            "G_CIVIL_male"
        };
    };
    DEPRECATE_CLASS(ade_item_goggles,GVAR(divingMask));
};
