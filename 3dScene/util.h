// glutSolidCylinder only available in freeglut
void solidCylinder(GLdouble base, GLdouble height, GLint slices, GLint stacks) {
    glPushMatrix();
    GLUquadricObj *quad = gluNewQuadric();
    
    gluQuadricNormals(quad, GLU_SMOOTH);
    gluQuadricTexture(quad, GL_TRUE);
    gluQuadricDrawStyle(quad, GLU_FILL);
    
    gluCylinder(quad, base, base, height, slices, stacks);
    gluDisk(quad, 0.0f, base, slices, 1);
    glTranslatef(0.0f, 0.0f, height);
    gluDisk(quad, 0.0f, base, slices, 1);
    
    glPopMatrix();
}

void tiledSquare(int tiles) {
    glPushMatrix();
    glNormal3f(0, 1, 0);
    for (int i = 0; i < tiles; i++) {
        for (int j = 0; j < tiles; j++) {
            float x1 = float(i) / tiles;
            float x2 = float(i + 1) / tiles;
            float z1 = float(j) / tiles;
            float z2 = float(j + 1) / tiles;
            
            glBegin(GL_POLYGON);
            glVertex3f(x1, 0, z1);
            glVertex3f(x1, 0, z2);
            glVertex3f(x2, 0, z2);
            glVertex3f(x2, 0, z1);
            glEnd();
        }
    }
    glPopMatrix();
}

/*void drawAxis(void) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x1111);
    
    // x axis
    glColor3fv(colors[RED]);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-WINDOW_WIDTH, 0, 0);
    glVertex3f(WINDOW_WIDTH, 0, 0);
    glEnd();
    
    // y axis
    glColor3fv(colors[GREEN]);
    glBegin(GL_LINE_LOOP);
    glVertex3f(0, -WINDOW_HEIGHT, 0);
    glVertex3f(0, WINDOW_HEIGHT, 0);
    glEnd();
    
    // z axis
    glColor3fv(colors[BLUE]);
    glBegin(GL_LINE_LOOP);
    glVertex3f(0, 0, -WINDOW_WIDTH);
    glVertex3f(0, 0, WINDOW_WIDTH);
    glEnd();
    
    glDisable(GL_LINE_STIPPLE);
}*/