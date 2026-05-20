class RscText;
class RscPicture;

class GVAR(HintPanel): RscText {
    text = "";
    colorBackground[] = {0, 0, 0, 0.65};
};

class GVAR(HintText): RscText {
    sizeEx = 0.025;
    colorText[] = {1, 1, 1, 1};
    colorBackground[] = {0, 0, 0, 0};
    shadow = 1;
};

class GVAR(HintIcon): RscPicture {
    colorText[] = {1, 1, 1, 1};
};
