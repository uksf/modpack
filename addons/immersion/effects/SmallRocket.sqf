params ["_dist"];

private _force = 8 - (_dist / 190);
private _length = 1.9 - (_dist / 300);
private _frequency = 30 - (_dist / 80);

[_force, _length, _frequency]
