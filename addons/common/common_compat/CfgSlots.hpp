class asdg_SlotInfo;
class asdg_MuzzleSlot;
class asdg_FrontSideRail : asdg_SlotInfo {
    delete asdg_MuzzleSlot_545R;
    delete asdg_MuzzleSlot_762R;
};
class asdg_MuzzleSlot_545R : asdg_MuzzleSlot {
    class compatibleItems {
        muzzle_tma_545R_G = 1;
    };
};
class asdg_MuzzleSlot_762R : asdg_MuzzleSlot {
    class compatibleItems {
        muzzle_tma_762R_G = 1;
    };
};
