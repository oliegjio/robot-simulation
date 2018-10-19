#include "main.hpp"

#define WIN_WIDTH 400
#define WIN_HEIGHT 400

clock_t current_time = clock();
clock_t last_time = current_time;
float dt = 0;

std::vector<point2i_shape*> shapes;

auto points = std::vector<point2i>();
std::vector<triangle2<int>*> *triangles;

static void setup() {
    // auto shape1 = point2i_shape::make_rectangle(150, 150, 50, 50);
    // shape1->rotate(0.3);
    // shape1->set_color(1, 0, 0);
    //
    // auto shape2 = point2i_shape::make_circle(30, 30, 180);
    // shape2->set_color(0, 1, 0);
    //
    // auto shape3 = point2i_shape::minkowski_sum(*shape2, *shape1);
    // shape3->set_color(0, 0, 1);
    //
    // auto shape4 = point2i_shape::make_random(0, 0, WIN_WIDTH, WIN_HEIGHT, 100, 15);
    // shape4->set_color(0, 1, 1);
    // auto points = shape4->get_points();

    points.push_back(point2i(200, 200));
    points.push_back(point2i(220, 150));
    points.push_back(point2i(240, 180));
    points.push_back(point2i(260, 260));
    points.push_back(point2i(300, 160));
    // points.push_back(point2i(320, 100));
    points.push_back(point2i(320, 200));
    points.push_back(point2i(330, 120));
    points.push_back(point2i(360, 140));

    triangles = delaunay::triangulate(points);

    // shapes.push_back(shape3);
    // shapes.push_back(shape1);
    // shapes.push_back(shape2);
    // shapes.push_back(shape4);
}

static void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    // glPointSize(2.5);

    // for (const auto &shape : shapes) {
    //     shape->draw();
    // }

    glPointSize(6);
    glColor3f(0, 0, 0);
    glBegin(GL_POINTS);
    for (const auto &p : points) {
        glVertex2f(p.x, p.y);
    }
    glEnd();

    draw_triangles(triangles);

    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2f(points[5].x, points[5].y);
    glEnd();

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

    return 0;
}
