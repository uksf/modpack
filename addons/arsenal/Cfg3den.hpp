class Cfg3DEN {
    class Attributes {
        class TitleWide;
        class AmmoBox: TitleWide {
            scriptName = "AmmoBox";
            scriptPath = "UKSFAttributes";
            onLoad = "[""onLoad"",_this,""AmmoBox"",'UKSFAttributes',false] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
            onUnload = "[""onUnload"",_this,""AmmoBox"",'UKSFAttributes',false] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
            attributeLoad = "['attributeLoad',_this] call (uinamespace getvariable 'AmmoBox_script');";
            attributeSave = "['attributeSave',_this] call (uinamespace getvariable 'AmmoBox_script');";
        };
    };
    class Object {
        class AttributeCategories {
            class Inventory {
                displayName = "$STR_3DEN_Object_AttributeCategory_Storage";
                collapsed = 1;
                class Attributes {
                    class AmmoBox {
                        property = "ammoBox";
                        value = 0;
                        control = "AmmoBox";
                        displayName = "$STR_3DEN_Object_AttributeCategory_Storage";
                        tooltip = "";
                        expression = "[_this,_value] call uksf_arsenal_fnc_initAmmoBox;";
                        defaultValue = "_this call uksf_arsenal_fnc_initAmmoBox;";
                        condition = "objectHasInventoryCargo";
                        wikiType = "[[String]]";
                    };
                    class Enh_RemoveWeapons;
                    class Enh_Arsenal: Enh_RemoveWeapons {
                        displayName = $STR_arsenal_displayName;
                        tooltip = $STR_arsenal_tooltip;
                        property = "Enh_arsenal";
                        expression = "if (_value && !is3DEN) then {['AmmoboxInit',[_this,true]] spawn uksf_arsenal_fnc_arsenal}";
                        condition = "objectControllable + objectVehicle + objectSimulated + objectDestructable";
                    };
                };
            };
        };
    };
};
class RscDisplayArsenal {
    scriptName = "RscDisplayArsenal";
    scriptPath = "UKSFGUI";
    onLoad = "[""onLoad"",_this,""RscDisplayArsenal"",'UKSFGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
    onUnload = "[""onUnload"",_this,""RscDisplayArsenal"",'UKSFGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
};
class CfgScriptPaths {
    UKSFAttributes = "u\uksf\addons\arsenal\UI\attributes\";
    UKSFGUI = "u\uksf\addons\arsenal\UI\";
};
