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


//DJ - ���Ⱑ �ý��� ���̱���

CONST TCHAR* lpszClass = _T("Message Box!\n");


CPlayer player;
CThief thief;

//�ϴ� ���� 50���� �����ߴµ� ���ͷ� �ٲܱ� ���� ��
CWall wall[50];
//CGameMain gameMain;
//vector<CWall> totalWall;

//��ü ����
int total = 0;

//�� ��ġ���� �����÷ο츦 ���� ���� ���� �տ� �ִ� �� //DJ-�÷��̾�� ���ʿ� �ִ� ��?
int front = 0;

//��ݱ��� ���� �տ� �־��� ������ �÷��̾� �ٷ� �տ� �ִ� ���� �ε���
int previous = 0;

//���� ���� �ٷ� �տ� �ִ� ���� �ε���
int now = 0;

//�� 3���� �ǹ̰� ���ݾ� �ٸ�.


//��� ���� Ƚ��
int failCount = 0;

//�� ���� ����
int interval = 5000;

//�� �̵� �ӵ�
float velocity = 0.01;

//���� ������ ���� start tick
int startTickCount = 0;

//���� ������ ���� current tick.
int currentTickCount = 0;

//�÷��̾� �ִϸ��̼��� ���� ��
bool pass = false;

float playerDistance = 0.1;

float previousPlayerPosition = 0.0;

void init();
void display();
void reshape(int w, int h);
void registerCallbackFunctions(char** argv);
void moveWall();
void selectPose(int key, int x, int y);
void setObjectColor(int color);
void message(bool success);
