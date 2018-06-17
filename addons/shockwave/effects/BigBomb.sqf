params ["_dist"];

// private _dist = 1750;
// private _force = linearConversion [1, 750, 2 ^ (10 - (_dist / 600)), 0, 10, true]; 
// private _length = 2.75 - (_dist / 750); 
// private _frequency = 40 - (_dist / 50);  

// addCamShake [_force, _length, _frequency];
// [_force, _length, _frequency]

private _force = 7 - (_dist / 400);
private _length = 2.5 - (_dist / 750);
private _frequency = 40 - (_dist / 50);

[_force, _length, _frequency]
