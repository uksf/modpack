params ["_dist"];

private _force = 2.4 - (_dist / 205);
private _length = 2.0 - (_dist / 290);
private _frequency = 35 - (_dist / 80);

[_force, _length, _frequency]
