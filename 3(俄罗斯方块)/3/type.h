#pragma once
#include"Tools.h"

#include<string> 
#include<iostream> 
using namespace std; 

#define a1 0  //长条形 
#define a2 1 

#define b 2   // 方块

#define c1 3   //L形 
#define c2 4 
#define c3 5 
#define c4 6 

#define d1 7   //T形
#define d2 8 
#define d3 9 
#define d4 10

#define e1 11   //闪电1形 
#define e2 12 

#define f1 13   //闪电2形 
#define f2 14

class type
{
public:
	type();
	void SetColor(int color_num); //控制颜色 
	void Turn(int num);  //旋转 
	void Input_score();  //输出分数
	~type();
public:
	int score;  // 得分
	int id;     //图形ID
};

