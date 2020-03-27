#pragma once
#include "global.h"
class CThief
{
private:
	//도둑의 좌표. 사실 벽과 플레이어만 이동이 있어서 도둑은 딱히 움직일 일이 없음.
	float positionX;
	float positionY;
	
	//정사각형이라 위, 아래 사이즈 같음. 혹시 나중에 원으로 바꾼다면 이게 반지름이 됨.
	float thiefSize;
	int pose;
public:
	CThief();
	~CThief();

	//사실 도둑은 포지션이 바뀔 일이 없어서 get만 만듦.
	//void setTheifPositionX(float positionX);
	float getTheifPositionX();
	float getTheifPositionY();



	void setTheifPose(int pose);
	int getTheifPose();

	float getThiefSize();

};

