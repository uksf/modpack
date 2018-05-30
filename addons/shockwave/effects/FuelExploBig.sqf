params ["_dist"];

private _force = 2 - (_dist / 280);
private _length = 2	- (_dist / 260);
private _frequency = 40	- (_dist / 80);

[_force, _length, _frequency]
