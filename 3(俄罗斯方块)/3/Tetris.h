#pragma once
#include"type.h"

#include<ctime> 
#include<conio.h>  //内置_kbhit()、_getch()

class Tetris :public type
{ 
public:
	Tetris(); ////构造函数， 初始化各个值 
	void Draw(int , int , int ); //画图形 
	bool Judge(int, int , int ); //判定在x, y 所指位置是否可画编号为num 的图形， 若不可画则反回true 
	void ReDraw(int, int, int);  //为更新图形的位置清除图形 

	void Updata(); // 更新界面 
	void Pause();  //游戏暂停 
public:
	int rank;     //游戏难度等级 
	int point[2]; //两基点
private: 
	int top;  //最高点高度 
};

