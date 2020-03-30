#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>
#include <vector>
#include "game.h"
#include <math.h>

using namespace std;

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);
	startTickCount = GetTickCount64();
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT);

	//Ground - initialize position and color
	glBegin(GL_QUADS);
		setObjectColor(BLACK);
		glVertex2f(0,0);
		glVertex2f(0, 1);
		glVertex2f(10, 1);
		glVertex2f(10, 0);
	glEnd();

	//Player - initialize position and color
	glBegin(GL_QUADS);
		setObjectColor(player.getPlayerPose());
		glVertex2f(player.getPlayerPositionX(), player.getPlayerPositionY());
		glVertex2f(player.getPlayerPositionX(), player.getPlayerPositionY() + player.getPlayerSize());
		glVertex2f(player.getPlayerPositionX() + player.getPlayerSize(), player.getPlayerPositionY() + player.getPlayerSize());
		glVertex2f(player.getPlayerPositionX() + player.getPlayerSize(), player.getPlayerPositionY());
	glEnd();

	//Thief - Initialize position and color
	glBegin(GL_QUADS);
		setObjectColor(thief.getTheifPose());
		glVertex2f(thief.getTheifPositionX(), thief.getTheifPositionY());
		glVertex2f(thief.getTheifPositionX(), thief.getTheifPositionY() + thief.getThiefSize());
		glVertex2f(thief.getTheifPositionX() + thief.getThiefSize(), thief.getTheifPositionY() + thief.getThiefSize());
		glVertex2f(thief.getTheifPositionX() + thief.getThiefSize(), thief.getTheifPositionY());
	glEnd();
	

	//Wall - create a wall every "interval" time
	glBegin(GL_QUADS);
		currentTickCount = GetTickCount64();
		if (currentTickCount - startTickCount >= interval) {
			wall[total].setWallPositionX(wall[total].getWallPositionX() + interval/1000.0 * total);
			startTickCount = currentTickCount;
			total++;
		}

		//Wall - initialize position and color
		//DJ - 벽의 갯수 일단 50개로 했는데 바꿔야할듯 "total"
		if (total <= 50) {
			for (int i = front; i < total; i++) {
				setObjectColor(wall[i].getWallColor());

				glVertex2f(wall[i].getWallPositionX(), wall[i].getWallPositionY());
				//(0,1)
				glVertex2f(wall[i].getWallPositionX(),
					wall[i].getWallPositionY() + wall[i].getWallHeight());
				//(1,1)
				glVertex2f(wall[i].getWallPositionX() + wall[i].getWallWidth(),
					wall[i].getWallPositionY() + wall[i].getWallHeight());
				//(1,0)
				glVertex2f(wall[i].getWallPositionX() + wall[i].getWallWidth(),
					wall[i].getWallPositionY());
				//cout << i << ", " << wall[i].getWallPositionX() << endl;
			}
		}

		//System - WIN if the distance between player and thief is less than a "threshold"
		// "threshold" == player.getPlayerSize()
		if (thief.getTheifPositionX() <= player.getPlayerPositionX() + player.getPlayerSize())
			message(true);
	glEnd();

	glutSwapBuffers();
	glFlush();
}

void setObjectColor(int color) {
	switch (color)
	{
	case RED:
		glColor3f(1.0, 0.0, 0.0);
		break;
	case GREEN:
		glColor3f(0.0, 1.0, 0.0);
		break;
	case BLUE:
		glColor3f(0.0, 0.0, 1.0);
		break;
	case YELLOW:
		glColor3f(1.0, 1.0, 0.0);
		break;
	case BLACK:
		glColor3f(0.0, 0.0, 0.0);
		break;
	default:
		glColor3f(0.0, 0.0, 0.0);
		break;
	}
}


//Camera - reshape viewport size
//DJ - 여긴가? 아직 잘 모르겠다
void reshape(int w, int h) {
	glViewport(0, 0, 1000, 500);
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 10, 0, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//Wall - move wall in "velocity" every "interval"
void moveWall() {
	//wall[i].setWallPositionX(wall[i].getWallPositionX() + 5 * i);
	
	for (int i = 0; i < total; i++) {
		wall[i].setWallPositionX(wall[i].getWallPositionX() - velocity);
		if (wall[i].getWallPositionX() + wall[i].getWallWidth() < 0) {
			wall[i].setWallPositionX(-10);
			front = i;
		}
	}

	//아래 두 if는 GameMain 클래스로 옮길 예정
	//Thief - change color
	if (wall[now].getWallPositionX() <= (thief.getTheifPositionX() + thief.getThiefSize())) {
		wall[now].setWallColor(thief.getTheifPose());
		thief.setTheifPose(rand() % 4);
		now++;
	}

	//System - check if pass or fail
	if (wall[previous].getWallPositionX() <= (player.getPlayerPositionX() + player.getPlayerSize())) {
		if (player.getPlayerPose() == wall[previous].getWallColor()) {
			cout << "Pass" << endl;
			velocity += 0.01;
			interval -= 250;
			previousPlayerPosition = player.getPlayerPositionX();
			pass = true;
		}
		else {
			cout << "Fail" << endl;
			failCount++;
			if (failCount >= 3)
				message(false);
			pass = false;
		}
		previous++;
	}

	//Player - move toward thief w/ moving animation
	if (pass) {
		player.setPlayerPositionX(player.getPlayerPositionX() + playerDistance);
		if ((player.getPlayerPositionX() - previousPlayerPosition) >= 1.0) {
			previousPlayerPosition = 0.0;
			pass = false;
		}
	}

	glutPostRedisplay();
}

//System - end the game if pass or fail
void message(bool success) {
	HWND hwnd;
	HINSTANCE hInstance = GetModuleHandle(NULL);
	hwnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);

	if (success) 
		MessageBoxA(hwnd, "Pass", "Pass", MB_OK);
	else 
		MessageBoxA(hwnd, "Fail", "Fail", MB_OK);

	exit(0);
}

//Player - select pose using keyboard input
void selectPose(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT: //RED
		player.setPlayerPose(RED);
		break;
	case GLUT_KEY_RIGHT: //GREEN
		player.setPlayerPose(GREEN);
		break;
	case GLUT_KEY_UP: //BLUE
		player.setPlayerPose(BLUE);
		break;
	case GLUT_KEY_DOWN: //YELLOW
		player.setPlayerPose(YELLOW);
		break;
	}
	//gameMain.selectPose(key, x, y);
	glutPostRedisplay();
}

//Register input callback functions
//DJ - 원래 play였는데 여러 기능이 합쳐져 있는 것 같아서 분리함 Initialize and open window / Register input callback functions / Enter event processing loop 
void registerCallbackFunctions(char **argv) {
	glutDisplayFunc(display);
	glutReshapeFunc(reshape); //DJ - 뭘 reshape함?
	glutIdleFunc(moveWall);
	glutSpecialFunc(selectPose); //DJ - glutKeyboardFunc 아니고?
}


void main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	//Initialize and open window
	glutInitWindowSize(1000, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();

	registerCallbackFunctions(argv);

	//Enter event processing loop
	glutMainLoop();
}

