params ["_dist"];

private _force = 3.5 - (_dist / 400);
private _length = 2.5 - (_dist / 480);
private _frequency = 40	- (_dist / 50);

[_force, _length, _frequency]
