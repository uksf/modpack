params ["_dist"];

private _force = 10 - (_dist / 250);
private _length = 2.5 - (_dist / 300);
private _frequency = 30 - (_dist / 60);

[_force, _length, _frequency]
