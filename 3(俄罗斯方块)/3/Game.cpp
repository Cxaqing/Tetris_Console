#include "Game.h"

Game::Game()
{}

void Game::Welcome() //开始界面 
{ 
	SetColor(1); 
	char x; 
	while(1) 
	{ 
		system("cls"); 
		cout<<"                                                                   ■■■■■■■■■■■■■■■■"<<endl; 
		cout<<"                                                                               俄罗斯方块       " << endl; 
		cout<<"                                                                   ■■■■■■■■■■■■■■■■"<<endl; 
		cout<< "                                                                              操作方式：" << endl; 
		cout<< "                                                                            ↑Up —— 旋转" << endl;
		cout<< "                                                                          ↓Down —— 加速下移" << endl; 
		cout<< "                                                                          ←Left —— 左移" << endl; 
		cout<< "                                                                          →Right —— 右移" << endl; 
		cout<< "                                                                             空格 —— 暂停" << endl; 
		cout<<"                                                                   ■■■■■■■■■■■■■■■■"<<endl; 
		cout<<"                                                                           ■ 按1—4选择难度■" << endl; 
		Tools::SetPos(85, 11);        //输入关卡等级
		x = getchar(); 
		if(x <= '9' && x >= '0') 
		{ 
			rank = x - '0'; 
			break; 
		} 
	} 
} 

void Game::DrawMap() //画游戏时界面 
{ 
	int i; 
	SetColor(5); 
	for(i = 0; i < 24; i++) //宽24格 
	{ 
		Tools::SetPos(i * 2, 0); 
		cout << "▓";
		Tools::SetPos(i * 2, 26); 
		cout << "▓"; 
	} 
	for(i = 0; i < 26; i++) //高26格 
	{ 
		Tools::SetPos(0, i); 
		cout << "▓"; 
		Tools::SetPos(28, i); 
		cout << "▓"; 
		Tools::SetPos(46, i);
		cout << "▓"; 
	} 
	for(i = 14; i < 24; i++)
	{ 
		Tools::SetPos(i * 2, 16); 
		cout << "▓"; 
	} 
	type::Input_score();  // 与“得分”字体颜色一样
	Tools::SetPos(30, 21); 
	cout << "难度等级: " << rank; 
	Tools::SetPos(32, 2); 
	cout << "下一图形"; 
} 

void Game::Run() //运行游戏 
{ 
	int next_id; 
	srand((int)time(0)); 
	id = rand() % 15; 
	next_id = rand() % 15; 
	Draw(point[0], point[1], id); 
	Draw(5, 16, next_id); 
	int count; 
	if(rank == 1) /////////////游戏难度等级
		count = 20; 
	else if(rank == 2) 
		count = 15; 
	else if(rank == 3)
		count = 10;
	else if(rank == 4)
		count = 5;
	int i = 0; //不同等级对应不同count 
	while(1) 
	{ 
		if(!(i < count)) //i 与 count 用于控制时间 
		{ 
			i = 0; 
			if(Judge(point[0] + 1, point[1], id)) //在某一位置不能下落的话 
			{ 
				Updata(); 
				id = next_id; 
				ReDraw(5, 16, next_id); 
				next_id = rand() % 15; 
				point[0] = 0; 
				point[1] = 5; 
				Draw(point[0], point[1], id); 
				Draw(5, 16, next_id); 
				if(Judge(point[0] , point[1], id)) 
				{
					system("cls");    // 清空界面
					SetColor(1); 
					Tools::SetPos(20, 10);
					cout << "游戏结束！" << endl; 
					Tools::SetPos(20, 11); 
					cout << "你的分数为 " << score << endl; 
					system("pause"); 
					exit(1); 
				} 
			} 
			else //继续下落 
			{
				ReDraw(point[0], point[1], id); 
				point[0]++; 
				Draw(point[0], point[1], id); 
			} 
		} 

		//1、使用getch读取字符时，读取一次就行
        //2、而读取方向键和功能键是，需要读取两次
        //   第一次的返回值为0或者224（方向键））
        //   getch函数在读取一个功能键或者箭头（方向）键盘时，函数会返回两次，第一次调用返回0或者0xE0，第二次调用返回实际的键值。

		if(_kbhit()) //键盘输入值时 
		{ 
			int key, key2; 
			key = _getch(); // 用getch()函数无需回车确认地获取用户输入
			if (key==224) 
			{ 
				key2 = _getch(); 
				if (key2 == 72) //按向上Up方向键时,旋转 
				{ 
					int temp = id; 
					Turn(id); 
					if(Judge(point[0], point[1], id)) 
						id = temp; 
					ReDraw(point[0], point[1], temp); 
					Draw(point[0], point[1], id); 
				} 
				if (key2== 80) //按向下Down方向键时，加速 
				{ 
					if(!Judge(point[0] + 2, point[1], id)) 
					{
						ReDraw(point[0], point[1], id); 
						point[0] += 2; 
						Draw(point[0], point[1], id); 
					} 
				}
				else if (key2== 75) //按向左Left方向键时，左移 
				{
					if(!Judge(point[0], point[1] - 1, id)) 
					{ 
						ReDraw(point[0], point[1], id); 
						point[1]--; 
						Draw(point[0], point[1], id); 
					} 
				} 
				else if (key2== 77) //按向右Right方向键时，右移 
				{ 
					if(!Judge(point[0], point[1] + 1, id)) 
					{
						ReDraw(point[0], point[1], id); 
						point[1]++; Draw(point[0], point[1], id); 
					}
				} 
			}
			else if(key == 32) // 按下空格暂停 
				Pause(); 
		} 
		Sleep(100); //等待1毫秒 
		i++; //控制下落间隔 
	} 
}

Game::~Game()
{}
