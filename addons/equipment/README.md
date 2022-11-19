# Equipment

Contains equipment definitions

## Equipment Randomization

Equipment randomization supports uniforms and vests.
To add equipment randomization to a unit, add an array containing the classes to choose from with a weighting value for each:

```sqf
class CfgVehicles {
    class CUP_B_BAF_Soldier_MTP;
    class UKSF_B_Rifleman: CUP_B_BAF_Soldier_MTP {
        uksf_equipment_randomUniforms[] = {
            "VSM_Multicam_Crye_Camo", 0.5,
            "VSM_Multicam_Crye_SS_Camo", 0.3,
            "Black_Black_Camo", 0.2
        };
        uksf_equipment_randomVests[] = {
            "V_Chestrig_rgr", 0.5,
            "V_TacVest_camo", 0.3,
            "V_TacChestrig_grn_F", 0.2
        };
    };
};
```

To skip randomization for a unit, either:

- Set a property in config: `uksf_equipment_skipRandomization = 1;`
- Set the attribute in 3DEN: `UKSF > Skip Randomization`
- Set via script: `_unit setVariable ["uksf_equipment_skipRandomization", true, true];`
