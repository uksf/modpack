params ["_dist"];

private _force = 2.6 - (_dist / 210);
private _length = 2.3 - (_dist / 290);
private _frequency = 40 - (_dist / 80);

[_force, _length, _frequency]
