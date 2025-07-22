#include <windows.h>
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);


    glLineWidth(5.0f);

    // Draw X and Y axes (black lines)
    glColor3f(0.0f, 0.0f, 0.0f); // Black
    glBegin(GL_LINES);
        glVertex2f(-1.0f, 0.0f); glVertex2f(1.0f, 0.0f);  // X-axis
        glVertex2f(0.0f, -1.0f); glVertex2f(0.0f, 1.0f);  // Y-axis
    glEnd();

    // Red square in top-left
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glBegin(GL_QUADS);
        glVertex2f(-0.7f, 0.7f);
        glVertex2f(-0.5f, 0.7f);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(-0.7f, 0.5f);
    glEnd();

    // Green arrow in top-right (rectangle + triangle)
    glColor3f(0.0f, 0.7f, 0.0f); // Green
    // Rectangle part
    glBegin(GL_QUADS);
        glVertex2f(0.2f, 0.6f);
        glVertex2f(0.6f, 0.6f);
        glVertex2f(0.6f, 0.5f);
        glVertex2f(0.2f, 0.5f);
    glEnd();
    // Arrowhead
    glBegin(GL_TRIANGLES);
        glVertex2f(0.6f, 0.65f);
        glVertex2f(0.8f, 0.55f);
        glVertex2f(0.6f, 0.45f);
    glEnd();

    // Purple left-pointing triangle in bottom-left
    glColor3f(0.5f, 0.0f, 0.5f); // Purple
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.7f, -0.3f);
        glVertex2f(-0.5f, -0.2f);
        glVertex2f(-0.5f, -0.4f);
    glEnd();


    // Yellow upward triangle in bottom-right
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glBegin(GL_TRIANGLES);
        glVertex2f(0.5f, -0.3f);
        glVertex2f(0.7f, -0.3f);
        glVertex2f(0.6f, -0.1f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Multi-Shape Quadrant Drawing");

    glutDisplayFunc(display);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // White background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1, 1, -1, 1);             // Normalized coordinates

    glutMainLoop();
    return 0;
}
