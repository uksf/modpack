class RscStandardDisplay;
class RscDisplayMain: RscStandardDisplay {
    class controls {
        class GroupSingleplayer: RscControlsGroupNoScrollbars {
            class Controls;
        };
        class GroupTutorials: GroupSingleplayer {
            h = "(5 *   1.5) *  (pixelH * pixelGrid * 2)";

            class Controls: Controls {
                class Bootcamp;
                class VRTraining;
                class Arsenal: Bootcamp {
                    h = "0";
                };
                class ace_arsenal_mission: Arsenal {
                    h = "1.5 * (pixelH * pixelGrid * 2) - (pixelH)";
                    y = "(2 * 1.5) * (pixelH * pixelGrid * 2) + (pixelH)";
                };
                class FieldManual: Bootcamp {
                    y = "(3 * 1.5) * (pixelH * pixelGrid * 2) + (pixelH)";
                };
                class CommunityGuides: Bootcamp {
                    y = "(4 * 1.5) * (pixelH * pixelGrid * 2) + (pixelH)";
                };
            };
        };
    };
};
