params ["_dist"];

private _force = 1.5 - (_dist / 150);
private _length = 1.3 - (_dist / 240);
private _frequency = 40	- (_dist / 80);

[_force, _length, _frequency]
