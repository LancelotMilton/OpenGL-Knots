#include <GL/glut.h>
#include <math.h>

#define PI 3.1415

float angle = 0.0f;

void drawKnot() {
    glBegin(GL_LINE_STRIP); /* write GL_LINE_LOOP if you want end of the lines to connect */
    for (float t = 0; t < 2 * PI; t += 0.01) {
        float y = (2+ cos(2*t)) * sin(3 * t);
        float z = -sin(3*t);
        float x =  (2+ cos(2*t)) * cos(3 * t);
        glVertex3f(x, y, z);

    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -6.0);
    glRotatef(angle, 1.0, 1.0, 1.0); /* you can change this part to make it rotate to your liking */
    glColor3f(1.0, 1.0, 1.0); /* you can also change this part if you want to change the color of the knot */
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
    glutCreateWindow("Trefoil Knot");

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClearDepth(1.0f);                   /* Set background depth to farthest */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);
    glutMainLoop();

    return 0;
}
