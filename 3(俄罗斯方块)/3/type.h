#pragma once
#include"Tools.h"

#include<string> 
#include<iostream> 
using namespace std; 

#define a1 0  //������ 
#define a2 1 

#define b 2   // ����

#define c1 3   //L�� 
#define c2 4 
#define c3 5 
#define c4 6 

#define d1 7   //T��
#define d2 8 
#define d3 9 
#define d4 10

#define e1 11   //����1�� 
#define e2 12 

#define f1 13   //����2�� 
#define f2 14

class type
{
public:
	type();
	void SetColor(int color_num); //������ɫ 
	void Turn(int num);  //��ת 
	void Input_score();  //�������
	~type();
public:
	int score;  // �÷�
	int id;     //ͼ��ID
};

