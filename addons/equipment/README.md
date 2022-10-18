# Equipment

Contains equipment definitions

## Uniform Randomization

To add uniform randomization to a unit, add an array containing the uniform classes to choose from with a weighting value for each:

```sqf
class CfgVehicles {
    class CUP_B_BAF_Soldier_MTP;
    class UKSF_B_Rifleman: CUP_B_BAF_Soldier_MTP {
        uksf_equipment_randomUniforms[] = {
            "VSM_Multicam_Crye_Camo", 0.5,
            "VSM_Multicam_Crye_SS_Camo", 0.3,
            "Black_Black_Camo", 0.2
        };
    };
};
```

To skip randomization for a unit, either:

- Set a property in config: `uksf_equipment_skipRandomization = 1`;
- Set the attribute in 3DEN: `UKSF > Skip Randomization`
- Via script: `_unit setVariable ["uksf_equipment_skipRandomization", true, true];`
