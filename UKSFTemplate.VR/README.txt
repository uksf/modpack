This is the template you should use for your missions.
To copy this to another map, copy the entire folder, and rename it to your desired mission name.
More importantly, the map extension needs to be changed to the map you want your mission on.
To find the extension of a map, open the editor and create a new mission on that map. Save it, and copy the map extension from that temporary save to your actual mission folder.
    E.g "UKSFTemplate.VR" -> "UKSFTemplate.Altis" would change the map from VR to altis

mission
    There are several parts that can be edited and several that shouldn't.
    In the 'Attributes' menu, nothing should be touched.

    Pre-placed entities:
        - All modules and virtual entities required. (Don't change any settings or variable names on these)
        - All units
        - Gear boxes
        - Resupply boxes (plus markers)
        - Aircraft based on current requirement (These are NOT ideally laid out) (Note: helipads have markers which need to be moved with the helipad & heli)
        - Vehicles
        - Respawn module

        By default, all of the pre-placed entities will appear in the [0,0] coordinate of the map (bottom left)
        The modules, virtual entities, and units should be left where they are.
        Headless clients should not be touched.
        The respawn module must be moved, else the default spawn will be in the sea/middle of nowhere.
        Everything else (boxes, aircraft, etc) should be moved to where they are needed, or deleted. Select everything in map view to ensure markers are selected aswell.

description.ext
    Some things in here can be changed and are clearly labelled.

    The mission name is set in here. This is what is displayed when the missions loads.
    THe persistence key is required if this mission should persist across server launches. For a series of missions that require persistence, this key must remain the same.

uksf.paa
    Should not be changed

cba_settings.sqf
    If this mission is considered a side op, change 'uksf_common_mainOp' to false.
    'uksf_persistence_overrideSavedDateTime' can be used for missions that will load a persistence save where you want the new mission to override the saved date and time.
    'uksf_caching_enabled' can be set to true if ai caching is to be used. This disables the simulation on ai that are not within player proximity or field of view.
