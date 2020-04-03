#pragma once
#include "global.h"
#include <math.h>

class CThief
{
private:
	float positionX;
	float positionY;
	float thiefSize;
	int pose;

public:
	CThief();
	~CThief();

	float getTheifPositionX();
	float getTheifPositionY();

	void setTheifPose(int pose);
	int getTheifPose();

	float getThiefSize();
};

