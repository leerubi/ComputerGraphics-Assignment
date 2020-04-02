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
	float playerSize;
	int pose;

public:
	CPlayer();
	~CPlayer();
	
	void setPlayerPositionX(float positionX);
	float getPlayerPositionX();

	float getPlayerPositionY();

	void setPlayerPose(int pose);
	int getPlayerPose();

	float getPlayerSize();
};

