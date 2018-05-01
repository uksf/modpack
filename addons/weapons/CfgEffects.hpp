class ACE_ChemlightEffect_HiBlue {
    class Light1 {
        simulation = "light";
        type = "ACE_ChemlightEffect_HiBlue";
    };
};
class ACE_ChemlightEffect_HiGreen {
    class Light1 {
        simulation = "light";
        type = "ACE_ChemlightEffect_HiGreen";
    };
};
class CfgLights {
    class Chemlight_Blue;
    class ACE_ChemlightEffect_HiBlue: Chemlight_Blue {
        intensity = 12000;
        class Attenuation {
            constant = 0;
            linear = 0;
            quadratic = 20;
            hardLimitStart = 3;
            hardLimitEnd = 4;
        };
    };
    class Chemlight_Green;
    class ACE_ChemlightEffect_HiGreen: Chemlight_Green {
        intensity = 12000;
        class Attenuation {
            constant = 0;
            linear = 0;
            quadratic = 20;
            hardLimitStart = 3;
            hardLimitEnd = 4;
        };
    };
};
