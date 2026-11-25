class CfgWeapons {
    class ItemGPS;
    class ItemcTab : ItemGPS {
        scope = 1;
        displayName = "cTab (removed)";
    };
    class ItemAndroid : ItemcTab {};
    class ItemMicroDAGR : ItemcTab {};
    class COMSPEC_ATAK_Camera;
    class ItemCore;
    class COMSPEC_ATAK_KeyLoader : ItemCore {
        displayName = "Key Loader (ATAK)";
        descriptionShort = "Loads mesh keys into an MPU5. Game mechanic.";
    };
    class COMSPEC_ATAK_Goniometer : ItemCore {
        displayName = "Handheld Direction Finder (ATAK)";
        descriptionShort = "Gives an approximate bearing to active emitters on a channel.";
    };
    class ItemcTabHCam : COMSPEC_ATAK_Camera {
        scope = 1;
        displayName = "cTab Helmet Camera (removed)";
    };
};
