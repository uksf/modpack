class cfgGroups
{
  class EAST
  {
    name = "OPFOR";
    class ACR {
      name = "ACR";
      class Infantry {
        name = "Infantry";
        class GVAR(Sniper_Pair) {
          name = "Sniper Pair";
          faction = QUOTE(ADDON);
          side = 0;
          class Unit0 {
            side = 0;
            vehicle = QGVAR(Sniper);
            rank = "PRIVATE";
            position[] = {0,-0,0};
          };
          class Unit1 {
            side = 0;
            vehicle = QGVAR(Sniper);
            rank = "PRIVATE";
            position[] = {0,-5,0};
          };
        };
        class GVAR(HQ) {
          name = "HQ";
          faction = QUOTE(ADDON);
          side = 0;
          class Unit0 {
            side = 0;
            vehicle = QGVAR(Officer);
            rank = "PRIVATE";
            position[] = {0,-0,0};
          };
          class Unit1 {
            side = 0;
            vehicle = QGVAR(Rifleman);
            rank = "PRIVATE";
            position[] = {0,-5,0};
          };
          class Unit2 {
            side = 0;
            vehicle = QGVAR(Signaller);
            rank = "PRIVATE";
            position[] = {0,-10,0};
          };
          class Unit3 {
            side = 0;
            vehicle = QGVAR(Signaller);
            rank = "PRIVATE";
            position[] = {0,-15,0};
          };
        };
        class GVAR(2_Man_Team) {
          name = "2 Man Team";
          faction = QUOTE(ADDON);
          side = 0;
          class Unit0 {
            side = 0;
            vehicle = QGVAR(Rifleman);
            rank = "PRIVATE";
            position[] = {0,-0,0};
          };
          class Unit1 {
            side = 0;
            vehicle = QGVAR(Squad_Leader);
            rank = "PRIVATE";
            position[] = {0,-5,0};
          };
        };
        class GVAR(Fireteam) {
          name = "Fireteam";
          faction = QUOTE(ADDON);
          side = 0;
          class Unit0 {
            side = 0;
            vehicle = QGVAR(Squad_Leader);
            rank = "PRIVATE";
            position[] = {0,-0,0};
          };
          class Unit1 {
            side = 0;
            vehicle = QGVAR(Rifleman);
            rank = "PRIVATE";
            position[] = {0,-5,0};
          };
          class Unit2 {
            side = 0;
            vehicle = QGVAR(Rifleman_LAT);
            rank = "PRIVATE";
            position[] = {0,-10,0};
          };
          class Unit3 {
            side = 0;
            vehicle = QGVAR(Machine_Gunner);
            rank = "PRIVATE";
            position[] = {0,-15,0};
          };
        };
        class GVAR(Section) {
          name = "Section";
          faction = QUOTE(ADDON);
          side = 0;
          class Unit0 {
            side = 0;
            vehicle = QGVAR(Squad_Leader);
            rank = "PRIVATE";
            position[] = {0,-0,0};
          };
          class Unit1 {
            side = 0;
            vehicle = QGVAR(Rifleman);
            rank = "PRIVATE";
            position[] = {0,-5,0};
          };
          class Unit2 {
            side = 0;
            vehicle = QGVAR(Machine_Gunner);
            rank = "PRIVATE";
            position[] = {0,-10,0};
          };
          class Unit3 {
            side = 0;
            vehicle = QGVAR(Rifleman);
            rank = "PRIVATE";
            position[] = {0,-15,0};
          };
          class Unit4 {
            side = 0;
            vehicle = QGVAR(Rifleman_LAT);
            rank = "PRIVATE";
            position[] = {0,-20,0};
          };
          class Unit5 {
            side = 0;
            vehicle = QGVAR(Rifleman);
            rank = "PRIVATE";
            position[] = {0,-25,0};
          };
          class Unit6 {
            side = 0;
            vehicle = QGVAR(Sharpshooter);
            rank = "PRIVATE";
            position[] = {0,-30,0};
          };
          class Unit7 {
            side = 0;
            vehicle = QGVAR(Rifleman);
            rank = "PRIVATE";
            position[] = {0,-35,0};
          };
        };
        class GVAR(AT_Section) {
          name = "AT Section";
          faction = QUOTE(ADDON);
          side = 0;
          class Unit0 {
            side = 0;
            vehicle = QGVAR(Squad_Leader);
            rank = "PRIVATE";
            position[] = {0,-0,0};
          };
          class Unit1 {
            side = 0;
            vehicle = QGVAR(Rifleman_HAT);
            rank = "PRIVATE";
            position[] = {0,-5,0};
          };
          class Unit2 {
            side = 0;
            vehicle = QGVAR(Rifleman_HAT);
            rank = "PRIVATE";
            position[] = {0,-10,0};
          };
          class Unit3 {
            side = 0;
            vehicle = QGVAR(Rifleman_LAT);
            rank = "PRIVATE";
            position[] = {0,-15,0};
          };
          class Unit4 {
            side = 0;
            vehicle = QGVAR(Rifleman_LAT);
            rank = "PRIVATE";
            position[] = {0,-20,0};
          };
          class Unit5 {
            side = 0;
            vehicle = QGVAR(Sharpshooter);
            rank = "PRIVATE";
            position[] = {0,-25,0};
          };
          class Unit6 {
            side = 0;
            vehicle = QGVAR(Machine_Gunner);
            rank = "PRIVATE";
            position[] = {0,-30,0};
          };
        };
        class GVAR(MG_Section) {
          name = "MG Section";
          faction = QUOTE(ADDON);
          side = 0;
          class Unit0 {
            side = 0;
            vehicle = QGVAR(Squad_Leader);
            rank = "PRIVATE";
            position[] = {0,-0,0};
          };
          class Unit1 {
            side = 0;
            vehicle = QGVAR(Machine_Gunner);
            rank = "PRIVATE";
            position[] = {0,-5,0};
          };
          class Unit2 {
            side = 0;
            vehicle = QGVAR(Machine_Gunner);
            rank = "PRIVATE";
            position[] = {0,-10,0};
          };
          class Unit3 {
            side = 0;
            vehicle = QGVAR(Machine_Gunner);
            rank = "PRIVATE";
            position[] = {0,-15,0};
          };
          class Unit4 {
            side = 0;
            vehicle = QGVAR(Autorifleman);
            rank = "PRIVATE";
            position[] = {0,-20,0};
          };
          class Unit5 {
            side = 0;
            vehicle = QGVAR(Sharpshooter);
            rank = "PRIVATE";
            position[] = {0,-25,0};
          };
          class Unit6 {
            side = 0;
            vehicle = QGVAR(Rifleman_LAT);
            rank = "PRIVATE";
            position[] = {0,-30,0};
          };
        };
      };
      class Motorized {
        name = "Motorized";
      };
      class Mechanized {
        name = "Mechanized";
      };
      class Armored {
        name = "Armored";
      };
      class SpecOps {
        name = "Special Forces";
      };
      class Support {
        name = "Support Infantry";
      };
      class Airborne {
        name = "Airborne";
      };
      class Air {
        name = "Air";
      };
    };
  };
};
