#include "CThief.h"

CThief::CThief()
{
	positionX = 7;
	positionY = 1;

	thiefSize = 0.5;
	pose = BLUE;
}

CThief::~CThief()
{
}

float CThief::getTheifPositionX()
{
	return positionX;
}

float CThief::getTheifPositionY()
{
	return positionY;
}

void CThief::setTheifPose(int pose)
{
	this->pose = pose;
}

int CThief::getTheifPose()
{
	return pose;
}

float CThief::getThiefSize()
{
	return thiefSize;
}
