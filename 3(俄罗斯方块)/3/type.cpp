#include "type.h"

type::type()
{}

void type::SetColor(int color_num)          //������ɫ 
{
	int n; 
	switch(color_num)
	{ 
		case 0: 
			n = 0x08; //8-��ɫ(ʮ����)
			break; 
		case 1:
			n = 0x0E; //14-��ɫ
			break; 
		case 2:
			n = 0x0D; //13-��ɫ
			break; 
		case 3: 
			n = 0x0B; //11-��ɫ
			break;
		case 4: 
			n = 0x0A; //10-��ɫ
			break;
		case 5: 
			n = 0x0C; //12-��ɫ
			break;
		case 6: 
			n = 0x0F; //15-��ɫ
			break;
	} 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);  //  �����windowsͷ�ļ������ú���
} 

void type::Turn(int num) //��ת���� 
{ 
	switch(num) 
	{ 
		case a1: 
			id = a2;break; //���λ��� 
		case a2: 
			id = a1; break; 
		case b: 
			id = b; break; //�����޷���ת 
		case c1: 
			id = c2; break; //����L�λ��� 
		case c2:
			id = c3; break; 
		case c3: 
			id = c4;break; 
		case c4:
			id = c1; break; 
		case d1: 
			id = d2; break; //����T�λ��� 
		case d2: 
			id = d3; break; 
		case d3: 
			id = d4; break; 
		case d4: 
			id = d1; break; 
		case e1: 
			id = e2; break; //���������λ��� 
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
	cout << "�÷�: " << score; 
} 

type::~type()
{}
