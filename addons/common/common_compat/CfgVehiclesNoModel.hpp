// Base classes with no usable model crash the engine when created (access violation), even at scope 1.
// scope 0 makes createVehicle refuse them; their placeable children set their own scope.
class Helicopter_Base_H;
class CUP_MH47E_base : Helicopter_Base_H {
    scope = 0;
};
class Pastor;
class Pastor_ACR : Pastor {
    scope = 0;
};
class DismantledWeapon_HeliHeavyMinigun_01_G_left : Items_base_F {
    scope = 0;
};
class DismantledWeapon_HeliHeavyMinigun_01_G_right : Items_base_F {
    scope = 0;
};
