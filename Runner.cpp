#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <cstring>

using namespace std;

void Start();
void GetResults();
void Gst();

const char dis[]={"��Ҫ��ʾ:�벻Ҫ����Ϸ����������������������������,Υ�ߺ���Ը�!"};
int i, j, life, maxrand;
char c;
float xp=0;

void Start() {
	i = 0;
	j = 0;
	life = 0;
	maxrand = 6;
	cout << "����:" << xp << endl;
	cout << "ѡ���Ѷȵȼ�:\n";
	cout << "1 : Peaceful (0-15)\n";
	cout << "2 : Easy (0-30)\n";
	cout << "3 : General (0-50)\n";
	cout << "4 : Difficult (0-100)\n";
	cout << "5 : Nether (0-250)\n";
	cout << "6 : The End (0-500)\n"; 
	cout << "7 : Ender Dragon (0-1000)\n";
	cout << "8 : Wither (0-2000)\n";
	cout << "9 : ����ģʽ (0-5000)\n";
	cout << "c : ����\n";
	cout << "���������˳�\n";
	c = 30;

	cin >> c;
	cout << "\n";

	switch (c) {
		case '1':
			life=4; 
			maxrand = 15;
			break;
		case '2':
			life=4;
			maxrand = 30;
			break;
		case '3':
			life=5;
			maxrand = 50;
			break;
		case '4':
			life=6;
			maxrand = 100;
			break;
		case '5':
			life=7;
			maxrand = 250;
			break;
		case '6':
			life=8;
			maxrand = 500;
			break;
		case '7':
			life=9;
			maxrand = 1000;
			break;
		case '8':
			life=10;
			maxrand = 2000;
			break;
		case '9':
			maxrand = 5000;
			break;
		case 'c':
			system("cls");
			Start();
			break;
		default:
			exit(0);
	}
	srand((unsigned)time(NULL));
	j = rand() % maxrand;
	if(c=='9')
	  Gst();
	else
	  GetResults();
}

void Gst(){
	system("color 09");
	cout << "����������:\n";
	cin >> i;
	
	if((i>maxrand) || (i<0)) {
		cout << "������ֲ��ܵ���1�ͳ���" << maxrand;
		Gst();
	}

	if(i == j) {
		cout << "��Ӯ��!!\n";
		cout << "��ʹ���� " << life << "������ֵ!\n";
		system("color a0");
		Sleep(1000);
		system("color 07");
		life++;
		if(life<=5) xp+=1.5;
		else if(life<=10) xp+=1;
		else if(life<=20) xp+=0.5;
		else xp+=0.2;
 		Start();
 	
	}
	if(life>500)
 	{
 		cout<<"�����쳣:Abnormal input.����3����˳�!\n";
 		system("color c7");
 		Sleep(3000);
 		exit(0);
	}
	else if(i>j) {
		cout << "���˵��.\n";
		life = life + 1;
		cout << "��������ֵ: " << life << "\n\n";
		Gst();
	} else if(i<j) {
		cout << "С�˵��.\n";
		life = life + 1;
		cout << "��������ֵ: " << life << "\n\n";
		Gst();
	}
}

void GetResults() {
	if (life <= 0) {
		cout<<"������!\n";
		system("color c7");
		Sleep(500);
		system("color 07");
		Sleep(100);
		system("color c7");
		Sleep(500);
		system("color 07");
		cout << "�����������\n";
		getch();
		Start();
	}

	cout << "����������:\n";
	cin >> i;
	
	if((i>maxrand) || (i<0)) {
		cout << "������ֲ��ܵ���1�ͳ���" << maxrand;
		Gst();
	}

	if(i == j) {
		cout << "��Ӯ��!!\n\n";
		system("color a0");
		Sleep(1000);
		system("color 07");
		switch (c) {
		case '1':
			xp+=0.1;
			break;
		case '2':
			xp+=0.2;
			break;
		case '3':
			xp+=0.3;
			break;
		case '4':
			xp+=0.4;
			break;
		case '5':
			xp+=0.5;
			break;
		case '6':
			xp+=0.6;
			break;
		case '7':
			xp+=0.7;
			break;
		case '8':
			xp+=0.8;
			break;
		}
		Start();
	} else if(i>j) {
		cout << "���˵��.\n";
		life = life - 1;
		cout << "ʣ������ֵ: " << life << "\n\n";
		GetResults();
	} else if(i<j) {
		cout << "С�˵��.\n";
		life = life - 1;
		cout << "ʣ������ֵ: " << life << "\n\n";
		GetResults();
	}
}

int main() {
	int n=0;
	for(int j=0;j<=strlen(dis);j++)
	{
		cout<<dis[j];
		if(n%2==0)
		{
			system("color 0c");
		}
		else
		{
			system("color 0a");
		}
		n++;
		Sleep(50);
	}
	cout<<endl;
	system("color 07");
	Start();
	return 0;
}
