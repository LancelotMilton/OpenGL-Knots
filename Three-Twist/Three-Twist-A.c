#include <GL/glut.h>
#include <math.h>

#define PI 3.1415

float angle = 0.0f;

void drawKnot() {
    glBegin(GL_LINE_STRIP);
    for (float t = 0; t < 2 * PI; t += 0.01) {
        float y = cos((2*t)+0.2);
        float z = cos(7*t);
        float x = sin((3*t)+0.7);
        glVertex3f(x, y, z);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -6.0);
    glRotatef(angle, 1.0, 1.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    drawKnot();
    glBegin(GL_LINES);
    glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(10, 0, 0);
    glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 10, 0);
    glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 10);
    glEnd();
    glutSwapBuffers();
}

void update(int value) {
    angle += 1.0f;
    if (angle > 360) {
        angle -= 360;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 1000);
    glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
    glutCreateWindow("Three-Twist Knot");

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClearDepth(1.0f);                   
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);
    glutMainLoop();

    return 0;
}
