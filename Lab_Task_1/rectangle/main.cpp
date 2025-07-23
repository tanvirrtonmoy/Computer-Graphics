#include <windows.h>
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // ✅ Thicker border
    glLineWidth(5.0f);



    // Draw rectangle outline
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);   // Bottom-left
    glVertex2f(4.0f, 1.0f);    // Bottom-right
    glVertex2f(4.0f, 3.0f);     // Top-right
    glVertex2f(1.0f, 3.0f);    // Top-left
glEnd();


    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Rectangle Outline");
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutDisplayFunc(display);


    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-7, 7, -7, 7);

    glutMainLoop();
    return 0;
}
