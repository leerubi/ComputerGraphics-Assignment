#include "CPlayer.h"



CPlayer::CPlayer()
{
	positionX = 1;
	positionY = 1;
	playerSize = 0.5;
	pose = RED;
}

CPlayer::~CPlayer()
{
	delete this;
}

void CPlayer::setPlayerPositionX(float positionX)
{
	this->positionX = positionX;
}

float CPlayer::getPlayerPositionX()
{
	return positionX;
}

float CPlayer::getPlayerPositionY()
{
	return positionY;
}

void CPlayer::setPlayerPose(int pose) {
	this->pose = pose;
}

int CPlayer::getPlayerPose()
{
	return pose;
}

float CPlayer::getPlayerSize()
{
	return playerSize;
}

