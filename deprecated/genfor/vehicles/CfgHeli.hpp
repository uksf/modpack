//Mi 8 - 2 Variants
class mas_Mi8_Base;
class I_mas_MI8: mas_Mi8_Base {
    scope = 0;
};
class I_mas_MI8MTV: mas_Mi8_Base {
    scope = 0;
};
class O_mas_MI8: I_mas_MI8 {
    scope = 0;
};
class O_mas_MI8MTV: I_mas_MI8MTV {
    scope = 0;
};
class Genfor_Air_MI8: O_mas_MI8 {
    scope = 2;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Air_MI8.jpg);
    displayName = "Mi-8";
    crew = "GENFOR_P";
    typicalCargo[] = { "GENFOR_C" };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
class Genfor_Air_MI8MTV: O_mas_MI8 {
    scope = 2;
    faction = "UKSF_Genfor";
    displayName = "Mi-8 MTV";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Air_MI8MTV.jpg);
    crew = "GENFOR_P";
    typicalCargo[] = { "GENFOR_C" };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
class Genfor_Air_MI8_Populated: Genfor_Air_MI8 {
    displayName = "Mi-8 (Populated)";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Air_MI8_Populated.jpg);
    class EventHandlers {
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};
class Genfor_Air_MI8MTV_Populated: Genfor_Air_MI8MTV {
    displayName = "Mi-8 MTV (Populated)";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Air_MI8MTV_Populated.jpg);
    class EventHandlers {
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

//Mi 24 Hind - 1 Variant
class mas_Mi24_Base;
class I_mas_MI24V: mas_Mi24_Base {
    scope = 0;
};
class O_mas_MI24V: I_mas_MI24V {
    scope = 0;
};
class Genfor_Air_MI24: O_mas_MI24V {
    scope = 2;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Air_MI24.jpg);
    crew = "GENFOR_P";
    typicalCargo[] = {
        "GENFOR_P"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
