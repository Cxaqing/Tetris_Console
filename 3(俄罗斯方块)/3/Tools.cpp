#include "Tools.h"

Tools::Tools()
{}

Tools::~Tools()
{}

void Tools::SetPos(int i, int j) //���ƹ��λ�ã����к��� 
{
	COORD pos={i,j}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
} 