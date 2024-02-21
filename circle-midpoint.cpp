#include <GL/glut.h>
#include <vector>
#include <cmath>
#include <iostream>

void drawCircleUsingMidPointAlgorithm(int centerX, int centerY, int radius) {
    std::vector<float> vertices;

    // Mid-Point Circle Drawing Algorithm to calculate vertices
    int x = radius;
    int y = 0;
    int p = 3 - 2 * radius; // Initial decision parameter

    // A function to add points in all octants
    auto addPoints = [&](int x, int y) {
        vertices.push_back(centerX + x);
        vertices.push_back(centerY + y);

        vertices.push_back(centerX - x);
        vertices.push_back(centerY + y);

        vertices.push_back(centerX + x);
        vertices.push_back(centerY - y);

        vertices.push_back(centerX - x);
        vertices.push_back(centerY - y);

        vertices.push_back(centerX + y);
        vertices.push_back(centerY + x);

        vertices.push_back(centerX - y);
        vertices.push_back(centerY + x);

        vertices.push_back(centerX + y);
        vertices.push_back(centerY - x);

        vertices.push_back(centerX - y);
        vertices.push_back(centerY - x);

    };

    // Add the initial points
    addPoints(x, y);

    while (x >= y) {
        y++;

        // Update the decision parameter based on its sign
        if (p <= 0) {
            p = p + 4 * y + 6;
        } else {
            x--;
            p = p + 4 * (y - x) + 1;
        }
        std::cout << "x: " << x << " y: " << y << " p: " << p << std::endl;

        addPoints(x, y);
    }

    // Use OpenGL to draw these points
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices.data());
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glPointSize(3.0f); // Point size
    glDrawArrays(GL_POINTS, 0, vertices.size() / 2);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawCircleUsingMidPointAlgorithm(3, 3, 4); // Center (3,3), Radius 4
    // Draw the diameter
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glBegin(GL_LINES);
    glVertex2f(3 - 4, 3); // Start point of the diameter
    glVertex2f(3 + 4, 3); // End point of the diameter
    glEnd();

    // Draw the x-axis
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glBegin(GL_LINES);
    glVertex2f(-10.0f, 0.0f); // Start point of the x-axis
    glVertex2f(20.0f, 0.0f); // End point of the x-axis
    glEnd();

    // Draw the y-axis
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glBegin(GL_LINES);
    glVertex2f(0.0f, -6.0f); // Start point of the y-axis
    glVertex2f(0.0f, 10.0f); // End point of the y-axis
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600); // Set the window size
    glutCreateWindow("OpenGL Mid-Point Circle");

    // Set up the projection to maintain the aspect ratio
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspectRatio = 800.0f / 600.0f;
    gluOrtho2D(-6.0 * aspectRatio, 10.0 * aspectRatio, -6.0, 10.0); // Adjust for aspect ratio

    // Set the clear color to white
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}