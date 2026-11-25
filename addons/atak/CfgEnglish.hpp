class CfgMods {
    class COMSPEC_Overwatch {
        name = "COMSPEC ATAK";
        tooltip = "COMSPEC ATAK";
        overview = "Tactical phone, map, messaging and tablet.";
        actionName = "";
        action = "";
    };
};

class CfgSounds {
    class COMSPEC_ATAK_SilentVib { name = "Silent - vibrate only"; };
    class COMSPEC_ATAK_Vibrate { name = "Terminal vibrate"; };
    class COMSPEC_ATAK_Stalker { name = "Tension ambience"; };
    class COMSPEC_ATAK_Health { name = "Medical signal"; };
    class COMSPEC_ATAK_Start { name = "ATAK start-up"; };
    class COMSPEC_ATAK_Disconnect { name = "ATAK disconnect"; };
    class COMSPEC_ATAK_Unconscious { name = "Unconscious alert"; };
    class COMSPEC_ATAK_Death { name = "Death alert"; };
    class COMSPEC_ATAK_Order { name = "Order received"; };
    class COMSPEC_ATAK_OrderPrio { name = "Priority order"; };
    class COMSPEC_ATAK_OrderAck { name = "Order accepted"; };
    class COMSPEC_ATAK_Intel { name = "Intel sent"; };
    class COMSPEC_ATAK_Beep { name = "ATAK beep"; };
};

class COMSPEC_ATAK_Module_DataBase;
class COMSPEC_ATAK_Module_Mesh : COMSPEC_ATAK_Module_DataBase {
    class Attributes {
        class Keys {
            displayName = "Group keys";
            tooltip = "name:side;name:side. Example: K-ALPHA:WEST;K-BRAVO:WEST. Game mechanic, used with the keys setting.";
        };
        class Groups {
            displayName = "Groups";
            tooltip = "number:name:key;... Example: 1:CMD:K-ALPHA;2:ALPHA:";
        };
        class Freq {
            displayName = "Frequency to group";
            tooltip = "MHz:group;... Example: 43.5:2;44:3. Empty: group derived from the frequency.";
        };
        class Backup {
            displayName = "Backup channel";
            tooltip = "1 to 16. 0: server setting.";
        };
        class Profile {
            displayName = "Realism profile";
            tooltip = "-1: server setting. 3 Milsim, 2 Standard, 1 Arcade.";
        };
    };
};
