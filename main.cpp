#include "main.hpp"

#define WIN_WIDTH 400
#define WIN_HEIGHT 400

clock_t current_time = clock();
clock_t last_time = current_time;
float dt = 0;

static void setup() {
    
}

static void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2.5);



    glutSwapBuffers();
}

static void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, WIN_WIDTH, 0.0, WIN_HEIGHT, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

    glutPostRedisplay();
}

static void idle() {
    current_time = clock();
    dt = static_cast<float>(current_time - last_time) / CLOCKS_PER_SEC;
    last_time = current_time;
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    srand(static_cast<unsigned int>(time(nullptr)));

    setup();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutCreateWindow("Robot Simulation");
    
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);

    glutMainLoop();

    auto shape1 = point2i_shape();
    return 0;
}