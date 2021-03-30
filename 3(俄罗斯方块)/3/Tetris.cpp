#include "Tetris.h"

const int sharp[15][8]= //组成图形的各个点的各个坐标，先纵后横
{ 
	{0,0,1,0,2,0,3,0}, //长条形
	{0,0,0,1,0,2,0,3},
	{0,0,0,1,1,0,1,1}, // 方块
	{0,0,1,0,1,1,1,2}, //L形
	{0,1,1,1,2,0,2,1}, 
	{0,0,0,1,0,2,1,2},
	{0,0,0,1,1,0,2,0}, 
	{1,0,1,1,1,2,0,2},
	{0,0,0,1,1,1,2,1},
	{0,0,0,1,0,2,1,0},
	{0,0,1,0,2,0,2,1}, 
	{0,0,0,1,1,1,1,2}, //闪电
	{0,1,1,0,1,1,2,0}, 
	{0,1,0,2,1,0,1,1},
	{0,0,1,0,1,1,2,1} 
}; 

const int high[15]={4,1,2,2,3,2,3,2,3,2,3,2,3,2,3}; 
int map[28][16];

Tetris::Tetris() //构造函数， 初始化各个值 
{ 
	point[0] = 0; 
	point[1] = 5; 
	score = 0; 
	top = 25; 
} 

void Tetris::Draw(int x, int y, int num) //画图形 
{ 
	int nx, ny;
	for(int i = 0; i < 4; i++) 
	{ 
		nx = x + sharp[num][2 * i]; 
		ny = y + sharp[num][2 * i + 1];
		Tools::SetPos((ny + 1) * 2, nx + 1); 
		SetColor(i + 1); 
		cout << "■"; 
	} 
} 

void Tetris::Pause() // 暂停函数 
{ 
	Tools::SetPos(32, 10); 
	cout << "游戏暂停!" << endl; 
	Tools::SetPos(30, 11); 
	cout << "你的分数为 " << score; 
	char temp; 
	while(1) 
	{ 
		while(1) 
		{ 
			if(_kbhit()) 
			{ 
				temp = _getch(); 
				break; 
			} 
		} 
		if(temp == 32) 
			break; 
	} 
	Tools::SetPos(32, 10); // 清除暂停时显示的信息 
	cout << "         "; 
	Tools::SetPos(30, 11); 
	cout << "              ";
} 

void Tetris::Updata() //更新界面函数
{ 
	int i, flag; 
	int nx, ny;
	for(i = 0; i < 4; i++) 
	{
		nx = point[0] + sharp[id][i * 2]; 
		ny = point[1] + sharp[id][i * 2 + 1]; 
		Tools::SetPos((ny + 1) * 2, nx + 1); 
		SetColor(1);    //落下之后的颜色
		cout << "■"; 
		map[nx][ny] = 1; //界面各个点是否为空的更新 
	}
	if(point[0] < top) 
		top = point[0]; //最高点的更新
	for(i = point[0]; i < point[0] + high[id]; i++) //消除行 
	{ 
		flag = 1; 
		for(int j = 0; j < 13; j++) //判定某一行是否满， 用flag来标记 
			if(map[i][j] == 0) 
				flag = 0; 
		if(flag == 1) 
		{ 
			for(int k = i; k >= top; k--) 
			{ 
				for(int p = 0; p < 13; p++) 
				{ 
					map[k][p] = map[k - 1][p]; 
					Tools::SetPos((p + 1) * 2, k + 1); 
					if(map[k][p] == 1) 
						cout << "■"; 
					else 
						cout << "  ";
				} 
			} 
			score += 10; 
			Input_score(); 
		} 
	} 
} 

void Tetris::ReDraw(int x, int y, int num) //为更新图形的位置清除图形 
{ 
	int nx, ny; 
	for(int i = 0; i < 4; i++) 
	{
		nx = x + sharp[num][2 * i]; 
		ny = y + sharp[num][2 * i + 1];
		Tools::SetPos((ny + 1) * 2, nx + 1); 
		cout << "  "; 
	} 
} 

bool Tetris::Judge(int x, int y, int num) //判定在x, y 所指位置是否可画编号为 
{                                         //num 的图形， 若不可画则反回true 
	int nx, ny; 
	for(int i = 0; i < 4; i++) 
	{
		nx = x + sharp[num][2 * i]; 
		ny = y + sharp[num][2 * i + 1]; 
		if(!(nx < 25 && nx >= 0 && ny < 13 && ny >= 0 && !map[nx][ny])) 
			return true;
	} 
	return false;
} 
