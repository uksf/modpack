This is the template you should use for your missions.
To copy this to another map, simply copy the entire folder, and rename it to your desired mission name.
More importantly, the map extension needs to be changed to the map you want your mission on.
To find the extension of a map, open the editor and create a new mission on that map. Save it, and copy the map extension from that temporary save to your actual mission folder.
    E.g "UKSFTemplate.VR" -> "UKSFTemplate.Altis" would change the map to altis

mission.sqm
    There are several parts that can be edited and several that shouldn't.
    In the 'Attributes', nothing should be touched.

    Pre-placed entities:
        - All modules and virtual entities required. (Don't change any settings or variable names on these)
        - All units
        - Gear boxes
        - Resupply boxes (plus markers)
        - Aircraft based on current requirement (These are NOT ideally laid out) (Note: helipads have markers which need to be moved with the helipad & heli)
        - Vehicles
        - Respawn marker

        By default, all of the pre-placed entities will appear in the [0,0] coordinate of the map (bottom left)
        The modules, virtual entities, and units should be left where they are.
        Everything else (boxes, aircraft, etc) should be moved to where they are needed, or deleted.
        Select everything in map view to ensure markers are selected aswell.
        Gamemasters and Headless clients should not be touched.
        The respawn marker (like all markers) is only visible in map view, so make sure you move it otherwise the default spawn will be in the sea.

    description.ext
        Some things in here can be changed and are clearly labelled.

        The UKSF settings can be adjusted per the mission.
        The settings for ACE are included and forced. Do not change these settings as they are standardised.
        The only setting that can be changed is the ACE medical level. This is clearly commented. By default, Advanced medical is enabled.
            Advanced: class ace_medical_useLocation_PAK { value = 3; typeName = "SCALAR"; force = 1; };
            Basic: class ace_medical_useLocation_PAK { value = 0; typeName = "SCALAR"; force = 1; };
        To change medical level (Basic or Advanced), simply comment out the uncommented line, and uncomment the commented line. (Clearly indicated)

    spawning.hpp
        Here you define the spawning parameters for the spawn area markers you have placed in the editor (if any)

    functions/*
        Should not be changed

    postInit.sqf
        Should not be changed

    uksf.paa
        Should not be changed
