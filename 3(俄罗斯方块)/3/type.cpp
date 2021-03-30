#include "type.h"

type::type()
{}

void type::SetColor(int color_num)          //设置颜色 
{
	int n; 
	switch(color_num)
	{ 
		case 0: 
			n = 0x08; //8-灰色(十进制)
			break; 
		case 1:
			n = 0x0E; //14-黄色
			break; 
		case 2:
			n = 0x0D; //13-紫色
			break; 
		case 3: 
			n = 0x0B; //11-蓝色
			break;
		case 4: 
			n = 0x0A; //10-绿色
			break;
		case 5: 
			n = 0x0C; //12-红色
			break;
		case 6: 
			n = 0x0F; //15-白色
			break;
	} 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);  //  句柄是windows头文件的内置函数
} 

void type::Turn(int num) //旋转函数 
{ 
	switch(num) 
	{ 
		case a1: 
			id = a2;break; //条形互换 
		case a2: 
			id = a1; break; 
		case b: 
			id = b; break; //方块无法旋转 
		case c1: 
			id = c2; break; //各种L形互换 
		case c2:
			id = c3; break; 
		case c3: 
			id = c4;break; 
		case c4:
			id = c1; break; 
		case d1: 
			id = d2; break; //各种T形互换 
		case d2: 
			id = d3; break; 
		case d3: 
			id = d4; break; 
		case d4: 
			id = d1; break; 
		case e1: 
			id = e2; break; //两种闪电形互换 
		case e2: 
			id = e1; break;
		case f1: 
			id = f2;break; 
		case f2: 
			id = f1; break; 
	} 
} 

void type::Input_score() 
{ 
	SetColor(6); 
	Tools::SetPos(30, 19); 
	cout << "得分: " << score; 
} 

type::~type()
{}
