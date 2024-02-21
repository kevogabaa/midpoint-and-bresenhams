#include <GL/glut.h>
#include <cmath>

void drawSquare(bool isShadow) {
    if (isShadow) {
        glPushAttrib(GL_LINE_BIT); // save current line attribute
        glLineStipple(1, 0x00FF); // dotted line
        glEnable(GL_LINE_STIPPLE);
        glColor3f(1.0, 0.0, 0.0); // Set the color to red
    } else {
        glColor3f(0.0, 0.0, 1.0); // Set the color to blue
    }

    glBegin(isShadow ? GL_LINE_LOOP : GL_QUADS);
    glVertex2f(-3, 5);
    glVertex2f(3, 7);
    glVertex2f(6, -2);
    glVertex2f(0, -4);
    glEnd();

    if (isShadow) {
        glDisable(GL_LINE_STIPPLE); // disable line stipple
        glPopAttrib(); // restore line attribute
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawSquare(true); // draw shadow square

    glPushMatrix(); // save current matrix
    glRotatef(48.0, 0.0, 0.0, 1.0); // rotate 48 degrees anticlockwise
    drawSquare(false); // draw rotated square
    glPopMatrix(); // restore matrix


    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Square Drawing");
    gluOrtho2D(-10, 10, -10, 10);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}