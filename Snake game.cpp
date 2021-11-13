#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
#define cin std::cin >>
#define cout std::cout <<
bool gameOver;
const int width = 20;
const int height = 20;
int SeatsX[100], SeatsY[100];
char charr[13];
int CntSeats;
int x, y, score, peopleX, peopleY;
enum eDirections {STOP = 0, LEFT , RIGHT, UP, DOWN};
eDirections dir;
bool GameStarted = false;
bool OptionMenu = false;
int SpdUp = 3;
int speedOfGame ;
bool SpdRight = false;
bool SpdLeft = false;
int cntt = 16;
bool isBack = false, menuExist = true;


void setUp() {
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	peopleY = rand() % width;
	peopleX = rand() % height;
	score = 0;
}
void draw() {
	char spc = ' ', hash = '#';
	system("cls");
	for (size_t i = 0; i < width + 2; i++)
		cout hash;
	cout endl;
	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			if (j == 0) {
				cout hash;
			}
			if (i == y && j == x)
				cout "@";
			else if (i == peopleY && j == peopleX) {
				cout "F";
			}
			else {
				bool print = false;
				for (size_t k = 0; k < CntSeats; k++)
				{
					
					if (SeatsX[k] == j && SeatsY[k] == i)
					{
						cout 'o';
						print = true;
					}
					
					
				}if (!print)
				{
					cout spc;
				}
				
			}

			if (j == width - 1)
			{
				cout hash;
			}
		}
		cout endl;
	}
	for (size_t i = 0; i < width + 2; i++)
		cout hash;
	cout endl;
	cout "Your score is:" << score;
	
	
}
void MainMenu() {
	gameOver = true;
	isBack = true;
	system("cls");
	int hash = '#';
	int spc = ' ';
	int widthM = 40, heightM = 10;
	string s1(4, spc);
    OptionMenu = false;
    cout s1 << "#####" << "  " << "##   " << "   #####" << "  ##  ##"  << s1 << endl;
	cout s1 << "#   #" << "  " << "##   " << "   #   #" << "  ##  ##" << s1 << endl;
	cout s1 << "#####" << "  " << "##   " << "   #####" << "  ######" << s1 << endl;
	cout s1 << "#    " << "  " << "#####" << "   #   #" << "    ##  " << s1 << endl;
	cout s1 << "#    " << "  " << "#####" << "   #   #" << "    ##  " << s1 << endl;
	printf("\033[1;35m");
	printf("         Press 1 to play!\n");
	printf("\033[0m");
	cout endl;
	cout endl;
	printf("\033[1;35m");
	printf("       Press 2 for options\n");
	printf("\033[0m");
	int n;
	cin n;
	if (n == 1)
	{
		GameStarted = true;
		menuExist = false;
		OptionMenu = false;
		isBack = false;
		
	}
	if (n == 2) {
		OptionMenu = true;
			isBack = false;
			
	}
	


}
void Options() {
	int hash = '#';
	int spc = ' ';
	system("cls");
	int widthO = 40, heightO = 10;
	for (size_t i = 0; i < widthO; i++) cout "#";
	int n = 15;
	cout endl;
	string spcc(n, spc);
	cout "#" << spcc;
	n += 4;
	cout  "OPTIONS" << spcc << " #" << endl;
	string s(widthO - 2, spc);
	for (size_t i = 0; i < heightO - 2; i++) cout "#" << s << "#" << endl; 
	
	
	cout "#" << "   " << "Speed:Slow-";
	if (SpdUp > 8)
	{
		SpdUp = 7;
	}
	if (SpdUp <0)
	{
		SpdUp = 1;
	}
	for (size_t i = SpdUp + 1; i > 0; i--)cout "# ";
	
	
	if (SpdLeft == true && SpdUp > -1)
	{
		cntt += 2;
		SpdLeft = false;
	}
	if (SpdRight == true && SpdUp < 9)
	{
		cntt -= 2;
		SpdRight = false;
	}
	string sesec(cntt, spc);
	cout sesec << "#";
	cout endl;
	for (size_t i = 0; i < 4; i++)cout "#" << s << "#" << endl;
	int z = 8;
		string b(z, spc);
	cout "#" << b << "To go back press 'e' " << b << " #" << endl;
	for (size_t i = 0; i < 2; i++)cout "#" << s << "#" << endl;

	for (size_t i = 0; i < widthO ; i++) cout "#";
	
	
	speedOfGame = SpdUp * 10;
	
	 

}
void OptionsInput() {
	if (_kbhit())
	{
		switch (_getch()) {
		case 'c':
			SpdUp++;
			SpdRight = true;
			SpdLeft = false;
			break;
		case 'z':
			SpdUp--;
			SpdLeft = true;
			SpdRight = false;
			break;
		case 'e':
			isBack = true;
			OptionMenu = false;
			break;
		}
		

		
	}
}
void Input() {
	if (_kbhit())
	{
		switch (_getch()) {

		case 'a':
			dir = LEFT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}
void LogicShits() {
	int LastX = SeatsX[0];
	int LastY = SeatsY[0];
	int Last2X, Last2Y;
	SeatsX[0] = x;
	SeatsY[0] = y;
	for (int i = 1; i < CntSeats; i++)
	{
		Last2X = SeatsX[i];
		Last2Y = SeatsY[i];
		SeatsX[i] = LastX;
		SeatsY[i] = LastY;
		LastX = Last2X;
		LastY = Last2Y;
	}
	switch(dir){
	case STOP:
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
		
	case DOWN:
		y++;
		break;
		
	default:
		break;
	}
	if (x > width || x < 0 || y > height || y < 0)
		gameOver = true;
	for (size_t i = 0; i < CntSeats; i++)
	{
		if (SeatsX[i] == x && SeatsY[i] == y)
		{
			gameOver = true;
		}

	}
	if (x == peopleX && y == peopleY)
	{
		score += 10;
		peopleX = rand() % width;
		peopleY = rand() % height;
		CntSeats++;
	}
}
/*




*/
int main() {
	srand(time(NULL));
	MainMenu();
	while (menuExist == true) {
		if (OptionMenu == true)
		{
			while (OptionMenu == true)
			{
				Options();
				OptionsInput();
			}
			while (isBack == true)
			{
				MainMenu();
			}
		}
	}
	
	if (GameStarted == true)
	{
		setUp();
	}
	while (!gameOver)
	{
		draw();
		Input();
		LogicShits();
		Sleep(speedOfGame);
	}
}