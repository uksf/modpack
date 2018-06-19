params ["_dist"];

private _force = 1.65 - (_dist / 300);
private _length = 1.8 - (_dist / 260);
private _frequency = 40 - (_dist / 80);

[_force, _length, _frequency]
