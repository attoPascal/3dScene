const float TEAPOT_INCREMENT = 5.0;
const float LIGHT_INCREMENT = 0.0125;
const float SPOTLIGHT_DIRECTION_MAX = 0.6;
const float SPOTLIGHT_DIRECTION_INCREMENT = 0.05;

bool spotlightDirectionIncrease = true;

void prepareAnimation() {
    spotlightIntensity[AMBIENT][0] = 0.0;
    spotlightIntensity[AMBIENT][1] = 0.0;
    spotlightIntensity[AMBIENT][2] = 0.0;
    spotlightIntensity[DIFFUSE][0] = 0.0;
    spotlightIntensity[DIFFUSE][1] = 0.0;
    spotlightIntensity[DIFFUSE][2] = 0.0;
    spotlightIntensity[SPECULAR][0] = 0.0;
    spotlightIntensity[SPECULAR][1] = 0.0;
    spotlightIntensity[SPECULAR][2] = 0.0;
    
    lightbulbIntensity[AMBIENT][0] = 0.0;
    lightbulbIntensity[AMBIENT][1] = 0.0;
    lightbulbIntensity[AMBIENT][2] = 0.0;
    lightbulbIntensity[DIFFUSE][0] = 0.0;
    lightbulbIntensity[DIFFUSE][1] = 0.0;
    lightbulbIntensity[DIFFUSE][2] = 0.0;
    lightbulbIntensity[SPECULAR][0] = 0.0;
    lightbulbIntensity[SPECULAR][1] = 0.0;
    lightbulbIntensity[SPECULAR][2] = 0.0;
}

void doAnimation() {
    // rotate teapot
    teapotRotation += TEAPOT_INCREMENT;
    
    // increase spotlight intensity
    if (spotlightIntensity[AMBIENT][0] <= SPOTLIGHT_AMBIENT_R) spotlightIntensity[AMBIENT][0] += LIGHT_INCREMENT;
    if (spotlightIntensity[AMBIENT][1] <= SPOTLIGHT_AMBIENT_G) spotlightIntensity[AMBIENT][1] += LIGHT_INCREMENT;
    if (spotlightIntensity[AMBIENT][2] <= SPOTLIGHT_AMBIENT_B) spotlightIntensity[AMBIENT][2] += LIGHT_INCREMENT;
    if (spotlightIntensity[DIFFUSE][0] <= SPOTLIGHT_DIFFUSE_R) spotlightIntensity[DIFFUSE][0] += LIGHT_INCREMENT;
    if (spotlightIntensity[DIFFUSE][1] <= SPOTLIGHT_DIFFUSE_G) spotlightIntensity[DIFFUSE][1] += LIGHT_INCREMENT;
    if (spotlightIntensity[DIFFUSE][2] <= SPOTLIGHT_DIFFUSE_B) spotlightIntensity[DIFFUSE][2] += LIGHT_INCREMENT;
    if (spotlightIntensity[SPECULAR][0] <= SPOTLIGHT_SPECULAR_R) spotlightIntensity[SPECULAR][0] += LIGHT_INCREMENT;
    if (spotlightIntensity[SPECULAR][1] <= SPOTLIGHT_SPECULAR_G) spotlightIntensity[SPECULAR][1] += LIGHT_INCREMENT;
    if (spotlightIntensity[SPECULAR][2] <= SPOTLIGHT_SPECULAR_B) spotlightIntensity[SPECULAR][2] += LIGHT_INCREMENT;
    
    // increase lightbulb intensity
    if (lightbulbIntensity[AMBIENT][0] <= LIGHTBULB_AMBIENT_R) lightbulbIntensity[AMBIENT][0] += LIGHT_INCREMENT;
    if (lightbulbIntensity[AMBIENT][1] <= LIGHTBULB_AMBIENT_G) lightbulbIntensity[AMBIENT][1] += LIGHT_INCREMENT;
    if (lightbulbIntensity[AMBIENT][2] <= LIGHTBULB_AMBIENT_B) lightbulbIntensity[AMBIENT][2] += LIGHT_INCREMENT;
    if (lightbulbIntensity[DIFFUSE][0] <= LIGHTBULB_DIFFUSE_R) lightbulbIntensity[DIFFUSE][0] += LIGHT_INCREMENT;
    if (lightbulbIntensity[DIFFUSE][1] <= LIGHTBULB_DIFFUSE_G) lightbulbIntensity[DIFFUSE][1] += LIGHT_INCREMENT;
    if (lightbulbIntensity[DIFFUSE][2] <= LIGHTBULB_DIFFUSE_B) lightbulbIntensity[DIFFUSE][2] += LIGHT_INCREMENT;
    if (lightbulbIntensity[SPECULAR][0] <= LIGHTBULB_SPECULAR_R) lightbulbIntensity[SPECULAR][0] += LIGHT_INCREMENT;
    if (lightbulbIntensity[SPECULAR][1] <= LIGHTBULB_SPECULAR_G) lightbulbIntensity[SPECULAR][1] += LIGHT_INCREMENT;
    if (lightbulbIntensity[SPECULAR][2] <= LIGHTBULB_SPECULAR_B) lightbulbIntensity[SPECULAR][2] += LIGHT_INCREMENT;
    
    // swing spotlight
    if (spotlightDirectionIncrease) {
        if (spotlightDirection[0] < SPOTLIGHT_DIRECTION_MAX) {
            spotlightDirection[0] += SPOTLIGHT_DIRECTION_INCREMENT;
        } else {
            spotlightDirectionIncrease = false;
        }
    } else {
        if (spotlightDirection[0] > -SPOTLIGHT_DIRECTION_MAX) {
            spotlightDirection[0] -= SPOTLIGHT_DIRECTION_INCREMENT;
        } else {
            spotlightDirectionIncrease = true;
        }
    }

}

void resetAnimation() {
    teapotRotation = 0.0;
    spotlightDirection[0] = 0.0;
    
    spotlightIntensity[AMBIENT][0] = SPOTLIGHT_AMBIENT_R;
    spotlightIntensity[AMBIENT][1] = SPOTLIGHT_AMBIENT_G;
    spotlightIntensity[AMBIENT][2] = SPOTLIGHT_AMBIENT_B;
    spotlightIntensity[DIFFUSE][0] = SPOTLIGHT_DIFFUSE_R;
    spotlightIntensity[DIFFUSE][1] = SPOTLIGHT_DIFFUSE_G;
    spotlightIntensity[DIFFUSE][2] = SPOTLIGHT_DIFFUSE_B;
    spotlightIntensity[SPECULAR][0] = SPOTLIGHT_SPECULAR_R;
    spotlightIntensity[SPECULAR][1] = SPOTLIGHT_SPECULAR_G;
    spotlightIntensity[SPECULAR][2] = SPOTLIGHT_SPECULAR_B;
    
    lightbulbIntensity[AMBIENT][0] = LIGHTBULB_AMBIENT_R;
    lightbulbIntensity[AMBIENT][1] = LIGHTBULB_AMBIENT_G;
    lightbulbIntensity[AMBIENT][2] = LIGHTBULB_AMBIENT_B;
    lightbulbIntensity[DIFFUSE][0] = LIGHTBULB_DIFFUSE_R;
    lightbulbIntensity[DIFFUSE][1] = LIGHTBULB_DIFFUSE_G;
    lightbulbIntensity[DIFFUSE][2] = LIGHTBULB_DIFFUSE_B;
    lightbulbIntensity[SPECULAR][0] = LIGHTBULB_SPECULAR_R;
    lightbulbIntensity[SPECULAR][1] = LIGHTBULB_SPECULAR_G;
    lightbulbIntensity[SPECULAR][2] = LIGHTBULB_SPECULAR_B;
}