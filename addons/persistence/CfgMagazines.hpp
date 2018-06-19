class CfgMagazines {
    class CA_Magazine;
    class GVAR(marker): CA_Magazine {
        author = QUOTE(UKSF);
        scope = 2;
        displayname = QUOTE(Logistics Marker);
        descriptionShort = QUOTE(Logistics Marker);
        displayNameShort = QUOTE(Logistics Marker);
        ammo = QGVAR(markerAmmo);
        model = "\z\ace\addons\attach\data\ace_IRStrobe.p3d";
        picture = "\A3\Weapons_F_EPB\Ammo\Data\UI\gear_B_IRstrobe_CA.paa";
        value = 2;
        nameSoundWeapon = "smokeshell";
        nameSound = "smokeshell";
        mass = 4;
        count = 1;
        initSpeed = 22;
    };
};
