typedef struct Material {
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat shininess;
} Material;

void setMaterial(Material material) {
    glMaterialfv(GL_FRONT, GL_AMBIENT, material.ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material.diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material.specular);
    glMaterialf(GL_FRONT, GL_SHININESS, material.shininess * 128.0f);
}

Material emerald() {
    Material material;
    material.ambient[0] = 0.0215;
    material.ambient[1] = 0.1745;
    material.ambient[2] = 0.0215;
    material.ambient[3] = 1.0;
    material.diffuse[0] = 0.07568;
    material.diffuse[1] = 0.61424;
    material.diffuse[2] = 0.07568;
    material.diffuse[3] = 1.0;
    material.specular[0] = 0.633;
    material.specular[1] = 0.727811;
    material.specular[2] = 0.633;
    material.specular[3] = 1.0;
    material.shininess = 0.6;
    return material;
}

Material chrome() {
    Material material;
    material.ambient[0] = 0.25;
    material.ambient[1] = 0.25;
    material.ambient[2] = 0.25;
    material.ambient[3] = 1.0;
    material.diffuse[0] = 0.4;
    material.diffuse[1] = 0.4;
    material.diffuse[2] = 0.4;
    material.diffuse[3] = 1.0;
    material.specular[0] = 0.774597;
    material.specular[1] = 0.774597;
    material.specular[2] = 0.774597;
    material.specular[3] = 1.0;
    material.shininess = 0.6;
    return material;
}

Material gold() {
    Material material;
    material.ambient[0] = 0.24725;
    material.ambient[1] = 0.1995;
    material.ambient[2] = 0.0745;
    material.ambient[3] = 1.0;
    material.diffuse[0] = 0.75164;
    material.diffuse[1] = 0.60648;
    material.diffuse[2] = 0.22648;
    material.diffuse[3] = 1.0;
    material.specular[0] = 0.628281;
    material.specular[1] = 0.555802;
    material.specular[2] = 0.366065;
    material.specular[3] = 1.0;
    material.shininess = 0.4;
    return material;
}

Material whitePlastic() {
    Material material;
    material.ambient[0] = 0.0;
    material.ambient[1] = 0.0;
    material.ambient[2] = 0.0;
    material.ambient[3] = 1.0;
    material.diffuse[0] = 0.55;
    material.diffuse[1] = 0.55;
    material.diffuse[2] = 0.55;
    material.diffuse[3] = 1.0;
    material.specular[0] = 0.7;
    material.specular[1] = 0.7;
    material.specular[2] = 0.7;
    material.specular[3] = 1.0;
    material.shininess = 0.25;
    return material;
}

Material blackPlastic() {
    Material material;
    material.ambient[0] = 0.0;
    material.ambient[1] = 0.0;
    material.ambient[2] = 0.0;
    material.ambient[3] = 1.0;
    material.diffuse[0] = 0.1;
    material.diffuse[1] = 0.1;
    material.diffuse[2] = 0.1;
    material.diffuse[3] = 1.0;
    material.specular[0] = 0.5;
    material.specular[1] = 0.5;
    material.specular[2] = 0.5;
    material.specular[3] = 1.0;
    material.shininess = 0.25;
    return material;
}

Material redPlastic() {
    Material material;
    material.ambient[0] = 0.0;
    material.ambient[1] = 0.0;
    material.ambient[2] = 0.0;
    material.ambient[3] = 1.0;
    material.diffuse[0] = 0.5;
    material.diffuse[1] = 0.0;
    material.diffuse[2] = 0.0;
    material.diffuse[3] = 1.0;
    material.specular[0] = 0.7;
    material.specular[1] = 0.6;
    material.specular[2] = 0.6;
    material.specular[3] = 1.0;
    material.shininess = 0.25;
    return material;
}

Material yellowPlastic() {
    Material material;
    material.ambient[0] = 0.0;
    material.ambient[1] = 0.0;
    material.ambient[2] = 0.0;
    material.ambient[3] = 1.0;
    material.diffuse[0] = 0.5;
    material.diffuse[1] = 0.5;
    material.diffuse[2] = 0.5;
    material.diffuse[3] = 1.0;
    material.specular[0] = 0.6;
    material.specular[1] = 0.6;
    material.specular[2] = 0.5;
    material.specular[3] = 1.0;
    material.shininess = 0.25;
    return material;
}

Material whiteRubber() {
    Material material;
    material.ambient[0] = 0.05;
    material.ambient[1] = 0.05;
    material.ambient[2] = 0.05;
    material.ambient[3] = 1.0;
    material.diffuse[0] = 0.5;
    material.diffuse[1] = 0.5;
    material.diffuse[2] = 0.5;
    material.diffuse[3] = 1.0;
    material.specular[0] = 0.7;
    material.specular[1] = 0.7;
    material.specular[2] = 0.7;
    material.specular[3] = 1.0;
    material.shininess = 0.078125;
    return material;
}

Material jade() {
    Material material;
    material.ambient[0] = 0.135;
    material.ambient[1] = 0.2225;
    material.ambient[2] = 0.1575;
    material.ambient[3] = 1.0;
    material.diffuse[0] = 0.54;
    material.diffuse[1] = 0.89;
    material.diffuse[2] = 0.63;
    material.diffuse[3] = 1.0;
    material.specular[0] = 0.316228;
    material.specular[1] = 0.316228;
    material.specular[2] = 0.316228;
    material.specular[3] = 1.0;
    material.shininess = 0.1;
    return material;
}

Material obsidian() {
    Material material;
    material.ambient[0] = 0.05375;
    material.ambient[1] = 0.05;
    material.ambient[2] = 0.06625;
    material.ambient[3] = 1.0;
    material.diffuse[0] = 0.18275;
    material.diffuse[1] = 0.17;
    material.diffuse[2] = 0.22525;
    material.diffuse[3] = 1.0;
    material.specular[0] = 0.332741;
    material.specular[1] = 0.328634;
    material.specular[2] = 0.346435;
    material.specular[3] = 1.0;
    material.shininess = 0.3;
    return material;
}

Material pearl() {
    Material material;
    material.ambient[0] = 0.25;
    material.ambient[1] = 0.20725;
    material.ambient[2] = 0.20725;
    material.ambient[3] = 1.0;
    material.diffuse[0] = 1.0;
    material.diffuse[1] = 0.829;
    material.diffuse[2] = 0.829;
    material.diffuse[3] = 1.0;
    material.specular[0] = 0.296648;
    material.specular[1] = 0.296648;
    material.specular[2] = 0.296648;
    material.specular[3] = 1.0;
    material.shininess = 0.088;
    return material;
}

Material ruby() {
    Material material;
    material.ambient[0] = 0.1745;
    material.ambient[1] = 0.01175;
    material.ambient[2] = 0.01175;
    material.ambient[3] = 1.0;
    material.diffuse[0] = 0.61424;
    material.diffuse[1] = 0.04136;
    material.diffuse[2] = 0.04136;
    material.diffuse[3] = 1.0;
    material.specular[0] = 0.727811;
    material.specular[1] = 0.626959;
    material.specular[2] = 0.626959;
    material.specular[3] = 1.0;
    material.shininess = 0.6;
    return material;
}

Material turquoise() {
    Material material;
    material.ambient[0] = 0.1;
    material.ambient[1] = 0.18725;
    material.ambient[2] = 0.1745;
    material.ambient[3] = 1.0;
    material.diffuse[0] = 0.396;
    material.diffuse[1] = 0.74151;
    material.diffuse[2] = 0.69102;
    material.diffuse[3] = 1.0;
    material.specular[0] = 0.297254;
    material.specular[1] = 0.30829;
    material.specular[2] = 0.306678;
    material.specular[3] = 1.0;
    material.shininess = 0.1;
    return material;
}

Material brass() {
    Material material;
    material.ambient[0] = 0.329412;
    material.ambient[1] = 0.223529;
    material.ambient[2] = 0.027451;
    material.ambient[3] = 1.0;
    material.diffuse[0] = 0.780392;
    material.diffuse[1] = 0.568627;
    material.diffuse[2] = 0.113725;
    material.diffuse[3] = 1.0;
    material.specular[0] = 0.992157;
    material.specular[1] = 0.941176;
    material.specular[2] = 0.807843;
    material.specular[3] = 1.0;
    material.shininess = 0.21794872;
    return material;
}

Material silver() {
    Material material;
    material.ambient[0] = 0.19225;
    material.ambient[1] = 0.19225;
    material.ambient[2] = 0.19225;
    material.ambient[3] = 1.0;
    material.diffuse[0] = 0.50754;
    material.diffuse[1] = 0.50754;
    material.diffuse[2] = 0.50754;
    material.diffuse[3] = 1.0;
    material.specular[0] = 0.508273;
    material.specular[1] = 0.508273;
    material.specular[2] = 0.508273;
    material.specular[3] = 1.0;
    material.shininess = 0.4;
    return material;
}

Material bronze() {
    Material material;
    material.ambient[0] = 0.2125;
    material.ambient[1] = 0.1275;
    material.ambient[2] = 0.054;
    material.ambient[3] = 1.0;
    material.diffuse[0] = 0.714;
    material.diffuse[1] = 0.4284;
    material.diffuse[2] = 0.18144;
    material.diffuse[3] = 1.0;
    material.specular[0] = 0.393548;
    material.specular[1] = 0.271906;
    material.specular[2] = 0.166721;
    material.specular[3] = 1.0;
    material.shininess = 0.2;
    return material;
}

Material copper() {
    Material material;
    material.ambient[0] = 0.19125;
    material.ambient[1] = 0.0735;
    material.ambient[2] = 0.0225;
    material.ambient[3] = 1.0;
    material.diffuse[0] = 0.7038;
    material.diffuse[1] = 0.27048;
    material.diffuse[2] = 0.0828;
    material.diffuse[3] = 1.0;
    material.specular[0] = 0.256777;
    material.specular[1] = 0.137622;
    material.specular[2] = 0.086014;
    material.specular[3] = 1.0;
    material.shininess = 0.1;
    return material;
}


