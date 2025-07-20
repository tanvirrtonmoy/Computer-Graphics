
#include<windows.h>
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Define the height of each stripe
    float stripeHeight = 2.0f / 6.0f; // total height is 2 (from -1 to 1)

    // Rainbow colors (from top to bottom)
    float colors[6][3] = {
        {0.5f, 0.4f, 0.8f}, // violet-ish (top)
        {0.2f, 0.6f, 0.9f}, // blue
        {0.0f, 0.8f, 0.4f}, // green
        {1.0f, 0.6f, 0.0f}, // orange
        {1.0f, 1.0f, 0.0f}, // yellow
        {1.0f, 0.0f, 0.0f}  // red (bottom)
    };

    float yTop = 1.0f;
    for (int i = 0; i < 6; ++i) {
        glColor3f(colors[i][0], colors[i][1], colors[i][2]);
        glBegin(GL_QUADS);
        glVertex2f(-1.0f, yTop - stripeHeight);
        glVertex2f( 1.0f, yTop - stripeHeight);
        glVertex2f( 1.0f, yTop);
        glVertex2f(-1.0f, yTop);
        glEnd();
        yTop -= stripeHeight;
    }

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // white background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Rainbow Flag");
    glutInitWindowSize(500, 300);
    glutInitWindowPosition(100, 100);
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
