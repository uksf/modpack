class Cfg3DEN {
    class Object {
        class AttributeCategories {
            class Inventory {
                class Attributes {
                    class Enh_RemoveWeapons;
                    class Enh_VirtualArsenal: Enh_RemoveWeapons {
                        displayName = "Arsenal";
                        tooltip = "Adds an Arsenal with all items to the object";
                        property = "Enh_virtualArsenal";
                        expression = QUOTE(if (!is3DEN && _value) then {[_this] call FUNC(addArsenal)});
                        condition = "objectControllable + objectVehicle + objectSimulated + objectDestructable + objectHasInventoryCargo";
                    };
                };
            };
        };
    };
};
