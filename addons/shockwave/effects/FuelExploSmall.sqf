params ["_dist"];

private _force = 1.3 - (_dist / 300);
private _length = 2.2 - (_dist / 250);
private _frequency = 40	- (_dist / 80);

[_force, _length, _frequency]
