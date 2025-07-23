#include <windows.h>
#include <GL/glut.h>

void display() {

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Set color to red
   // glColor3f(1.0f, 0.0f, 0.0f);

    // Draw trapezoid using GL_POLYGON
    glBegin(GL_POLYGON);

    glColor3f(1.0f, 0.0f, 0.0f);


        glVertex2f(-3.0f, 1.0f);  // Bottom-left
        glVertex2f(2.0f, 1.0f);   // Bottom-right
        glVertex2f(1.0f, 3.0f);    // Top-right
        glVertex2f(-2.0f, 3.0f);   // Top-left
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Red Trapezoid");

    glutDisplayFunc(display);

    // Background color: white
    //glClearColor(1.0, 1.0, 1.0, 1.0);

    // 2D projection
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-5, 5, -5, 5);

    glutMainLoop();
    return 0;
}
