#include <windows.h>
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3.0f);  // Border thickness

    // --- Stripe 1 (Violet) ---
    glColor3f(0.5f, 0.2f, 0.5f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, 1.5f);
        glVertex2f(1.0f, 1.5f);
        glVertex2f(1.0f, 1.1f);
        glVertex2f(-1.0f, 1.1f);
    glEnd();
    glColor3f(0,0,0);  // Border
    glBegin(GL_LINE_LOOP);
        glVertex2f(-1.0f, 1.5f);
        glVertex2f(1.0f, 1.5f);
        glVertex2f(1.0f, 1.1f);
        glVertex2f(-1.0f, 1.1f);
    glEnd();

    // --- Stripe 2 (Indigo) ---
    glColor3f(0.3f, 0.3f, 0.8f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, 1.1f);
        glVertex2f(1.0f, 1.1f);
        glVertex2f(1.0f, 0.7f);
        glVertex2f(-1.0f, 0.7f);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-1.0f, 1.1f);
        glVertex2f(1.0f, 1.1f);
        glVertex2f(1.0f, 0.7f);
        glVertex2f(-1.0f, 0.7f);
    glEnd();

    // --- Stripe 3 (Blue-green) ---
    glColor3f(0.0f, 0.7f, 0.7f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, 0.7f);
        glVertex2f(1.0f, 0.7f);
        glVertex2f(1.0f, 0.3f);
        glVertex2f(-1.0f, 0.3f);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-1.0f, 0.7f);
        glVertex2f(1.0f, 0.7f);
        glVertex2f(1.0f, 0.3f);
        glVertex2f(-1.0f, 0.3f);
    glEnd();

    // --- Stripe 4 (Green) ---
    glColor3f(0.0f, 0.6f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, 0.3f);
        glVertex2f(1.0f, 0.3f);
        glVertex2f(1.0f, -0.1f);
        glVertex2f(-1.0f, -0.1f);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-1.0f, 0.3f);
        glVertex2f(1.0f, 0.3f);
        glVertex2f(1.0f, -0.1f);
        glVertex2f(-1.0f, -0.1f);
    glEnd();

    // --- Stripe 5 (Orange) ---
    glColor3f(1.0f, 0.6f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.1f);
        glVertex2f(1.0f, -0.1f);
        glVertex2f(1.0f, -0.5f);
        glVertex2f(-1.0f, -0.5f);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-1.0f, -0.1f);
        glVertex2f(1.0f, -0.1f);
        glVertex2f(1.0f, -0.5f);
        glVertex2f(-1.0f, -0.5f);
    glEnd();

    // --- Stripe 6 (Yellow) ---
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.5f);
        glVertex2f(1.0f, -0.5f);
        glVertex2f(1.0f, -0.9f);
        glVertex2f(-1.0f, -0.9f);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-1.0f, -0.5f);
        glVertex2f(1.0f, -0.5f);
        glVertex2f(1.0f, -0.9f);
        glVertex2f(-1.0f, -0.9f);
    glEnd();

    // --- Stripe 7 (Red) ---
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.9f);
        glVertex2f(1.0f, -0.9f);
        glVertex2f(1.0f, -1.3f);
        glVertex2f(-1.0f, -1.3f);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-1.0f, -0.9f);
        glVertex2f(1.0f, -0.9f);
        glVertex2f(1.0f, -1.3f);
        glVertex2f(-1.0f, -1.3f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rainbow Flag with Stripe Borders");
    glutDisplayFunc(display);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-2, 2, -2, 2);
    glutMainLoop();
    return 0;
}
