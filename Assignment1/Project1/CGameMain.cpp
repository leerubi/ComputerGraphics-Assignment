#include "CGameMain.h"

void CGameMain::selectPose(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_LEFT://аб -> RED
		//player.setPlayerPose(RED);
		break;
	case GLUT_KEY_RIGHT://©Л -> GREEN
		//player.setPlayerPose(GREEN);
		break;
	case GLUT_KEY_UP://╩С -> BLUE
		//player.setPlayerPose(BLUE);
		break;
	case GLUT_KEY_DOWN://го ->YELLOW
		//player.setPlayerPose(YELLOW);
		break;
	}
	glutPostRedisplay();
}

void CGameMain::temp()
{


}
