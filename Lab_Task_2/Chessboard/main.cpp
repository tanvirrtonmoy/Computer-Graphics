#include <windows.h>
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    float size = 0.5f;
    float x = -1.0f;
    float y = 1.0f;

    // -------- Row 1 --------
    glColor3f(0, 0, 0);  // Black
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y - size);
        glVertex2f(x, y - size);
    glEnd();

    glColor3f(1, 1, 1);  // White
    glBegin(GL_QUADS);
        glVertex2f(x + size, y);
        glVertex2f(x + 2*size, y);
        glVertex2f(x + 2*size, y - size);
        glVertex2f(x + size, y - size);
    glEnd();

    glColor3f(0, 0, 0);  // Black
    glBegin(GL_QUADS);
        glVertex2f(x + 2*size, y);
        glVertex2f(x + 3*size, y);
        glVertex2f(x + 3*size, y - size);
        glVertex2f(x + 2*size, y - size);
    glEnd();

    glColor3f(1, 1, 1);  // White
    glBegin(GL_QUADS);
        glVertex2f(x + 3*size, y);
        glVertex2f(x + 4*size, y);
        glVertex2f(x + 4*size, y - size);
        glVertex2f(x + 3*size, y - size);
    glEnd();

    // -------- Row 2 --------
    y -= size;

    glColor3f(1, 1, 1);  // White
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y - size);
        glVertex2f(x, y - size);
    glEnd();

    glColor3f(0, 0, 0);  // Black
    glBegin(GL_QUADS);
        glVertex2f(x + size, y);
        glVertex2f(x + 2*size, y);
        glVertex2f(x + 2*size, y - size);
        glVertex2f(x + size, y - size);
    glEnd();

    glColor3f(1, 1, 1);  // White
    glBegin(GL_QUADS);
        glVertex2f(x + 2*size, y);
        glVertex2f(x + 3*size, y);
        glVertex2f(x + 3*size, y - size);
        glVertex2f(x + 2*size, y - size);
    glEnd();

    glColor3f(0, 0, 0);  // Black
    glBegin(GL_QUADS);
        glVertex2f(x + 3*size, y);
        glVertex2f(x + 4*size, y);
        glVertex2f(x + 4*size, y - size);
        glVertex2f(x + 3*size, y - size);
    glEnd();

    // -------- Row 3 --------
    y -= size;

    glColor3f(0, 0, 0);  // Black
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y - size);
        glVertex2f(x, y - size);
    glEnd();

    glColor3f(1, 1, 1);  // White
    glBegin(GL_QUADS);
        glVertex2f(x + size, y);
        glVertex2f(x + 2*size, y);
        glVertex2f(x + 2*size, y - size);
        glVertex2f(x + size, y - size);
    glEnd();

    glColor3f(0, 0, 0);  // Black
    glBegin(GL_QUADS);
        glVertex2f(x + 2*size, y);
        glVertex2f(x + 3*size, y);
        glVertex2f(x + 3*size, y - size);
        glVertex2f(x + 2*size, y - size);
    glEnd();

    glColor3f(1, 1, 1);  // White
    glBegin(GL_QUADS);
        glVertex2f(x + 3*size, y);
        glVertex2f(x + 4*size, y);
        glVertex2f(x + 4*size, y - size);
        glVertex2f(x + 3*size, y - size);
    glEnd();

    // -------- Row 4 --------
    y -= size;

    glColor3f(1, 1, 1);  // White
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y - size);
        glVertex2f(x, y - size);
    glEnd();

    glColor3f(0, 0, 0);  // Black
    glBegin(GL_QUADS);
        glVertex2f(x + size, y);
        glVertex2f(x + 2*size, y);
        glVertex2f(x + 2*size, y - size);
        glVertex2f(x + size, y - size);
    glEnd();

    glColor3f(1, 1, 1);  // White
    glBegin(GL_QUADS);
        glVertex2f(x + 2*size, y);
        glVertex2f(x + 3*size, y);
        glVertex2f(x + 3*size, y - size);
        glVertex2f(x + 2*size, y - size);
    glEnd();

    glColor3f(0, 0, 0);  // Black
    glBegin(GL_QUADS);
        glVertex2f(x + 3*size, y);
        glVertex2f(x + 4*size, y);
        glVertex2f(x + 4*size, y - size);
        glVertex2f(x + 3*size, y - size);
    glEnd();

    // -------- Border Around Board --------
    glColor3f(0, 0, 0);     // Border color
    glLineWidth(3.0f);      // Border thickness
    glBegin(GL_LINE_LOOP);
        glVertex2f(-1.0f, 1.0f);   // Top-left
        glVertex2f(1.0f, 1.0f);    // Top-right
        glVertex2f(1.0f, -1.0f);   // Bottom-right
        glVertex2f(-1.0f, -1.0f);  // Bottom-left
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("4x4 Chessboard with Border");
    glutDisplayFunc(display);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-2, 2, -2, 2);  // 2D view
    glutMainLoop();
    return 0;
}
