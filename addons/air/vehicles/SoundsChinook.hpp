class Sounds {
    class EngineExt {
        sound[] = { QPATHTOF(data\sounds\chinook\Engine_Close), 2, 1, 300 };
        frequency = "rotorSpeed";
        volume = "3 * camPos * (0 max (rotorSpeed-0.4))";
    };
    class RotorExt {
        sound[] = { QPATHTOF(data\sounds\chinook\Rotor_Close), 2, 1, 2000 };
        frequency = "(rotorSpeed factor [0.3, 0.7]) * (rotorSpeed factor [0.3, 1]) * (1 - rotorThrust/4)";
        volume = "camPos *3* (rotorSpeed factor [0.3, 1]) * (1 + rotorThrust)";
    };
    class RotorSwist {
        sound[] = { QPATHTOF(data\sounds\chinook\Tail_Rotor), 2, 1, 1000 };
        frequency = 1;
        volume = "camPos * (rotorThrust factor [0.7, 0.9])";
    };
    class RotorInt {
        sound[] = { QPATHTOF(data\sounds\chinook\Int_Rotor), 1, 1 };
        frequency = "(rotorSpeed factor [0.3, 0.7]) * (rotorSpeed factor [0.3, 1]) * (1 - rotorThrust/4)";
        volume = "(1 - camPos) * (rotorSpeed factor [0.3, 0.7]) * (1 + rotorThrust) * 0.7";
    };
    class EngineInt {
        sound[] = { QPATHTOF(data\sounds\chinook\Int_Main), 1.5, 1, 200 };
        frequency = "rotorSpeed";
        volume = "1*(1-camPos)*(0 max (rotorSpeed-0.4))";
    };
    class RotorBench {
        sound[] = { QPATHTOF(data\sounds\chinook\Rotor_double), 1, 1 };
        frequency = "rotorSpeed";
        volume = "(playerPos factor [3.9, 4]) * (1 - camPos) * (rotorSpeed factor [0.3, 1]) * (1 + rotorThrust) * 0.4";
        cone[] = { 1.6,3.1400001,1.6,0.94999999 };
    };
    class RotorNoiseExt {
        sound[] = { QPATHTOF(data\sounds\chinook\Rotor_double), 1, 1, 600 };
        frequency = 1;
        volume = "(camPos*(rotorSpeed factor [0.6, 0.85]))";
        cone[] = { 1.6,3.1400001,2,0.94999999 };
    };
    class Distance {
        sound[] = { QPATHTOF(data\sounds\chinook\Engine_Far), 2, 1, 2000 };
        frequency = "rotorSpeed";
        volume = "2 * camPos * (0 max (rotorSpeed-0.4))";
    };
    class FarDistance {
        sound[] = { QPATHTOF(data\sounds\chinook\Rotor_Far), 2, 1, 3500 };
        frequency = "(rotorSpeed factor [0.3, 0.7]) * (rotorSpeed factor [0.3, 1]) * (1 - rotorThrust/4)";
        volume = "1 * camPos * (0 max (rotorSpeed-0.4))";
    };
    class WindBench {
        sound[] = { QPATHTOF(data\sounds\chinook\wind_close_in), 0.5, 1 };
        frequency = 1;
        volume = "4 * (playerPos factor [3.9, 4]) * (1 - camPos) * ((speed factor[0, 30]) + (speed factor[0, -30]))";
    };
    class RainExt {
        sound[] = { QPATHTOF(data\sounds\chinook\rain1_ext), 1, 1, 100 };
        frequency = 1;
        volume = "camPos * (rain - rotorSpeed/2) * 2";
    };
    class RainInt {
        sound[] = { QPATHTOF(data\sounds\chinook\rain1_int_open), 0.5, 1 };
        frequency = 1;
        volume = "(1-camPos)*(rain - rotorSpeed/2)*2";
    };
    class WindInt {
        sound[] = { QPATHTOF(data\sounds\chinook\wind_close_in), 0.5, 1 };
        frequency = 1;
        volume = "(1-camPos)*(speed factor[5, 50])*(speed factor[5, 50])";
    };
    class WindLateralMovementInt {
        sound[] = { QPATHTOF(data\sounds\chinook\wind_close_in), 0.5, 1, 50 };
        frequency = 1;
        volume = "(1-camPos)*lateralMovement*((speed factor [5,40]) + (speed factor [-5,-40]))";
    };
};