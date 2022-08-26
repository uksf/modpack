class RscDisplayMain : RscStandardDisplay {
    class Controls {
        class GVAR(directConnectLogo) : RscPictureKeepAspectAllowPixelSplit {
            text = QPATHTOEF(common,data\icon_uksf_ca.paa);
            x = DIRECTCONNECTLOGO_X;
            y = "safezoneY + 2.15 * (pixelH * pixelGrid * 2)";
            w = "2.00 * (pixelH * pixelGrid * 2)";
            h = "1.70 * (pixelH * pixelGrid * 2)";
        };
        class GVAR(serverList) : RscCombo {
            idc = 56567;
            onLoad = QUOTE(call (uiNamespace getVariable QQFUNC(onServerListLoad)));
            onLBSelChanged = QUOTE(call (uiNamespace getVariable QQFUNC(onServerListChange)));
            x = DIRECTCONNECTLIST_X;
            y = "safezoneY + 2 * (pixelH * pixelGrid * 2)";
            w = "9 * (pixelW * pixelGrid * 2)";
            h = "2 * (pixelH * pixelGrid * 2)";
        };
        class GVAR(directConnectButton) : RscButtonMenu {
            idc = 56568;
            colorBackground[] = { 0, 0, 0, 0 };
            colorBackground2[] = { 1, 1, 1, 1 };
            size = "1.25 * (pixelH * pixelGrid * 2)";
            text = "Connect";
            style = "0x02 + 0xC0";
            x = DIRECTCONNECTBUTTON_X;
            y = "safezoneY + 2 * (pixelH * pixelGrid * 2)";
            w = "5 * (pixelW * pixelGrid * 2)";
            h = "2 * (pixelH * pixelGrid * 2)";
            onButtonClick = QUOTE(call (uiNamespace getVariable QQFUNC(connectToServer)));
            class Attributes {
                align = "center";
                color = "#ffffff";
                font = "PuristaLight";
                shadow = 0;
                size = 1;
            };
            class TextPos {
                left = "0.1 * 2 * (pixelW * pixelGrid * 2)";
                top = "0.18 * 2 * (pixelH * pixelGrid * 2)";
                right = "0.1 * 2 * (pixelW * pixelGrid * 2)";
                bottom = "0.18 * 2 * (pixelH * pixelGrid * 2)";
            };
        };
    };
};
