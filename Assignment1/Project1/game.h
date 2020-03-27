#pragma once

#include "CPlayer.h"
#include "CThief.h"
#include "CThief.h"
#include "CWall.h"
#include "CGameMain.h"
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>
#include <vector>
#include <Windows.h>
#include <tchar.h>


CONST TCHAR* lpszClass = _T("Message Box!\n");


CPlayer player;
CThief thief;

//일단 벽을 50개로 설정했는데 벡터로 바꿀까 생각 중
CWall wall[50];
//CGameMain gameMain;
//vector<CWall> totalWall;

//전체 갯수
int total = 0;

//벽 위치값의 오버플로우를 막기 위해 가장 앞에 있는 벽
int front = 0;

//방금까지 도둑 앞에 있었고 지금은 플레이어 바로 앞에 있는 벽의 인덱스
int previous = 0;

//지금 도둑 바로 앞에 있는 벽의 인덱스
int now = 0;

//위 3개의 의미가 조금씩 다름.


//통과 실패 횟수
int failCount = 0;

//벽 생성 간격
int interval = 5000;

//벽 이동 속도
float velocity = 0.01;

//간격 조정을 위한 start tick
int startTickCount = 0;

//간격 조정을 위한 current tick.
int currentTickCount = 0;

//플레이어 애니메이션을 위한 것
bool pass = false;

float playerDistance = 0.1;

float previousPlayerPosition = 0.0;

void init();
void display();
void reshape(int w, int h);
void play(char** argv);
void moveWall();
void selectPose(int key, int x, int y);
void setObjectColor(int color);
void message(bool success);
