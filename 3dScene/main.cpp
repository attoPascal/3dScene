#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include "freeglut.h"
#endif

#include "Trackball.h"
#include "camera.h"
#include "fshill.h"

#include "globals.h"
#include "materials.h"
#include "scene.h"
#include "lighting.h"
#include "animation.h"
#include "menu.h"

const GLsizei WINDOW_WIDTH = 400;
const GLsizei WINDOW_HEIGHT = 400;

CTrackball trackball;
Camera camera;

void timer(int iteration) {
    if (animate) {
        if (iteration == 0) {
            prepareAnimation();
        }
        
        doAnimation();
        
        // stop animation after some iterations
        if (iteration > 145) {
            animate = false;
            resetAnimation();
        }
        
        glutPostRedisplay();
        glutTimerFunc(50, timer, iteration + 1);
    } else {
        glutTimerFunc(500, timer, 0);
    }
}

void handleMouseMotion(int x, int y) {
    trackball.tbMotion(x, y);
}

void handleMouseClick(int button, int state, int x, int y) {
    trackball.tbMouse(button, state, x, y);
}

void reshape(int width, int height) {
    // Called at start, and whenever user resizes component
    int size;
    if (width < height) {
        size = width;
    } else {
        size = height;
    }
    
    glViewport(0, 0, size, size);  // Largest possible square
    trackball.tbReshape(width, height);
}

void traverse(SceneNode* root) {
    if (root == NULL) {
        return;
    }
    
    glPushMatrix();
    glMultMatrixf(root->m);
    setMaterial(root->material);
    root->drawNode(root);
    
    if (root->child != NULL) {
        traverse(root->child);
    }
    
    glPopMatrix();
    
    if (root->sibling != NULL) {
        traverse(root->sibling);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(0, 10, 30, 0, 10, 0, 0, 1, 0); // camera is on the z-axis
    trackball.tbMatrix();
    
    //camera.set(0, 10, 30, 0, 10, 0, 0, 1, 0);
    
    setSpotlight();
    setLightbulb();
    traverse(&room);
    
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'd':
            chooseMenuOption(USE_MANY_POLYGONS);
            break;
        case '+':
            chooseMenuOption(INCREASE_SPOT_EXPONENT);
            break;
        case '-':
            chooseMenuOption(DECREASE_SPOT_EXPONENT);
            break;
        case ',':
            chooseMenuOption(INCREASE_SPOT_CUTOFF);
            break;
        case '.':
            chooseMenuOption(DECREASE_SPOT_CUTOFF);
            break;
        case 'w':
            camera.slide(1.0, 10.0, 100.0);
            glutPostRedisplay();
        default:
            break;
    }
}

void init() {
    // select clearing color (for glClear)
    glClearColor(1, 1, 1, 1);	// RGB-value for black
    // enable depth buffering
    glEnable(GL_DEPTH_TEST);
    trackball.tbInit(GLUT_LEFT_BUTTON);
    
    // initialize view (simple orthographic projection)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(120, 1, 1, 200);
    
    glMatrixMode(GL_MODELVIEW);
    
    initMenu();
    initSceneNodes();
    initLighting();
}

// create a double buffered colour window
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Room And Table");
    init();								// initialise view
    glutMouseFunc(handleMouseClick);		// Set function to handle mouse clicks
    glutMotionFunc(handleMouseMotion);		// Set function to handle mouse motion
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);		// Set function to draw scene
    glutReshapeFunc(reshape);		// Set function called if window gets resized
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
