#pragma once

#include"Tools.h"
#include"Tetris.h"

class Game:public Tetris
{
public:
	Game();
	void Welcome(); //开始界面
	void DrawMap(); //游戏界面 
	void Run(); //运行游戏 
	~Game();
};

