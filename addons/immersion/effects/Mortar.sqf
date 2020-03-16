params ["_dist"];

private _force = 5 - (_dist / 340);
private _length = 2.3 - (_dist / 240);
private _frequency = 24 - (_dist / 80);

[_force, _length, _frequency]
