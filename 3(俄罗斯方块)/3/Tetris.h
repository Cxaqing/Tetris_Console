#pragma once
#include"type.h"

#include<ctime> 
#include<conio.h>  //����_kbhit()��_getch()

class Tetris :public type
{ 
public:
	Tetris(); ////���캯���� ��ʼ������ֵ 
	void Draw(int , int , int ); //��ͼ�� 
	bool Judge(int, int , int ); //�ж���x, y ��ָλ���Ƿ�ɻ����Ϊnum ��ͼ�Σ� �����ɻ��򷴻�true 
	void ReDraw(int, int, int);  //Ϊ����ͼ�ε�λ�����ͼ�� 

	void Updata(); // ���½��� 
	void Pause();  //��Ϸ��ͣ 
public:
	int rank;     //��Ϸ�Ѷȵȼ� 
	int point[2]; //������
private: 
	int top;  //��ߵ�߶� 
};

