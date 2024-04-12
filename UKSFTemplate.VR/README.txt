This is the template you should use for your missions.

To copy this to another map, copy the entire folder, and rename it to your desired mission name.
The map extension needs to be changed to the map you want your mission on.
To find the extension of a map, open the editor and create a new mission on that map. Save it, and copy the map extension from that temporary save to your actual mission folder.
    E.g "UKSFTemplate.VR" -> "UKSFTemplate.Altis" would change the map from VR to Altis

mission
    There are several parts that can be edited and several that shouldn't.
    In the main 'Attributes' menu, nothing should be touched.

    Pre-placed entities:
        - All modules and virtual entities required. (Don't change any settings or variable names on these)
        - All units
        - Gear boxes
        - Resupply boxes
        - Aircraft based on current requirement (These are NOT ideally laid out)
        - Vehicles
        - Respawn module

        By default, all of the pre-placed entities will appear in the [0,0] coordinate of the map (bottom left)
        The modules, virtual entities, and units should be left where they are.
        Headless clients should not be touched.
        The respawn module must be moved, else the default spawn will be in the sea/middle of nowhere.
        Everything else (boxes, aircraft, etc) should be moved to where they are needed, or deleted.

description.ext
    Some things in here can be changed and are clearly labelled.

    The mission name is set in here. This is what is displayed when the missions loads.

    THe persistence key is required if this mission should persist across server launches. For a series of missions that require persistence, this key must remain the same.
    Re-deploy is still available within a mission without a persistence key.

uksf.paa
    Should not be changed

cba_settings.sqf
    If this mission is considered a side op, change 'uksf_common_mainOp' to false.
    'uksf_persistence_loadMapMarkers' can be used for missions that are a direct continuation of the previous mission, to ensure map markers are loaded.
    'uksf_persistence_overrideSavedDateTime' can be used for missions that will load a persistence save where you want the new mission to override the date and time saved on the server.
    'uksf_caching_enabled' can be set to true if ai caching is to be used. This disables the simulation on ai that are not within player proximity or field of view.

CfgFunctions.hpp
    This is where you need to define the name of your functions so you can call them in the mission.
    A pre-made operation folder is made with a preInit, postInit and dummy function already setup.
    To add a function, copy "fn_dummy.sqf" in "functions/operation" and rename it to your function name. The "fn_" at the start must be kept in place.
    To register the function, copy the "class dummy {};" line in CfgFunctions.hpp and rename the "dummy" to your function name, excluding the "fn_" and ".sqf"
    To call this function, the pattern is as follows: [<args>] call uksf_operation_fnc_dummy;
    For example:
        Copy "fn_dummy.sqf", paste, rename to "fn_spawnVehicle.sqf"
        Copy "class dummy {};", paste on line below, rename to "class spawnVehicle {};"
        To call: [] call uksf_operation_fnc_spawnVehicle;

    When creating a function file, it is vital the '#include "script_component.hpp"' is the first line, followed by the header.
    Always copy and paste the dummy file to be safe.

    Certain Macros are available to you in functions set up this way. For an explanation of how to use these, please ask Beswick or Bridgford or post in SR6 chat.

functions/script_macros.hpp
    Do not change or delete this file

functions/<folder name>/script_component.hpp
    Do not change or delete this file

For further help with anything please ask Beswick or Bridgford or post in SR6 chat.
