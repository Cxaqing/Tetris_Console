#include "Tetris.h"

const int sharp[15][8]= //���ͼ�εĸ�����ĸ������꣬���ݺ��
{ 
	{0,0,1,0,2,0,3,0}, //������
	{0,0,0,1,0,2,0,3},
	{0,0,0,1,1,0,1,1}, // ����
	{0,0,1,0,1,1,1,2}, //L��
	{0,1,1,1,2,0,2,1}, 
	{0,0,0,1,0,2,1,2},
	{0,0,0,1,1,0,2,0}, 
	{1,0,1,1,1,2,0,2},
	{0,0,0,1,1,1,2,1},
	{0,0,0,1,0,2,1,0},
	{0,0,1,0,2,0,2,1}, 
	{0,0,0,1,1,1,1,2}, //����
	{0,1,1,0,1,1,2,0}, 
	{0,1,0,2,1,0,1,1},
	{0,0,1,0,1,1,2,1} 
}; 

const int high[15]={4,1,2,2,3,2,3,2,3,2,3,2,3,2,3}; 
int map[28][16];

Tetris::Tetris() //���캯���� ��ʼ������ֵ 
{ 
	point[0] = 0; 
	point[1] = 5; 
	score = 0; 
	top = 25; 
} 

void Tetris::Draw(int x, int y, int num) //��ͼ�� 
{ 
	int nx, ny;
	for(int i = 0; i < 4; i++) 
	{ 
		nx = x + sharp[num][2 * i]; 
		ny = y + sharp[num][2 * i + 1];
		Tools::SetPos((ny + 1) * 2, nx + 1); 
		SetColor(i + 1); 
		cout << "��"; 
	} 
} 

void Tetris::Pause() // ��ͣ���� 
{ 
	Tools::SetPos(32, 10); 
	cout << "��Ϸ��ͣ!" << endl; 
	Tools::SetPos(30, 11); 
	cout << "��ķ���Ϊ " << score; 
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
	Tools::SetPos(32, 10); // �����ͣʱ��ʾ����Ϣ 
	cout << "         "; 
	Tools::SetPos(30, 11); 
	cout << "              ";
} 

void Tetris::Updata() //���½��溯��
{ 
	int i, flag; 
	int nx, ny;
	for(i = 0; i < 4; i++) 
	{
		nx = point[0] + sharp[id][i * 2]; 
		ny = point[1] + sharp[id][i * 2 + 1]; 
		Tools::SetPos((ny + 1) * 2, nx + 1); 
		SetColor(1);    //����֮�����ɫ
		cout << "��"; 
		map[nx][ny] = 1; //����������Ƿ�Ϊ�յĸ��� 
	}
	if(point[0] < top) 
		top = point[0]; //��ߵ�ĸ���
	for(i = point[0]; i < point[0] + high[id]; i++) //������ 
	{ 
		flag = 1; 
		for(int j = 0; j < 13; j++) //�ж�ĳһ���Ƿ����� ��flag����� 
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
						cout << "��"; 
					else 
						cout << "  ";
				} 
			} 
			score += 10; 
			Input_score(); 
		} 
	} 
} 

void Tetris::ReDraw(int x, int y, int num) //Ϊ����ͼ�ε�λ�����ͼ�� 
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

bool Tetris::Judge(int x, int y, int num) //�ж���x, y ��ָλ���Ƿ�ɻ����Ϊ 
{                                         //num ��ͼ�Σ� �����ɻ��򷴻�true 
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
