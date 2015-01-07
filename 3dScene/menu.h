enum MenuOption {
    USE_MANY_POLYGONS,
    ENABLE_SPOTLIGHT,
    ENABLE_LIGHTBULB,
    SHOW_LIGHT_POSITIONS,
    ONLY_GLOBAL_AMBIENT,
    ONLY_AMBIENT,
    ONLY_DIFFUSE,
    ONLY_SPECULAR,
    ENABLE_ALL_LIGHTING,
    INCREASE_SPOT_CUTOFF,
    DECREASE_SPOT_CUTOFF,
    INCREASE_SPOT_EXPONENT,
    DECREASE_SPOT_EXPONENT,
    FLOOR_MATERIAL_1,
    FLOOR_MATERIAL_2,
    FLOOR_MATERIAL_3,
    FLOOR_MATERIAL_4,
    TABLE_MATERIAL_1,
    TABLE_MATERIAL_2,
    TABLE_MATERIAL_3,
    TABLE_MATERIAL_4,
    TEAPOT_MATERIAL_1,
    TEAPOT_MATERIAL_2,
    TEAPOT_MATERIAL_3,
    TEAPOT_MATERIAL_4,
    LAMP_MATERIAL_1,
    LAMP_MATERIAL_2,
    LAMP_MATERIAL_3,
    LAMP_MATERIAL_4,
    TEAPOT_SHININESS_NONE,
    TEAPOT_SHININESS_HALF,
    TEAPOT_SHININESS_FULL,
    START_ANIMATION
};

void chooseMenuOption(int option) {
    switch (option) {
        case USE_MANY_POLYGONS:
            useManyPolygons = !useManyPolygons;
            break;
        case ENABLE_SPOTLIGHT:
            enableSpotlight = !enableSpotlight;
            break;
        case ENABLE_LIGHTBULB:
            enableLightbulb = !enableLightbulb;
            break;
        case SHOW_LIGHT_POSITIONS:
            showSpotlightPosition = !showSpotlightPosition;
            showLightbulbPosition = !showLightbulbPosition;
            break;
        case ONLY_GLOBAL_AMBIENT:
            enableGlobalAmbientLighting = true;
            enableAmbientLighting = false;
            enableDiffuseLighting = false;
            enableSpecularLighting = false;
            break;
        case ONLY_AMBIENT:
            enableGlobalAmbientLighting = false;
            enableAmbientLighting = true;
            enableDiffuseLighting = false;
            enableSpecularLighting = false;
            break;
        case ONLY_DIFFUSE:
            enableGlobalAmbientLighting = false;
            enableAmbientLighting = false;
            enableDiffuseLighting = true;
            enableSpecularLighting = false;
            break;
        case ONLY_SPECULAR:
            enableGlobalAmbientLighting = false;
            enableAmbientLighting = false;
            enableDiffuseLighting = false;
            enableSpecularLighting = true;
            break;
        case ENABLE_ALL_LIGHTING:
            enableGlobalAmbientLighting = true;
            enableAmbientLighting = true;
            enableDiffuseLighting = true;
            enableSpecularLighting = true;
            break;
        case INCREASE_SPOT_CUTOFF:
            increaseSpotCutoff();
            break;
        case DECREASE_SPOT_CUTOFF:
            decreaseSpotCutoff();
            break;
        case INCREASE_SPOT_EXPONENT:
            increaseSpotExponent();
            break;
        case DECREASE_SPOT_EXPONENT:
            decreaseSpotExponent();
            break;
        case FLOOR_MATERIAL_1:
            room.material = whiteRubber();
            break;
        case FLOOR_MATERIAL_2:
            room.material = obsidian();
            break;
        case FLOOR_MATERIAL_3:
            room.material = pearl();
            break;
        case FLOOR_MATERIAL_4:
            room.material = jade();
            break;
        case TABLE_MATERIAL_1:
            tableTop.material = emerald();
            break;
        case TABLE_MATERIAL_2:
            tableTop.material = ruby();
            break;
        case TABLE_MATERIAL_3:
            tableTop.material = turquoise();
            break;
        case TABLE_MATERIAL_4:
            tableTop.material = redPlastic();
            break;
        case LAMP_MATERIAL_1:
            lampShade.material = gold();
            break;
        case LAMP_MATERIAL_2:
            lampShade.material = brass();
            break;
        case LAMP_MATERIAL_3:
            lampShade.material = copper();
            break;
        case LAMP_MATERIAL_4:
            lampShade.material = silver();
            break;
        case TEAPOT_MATERIAL_1:
            teapot.material = chrome();
            break;
        case TEAPOT_MATERIAL_2:
            teapot.material = bronze();
            break;
        case TEAPOT_MATERIAL_3:
            teapot.material = brass();
            break;
        case TEAPOT_MATERIAL_4:
            teapot.material = pearl();
            break;
        case TEAPOT_SHININESS_NONE:
            teapot.material.shininess = 0;
            break;
        case TEAPOT_SHININESS_HALF:
            teapot.material.shininess = 1;
            break;
        case TEAPOT_SHININESS_FULL:
            teapot.material.shininess = 128;
            break;
        case START_ANIMATION:
            animate = true;
            break;
        default:
            break;
    }
    
    glutPostRedisplay();
}

void initMenu() {
    int lightComponentMenu = glutCreateMenu(chooseMenuOption);
    glutAddMenuEntry("Global ambient only", ONLY_GLOBAL_AMBIENT);
    glutAddMenuEntry("Ambient only", ONLY_AMBIENT);
    glutAddMenuEntry("Diffuse only", ONLY_DIFFUSE);
    glutAddMenuEntry("Specular only", ONLY_SPECULAR);
    glutAddMenuEntry("All", ENABLE_ALL_LIGHTING);
    
    int spotlightMenu = glutCreateMenu(chooseMenuOption);
    glutAddMenuEntry("Toggle spotlight", ENABLE_SPOTLIGHT);
    glutAddMenuEntry("Intensity +", INCREASE_SPOT_EXPONENT);
    glutAddMenuEntry("Intensity -", DECREASE_SPOT_EXPONENT);
    glutAddMenuEntry("Cutoff +", INCREASE_SPOT_CUTOFF);
    glutAddMenuEntry("Cutoff -", DECREASE_SPOT_CUTOFF);
    
    int lightingMenu = glutCreateMenu(chooseMenuOption);
    glutAddMenuEntry("Show light positions", SHOW_LIGHT_POSITIONS);
    glutAddMenuEntry("Toggle lightbulb", ENABLE_LIGHTBULB);
    glutAddSubMenu("Spotlight", spotlightMenu);
    glutAddSubMenu("Choose light components", lightComponentMenu);
    
    int floorMenu = glutCreateMenu(chooseMenuOption);
    glutAddMenuEntry("White rubber", FLOOR_MATERIAL_1);
    glutAddMenuEntry("Obsidian", FLOOR_MATERIAL_2);
    glutAddMenuEntry("Pearl", FLOOR_MATERIAL_3);
    glutAddMenuEntry("Jade", FLOOR_MATERIAL_4);
    
    int tableMenu = glutCreateMenu(chooseMenuOption);
    glutAddMenuEntry("Emerald", TABLE_MATERIAL_1);
    glutAddMenuEntry("Ruby", TABLE_MATERIAL_2);
    glutAddMenuEntry("Turquoise", TABLE_MATERIAL_3);
    glutAddMenuEntry("Red plastic", TABLE_MATERIAL_4);
    
    int lampMenu = glutCreateMenu(chooseMenuOption);
    glutAddMenuEntry("Gold", LAMP_MATERIAL_1);
    glutAddMenuEntry("Brass", LAMP_MATERIAL_2);
    glutAddMenuEntry("Copper", LAMP_MATERIAL_3);
    glutAddMenuEntry("Silver", LAMP_MATERIAL_4);
    
    int teapotMenu = glutCreateMenu(chooseMenuOption);
    glutAddMenuEntry("Chrome", TEAPOT_MATERIAL_1);
    glutAddMenuEntry("Bronze", TEAPOT_MATERIAL_2);
    glutAddMenuEntry("Brass", TEAPOT_MATERIAL_3);
    glutAddMenuEntry("Pearl", TEAPOT_MATERIAL_4);
    glutAddMenuEntry("Shininess 0", TEAPOT_SHININESS_NONE);
    glutAddMenuEntry("Shininess 1", TEAPOT_SHININESS_HALF);
    glutAddMenuEntry("Shininess 128", TEAPOT_SHININESS_FULL);
    
    int materialMenu = glutCreateMenu(chooseMenuOption);
    glutAddSubMenu("Floor", floorMenu);
    glutAddSubMenu("Table", tableMenu);
    glutAddSubMenu("Lamp", lampMenu);
    glutAddSubMenu("Teapot", teapotMenu);
    
    int mainMenu = glutCreateMenu(chooseMenuOption);
    glutAddMenuEntry("Use many polygons", USE_MANY_POLYGONS);
    glutAddMenuEntry("Start animation", START_ANIMATION);
    glutAddSubMenu("Lighting", lightingMenu);
    glutAddSubMenu("Material", materialMenu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

