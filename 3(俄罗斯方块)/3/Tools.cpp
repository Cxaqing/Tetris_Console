#include "Tools.h"

Tools::Tools()
{}

Tools::~Tools()
{}

void Tools::SetPos(int i, int j) //控制光标位置，先列后行 
{
	COORD pos={i,j}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
} 