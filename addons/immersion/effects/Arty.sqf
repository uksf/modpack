params ["_dist"];

private _force = 8 - (_dist / 330);
private _length = 2.2 - (_dist / 400);
private _frequency = 40 - (_dist / 50);

[_force, _length, _frequency]
