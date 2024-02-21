#include <GL/glut.h>
#include <cmath>

void drawSquare() {
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0); // Set the color to blue
    glVertex2f(-3, 5);
    glVertex2f(3, 7);
    glVertex2f(6, -2);
    glVertex2f(0, -4);
    glEnd();
}



void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawSquare();
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