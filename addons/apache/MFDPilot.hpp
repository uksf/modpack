class MFD {
    class MFD_Pilot_1 {
        topLeft = "MFD_1_TL";
        topRight = "MFD_1_TR";
        bottomLeft = "MFD_1_BL";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = { 1, 1, 1, 1 };
        helmetMountedDisplay = 0;
        helmetPosition[] = { -0.0375, 0.0375, 0.1 };
        helmetRight[] = { 0.075, 0, 0 };
        helmetDown[] = { 0, -0.075, 0 };
        font = "LucidaConsoleB";
        turret[] = { 0 };
        class Bones {};
        class Draw {
            alpha = 1;
            color[] = { 0.25, 1, 0.25 };
            condition = "on";
            class ReticleGroup {
                color[] = { 1, 1, 1 };
                class Reticle {
                    type = "line";
                    width = 4;
                    points[] = { { { 0.501429, 0.492766 }, 1 }, { { 0.505, 0.492766 }, 1 }, { { 0.505, 0.497802 }, 1 }, { { 0.501429, 0.497802 }, 1 }, { { 0.501429, 0.492766 }, 1 }, {}, { { 0.509286, 0.495788 }, 1 }, { { 0.587143, 0.495788 }, 1 }, {}, { { 0.502857, 0.502839 }, 1 }, { { 0.502857, 0.597528 }, 1 }, {}, { { 0.498571, 0.495788 }, 1 }, { { 0.42, 0.495788 }, 1 }, {}, { { 0.502857, 0.394048 }, 1 }, { { 0.502857, 0.486722 }, 1 }, {}, { { 0.62, 0.339652 }, 1 }, { { 0.652857, 0.339652 }, 1 }, { { 0.652857, 0.382967 }, 1 }, {}, { { 0.652857, 0.615659 }, 1 }, { { 0.652857, 0.659982 }, 1 }, { { 0.620714, 0.659982 }, 1 }, {}, { { 0.384286, 0.659982 }, 1 }, { { 0.351429, 0.659982 }, 1 }, { { 0.351429, 0.615659 }, 1 }, {}, { { 0.384286, 0.339652 }, 1 }, { { 0.351429, 0.339652 }, 1 }, { { 0.351429, 0.382967 }, 1 } };
                };
                class ModeText {
                    type = "text";
                    source = "static";
                    text = "Mode: TI WHOT";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { 0.04, 0.32 }, 1 };
                    right[] = { { 0.07, 0.32 }, 1 };
                    down[] = { { 0.04, 0.345 }, 1 };
                };
                class RangeText {
                    type = "text";
                    source = "static";
                    text = "Range:";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { 0.33, 0.81 }, 1 };
                    right[] = { { 0.37, 0.81 }, 1 };
                    down[] = { { 0.33, 0.845 }, 1 };
                };
                class Fuel {
                    type = "text";
                    source = "impactDistance";
                    sourceScale = 1;
                    sourceLength = 4;
                    align = "right";
                    scale = 1;
                    pos[] = { { 0.48, 0.81 }, 1 };
                    right[] = { { 0.52, 0.81 }, 1 };
                    down[] = { { 0.48, 0.845 }, 1 };
                };
            };
        };
    };
    class MFD_Pilot_2 {
        topLeft = "MFD_2_TL";
        topRight = "MFD_2_TR";
        bottomLeft = "MFD_2_BL";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = { 1, 1, 1, 1 };
        helmetMountedDisplay = 0;
        helmetPosition[] = { -0.0375, 0.0375, 0.1 };
        helmetRight[] = { 0.075, 0, 0 };
        helmetDown[] = { 0, -0.075, 0 };
        font = "LucidaConsoleB";
        turret[] = { -2 };
        class Bones {};
        class Draw {
            alpha = 1;
            color[] = { 0, 0.12, 0 };
            condition = "on";
            class Time {
                type = "text";
                source = "time";
                text = "%X";
                sourceScale = 1;
                align = "right";
                scale = 1;
                pos[] = { { 0.03, 0.11 }, 1 };
                right[] = { { 0.13, 0.11 }, 1 };
                down[] = { { 0.03, 0.2 }, 1 };
            };
            class Fuel {
                type = "text";
                source = "fuel";
                text = "%X";
                sourceScale = 2517;
                sourceLength = 4;
                align = "right";
                scale = 1;
                pos[] = { { 0.03, 0.31 }, 1 };
                right[] = { { 0.13, 0.31 }, 1 };
                down[] = { { 0.03, 0.4 }, 1 };
            };
            class LBSText {
                type = "text";
                source = "static";
                text = "LBS";
                scale = 1;
                sourceScale = 1;
                align = "right";
                pos[] = { { 0.3, 0.31 }, 1 };
                right[] = { { 0.4, 0.31 }, 1 };
                down[] = { { 0.3, 0.4 }, 1 };
            };
            class GridX {
                type = "text";
                source = "coordinateX";
                sourceScale = 0.01;
                sourceOffset = -0.5;
                sourceLength = 3;
                align = "right";
                scale = 1;
                pos[] = { { 0.03, 0.61 }, 1 };
                right[] = { { 0.13, 0.61 }, 1 };
                down[] = { { 0.03, 0.7 }, 1 };
            };
            class GridY : GridX {
                source = "coordinateY";
                pos[] = { { 0.24, 0.61 }, 1 };
                right[] = { { 0.34, 0.61 }, 1 };
                down[] = { { 0.24, 0.7 }, 1 };
            };
            class GridText {
                type = "text";
                source = "static";
                text = "GRID:";
                scale = 1;
                sourceScale = 1;
                align = "right";
                pos[] = { { 0.03, 0.51 }, 1 };
                right[] = { { 0.13, 0.51 }, 1 };
                down[] = { { 0.03, 0.6 }, 1 };
            };
        };
    };
    class MFD_Pilot_3 {
        topLeft = "MFD_3_TL";
        topRight = "MFD_3_TR";
        bottomLeft = "MFD_3_BL";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = { 1, 1, 1, 1 };
        helmetMountedDisplay = 0;
        helmetPosition[] = { -0.0375, 0.0375, 0.1 };
        helmetRight[] = { 0.075, 0, 0 };
        helmetDown[] = { 0, -0.075, 0 };
        font = "LucidaConsoleB";
        turret[] = { -2 };
        class Bones {};
        class Draw {
            alpha = 1;
            color[] = { 0, 0.12, 0 };
            condition = "on";
            class CollectiveGroup {
                condition = "simulRTD";
                class CollectiveText {
                    type = "text";
                    source = "static";
                    text = "%";
                    align = "right";
                    scale = 1;
                    pos[] = { { 0.22, 0.2 }, 1 };
                    right[] = { { 0.28, 0.2 }, 1 };
                    down[] = { { 0.22, 0.24 }, 1 };
                };
                class CollectiveNumber {
                    type = "text";
                    source = "rtdCollective";
                    sourceScale = 100;
                    align = "left";
                    scale = 1;
                    pos[] = { { 0.22, 0.2 }, 1 };
                    right[] = { { 0.28, 0.2 }, 1 };
                    down[] = { { 0.22, 0.24 }, 1 };
                };
            };
            class SpeedNumber {
                type = "text";
                source = "speed";
                sourceScale = 1.94384;
                align = "left";
                scale = 1;
                pos[] = { { 0.28, 0.452 }, 1 };
                right[] = { { 0.32, 0.452 }, 1 };
                down[] = { { 0.28, 0.492 }, 1 };
            };
            class AltNumber {
                type = "text";
                source = "altitudeAGL";
                sourceScale = 3.28084;
                sourceOffset = -2;
                align = "left";
                scale = 1;
                pos[] = { { 0.75, 0.452 }, 1 };
                right[] = { { 0.79, 0.452 }, 1 };
                down[] = { { 0.75, 0.492 }, 1 };
            };
            class CruiseMode {
                condition = "1+((altitudeASL-27) min 1) - autohover";
                class AltNumberASL {
                    type = "text";
                    source = "altitudeASL";
                    sourceScale = 3.28084;
                    align = "left";
                    scale = 1;
                    pos[] = { { 0.81, 0.16 }, 1 };
                    right[] = { { 0.85, 0.16 }, 1 };
                    down[] = { { 0.81, 0.2 }, 1 };
                };
            };
        };
    };
    class MFD_Pilot_5 : MFD_Pilot_1 {
        topLeft = "MFD_5_TL";
        topRight = "MFD_5_TR";
        bottomLeft = "MFD_5_BL";
        turret[] = { 0 };
        class Draw {
            color[] = { 0, 0.12, 0 };
            condition = "on";
            class BlackBackgroundGroup {
                color[] = { 0, 0, 0 };
                class BlackBackground {
                    type = "polygon";
                    points[] = { { { { 0, 0.1 }, 1 }, { { 1, 0.1 }, 1 }, { { 1, 1 }, 1 }, { { 0, 1 }, 1 } } };
                };
            };
            class ReticleGroup {
                color[] = { 0, 0.12, 0 };
                class Reticle {
                    type = "line";
                    width = 4;
                    points[] = { { { 0.43, 0.490598 }, 1 }, { { 0.164, 0.490598 }, 1 }, { { 0.164, 0.490598 }, 1 }, { { 0.164, 0.630171 }, 1 }, { { 0.164, 0.630171 }, 1 }, { { 0.438, 0.630171 }, 1 }, { { 0.438, 0.630171 }, 1 }, { { 0.438, 0.732393 }, 1 }, { { 0.622, 0.732393 }, 1 }, { { 0.622, 0.630171 }, 1 }, { { 0.622, 0.630171 }, 1 }, { { 0.898, 0.630171 }, 1 }, { { 0.898, 0.630171 }, 1 }, { { 0.898, 0.490598 }, 1 }, { { 0.63, 0.490598 }, 1 }, { { 0.63, 0.490598 }, 1 }, { { 0.616, 0.482735 }, 1 }, { { 0.616, 0.297949 }, 1 }, { { 0.592, 0.297949 }, 1 }, { { 0.558, 0.286154 }, 1 }, { { 0.558, 0.272393 }, 1 }, { { 0.5, 0.272393 }, 1 }, { { 0.5, 0.286154 }, 1 }, { { 0.468, 0.297949 }, 1 }, { { 0.446, 0.297949 }, 1 }, { { 0.446, 0.482735 }, 1 }, { { 0.43, 0.490598 }, 1 }, {}, { { 0.46, 0.6 }, 1 }, { { 0.6, 0.6 }, 1 }, { { 0.6, 0.72 }, 1 }, { { 0.46, 0.72 }, 1 }, { { 0.46, 0.6 }, 1 }, {}, { { 0.04, 0.8 }, 1 }, { { 0.24, 0.8 }, 1 }, { { 0.24, 0.86 }, 1 }, { { 0.04, 0.86 }, 1 }, { { 0.04, 0.8 }, 1 }, {}, { { -0.06, 0.83 }, 1 }, { { 0.04, 0.83 }, 1 }, {}, { { 0.04, 0.93 }, 1 }, { { 0.24, 0.93 }, 1 }, { { 0.24, 0.99 }, 1 }, { { 0.04, 0.99 }, 1 }, { { 0.04, 0.93 }, 1 }, {}, { { -0.06, 0.96 }, 1 }, { { 0.04, 0.96 }, 1 }, {}, { { 0.27, 0.86 }, 1 }, { { 0.83, 0.86 }, 1 }, { { 0.83, 0.98 }, 1 }, { { 0.27, 0.98 }, 1 }, { { 0.27, 0.86 }, 1 }, {}, { { 0.23, 0.18 }, 1 }, { { 0.37, 0.18 }, 1 }, { { 0.37, 0.26 }, 1 }, { { 0.23, 0.26 }, 1 }, { { 0.23, 0.18 }, 1 }, {}, { { 0.7, 0.18 }, 1 }, { { 0.84, 0.18 }, 1 }, { { 0.84, 0.26 }, 1 }, { { 0.7, 0.26 }, 1 }, { { 0.7, 0.18 }, 1 }, {}, { { 0.24, 0.29 }, 1 }, { { 0.36, 0.29 }, 1 }, { { 0.36, 0.37 }, 1 }, { { 0.24, 0.37 }, 1 }, { { 0.24, 0.29 }, 1 }, {}, { { 0.71, 0.29 }, 1 }, { { 0.83, 0.29 }, 1 }, { { 0.83, 0.37 }, 1 }, { { 0.71, 0.37 }, 1 }, { { 0.71, 0.29 }, 1 } };
                };
                class SightSelect1 {
                    type = "text";
                    source = "static";
                    text = "SIGHT";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { "0.53-0.29", 0.187 }, 1 };
                    right[] = { { 0.28, 0.187 }, 1 };
                    down[] = { { "0.53-0.29", 0.222 }, 1 };
                };
                class SightSelect2 {
                    type = "text";
                    source = "static";
                    text = "FCR";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { "0.53-0.29", 0.227 }, 1 };
                    right[] = { { 0.28, 0.227 }, 1 };
                    down[] = { { "0.53-0.29", 0.262 }, 1 };
                };
                class AcqSelect1 {
                    type = "text";
                    source = "static";
                    text = "ACQ";
                    scale = 1;
                    sourceScale = 1;
                    align = "left";
                    pos[] = { { "0.53+0.29", 0.187 }, 1 };
                    right[] = { { 0.86, 0.187 }, 1 };
                    down[] = { { "0.53+0.29", 0.222 }, 1 };
                };
                class AcqSelect2 {
                    type = "text";
                    source = "static";
                    text = "FCR";
                    scale = 1;
                    sourceScale = 1;
                    align = "left";
                    pos[] = { { "0.53+0.29", 0.227 }, 1 };
                    right[] = { { 0.86, 0.227 }, 1 };
                    down[] = { { "0.53+0.29", 0.262 }, 1 };
                };
                class LSTSelect1 {
                    type = "text";
                    source = "static";
                    text = "LST";
                    scale = 1;
                    sourceScale = 1;
                    align = "center";
                    pos[] = { { "0.53-0.23", 0.297 }, 1 };
                    right[] = { { 0.34, 0.297 }, 1 };
                    down[] = { { "0.53-0.23", 0.332 }, 1 };
                };
                class LSTSelect2 {
                    type = "text";
                    source = "static";
                    text = "A";
                    scale = 1;
                    sourceScale = 1;
                    align = "center";
                    pos[] = { { "0.53-0.23", 0.337 }, 1 };
                    right[] = { { 0.34, 0.337 }, 1 };
                    down[] = { { "0.53-0.23", 0.372 }, 1 };
                };
                class LRFDSelect1 {
                    type = "text";
                    source = "static";
                    text = "LRFD";
                    scale = 1;
                    sourceScale = 1;
                    align = "center";
                    pos[] = { { "0.53+0.24", 0.297 }, 1 };
                    right[] = { { 0.81, 0.297 }, 1 };
                    down[] = { { "0.53+0.24", 0.332 }, 1 };
                };
                class LRFDSelect2 {
                    type = "text";
                    source = "static";
                    text = "B";
                    scale = 1;
                    sourceScale = 1;
                    align = "center";
                    pos[] = { { "0.53+0.24", 0.337 }, 1 };
                    right[] = { { 0.81, 0.337 }, 1 };
                    down[] = { { "0.53+0.24", 0.372 }, 1 };
                };
                class PilotText {
                    type = "text";
                    source = "static";
                    text = "PILOT";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { "0.53-0.48", 0.815 }, 1 };
                    right[] = { { 0.09, 0.815 }, 1 };
                    down[] = { { "0.53-0.48", 0.85 }, 1 };
                };
                class CopilotText {
                    type = "text";
                    source = "static";
                    text = "COPILOT";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { "0.53-0.48", 0.945 }, 1 };
                    right[] = { { 0.09, 0.945 }, 1 };
                    down[] = { { "0.53-0.48", 0.98 }, 1 };
                };
                class PylonText4 {
                    type = "text";
                    source = "static";
                    text = "#4";
                    scale = 1;
                    sourceScale = 1;
                    align = "center";
                    pos[] = { { "0.53-0.31 + 0.09*2", 0.55 }, 1 };
                    right[] = { { 0.44, 0.55 }, 1 };
                    down[] = { { "0.53-0.31 + 0.09*2", 0.585 }, 1 };
                };
                class PylonText3 {
                    type = "text";
                    source = "static";
                    text = "#3";
                    scale = 1;
                    sourceScale = 1;
                    align = "center";
                    pos[] = { { "0.53+0.31 - 0.09*2", 0.55 }, 1 };
                    right[] = { { 0.7, 0.55 }, 1 };
                    down[] = { { "0.53+0.31 - 0.09*2", 0.585 }, 1 };
                };
                class PylonText2 {
                    type = "text";
                    source = "static";
                    text = "#2";
                    scale = 1;
                    sourceScale = 1;
                    align = "center";
                    pos[] = { { "0.53+0.31 - 0.09", 0.55 }, 1 };
                    right[] = { { 0.79, 0.55 }, 1 };
                    down[] = { { "0.53+0.31 - 0.09", 0.585 }, 1 };
                };
                class PylonText1 {
                    type = "text";
                    source = "static";
                    text = "#1";
                    scale = 1;
                    sourceScale = 1;
                    align = "center";
                    pos[] = { { "0.53+0.31 - 0.00", 0.55 }, 1 };
                    right[] = { { 0.88, 0.55 }, 1 };
                    down[] = { { "0.53+0.31 - 0.00", 0.585 }, 1 };
                };
                class CurrentWeaponText {
                    type = "text";
                    source = "static";
                    text = "CURRENT WEAPON";
                    scale = 1;
                    sourceScale = 1;
                    align = "center";
                    pos[] = { { 0.55, 0.82 }, 1 };
                    right[] = { { 0.59, 0.82 }, 1 };
                    down[] = { { 0.55, 0.855 }, 1 };
                };
                class Weapons {
                    type = "text";
                    source = "weapon";
                    sourceScale = 1;
                    align = "center";
                    scale = 1;
                    pos[] = { { 0.55, 0.87 }, 1 };
                    right[] = { { 0.59, 0.87 }, 1 };
                    down[] = { { 0.55, 0.905 }, 1 };
                };
                class Ammo {
                    type = "text";
                    source = "ammo";
                    sourceScale = 1;
                    align = "center";
                    scale = 1;
                    pos[] = { { 0.55, 0.92 }, 1 };
                    right[] = { { 0.59, 0.92 }, 1 };
                    down[] = { { 0.55, 0.955 }, 1 };
                };
            };
            class MGun {
                class Default {
                    condition = "ammo0 > 0";
                    color[] = { 0, 0.12, 0 };
                    class Shape {
                        type = "line";
                        width = 4;
                        points[] = { { { 0.556, 0.38641 }, 1 }, { { 0.502, 0.38641 }, 1 }, { { 0.458, 0.38641 }, 1 }, { { 0.458, 0.449316 }, 1 }, { { 0.6, 0.449316 }, 1 }, { { 0.6, 0.38641 }, 1 }, { { 0.556, 0.38641 }, 1 }, {}, { { 0.502, 0.38641 }, 1 }, { { 0.502, 0.32547 }, 1 }, { { 0.522, 0.32547 }, 1 }, { { 0.522, 0.284188 }, 1 }, { { 0.54, 0.284188 }, 1 }, { { 0.54, 0.327436 }, 1 }, { { 0.556, 0.327436 }, 1 }, { { 0.556, 0.38641 }, 1 }, { { 0.502, 0.38641 }, 1 } };
                    };
                    class Ammo {
                        type = "text";
                        source = "ammo";
                        sourceIndex = 0;
                        sourceScale = 1;
                        sourceLength = 4;
                        align = "center";
                        scale = 1;
                        pos[] = { { 0.53, 0.41 }, 1 };
                        right[] = { { 0.57, 0.41 }, 1 };
                        down[] = { { 0.53, 0.445 }, 1 };
                    };
                };
                class Selected : Default {
                    condition = "(mgun +  (ammo0 min 1))/2";
                    color[] = { 0.99, 0.94, 0.59 };
                    class Shape : Shape {};
                    class Ammo : Ammo {};
                };
                class Empty : Default {
                    condition = "ammo0 <= 0";
                    color[] = { 1, 0, 0, 1 };
                    class Shape : Shape {};
                    class Ammo : Ammo {
                        source = "static";
                        text = "EMPTY";
                    };
                };
            };
            class Pylon1 {
                type = "pylonicon";
                pos[] = { { 0.82, 0.5 }, 1 };
                pylon = 1;
                name = "Heli_Attack_01";
            };
            class Pylon2 : Pylon1 {
                pos[] = { { 0.73, 0.5 }, 1 };
                pylon = 2;
            };
            class Pylon3 : Pylon1 {
                pos[] = { { 0.64, 0.5 }, 1 };
                pylon = 3;
            };
            class Pylon4 : Pylon1 {
                pos[] = { { 0.36, 0.5 }, 1 };
                pylon = 4;
            };
            class ArmBackground {
                color[] = { 0.19, 0.04, 0 };
                class BlackBackground {
                    type = "polygon";
                    points[] = { { { { "0.0+0.48", "0.0+0.14" }, 1 }, { { "0.1+0.48", "0.0+0.14" }, 1 }, { { "0.1+0.48", "0.1+0.14" }, 1 }, { { "0.0+0.48", "0.1+0.14" }, 1 } } };
                };
            };
            class BlackText {
                color[] = { 0.15, 0.01, 0 };
                class CMText {
                    type = "text";
                    source = "static";
                    text = "ARM";
                    scale = 1;
                    sourceScale = 1;
                    align = "center";
                    pos[] = { { 0.53, 0.17 }, 1 };
                    right[] = { { 0.57, 0.17 }, 1 };
                    down[] = { { 0.53, 0.205 }, 1 };
                };
            };
        };
    };
    class MFD_Pilot_5_CM : MFD_Pilot_5 {
        topLeft = "MFD_5_TL";
        topRight = "MFD_5_TR";
        bottomLeft = "MFD_5_BL";
        turret[] = { -1 };
        class Draw {
            color[] = { 0, 0.12, 0 };
            condition = "on";
            class CMText {
                type = "text";
                source = "static";
                text = "CM";
                scale = 1;
                sourceScale = 1;
                align = "center";
                pos[] = { { 0.53, 0.61 }, 1 };
                right[] = { { 0.57, 0.61 }, 1 };
                down[] = { { 0.53, 0.645 }, 1 };
            };
            class CMAmmo {
                type = "text";
                source = "cmammo";
                sourceScale = 1;
                sourceLength = 3;
                align = "center";
                scale = 1;
                pos[] = { { 0.53, 0.66 }, 1 };
                right[] = { { 0.57, 0.66 }, 1 };
                down[] = { { 0.53, 0.695 }, 1 };
            };
        };
    };
    class AirplaneHUD {
        topLeft = "HUD_top_left";
        topRight = "HUD_top_right";
        bottomLeft = "HUD_bottom_left";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = { 1, 1, 1, 1 };
        helmetMountedDisplay = 1;
        helmetPosition[] = { -0.0375, 0.0375, 0.1 };
        helmetRight[] = { 0.075, 0, 0 };
        helmetDown[] = { 0, -0.075, 0 };
        font = "LucidaConsoleB";
        //turret[] = { -2 }; // CAUSES CRASH
        turret[] = { 0 };
        class Bones {
            class HUDCenter {
                type = "fixed";
                pos[] = { 0.5, 0.5 };
            };
            class WeaponFixed {
                type = "fixed";
                pos[] = { 0.5, 0.5 };
                pos10[] = { 0.753, 0.753 };
            };
            class WeaponAim {
                type = "vector";
                source = "weapon";
                pos0[] = { 0.5, 0.5 };
                pos10[] = { 0.734, 0.73 };
            };
            class WeaponAimRelative : WeaponAim {
                source = "weapontoview";
            };
            class VelocityVector {
                type = "vector";
                source = "velocityToView";
                pos0[] = { 0.5, 0.5 };
                pos10[] = { 0.734, 0.73 };
            };
            class ForwardVector {
                type = "vector";
                source = "forward";
                pos0[] = { 0, 0 };
                pos10[] = { 0.234, 0.23 };
            };
            class HorizonVector {
                type = "horizon";
                pos0[] = { 0.5, 0.5 };
                pos10[] = { 0.838, 0.881 };
                angle = 0;
            };
            class GunnerAim {
                type = "vector";
                source = "turret";
                pos0[] = { 0, -2 };
                pos10[] = { 0.0068, -0.01 };
                projection = 0;
            };
            class VerticalSpeedBone {
                type = "linear";
                source = "vspeed";
                sourceScale = 1;
                min = -10;
                max = 10;
                minPos[] = { 0, -0.32 };
                maxPos[] = { 0, 0.32 };
            };
            class SlipVector {
                type = "vector";
                source = "velocity";
                pos0[] = { 0.5, 0.845 };
                pos10[] = { 0.53, 0.845 };
            };
            class ImpactPoint {
                type = "vector";
                source = "ImpactPointToView";
                pos0[] = { 0.5, 0.5 };
                pos10[] = { 0.734, 0.73 };
            };
            class Target {
                source = "targettoview";
                type = "vector";
                pos0[] = { 0.5, 0.5 };
                pos10[] = { 0.734, 0.73 };
            };
            class Limit0109 {
                type = "limit";
                limits[] = { 0.1, 0.1, 0.9, 0.9 };
            };
            class LimitWaypoint {
                type = "limit";
                limits[] = { 0.2, 0.1, 0.8, 0.1 };
            };
            class WPPoint {
                type = "vector";
                source = "WPPoint";
                pos0[] = { 0.5, 0.5 };
                pos10[] = { 0.734, 0.73 };
            };
            class WPPointToView : WPPoint {
                source = "WPPointToView";
            };
            class RadarHeight {
                type = "linear";
                source = "altitudeAGL";
                sourceScale = 3.28084;
                sourceOffset = -2;
                min = 0;
                max = 100;
                minPos[] = { 0.903, 0.18 };
                maxPos[] = { 0.903, 0.82 };
            };
            class HorizonBankRotFull {
                type = "rotational";
                source = "horizonBank";
                center[] = { 0, 0 };
                min = -3.1416;
                max = 3.1416;
                minAngle = -180;
                maxAngle = 180;
                aspectRatio = 1;
            };
        };
        class Draw {
            alpha = 1;
            color[] = { 0.25, 1, 0.25 };
            condition = "(1 - (cameraHeadingDiffY<=-19) + (abs(cameraHeadingDiffX)>=24))*on";
            class Static {
                type = "line";
                width = 4;
                points[] = { { { 0.5, 0.11 }, 1 }, { { 0.5, 0.14 }, 1 }, {}, { { 0.4, 0.86 }, 1 }, { { 0.4, 0.94 }, 1 }, { { 0.6, 0.94 }, 1 }, { { 0.6, 0.86 }, 1 }, { { 0.4, 0.86 }, 1 }, {}, { { 0.4, 0.885 }, 1 }, { { 0.408, 0.885 }, 1 }, {}, { { 0.6, 0.885 }, 1 }, { { 0.592, 0.885 }, 1 }, {}, { { 0.5, 0.86 }, 1 }, { { 0.5, 0.868 }, 1 }, {}, { { 0.5, 0.94 }, 1 }, { { 0.5, 0.932 }, 1 }, {}, { { 0.52, 0.86 }, 1 }, { { 0.52, 0.82 }, 1 }, {}, { { 0.48, 0.86 }, 1 }, { { 0.48, 0.82 }, 1 }, {}, { { 0.55, 0 }, 1 }, { { 0.55, 0.04 }, 1 }, { { 0.45, 0.04 }, 1 }, { { 0.45, 0 }, 1 }, { { 0.55, 0 }, 1 } };
            };
            class HeadingNumber {
                type = "text";
                source = "Heading";
                sourceScale = 1;
                align = "center";
                scale = 1;
                pos[] = { { 0.5, 0.006 }, 1 };
                right[] = { { 0.55, 0.006 }, 1 };
                down[] = { { 0.5, 0.046 }, 1 };
            };
            class HeadingRotation {
                condition = "abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)-5";
                class HeadingHeadNumber {
                    type = "text";
                    source = "cameraDir";
                    sourceScale = 1;
                    align = "center";
                    scale = 1;
                    pos[] = { { "0.80-0.302", "0.082-0.025" }, 1 };
                    right[] = { { "0.83-0.302", "0.082-0.025" }, 1 };
                    down[] = { { "0.80-0.302", "0.113-0.025" }, 1 };
                };
                class HeadingArrow {
                    type = "line";
                    width = 3;
                    points[] = { { { 0.478, 0.045 }, 1 }, { { 0.522, 0.045 }, 1 }, { { 0.552, 0.07 }, 1 }, { { 0.522, 0.095 }, 1 }, { { 0.478, 0.095 }, 1 }, { { 0.448, 0.07 }, 1 }, { { 0.478, 0.045 }, 1 }, {} };
                };
                class HeadingScaleRight {
                    clipTL[] = { 0.55, 0.05 };
                    clipBR[] = { 0.83, 0.11 };
                    class lines {
                        type = "scale";
                        horizontal = 1;
                        source = "heading";
                        sourceScale = 1;
                        width = 4;
                        top = 0.5;
                        center = 0.5;
                        bottom = 0.85;
                        lineXleft = 0.11;
                        lineYright = 0.1;
                        lineXleftMajor = 0.11;
                        lineYrightMajor = 0.09;
                        majorLineEach = 2;
                        numberEach = 2;
                        step = 22.5;
                        stepSize = 0.075;
                        align = "center";
                        scale = 1;
                        pos[] = { 0.496, 0.05 };
                        right[] = { 0.536, 0.05 };
                        down[] = { 0.496, 0.09 };
                    };
                };
                class HeadingScaleMidle {
                    type = "scale";
                    horizontal = 1;
                    source = "heading";
                    sourceScale = 1;
                    width = 4;
                    top = 0.45;
                    center = 0.5;
                    bottom = 0.55;
                    lineXleft = 0.11;
                    lineYright = 0.1;
                    lineXleftMajor = 0.11;
                    lineYrightMajor = 0.1;
                    majorLineEach = 2;
                    step = 22.5;
                    stepSize = 0.075;
                    align = "center";
                    scale = 1;
                    numberEach = 0;
                    pos[] = { 0.47, 0.05 };
                    right[] = { 0.5, 0.05 };
                    down[] = { 0.45, 0.09 };
                };
                class HeadingScaleLeft {
                    clipTL[] = { 0.18, 0.05 };
                    clipBR[] = { 0.45, 0.11 };
                    class lines {
                        type = "scale";
                        horizontal = 1;
                        source = "heading";
                        sourceScale = 1;
                        width = 4;
                        top = 0.15;
                        center = 0.5;
                        bottom = 0.55;
                        lineXleft = 0.11;
                        lineYright = 0.1;
                        lineXleftMajor = 0.11;
                        lineYrightMajor = 0.09;
                        majorLineEach = 2;
                        numberEach = 2;
                        step = 22.5;
                        stepSize = 0.075;
                        align = "center";
                        scale = 1;
                        pos[] = { 0.146, 0.05 };
                        right[] = { 0.186, 0.05 };
                        down[] = { 0.146, 0.09 };
                    };
                };
            };
            class HeadingScaleFull {
                condition = "4-abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)";
                class HeadingScale {
                    clipTL[] = { 0.18, 0 };
                    clipBR[] = { 0.83, 1 };
                    class lines {
                        type = "scale";
                        horizontal = 1;
                        source = "heading";
                        sourceScale = 1;
                        width = 4;
                        top = 0.15;
                        center = 0.5;
                        bottom = 0.85;
                        lineXleft = 0.11;
                        lineYright = 0.1;
                        lineXleftMajor = 0.11;
                        lineYrightMajor = 0.09;
                        majorLineEach = 2;
                        numberEach = 2;
                        step = 22.5;
                        stepSize = 0.075;
                        align = "center";
                        scale = 1;
                        pos[] = { 0.146, 0.05 };
                        right[] = { 0.186, 0.05 };
                        down[] = { 0.146, 0.09 };
                    };
                };
            };
            class SlipVector {
                type = "polygon";
                width = 4;
                points[] = { { { "SlipVector", 1, { 0, 0 }, 1 }, { "SlipVector", { 0.00260472, -0.0145196 }, 1 }, { "SlipVector", { 0.0051303, -0.0138544 }, 1 }, { "SlipVector", { 0.0075, -0.0127683 }, 1 } }, { { "SlipVector", 1, { 0, 0 }, 1 }, { "SlipVector", { 0.0075, -0.0127683 }, 1 }, { "SlipVector", { 0.00964181, -0.0112942 }, 1 }, { "SlipVector", { 0.0114907, -0.009477 }, 1 } }, { { "SlipVector", 1, { 0, 0 }, 1 }, { "SlipVector", { 0.0114907, -0.009477 }, 1 }, { "SlipVector", { 0.0129904, -0.00737179 }, 1 }, { "SlipVector", { 0.0140954, -0.0050426 }, 1 } }, { { "SlipVector", 1, { 0, 0 }, 1 }, { "SlipVector", { 0.0140954, -0.0050426 }, 1 }, { "SlipVector", { 0.0147721, -0.0025602 }, 1 }, { "SlipVector", { 0.015, 6.44463e-010 }, 1 } }, { { "SlipVector", 1, { 0, 0 }, 1 }, { "SlipVector", { 0.015, 6.44463e-010 }, 1 }, { "SlipVector", { 0.0147721, 0.0025602 }, 1 }, { "SlipVector", { 0.0140954, 0.0050426 }, 1 } }, { { "SlipVector", 1, { 0, 0 }, 1 }, { "SlipVector", { 0.0140954, 0.0050426 }, 1 }, { "SlipVector", { 0.0129904, 0.0073718 }, 1 }, { "SlipVector", { 0.0114907, 0.009477 }, 1 } }, { { "SlipVector", 1, { 0, 0 }, 1 }, { "SlipVector", { 0.0114907, 0.009477 }, 1 }, { "SlipVector", { 0.00964181, 0.0112942 }, 1 }, { "SlipVector", { 0.0075, 0.0127683 }, 1 } }, { { "SlipVector", 1, { 0, 0 }, 1 }, { "SlipVector", { 0.0075, 0.0127683 }, 1 }, { "SlipVector", { 0.0051303, 0.0138544 }, 1 }, { "SlipVector", { 0.00260472, 0.0145196 }, 1 } }, { { "SlipVector", 1, { 0, 0 }, 1 }, { "SlipVector", { 0.00260472, 0.0145196 }, 1 }, { "SlipVector", { -1.31134e-009, 0.0147436 }, 1 }, { "SlipVector", { -0.00260473, 0.0145196 }, 1 } }, { { "SlipVector", 1, { 0, 0 }, 1 }, { "SlipVector", { -0.00260473, 0.0145196 }, 1 }, { "SlipVector", { -0.0051303, 0.0138544 }, 1 }, { "SlipVector", { -0.0075, 0.0127683 }, 1 } }, { { "SlipVector", 1, { 0, 0 }, 1 }, { "SlipVector", { -0.0075, 0.0127683 }, 1 }, { "SlipVector", { -0.00964181, 0.0112942 }, 1 }, { "SlipVector", { -0.0114907, 0.009477 }, 1 } }, { { "SlipVector", 1, { 0, 0 }, 1 }, { "SlipVector", { -0.0114907, 0.009477 }, 1 }, { "SlipVector", { -0.0129904, 0.00737179 }, 1 }, { "SlipVector", { -0.0140954, 0.0050426 }, 1 } }, { { "SlipVector", 1, { 0, 0 }, 1 }, { "SlipVector", { -0.0140954, 0.0050426 }, 1 }, { "SlipVector", { -0.0147721, 0.0025602 }, 1 }, { "SlipVector", { -0.015, -1.75816e-010 }, 1 } }, { { "SlipVector", 1, { 0, 0 }, 1 }, { "SlipVector", { -0.015, -1.75816e-010 }, 1 }, { "SlipVector", { -0.0147721, -0.0025602 }, 1 }, { "SlipVector", { -0.0140954, -0.0050426 }, 1 } }, { { "SlipVector", 1, { 0, 0 }, 1 }, { "SlipVector", { -0.0140954, -0.0050426 }, 1 }, { "SlipVector", { -0.0129904, -0.0073718 }, 1 }, { "SlipVector", { -0.0114907, -0.009477 }, 1 } }, { { "SlipVector", 1, { 0, 0 }, 1 }, { "SlipVector", { -0.0114907, -0.009477 }, 1 }, { "SlipVector", { -0.00964181, -0.0112942 }, 1 }, { "SlipVector", { -0.0075, -0.0127683 }, 1 } }, { { "SlipVector", 1, { 0, 0 }, 1 }, { "SlipVector", { -0.0075, -0.0127683 }, 1 }, { "SlipVector", { -0.00513031, -0.0138544 }, 1 }, { "SlipVector", { -0.00260472, -0.0145196 }, 1 } }, { { "SlipVector", 1, { 0, 0 }, 1 }, { "SlipVector", { -0.00260472, -0.0145196 }, 1 }, { "SlipVector", { 2.62268e-009, -0.0147436 }, 1 }, { "SlipVector", { 0.00260472, -0.0145196 }, 1 } } };
            };
            class CollectiveGroup {
                condition = "simulRTD";
                class CollectiveText {
                    type = "text";
                    source = "static";
                    text = "%";
                    align = "right";
                    scale = 1;
                    pos[] = { { 0.22, 0.2 }, 1 };
                    right[] = { { 0.28, 0.2 }, 1 };
                    down[] = { { 0.22, 0.24 }, 1 };
                };
                class CollectiveNumber {
                    type = "text";
                    source = "rtdCollective";
                    sourceScale = 100;
                    align = "left";
                    scale = 1;
                    pos[] = { { 0.22, 0.2 }, 1 };
                    right[] = { { 0.28, 0.2 }, 1 };
                    down[] = { { 0.22, 0.24 }, 1 };
                };
            };
            class SpeedNumber {
                type = "text";
                source = "speed";
                sourceScale = 1.94384;
                align = "right";
                scale = 1;
                pos[] = { { 0.16, 0.48 }, 1 };
                right[] = { { 0.22, 0.48 }, 1 };
                down[] = { { 0.16, 0.52 }, 1 };
            };
            class AltNumber {
                type = "text";
                source = "altitudeAGL";
                sourceScale = 3.28084;
                sourceOffset = -2;
                align = "left";
                scale = 1;
                pos[] = { { 0.81, 0.48 }, 1 };
                right[] = { { 0.87, 0.48 }, 1 };
                down[] = { { 0.81, 0.52 }, 1 };
            };
            class HoverMode {
                condition = "autohover";
                class HoverText {
                    type = "text";
                    source = "static";
                    text = "HOVER";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { 0.005, 0.075 }, 1 };
                    right[] = { { 0.045, 0.075 }, 1 };
                    down[] = { { 0.005, 0.11 }, 1 };
                };
            };
            class CruiseMode {
                condition = "((altitudeASL-27) min 1) - autohover";
                class CruiseText {
                    type = "text";
                    source = "static";
                    text = "CRUISE";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { 0.005, 0.075 }, 1 };
                    right[] = { { 0.045, 0.075 }, 1 };
                    down[] = { { 0.005, 0.11 }, 1 };
                };
                class AltNumberASL {
                    type = "text";
                    source = "altitudeASL";
                    sourceScale = 3.28084;
                    align = "left";
                    scale = 1;
                    pos[] = { { 0.81, 0.16 }, 1 };
                    right[] = { { 0.87, 0.16 }, 1 };
                    down[] = { { 0.81, 0.2 }, 1 };
                };
            };
            class TransitionMode {
                condition = "((27-altitudeASL) min 1) - autohover";
                class TransText {
                    type = "text";
                    source = "static";
                    text = "TRANS";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { 0.005, 0.075 }, 1 };
                    right[] = { { 0.045, 0.075 }, 1 };
                    down[] = { { 0.005, 0.11 }, 1 };
                };
            };
            class HoverModeHide {
                condition = "1-autohover";
                class VelocityLine {
                    type = "line";
                    width = 4;
                    points[] = { { "VelocityVector", { 0, -0.0196581 }, 1 }, { "VelocityVector", { 0.014, -0.0137607 }, 1 }, { "VelocityVector", { 0.02, 0 }, 1 }, { "VelocityVector", { 0.014, 0.0137607 }, 1 }, { "VelocityVector", { 0, 0.0196581 }, 1 }, { "VelocityVector", { -0.014, 0.0137607 }, 1 }, { "VelocityVector", { -0.02, 0 }, 1 }, { "VelocityVector", { -0.014, -0.0137607 }, 1 }, { "VelocityVector", { 0, -0.0196581 }, 1 }, {}, { "VelocityVector", { 0.04, 0 }, 1 }, { "VelocityVector", { 0.02, 0 }, 1 }, {}, { "VelocityVector", { -0.04, 0 }, 1 }, { "VelocityVector", { -0.02, 0 }, 1 }, {}, { "VelocityVector", { 0, -0.0393162 }, 1 }, { "VelocityVector", { 0, -0.0196581 }, 1 }, {} };
                };
            };
            class LaserGroup {
                condition = "laseron";
                class laserText {
                    type = "text";
                    source = "static";
                    text = "LASER";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { 0.015, 0.37 }, 1 };
                    right[] = { { 0.055, 0.37 }, 1 };
                    down[] = { { 0.015, 0.405 }, 1 };
                };
            };
            class RadarGroup {
                condition = "activeSensorsOn";
                class radarText {
                    type = "text";
                    source = "static";
                    text = "RADAR";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { 0.015, 0.41 }, 1 };
                    right[] = { { 0.055, 0.41 }, 1 };
                    down[] = { { 0.015, 0.445 }, 1 };
                };
            };
            class VerticalSpeedScale {
                type = "line";
                width = 4;
                points[] = { { "WeaponAimRelative", 1, { -0.03, 0 }, 1 }, { "WeaponAimRelative", 1, { -0.02, 0 }, 1 }, {}, { "WeaponAimRelative", 1, { 0.02, 0 }, 1 }, { "WeaponAimRelative", 1, { 0.03, 0 }, 1 }, {}, { "WeaponAimRelative", 1, { 0, -0.02 }, 1 }, { "WeaponAimRelative", 1, { 0, -0.03 }, 1 }, {}, { "WeaponAimRelative", 1, { 0, 0.02 }, 1 }, { "WeaponAimRelative", 1, { 0, 0.03 }, 1 }, {}, { "HUDCenter", 1, { -0.03, 0 }, 1 }, { "HUDCenter", 1, { -0.01, 0 }, 1 }, {}, { "HUDCenter", 1, { 0.01, 0 }, 1 }, { "HUDCenter", 1, { 0.03, 0 }, 1 }, {}, { "HUDCenter", 1, { 0, -0.01 }, 1 }, { "HUDCenter", 1, { 0, -0.03 }, 1 }, {}, { "HUDCenter", 1, { 0, 0.01 }, 1 }, { "HUDCenter", 1, { 0, 0.03 }, 1 }, {}, { { 0.915, 0.18 }, 1 }, { { 0.935, 0.18 }, 1 }, {}, { { 0.87, 0.18 }, 1 }, { { 0.89, 0.18 }, 1 }, {}, { { 0.915, 0.34 }, 1 }, { { 0.935, 0.34 }, 1 }, {}, { { 0.87, 0.34 }, 1 }, { { 0.89, 0.34 }, 1 }, {}, { { 0.875, 0.372 }, 1 }, { { 0.885, 0.372 }, 1 }, {}, { { 0.875, 0.404 }, 1 }, { { 0.885, 0.404 }, 1 }, {}, { { 0.875, 0.436 }, 1 }, { { 0.885, 0.436 }, 1 }, {}, { { 0.875, 0.468 }, 1 }, { { 0.885, 0.468 }, 1 }, {}, { { 0.87, 0.5 }, 1 }, { { 0.89, 0.5 }, 1 }, {}, { { 0.915, 0.5 }, 1 }, { { 0.935, 0.5 }, 1 }, {}, { { 0.915, 0.66 }, 1 }, { { 0.935, 0.66 }, 1 }, {}, { { 0.87, 0.66 }, 1 }, { { 0.89, 0.66 }, 1 }, {}, { { 0.875, 0.628 }, 1 }, { { 0.885, 0.628 }, 1 }, {}, { { 0.875, 0.596 }, 1 }, { { 0.885, 0.596 }, 1 }, {}, { { 0.875, 0.564 }, 1 }, { { 0.885, 0.564 }, 1 }, {}, { { 0.875, 0.532 }, 1 }, { { 0.885, 0.532 }, 1 }, {}, { { 0.92, 0.692 }, 1 }, { { 0.93, 0.692 }, 1 }, {}, { { 0.92, 0.724 }, 1 }, { { 0.93, 0.724 }, 1 }, {}, { { 0.92, 0.756 }, 1 }, { { 0.93, 0.756 }, 1 }, {}, { { 0.92, 0.788 }, 1 }, { { 0.93, 0.788 }, 1 }, {}, { { 0.915, 0.82 }, 1 }, { { 0.935, 0.82 }, 1 }, {}, { { 0.87, 0.82 }, 1 }, { { 0.89, 0.82 }, 1 }, {} };
            };
            class VerticalSpeedArrow {
                type = "polygon";
                points[] = { { { "VerticalSpeedBone", { 0.85, 0.488 }, 1 }, { "VerticalSpeedBone", { 0.87, 0.5 }, 1 }, { "VerticalSpeedBone", { 0.85, 0.512 }, 1 } } };
            };
            class RadarAltitude {
                condition = "101-altitudeAGL";
                class RadarHeight {
                    type = "line";
                    width = 15;
                    points[] = { { { 0.903, 0.82 }, 1 }, { "RadarHeight", { 0, 0 }, 1 }, {} };
                };
            };
            class HorizonLine {
                condition = "1-autohover";
                clipTL[] = { 0.2, 0.145 };
                clipBR[] = { 0.8, 0.855 };
                class HorizonLineDraw {
                    type = "line";
                    width = 4;
                    points[] = { { "HorizonVector", { -0.225, 0 }, 1 }, { "HorizonVector", { -0.1875, 0 }, 1 }, {}, { "HorizonVector", { -0.15, 0 }, 1 }, { "HorizonVector", { -0.1125, 0 }, 1 }, {}, { "HorizonVector", { -0.075, 0 }, 1 }, { "HorizonVector", { -0.0375, 0 }, 1 }, {}, { "HorizonVector", { 0.0375, 0 }, 1 }, { "HorizonVector", { 0.075, 0 }, 1 }, {}, { "HorizonVector", { 0.1125, 0 }, 1 }, { "HorizonVector", { 0.15, 0 }, 1 }, {}, { "HorizonVector", { 0.1875, 0 }, 1 }, { "HorizonVector", { 0.225, 0 }, 1 } };
                };
            };
            class Gunner {
                type = "line";
                width = 4;
                points[] = { { "GunnerAim", { 0.485, 0.892 }, 1 }, { "GunnerAim", { 0.485, 0.908 }, 1 }, { "GunnerAim", { 0.515, 0.908 }, 1 }, { "GunnerAim", { 0.515, 0.892 }, 1 }, { "GunnerAim", { 0.485, 0.892 }, 1 } };
            };
            class WeaponsText {
                condition = "1- mgun";
                class Weapons {
                    type = "text";
                    source = "weapon";
                    sourceScale = 1;
                    align = "left";
                    scale = 0.5;
                    pos[] = { { 0.38, 0.869 }, 1 };
                    right[] = { { 0.415, 0.869 }, 1 };
                    down[] = { { 0.38, 0.904 }, 1 };
                };
            };
            class Ammo {
                type = "text";
                source = "ammo";
                sourceScale = 1;
                align = "left";
                scale = 0.5;
                pos[] = { { 0.38, 0.901 }, 1 };
                right[] = { { 0.415, 0.901 }, 1 };
                down[] = { { 0.38, 0.936 }, 1 };
            };
            class MGun {
                condition = "mgun";
                class Weapons {
                    type = "text";
                    source = "static";
                    text = "GUN";
                    sourceScale = 1;
                    align = "left";
                    scale = 0.5;
                    pos[] = { { 0.38, 0.869 }, 1 };
                    right[] = { { 0.415, 0.869 }, 1 };
                    down[] = { { 0.38, 0.904 }, 1 };
                };
                class Circle {
                    type = "line";
                    width = 4;
                    points[] = { { "WeaponAimRelative", { 0.025, 0 }, 1 }, { "WeaponAimRelative", { 0.01, 0 }, 1 }, {}, { "WeaponAimRelative", { 0, 0.0245726 }, 1 }, { "WeaponAimRelative", { 0, 0.00982906 }, 1 }, {}, { "WeaponAimRelative", { -0.025, 0 }, 1 }, { "WeaponAimRelative", { -0.01, 0 }, 1 }, {}, { "WeaponAimRelative", { 0, -0.0245726 }, 1 }, { "WeaponAimRelative", { 0, -0.00982906 }, 1 }, {}, { "WeaponAimRelative", { 0, -0.00982906 }, 1 }, { "WeaponAimRelative", { 0.007, -0.00688034 }, 1 }, { "WeaponAimRelative", { 0.01, 0 }, 1 }, { "WeaponAimRelative", { 0.007, 0.00688034 }, 1 }, { "WeaponAimRelative", { 0, 0.00982906 }, 1 }, { "WeaponAimRelative", { -0.007, 0.00688034 }, 1 }, { "WeaponAimRelative", { -0.01, 0 }, 1 }, { "WeaponAimRelative", { -0.007, -0.00688034 }, 1 }, { "WeaponAimRelative", { 0, -0.00982906 }, 1 } };
                };
            };
            class AAMissile {
                condition = "AAmissile";
                class Circle {
                    type = "line";
                    width = 4;
                    points[] = { { "ForwardVector", 1, "HUDCenter", { 0, -0.245726 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.0434, -0.241991 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.0855, -0.230909 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.125, -0.212799 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.1607, -0.188226 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.1915, -0.157953 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.2165, -0.122863 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.234925, -0.0840385 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.2462, -0.0426581 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.25, 0 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.2462, 0.0426581 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.234925, 0.0840385 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.2165, 0.122863 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.1915, 0.157953 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.1607, 0.188226 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.125, 0.212799 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.0855, 0.230909 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.0434, 0.241991 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0, 0.245726 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.0434, 0.241991 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.0855, 0.230909 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.125, 0.212799 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.1607, 0.188226 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.1915, 0.157953 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.2165, 0.122863 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.234925, 0.0840385 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.2462, 0.0426581 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.25, 0 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.2462, -0.0426581 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.234925, -0.0840385 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.2165, -0.122863 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.1915, -0.157953 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.1607, -0.188226 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.125, -0.212799 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.0855, -0.230909 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.0434, -0.241991 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0, -0.245726 }, 1 } };
                };
            };
            class ATMissile {
                condition = "ATmissile";
                class Circle {
                    type = "line";
                    width = 4;
                    points[] = { { "ForwardVector", 1, "HUDCenter", { -0.15, -0.147436 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.15, -0.127778 }, 1 }, {}, { "ForwardVector", 1, "HUDCenter", { -0.15, 0.147436 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.15, 0.127778 }, 1 }, {}, { "ForwardVector", 1, "HUDCenter", { 0.15, -0.147436 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.15, -0.127778 }, 1 }, {}, { "ForwardVector", 1, "HUDCenter", { 0.15, 0.147436 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.15, 0.127778 }, 1 }, {}, { "ForwardVector", 1, "HUDCenter", { -0.15, -0.147436 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.13, -0.147436 }, 1 }, {}, { "ForwardVector", 1, "HUDCenter", { -0.15, 0.147436 }, 1 }, { "ForwardVector", 1, "HUDCenter", { -0.13, 0.147436 }, 1 }, {}, { "ForwardVector", 1, "HUDCenter", { 0.15, -0.147436 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.13, -0.147436 }, 1 }, {}, { "ForwardVector", 1, "HUDCenter", { 0.15, 0.147436 }, 1 }, { "ForwardVector", 1, "HUDCenter", { 0.13, 0.147436 }, 1 } };
                };
            };
            class RocketCross {
                condition = "rocket";
                class Circle {
                    type = "line";
                    width = 4;
                    points[] = { { "ForwardVector", 1, "Weapons", 1, { -0.05, -0.08 }, 1 }, { "ForwardVector", 1, "Weapons", 1, { 0.05, -0.08 }, 1 }, {}, { "ForwardVector", 1, "Weapons", 1, { 0, -0.08 }, 1 }, { "ForwardVector", 1, "Weapons", 1, { 0, 0.08 }, 1 }, {}, { "ForwardVector", 1, "Weapons", 1, { -0.05, 0.08 }, 1 }, { "ForwardVector", 1, "Weapons", 1, { 0.05, 0.08 }, 1 }, {} };
                };
            };
            class WP {
                condition = "wpvalid - autohover";
                class WPdist {
                    type = "text";
                    source = "wpdist";
                    sourceScale = 0.001;
                    sourcePrecision = 1;
                    align = "left";
                    scale = 1;
                    pos[] = { { 0.235, 0.774038 }, 1 };
                    right[] = { { 0.275, 0.774038 }, 1 };
                    down[] = { { 0.235, 0.80156 }, 1 };
                };
                class WPIndex {
                    type = "text";
                    source = "wpIndex";
                    sourceScale = 1;
                    sourceLength = 2;
                    align = "right";
                    scale = 1;
                    pos[] = { { 0.096, 0.776004 }, 1 };
                    right[] = { { 0.126, 0.776004 }, 1 };
                    down[] = { { 0.096, 0.799594 }, 1 };
                };
                class WPstatic {
                    type = "text";
                    source = "static";
                    text = "W";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { 0.075, 0.775 }, 1 };
                    right[] = { { 0.105, 0.775 }, 1 };
                    down[] = { { 0.075, 0.8 }, 1 };
                };
                class WPAuto {
                    type = "text";
                    source = "static";
                    text = "A";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { "0.075 +0.035", 0.8 }, 1 };
                    right[] = { { 0.14, 0.8 }, 1 };
                    down[] = { { "0.075 +0.035", 0.825 }, 1 };
                };
                class WPKM {
                    type = "text";
                    source = "static";
                    text = "KM";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { "0.075 +0.16", 0.775 }, 1 };
                    right[] = { { 0.265, 0.775 }, 1 };
                    down[] = { { "0.075 +0.16", 0.803 }, 1 };
                };
                class WPTime {
                    type = "text";
                    source = "static";
                    text = "-:--";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { "0.075 +0.11", 0.8 }, 1 };
                    right[] = { { 0.215, 0.8 }, 1 };
                    down[] = { { "0.075 +0.11", 0.825 }, 1 };
                };
                class WP {
                    type = "line";
                    width = 2;
                    points[] = { { "WPPoint", 1, "LimitWaypoint", 1, { -0.02, 0.042 }, 1 }, { "WPPoint", 1, "LimitWaypoint", 1, { 0, 0.022 }, 1 }, { "WPPoint", 1, "LimitWaypoint", 1, { 0.02, 0.042 }, 1 } };
                };
            };
            class WeaponsLocking {
                condition = "missilelocking";
                blinkingPattern[] = { 0.2, 0.2 };
                blinkingStartsOn = 1;
                class Text {
                    type = "text";
                    source = "static";
                    text = "LOCKING";
                    align = "center";
                    scale = 1;
                    pos[] = { { 0.493, 0.766667 }, 1 };
                    right[] = { { 0.553, 0.766667 }, 1 };
                    down[] = { { 0.493, 0.815812 }, 1 };
                };
            };
            class IncomingMissile {
                condition = "incomingmissile";
                blinkingPattern[] = { 0.3, 0.3 };
                blinkingStartsOn = 1;
                class Text {
                    type = "text";
                    source = "static";
                    text = "!INCOMING MISSILE!";
                    align = "center";
                    scale = 1;
                    pos[] = { { 0.485, 0.216239 }, 1 };
                    right[] = { { 0.545, 0.216239 }, 1 };
                    down[] = { { 0.485, 0.265385 }, 1 };
                };
            };
            class RadarTargets {
                class RadarBoxes {
                    type = "radartoview";
                    pos0[] = { 0.5, 0.5 };
                    pos10[] = { 0.734, 0.73 };
                    width = 4;
                    points[] = { { { -0.0035, -0.00344017 }, 1 }, { { 0.0035, -0.00344017 }, 1 }, { { 0.0035, 0.00344017 }, 1 }, { { -0.0035, 0.00344017 }, 1 }, { { -0.0035, -0.00344017 }, 1 } };
                };
            };
            class TargetDiamond {
                class shape {
                    type = "line";
                    width = 3;
                    points[] = { { "Target", 1, "Limit0109", 1, { 0.0075, 0 }, 1 }, { "Target", 1, "Limit0109", 1, { 0.0125, 0 }, 1 }, {}, { "Target", 1, "Limit0109", 1, { 0.0175, 0 }, 1 }, { "Target", 1, "Limit0109", 1, { 0.0225, 0 }, 1 }, {}, { "Target", 1, "Limit0109", 1, { 0.0275, 0 }, 1 }, { "Target", 1, "Limit0109", 1, { 0.0325, 0 }, 1 }, {}, { "Target", 1, "Limit0109", 1, { 0.0375, 0 }, 1 }, { "Target", 1, "Limit0109", 1, { 0.0425, 0 }, 1 }, {}, { "Target", 1, "Limit0109", 1, { 0.0475, 0 }, 1 }, { "Target", 1, "Limit0109", 1, { 0.0525, 0 }, 1 }, {}, { "Target", 1, "Limit0109", 1, { -0.0075, 0 }, 1 }, { "Target", 1, "Limit0109", 1, { -0.0125, 0 }, 1 }, {}, { "Target", 1, "Limit0109", 1, { -0.0175, 0 }, 1 }, { "Target", 1, "Limit0109", 1, { -0.0225, 0 }, 1 }, {}, { "Target", 1, "Limit0109", 1, { -0.0275, 0 }, 1 }, { "Target", 1, "Limit0109", 1, { -0.0325, 0 }, 1 }, {}, { "Target", 1, "Limit0109", 1, { -0.0375, 0 }, 1 }, { "Target", 1, "Limit0109", 1, { -0.0425, 0 }, 1 }, {}, { "Target", 1, "Limit0109", 1, { -0.0475, 0 }, 1 }, { "Target", 1, "Limit0109", 1, { -0.0525, 0 }, 1 }, {}, { "Target", 1, "Limit0109", 1, { 0, 0.00737179 }, 1 }, { "Target", 1, "Limit0109", 1, { 0, 0.0122863 }, 1 }, {}, { "Target", 1, "Limit0109", 1, { 0, 0.0172009 }, 1 }, { "Target", 1, "Limit0109", 1, { 0, 0.0221154 }, 1 }, {}, { "Target", 1, "Limit0109", 1, { 0, 0.0270299 }, 1 }, { "Target", 1, "Limit0109", 1, { 0, 0.0319444 }, 1 }, {}, { "Target", 1, "Limit0109", 1, { 0, 0.036859 }, 1 }, { "Target", 1, "Limit0109", 1, { 0, 0.0417735 }, 1 }, {}, { "Target", 1, "Limit0109", 1, { 0, 0.046688 }, 1 }, { "Target", 1, "Limit0109", 1, { 0, 0.0516026 }, 1 }, {}, { "Target", 1, "Limit0109", 1, { 0, -0.00737179 }, 1 }, { "Target", 1, "Limit0109", 1, { 0, -0.0122863 }, 1 }, {}, { "Target", 1, "Limit0109", 1, { 0, -0.0172009 }, 1 }, { "Target", 1, "Limit0109", 1, { 0, -0.0221154 }, 1 }, {}, { "Target", 1, "Limit0109", 1, { 0, -0.0270299 }, 1 }, { "Target", 1, "Limit0109", 1, { 0, -0.0319444 }, 1 }, {}, { "Target", 1, "Limit0109", 1, { 0, -0.036859 }, 1 }, { "Target", 1, "Limit0109", 1, { 0, -0.0417735 }, 1 }, {}, { "Target", 1, "Limit0109", 1, { 0, -0.046688 }, 1 }, { "Target", 1, "Limit0109", 1, { 0, -0.0516026 }, 1 }, {} };
                };
            };
            class TargetLocked {
                condition = "missilelocked";
                class TargetLockedText {
                    type = "text";
                    source = "static";
                    text = "VALID LOCK";
                    scale = 1;
                    sourceScale = 1;
                    align = "center";
                    pos[] = { { 0.493, 0.779 }, 1 };
                    right[] = { { 0.533, 0.779 }, 1 };
                    down[] = { { 0.493, 0.81 }, 1 };
                };
                class TimeOfFlightText {
                    type = "text";
                    source = "static";
                    text = "TOF:";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { "0.127+0.49", 0.869 }, 1 };
                    right[] = { { 0.652, 0.869 }, 1 };
                    down[] = { { "0.127+0.49", 0.904 }, 1 };
                };
                class DistanceText {
                    type = "text";
                    source = "static";
                    text = "DIST:";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { "0.125+0.49", 0.901 }, 1 };
                    right[] = { { 0.65, 0.901 }, 1 };
                    down[] = { { "0.125+0.49", 0.936 }, 1 };
                };
                class TOF_source {
                    type = "text";
                    scale = 1;
                    sourceScale = 1;
                    source = "missileflighttime";
                    align = "right";
                    pos[] = { { 0.739, 0.869 }, 1 };
                    right[] = { { 0.774, 0.869 }, 1 };
                    down[] = { { 0.739, 0.904 }, 1 };
                };
                class TargetDistance : TOF_source {
                    source = "targetDist";
                    sourceLength = 0;
                    sourcePrecision = 1;
                    sourceScale = 0.001;
                    align = "right";
                    pos[] = { { 0.739, 0.901 }, 1 };
                    right[] = { { 0.774, 0.901 }, 1 };
                    down[] = { { 0.739, 0.936 }, 1 };
                };
            };
        };
    };
    class HMD_CMPilot : AirplaneHUD {
        turret[] = { -1 };
        class Draw {
            alpha = 1;
            color[] = { 0.25, 1, 0.25 };
            condition = "(1 - (cameraHeadingDiffY<=-19) + (abs(cameraHeadingDiffX)>=24))*on";
            class cmWeapons {
                type = "text";
                source = "cmweapon";
                sourceScale = 1;
                align = "right";
                scale = 0.5;
                pos[] = { { 0.001, 0.869 }, 1 };
                right[] = { { 0.036, 0.869 }, 1 };
                down[] = { { 0.001, 0.904 }, 1 };
            };
            class cmAmmo {
                type = "text";
                source = "cmammo";
                sourceScale = 1;
                align = "right";
                scale = 0.5;
                pos[] = { { 0.001, 0.901 }, 1 };
                right[] = { { 0.036, 0.901 }, 1 };
                down[] = { { 0.001, 0.936 }, 1 };
            };
        };
    };
};
