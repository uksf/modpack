#include "RscCommon.hpp"
#define pixelScale  0.25
#define GRID_W (pixelW * pixelGridNoUIScale * pixelScale)
#define GRID_H (pixelH * pixelGridNoUIScale * pixelScale)

#define WIDTH_TOTAL (safezoneW - 2 * (93 * GRID_W))
#define WIDTH_GAP (WIDTH_TOTAL / 100)
#define WIDTH_SINGLE ((WIDTH_TOTAL - 6 * WIDTH_GAP) / 5)

class ace_arsenal_display {
    class controls {
        class menuBar: RscControlsGroupNoScrollbars {
            x = QUOTE(0.5 - WIDTH_TOTAL / 2);
            y = QUOTE(safezoneH + safezoneY - 17 * GRID_H - WIDTH_GAP);
            w = QUOTE(WIDTH_TOTAL);
            h = QUOTE(15 * GRID_H + WIDTH_GAP);
            class controls {
                class buttonHide: ctrlButton {
                    y = QUOTE(8 * GRID_H + WIDTH_GAP);
                };
                class buttonLoadouts: buttonHide {
                    y = QUOTE(8 * GRID_H + WIDTH_GAP);
                };
                class buttonExport: buttonHide {
                    y = QUOTE(8 * GRID_H + WIDTH_GAP);
                };
                class buttonImport: buttonHide {
                    y = QUOTE(8 * GRID_H + WIDTH_GAP);
                };
                class buttonClose: ctrlButtonOK {
                    y = QUOTE(8 * GRID_H + WIDTH_GAP);
                };
                class buttonMainOp: buttonClose {
                    idc = 1006;
                    x = QUOTE(1 * WIDTH_GAP + 0 * WIDTH_SINGLE);
                    y = QUOTE(0);
                    text = "Turn On Main Op Gear";
                    onButtonClick = QUOTE([ctrlparent (_this select 0)] call FUNC(switchMainOpGear));
                };
            };
        };
    };
};
