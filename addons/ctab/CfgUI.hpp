#define LISTBOX_MULTI_SELECT 32

class cTab_RscListBox;

class GVAR(listBox): cTab_RscListBox {
    x = 0;
    y = 0;
    w = 0;
    h = 0;
};

class GVAR(listBoxMulti): GVAR(listBox) {
    style = LISTBOX_MULTI_SELECT;
};

class ScrollBar;
class cTab_RscCombo;

class GVAR(combo): cTab_RscCombo {
    class ComboScrollBar: ScrollBar {};
};
