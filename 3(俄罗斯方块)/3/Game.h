#pragma once

#include"Tools.h"
#include"Tetris.h"

class Game:public Tetris
{
public:
	Game();
	void Welcome(); //��ʼ����
	void DrawMap(); //��Ϸ���� 
	void Run(); //������Ϸ 
	~Game();
};

