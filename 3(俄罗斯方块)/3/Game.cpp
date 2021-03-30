#include "Game.h"

Game::Game()
{}

void Game::Welcome() //��ʼ���� 
{ 
	SetColor(1); 
	char x; 
	while(1) 
	{ 
		system("cls"); 
		cout<<"                                                                   ��������������������������������"<<endl; 
		cout<<"                                                                               ����˹����       " << endl; 
		cout<<"                                                                   ��������������������������������"<<endl; 
		cout<< "                                                                              ������ʽ��" << endl; 
		cout<< "                                                                            ��Up ���� ��ת" << endl;
		cout<< "                                                                          ��Down ���� ��������" << endl; 
		cout<< "                                                                          ��Left ���� ����" << endl; 
		cout<< "                                                                          ��Right ���� ����" << endl; 
		cout<< "                                                                             �ո� ���� ��ͣ" << endl; 
		cout<<"                                                                   ��������������������������������"<<endl; 
		cout<<"                                                                           �� ��1��4ѡ���Ѷȡ�" << endl; 
		Tools::SetPos(85, 11);        //����ؿ��ȼ�
		x = getchar(); 
		if(x <= '9' && x >= '0') 
		{ 
			rank = x - '0'; 
			break; 
		} 
	} 
} 

void Game::DrawMap() //����Ϸʱ���� 
{ 
	int i; 
	SetColor(5); 
	for(i = 0; i < 24; i++) //��24�� 
	{ 
		Tools::SetPos(i * 2, 0); 
		cout << "��";
		Tools::SetPos(i * 2, 26); 
		cout << "��"; 
	} 
	for(i = 0; i < 26; i++) //��26�� 
	{ 
		Tools::SetPos(0, i); 
		cout << "��"; 
		Tools::SetPos(28, i); 
		cout << "��"; 
		Tools::SetPos(46, i);
		cout << "��"; 
	} 
	for(i = 14; i < 24; i++)
	{ 
		Tools::SetPos(i * 2, 16); 
		cout << "��"; 
	} 
	type::Input_score();  // �롰�÷֡�������ɫһ��
	Tools::SetPos(30, 21); 
	cout << "�Ѷȵȼ�: " << rank; 
	Tools::SetPos(32, 2); 
	cout << "��һͼ��"; 
} 

void Game::Run() //������Ϸ 
{ 
	int next_id; 
	srand((int)time(0)); 
	id = rand() % 15; 
	next_id = rand() % 15; 
	Draw(point[0], point[1], id); 
	Draw(5, 16, next_id); 
	int count; 
	if(rank == 1) /////////////��Ϸ�Ѷȵȼ�
		count = 20; 
	else if(rank == 2) 
		count = 15; 
	else if(rank == 3)
		count = 10;
	else if(rank == 4)
		count = 5;
	int i = 0; //��ͬ�ȼ���Ӧ��ͬcount 
	while(1) 
	{ 
		if(!(i < count)) //i �� count ���ڿ���ʱ�� 
		{ 
			i = 0; 
			if(Judge(point[0] + 1, point[1], id)) //��ĳһλ�ò�������Ļ� 
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
					system("cls");    // ��ս���
					SetColor(1); 
					Tools::SetPos(20, 10);
					cout << "��Ϸ������" << endl; 
					Tools::SetPos(20, 11); 
					cout << "��ķ���Ϊ " << score << endl; 
					system("pause"); 
					exit(1); 
				} 
			} 
			else //�������� 
			{
				ReDraw(point[0], point[1], id); 
				point[0]++; 
				Draw(point[0], point[1], id); 
			} 
		} 

		//1��ʹ��getch��ȡ�ַ�ʱ����ȡһ�ξ���
        //2������ȡ������͹��ܼ��ǣ���Ҫ��ȡ����
        //   ��һ�εķ���ֵΪ0����224�����������
        //   getch�����ڶ�ȡһ�����ܼ����߼�ͷ�����򣩼���ʱ�������᷵�����Σ���һ�ε��÷���0����0xE0���ڶ��ε��÷���ʵ�ʵļ�ֵ��

		if(_kbhit()) //��������ֵʱ 
		{ 
			int key, key2; 
			key = _getch(); // ��getch()��������س�ȷ�ϵػ�ȡ�û�����
			if (key==224) 
			{ 
				key2 = _getch(); 
				if (key2 == 72) //������Up�����ʱ,��ת 
				{ 
					int temp = id; 
					Turn(id); 
					if(Judge(point[0], point[1], id)) 
						id = temp; 
					ReDraw(point[0], point[1], temp); 
					Draw(point[0], point[1], id); 
				} 
				if (key2== 80) //������Down�����ʱ������ 
				{ 
					if(!Judge(point[0] + 2, point[1], id)) 
					{
						ReDraw(point[0], point[1], id); 
						point[0] += 2; 
						Draw(point[0], point[1], id); 
					} 
				}
				else if (key2== 75) //������Left�����ʱ������ 
				{
					if(!Judge(point[0], point[1] - 1, id)) 
					{ 
						ReDraw(point[0], point[1], id); 
						point[1]--; 
						Draw(point[0], point[1], id); 
					} 
				} 
				else if (key2== 77) //������Right�����ʱ������ 
				{ 
					if(!Judge(point[0], point[1] + 1, id)) 
					{
						ReDraw(point[0], point[1], id); 
						point[1]++; Draw(point[0], point[1], id); 
					}
				} 
			}
			else if(key == 32) // ���¿ո���ͣ 
				Pause(); 
		} 
		Sleep(100); //�ȴ�1���� 
		i++; //���������� 
	} 
}

Game::~Game()
{}
