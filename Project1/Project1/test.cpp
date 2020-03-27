#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>
#include <vector>
using namespace std;
std::vector<glm::vec3> position = {
glm::vec3(0.0f, 0.0f, 0.0f),
glm::vec3(1.0f, 0.0f, 0.0f),
glm::vec3(0.0f, 1.0f, 0.0f),
};
void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	for (size_t i = 0; i < position.size(); i++) {
		glVertex3f(position[i][0], position[i][1], position[i][2]);
	}
	glEnd();
	glFlush();
}

//example 1

void myReshape(int w, int h) {
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluOrtho2D(10.0, 100.0, 10.0, 100.0);
	//left, right, bottom, top
	//이거는 내가 viewport에서 정한 사이즈가 있다고 했을 때
	//그 안에서 밀도를 어떻게 할 것인가에 대한 것이다.
	//즉 위와 같은 경우라고 하면
	//viewport w안에 0~200 범위의 점이 있고
	//viewport h안에 0~100 범위의 점이 있는 것이다.
	//다시 말해서 좌표와 밀도 동시에 적용하는 부분인 것.


}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 1.0);
	glRectf(10.0, 10.0, 90.0, 90.0);
	//x1, y1, x2, y2
	//참고로 OpenGL의 좌표계는 평소 수학에서 쓰던 좌표계와 동일
	//즉, (0,0)이 왼쪽 하단
	glutSwapBuffers();
}

void example1() {
	
	glutCreateWindow("simple");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutMainLoop();
}

////

///example2

typedef struct rect {
	float x;
	float y;
	float width;
	float height;
} rect;
rect rectangle;

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);

	rectangle.x = 0.1;
	rectangle.y = 0.1;
	rectangle.width = 0.15;
	rectangle.height = 0.1;
}

void display2() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(rectangle.x, rectangle.y);
	glVertex2f(rectangle.x, rectangle.y + rectangle.height);
	glVertex2f(rectangle.x + rectangle.width, rectangle.y + rectangle.height);
	glVertex2f(rectangle.x + rectangle.width, rectangle.y);
	glEnd();

	glutSwapBuffers();

}

void reshape2(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1 + rectangle.x, 0, 1 + rectangle.y);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void moveObjects() {
	rectangle.x += 0.001;
	rectangle.y += 0.001;

	glutPostRedisplay();
}


void example2(char **argv) {
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();

	glutDisplayFunc(display2);
	//얜 말 그대로 보여주는 함수
	glutReshapeFunc(reshape2);
	glutIdleFunc(moveObjects);
	//움직이는 물체가 있을 때
	glutMainLoop();




}




void main(int argc, char** argv) {
	// inspect array elements and print to console
/*	const float* probe = &position[0].x;
	for (size_t i = 0; i < position.size() * 3; i++) {
		std::cout << probe[i] << std::endl;
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Hello OpenGL");
	glutDisplayFunc(renderScene);
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	glewInit();
	glutMainLoop();*/

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	example2(argv);

	

}

