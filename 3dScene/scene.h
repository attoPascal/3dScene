#include "util.h"

const int TABLE_WIDTH = 10;
const int TABLE_DEPTH = 12;
const int TABLE_HEIGHT = 2;
const int FLOOR_WIDTH = 60;
const int FLOOR_DEPTH = 60;
const int WALL_HEIGHT = 45;

const int TILES = 64;

typedef struct SceneNode {
    GLfloat m[16];
    void(*drawNode)(SceneNode*);
    struct SceneNode *sibling;
    struct SceneNode *child;
    Material material;
} SceneNode;

SceneNode room, wall1, wall2, wall3, tableTop, tableLeg1, tableLeg2, tableLeg3, tableLeg4, lampBase, lampUpright, lampShade, teapot;

void drawFloor(SceneNode* sceneNode) {
    glPushMatrix();
    glScalef(FLOOR_WIDTH, 1, FLOOR_DEPTH);
    glTranslatef(-0.5, 0, -0.5);
    tiledSquare(useManyPolygons ? TILES : 1);
    glPopMatrix();
}

void drawWall(SceneNode* sceneNode) {
    glPushMatrix();
    glScalef(FLOOR_WIDTH, WALL_HEIGHT, 1);
    glNormal3f(0, 0, 1);
    glTranslatef(-0.5, 0, -0.5);
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0);
    glVertex3f(1.0, 0, 0);
    glVertex3f(1.0, 1.0, 0);
    glVertex3f(0, 1.0, 0);
    glEnd();
    glPopMatrix();
}

//table top
void drawTop(SceneNode* sNode) {
    glPushMatrix();
    glScalef(TABLE_WIDTH, TABLE_HEIGHT, TABLE_DEPTH);
    glutSolidCube(1);
    glTranslatef(-0.5, 0.51, -0.5);
    tiledSquare(useManyPolygons ? TILES : 1);
    glPopMatrix();
}

void drawLeg(SceneNode* sNode) {
    glPushMatrix();
    glRotatef(90, 90, 0, 1);
    solidCylinder(0.4, 5.0, 10, 10);
    glPopMatrix();
}

void drawLampBase(SceneNode* sNode) {
    glPushMatrix();
    glRotatef(90, 90, 0, 1);
    solidCylinder(1.5, 0.6, 10, 10);
    glPopMatrix();
}

void drawLampUpright(SceneNode* sNode) {
    glPushMatrix();
    glRotatef(90, 90, 0, 1);
    solidCylinder(0.3, 2.5, 10, 10);
    glPopMatrix();
}

void drawLampShade(SceneNode* sNode) {
    glPushMatrix();
    
    GLUquadricObj *quad = gluNewQuadric();
    gluQuadricNormals(quad, GLU_SMOOTH);
    gluQuadricTexture(quad, GL_TRUE);
    
    glRotatef(-90, 90, 0, 1);
    gluCylinder(quad, 2.5, 1.5, 2.5, 10, 10);
    glPopMatrix();
}

void drawTeapot(SceneNode* sNode) {
    glPushMatrix();
    glRotatef(teapotRotation, 0.0, 1.0, 0.0);
    glutSolidTeapot(2.0);
    glPopMatrix();
}

void initSceneNodes() {
    //floor
    glLoadIdentity();
    glGetFloatv(GL_MODELVIEW_MATRIX, room.m);
    room.drawNode = drawFloor;
    room.sibling = NULL;
    room.child = &wall1;
    room.material = whiteRubber();
    
    //wall 1
    glLoadIdentity();
    glTranslatef(0, 0, -FLOOR_DEPTH / 2);
    glGetFloatv(GL_MODELVIEW_MATRIX, wall1.m);
    wall1.drawNode = drawWall;
    wall1.sibling = &wall2;
    wall1.child = NULL;
    wall1.material = silver();
    
    //wall 2
    glLoadIdentity();
    glTranslatef(-FLOOR_WIDTH / 2, 0, 0);
    glRotatef(90, 0, 1, 0);
    glGetFloatv(GL_MODELVIEW_MATRIX, wall2.m);
    wall2.drawNode = drawWall;
    wall2.sibling = &wall3;
    wall2.child = NULL;
    wall2.material = silver();
    
    //wall 3
    glLoadIdentity();
    glTranslatef(FLOOR_WIDTH / 2, 0, 0);
    glRotatef(-90, 0, 1, 0);
    glGetFloatv(GL_MODELVIEW_MATRIX, wall3.m);
    wall3.drawNode = drawWall;
    wall3.sibling = &tableTop;
    wall3.child = NULL;
    wall3.material = silver();
    
    //table
    glLoadIdentity();
    glTranslatef(0, 5.0, 0);
    glGetFloatv(GL_MODELVIEW_MATRIX, tableTop.m);
    tableTop.drawNode = drawTop;
    tableTop.sibling = NULL;
    tableTop.child = &tableLeg1;
    tableTop.material = emerald();
    
    glLoadIdentity();
    glTranslatef(TABLE_WIDTH / 2.0, 0, TABLE_DEPTH / 2.0);
    glGetFloatv(GL_MODELVIEW_MATRIX, tableLeg1.m);
    tableLeg1.drawNode = drawLeg;
    tableLeg1.sibling = &tableLeg2;
    tableLeg1.child = NULL;
    tableLeg1.material = whitePlastic();
    
    glLoadIdentity();
    glTranslatef(-TABLE_WIDTH / 2.0, 0, TABLE_DEPTH / 2.0);
    glGetFloatv(GL_MODELVIEW_MATRIX, tableLeg2.m);
    tableLeg2.drawNode = drawLeg;
    tableLeg2.sibling = &tableLeg3;
    tableLeg2.child = NULL;
    tableLeg2.material = whitePlastic();
    
    glLoadIdentity();
    glTranslatef(-TABLE_WIDTH / 2.0, 0, -TABLE_DEPTH / 2.0);
    glGetFloatv(GL_MODELVIEW_MATRIX, tableLeg3.m);
    tableLeg3.drawNode = drawLeg;
    tableLeg3.sibling = &tableLeg4;
    tableLeg3.child = NULL;
    tableLeg3.material = whitePlastic();
    
    glLoadIdentity();
    glTranslatef(TABLE_WIDTH / 2.0, 0, -TABLE_DEPTH / 2.0);
    glGetFloatv(GL_MODELVIEW_MATRIX, tableLeg4.m);
    tableLeg4.drawNode = drawLeg;
    tableLeg4.sibling = &lampBase;
    tableLeg4.child = NULL;
    tableLeg4.material = whitePlastic();
    
    // lamp
    glLoadIdentity();
    glTranslatef(0, 1.5, -2.0);
    glGetFloatv(GL_MODELVIEW_MATRIX, lampBase.m);
    lampBase.drawNode = drawLampBase;
    lampBase.sibling = &teapot;
    lampBase.child = &lampUpright;
    lampBase.material = silver();
    
    glLoadIdentity();
    glTranslatef(0, 2.0, 0);
    glGetFloatv(GL_MODELVIEW_MATRIX, lampUpright.m);
    lampUpright.drawNode = drawLampUpright;
    lampUpright.sibling = NULL;
    lampUpright.child = &lampShade;
    lampUpright.material = silver();
    
    glLoadIdentity();
    glGetFloatv(GL_MODELVIEW_MATRIX, lampShade.m);
    lampShade.drawNode = drawLampShade;
    lampShade.sibling = NULL;
    lampShade.child = NULL;
    lampShade.material = gold();
    
    // teapot
    glLoadIdentity();
    glTranslatef(0, 2.5, 3.0);
    glGetFloatv(GL_MODELVIEW_MATRIX, teapot.m);
    teapot.drawNode = drawTeapot;
    teapot.sibling = NULL;
    teapot.child = NULL;
    teapot.material = chrome();
}