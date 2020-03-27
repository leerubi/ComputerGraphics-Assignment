#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>
#include <vector>
#include "global.h"
using namespace std;

class CPlayer
{
private:
	float positionX;
	float positionY;
	//position[2]
	int pose;
	float playerSize;
public:
	CPlayer();
	~CPlayer();
	//player의 경우 X좌표 값이 바뀜.
	void setPlayerPositionX(float positionX);
	float getPlayerPositionX();

	//Y좌표의 경우 처음 설정한 값 그대로 가져가서 값이 변하지X
	float getPlayerPositionY();

	void setPlayerPose(int pose);
	int getPlayerPose();
	float getPlayerSize();
};

