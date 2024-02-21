#include <GL/glut.h>
#include <iostream>

void drawAxes() {
    glColor3f(1.0, 1.0, 1.0); // white color
    glBegin(GL_LINES);
    // Draw X-axis
    glVertex2i(-250, 0);
    glVertex2i(250, 0);
    // Draw Y-axis
    glVertex2i(0, -250);
    glVertex2i(0, 250);
    glEnd();
}

void drawEllipseBresenham(int rx, int ry, int xc, int yc) {
    int x = 0, y = ry;
    int rxSq = rx * rx;
    int rySq = ry * ry;
    int fx = 0, fy = 2 * rxSq * y;

    // Function to draw points
    auto drawPoints = [&](int x, int y) {
        glVertex2i(x + xc, y + yc);
        glVertex2i(-x + xc, y + yc);
        glVertex2i(x + xc, -y + yc);
        glVertex2i(-x + xc, -y + yc);
    };

    // Region 1
    int d1 = rySq - (rxSq * ry) + (0.25 * rxSq);
    drawPoints(x, y);
    while (fx < fy) {
        x++;
        fx += 2 * rySq;
        if (d1 < 0) {
            d1 += fx + rySq;
        } else {
            y--;
            fy -= 2 * rxSq;
            d1 += fx - fy + rySq;
        }
        drawPoints(x, y);
    }

    // Region 2
    int d2 = rySq * ((x + 0.5) * (x + 0.5)) + rxSq * ((y - 1) * (y - 1)) - rxSq * rySq;
    while (y >= 0) {
        y--;
        fy -= 2 * rxSq;
        if (d2 > 0) {
            d2 += rxSq - fy;
        } else {
            x++;
            fx += 2 * rySq;
            d2 += fx - fy + rxSq;
        }
        drawPoints(x, y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    drawEllipseBresenham(100, 50, 0, 0);
    glEnd();
    drawAxes();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ellipse Drawing");
    gluOrtho2D(-250, 250, -250, 250);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}