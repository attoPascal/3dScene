#define AMBIENT 0
#define DIFFUSE 1
#define SPECULAR 2
#define SHININESS 3

const GLfloat SPOTLIGHT_AMBIENT_R = 1.0;
const GLfloat SPOTLIGHT_AMBIENT_G = 1.0;
const GLfloat SPOTLIGHT_AMBIENT_B = 1.0;
const GLfloat SPOTLIGHT_DIFFUSE_R = 1.0;
const GLfloat SPOTLIGHT_DIFFUSE_G = 1.0;
const GLfloat SPOTLIGHT_DIFFUSE_B = 1.0;
const GLfloat SPOTLIGHT_SPECULAR_R = 1.0;
const GLfloat SPOTLIGHT_SPECULAR_G = 1.0;
const GLfloat SPOTLIGHT_SPECULAR_B = 1.0;

const GLfloat LIGHTBULB_AMBIENT_R = 0.8;
const GLfloat LIGHTBULB_AMBIENT_G = 0.7;
const GLfloat LIGHTBULB_AMBIENT_B = 0.7;
const GLfloat LIGHTBULB_DIFFUSE_R = 0.8;
const GLfloat LIGHTBULB_DIFFUSE_G = 0.7;
const GLfloat LIGHTBULB_DIFFUSE_B = 0.7;
const GLfloat LIGHTBULB_SPECULAR_R = 0.8;
const GLfloat LIGHTBULB_SPECULAR_G = 0.7;
const GLfloat LIGHTBULB_SPECULAR_B = 0.7;

GLfloat globalAmbientIntensity[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat zeroIntensity[] = { 0.0, 0.0, 0.0, 1.0 };

GLfloat spotlightPosition[] = { 0.0, 30.0, 15.0, 1.0 };
GLfloat spotlightDirection[] = { 0.0, -1.0, -0.4, 1.0 };
GLfloat spotlightIntensity[][4] = {
    { SPOTLIGHT_AMBIENT_R, SPOTLIGHT_AMBIENT_G, SPOTLIGHT_AMBIENT_B, 1.0 },
    { SPOTLIGHT_DIFFUSE_R, SPOTLIGHT_DIFFUSE_G, SPOTLIGHT_DIFFUSE_B, 1.0 },
    { SPOTLIGHT_SPECULAR_R, SPOTLIGHT_SPECULAR_G, SPOTLIGHT_SPECULAR_B, 1.0 }
};

GLfloat lightbulbPosition[] = { 0.0, 10.0, -2.0, 0.0 };
GLfloat lightbulbIntensity[][4] = {
    { LIGHTBULB_AMBIENT_R, LIGHTBULB_AMBIENT_G, LIGHTBULB_AMBIENT_B, 1.0 },
    { LIGHTBULB_DIFFUSE_R, LIGHTBULB_DIFFUSE_G, LIGHTBULB_DIFFUSE_B, 1.0 },
    { LIGHTBULB_SPECULAR_R, LIGHTBULB_SPECULAR_G, LIGHTBULB_SPECULAR_B, 1.0 }
};

const int SPOT_CUTOFF_MIN = 0;
const int SPOT_CUTOFF_MAX = 90;
const int SPOT_CUTOFF_STEP = 10;
const int SPOT_EXPONENT_MIN = 0;
const int SPOT_EXPONENT_MAX = 50;
const int SPOT_EXPONENT_STEP = 5;

void initLighting() {
    glEnable(GL_LIGHTING);
    
    if (enableGlobalAmbientLighting) {
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientIntensity);
    } else {
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, zeroIntensity);
    }
}

void setSpotlight() {
    if (enableSpotlight) {
        glEnable(GL_LIGHT0);
        glLightfv(GL_LIGHT0, GL_POSITION, spotlightPosition);
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotlightDirection);
        glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, spotCutoff);
        glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, spotExponent);
    } else {
        glDisable(GL_LIGHT0);
    }
    
    if (enableAmbientLighting) {
        glLightfv(GL_LIGHT0, GL_AMBIENT, spotlightIntensity[AMBIENT]);
    } else {
        glLightfv(GL_LIGHT0, GL_AMBIENT, zeroIntensity);
    }
    
    if (enableDiffuseLighting) {
        glLightfv(GL_LIGHT0, GL_DIFFUSE, spotlightIntensity[DIFFUSE]);
    } else {
        glLightfv(GL_LIGHT0, GL_DIFFUSE, zeroIntensity);
    }
    
    if (enableSpecularLighting) {
        glLightfv(GL_LIGHT0, GL_SPECULAR, spotlightIntensity[SPECULAR]);
    } else {
        glLightfv(GL_LIGHT0, GL_SPECULAR, zeroIntensity);
    }
    
    if (showSpotlightPosition) {
        glPushMatrix();
        setMaterial(yellowPlastic());
        glTranslatef(spotlightPosition[0], spotlightPosition[1], spotlightPosition[2]);
        glutSolidSphere(1.0, 10, 10);
        glPopMatrix();
    }
}

void setLightbulb() {
    if (enableLightbulb) {
        glEnable(GL_LIGHT1);
        glLightfv(GL_LIGHT1, GL_POSITION, lightbulbPosition);
    } else {
        glDisable(GL_LIGHT1);
    }
    
    if (enableAmbientLighting) {
        glLightfv(GL_LIGHT1, GL_AMBIENT, lightbulbIntensity[AMBIENT]);
    } else {
        glLightfv(GL_LIGHT1, GL_AMBIENT, zeroIntensity);
    }
    
    if (enableDiffuseLighting) {
        glLightfv(GL_LIGHT1, GL_DIFFUSE, lightbulbIntensity[DIFFUSE]);
    } else {
        glLightfv(GL_LIGHT1, GL_DIFFUSE, zeroIntensity);
    }
    
    if (enableSpecularLighting) {
        glLightfv(GL_LIGHT1, GL_SPECULAR, lightbulbIntensity[SPECULAR]);
    } else {
        glLightfv(GL_LIGHT1, GL_SPECULAR, zeroIntensity);
    }
    
    if (showLightbulbPosition) {
        glPushMatrix();
        setMaterial(yellowPlastic());
        glTranslatef(lightbulbPosition[0], lightbulbPosition[1], lightbulbPosition[2]);
        glutSolidSphere(1.0, 10, 10);
        glPopMatrix();
    }
}

void increaseSpotExponent() {
    if (spotExponent + SPOT_EXPONENT_STEP <= SPOT_EXPONENT_MAX) {
        spotExponent += SPOT_EXPONENT_STEP;
    } else {
        spotExponent = SPOT_EXPONENT_MAX;
    }
}

void decreaseSpotExponent() {
    if (spotExponent - SPOT_EXPONENT_STEP >= SPOT_EXPONENT_MIN) {
        spotExponent -= SPOT_EXPONENT_STEP;
    } else {
        spotExponent = SPOT_EXPONENT_MIN;
    }
}

void increaseSpotCutoff() {
    if (spotCutoff + SPOT_CUTOFF_STEP <= SPOT_CUTOFF_MAX) {
        spotCutoff += SPOT_CUTOFF_STEP;
    } else {
        spotCutoff = SPOT_CUTOFF_MAX;
    }
}

void decreaseSpotCutoff() {
    if (spotCutoff - SPOT_CUTOFF_STEP >= SPOT_CUTOFF_MIN) {
        spotCutoff -= SPOT_CUTOFF_STEP;
    } else {
        spotCutoff = SPOT_CUTOFF_MIN;
    }
}