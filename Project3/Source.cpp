#include<iostream>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <cstring>
#include <ctime>
#include <windows.h>
#include <mmsystem.h>
using namespace std;
//global variables
int timer = clock(), moves = 15;
int score = 0;
//function prototyping

void check2(char array[10][10]);//function to check in hard mode if there are any consuetive candies in either row or col

void random2();//function to generate random values for hard mode

void check(char array[8][8]);//function to check in easy mode if there are any consuetive candies in either row or col

void grid1(char a[8][8]);//function to c reate grid for easy mode

char again_generate(char ch);//function to again generate the candies

void random();// function to generate random candies for easy mode

void movement(char array[][8]);//function for cursor movement in easy mode

void movement2(char array[][10]);//function for cursor movement in hard mode

void swapping(int& i, int& j, char array[8][8], int& moves);//function for swapping in easy mode

void move_cursor_to_xy(int row, int col);//cursor movement function

void crush(char array[][8], int i, int j);//function to crush the candies in easy mode

void crush2(char array[][10], int i, int j);//function to crush candies in hard mode

void grid2(char a[10][10]);//grid for hard mode

void swapping2(int& i, int& j, char array[10][10], int& moves);//swapping for hard mode

void SaveScore(char name[20]); //to store the scores

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//Arroe keys defination
#define KEY_UP 75 
#define KEY_DOWN 77
#define KEY_LEFT 72
#define KEY_RIGHT 80
#define ENTER 32

//This function will randomly generate the candies for easy mode and will call a function to check if there's any consuetive candy on three or more blocks

void random() {
	char array[8][8];
	/*srand(time(0));*/
	int x;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			x = rand() % 5 + 1;
			switch (x)
			{
			case 1:
				array[i][j] = '#';
				break;
			case 2:
				array[i][j] = '*';
				break;
			case 3:
				array[i][j] = '&';
				break;
			case 4:
				array[i][j] = '%';
				break;
			case 5:
				array[i][j] = '@';
				break;
			}

		}

	}
	check(array);

}
//This function will randomly generate the candies for easy mode and will call a function to check if there's any consuetive candy on three or more blocks
void random2() {

	char array[10][10];
	//srand(time(0));
	int x;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			x = rand() % 6 + 1;
			switch (x)
			{
			case 1:
				array[i][j] = '#';
				break;
			case 2:
				array[i][j] = '*';
				break;
			case 3:
				array[i][j] = '&';
				break;
			case 4:
				array[i][j] = '%';
				break;
			case 5:
				array[i][j] = '@';
				break;
			case 6:
				array[i][j] = '!';
				break;
			case 7:
				array[i][j] = '^';
				break;
			}

		}

	}
	check2(array);

}

// This function will check for easy mode if there's any same candy on conseuctive blocks and will call the other function to again randomly generate the candy
void check(char array[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((array[i][j] == array[i - 1][j] && array[i][j] == array[i + 1][j]) || (array[i][j] == array[i - 2][j] && array[i][j] == array[i + 2][j]))
				array[i][j] = again_generate(array[i][j]);
			if ((array[i][j] == array[i][j - 1] && array[i][j] == array[i][j + 1]) || (array[i][j] == array[i][j - 2] && array[i][j] == array[i][j + 2]))
				array[i][j] = again_generate(array[i][j]);
		}
	}
	grid1(array);
}

// This function will check for hard mode if there's any same candy on conseuctive blocks and will call the other function to again randomly generate the candy
void check2(char array[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ((array[i][j] == array[i - 1][j] && array[i][j] == array[i + 1][j]) || (array[i][j] == array[i - 2][j] && array[i][j] == array[i + 2][j]))
				array[i][j] = again_generate(array[i][j]);
			if ((array[i][j] == array[i][j - 1] && array[i][j] == array[i][j + 1]) || (array[i][j] == array[i][j - 2] && array[i][j] == array[i][j + 2]))
				array[i][j] = again_generate(array[i][j]);
		}
	}
	grid2(array);
}


//this function will again generate a candy for consuective blocks
char again_generate(char ch)
{
	bool flag = true;
	int n;
	n = rand() % 5;
	char c = ch;
	while (flag == true)
	{
		switch (n)
		{
		case 1:
			ch = '#';
			break;
		case 2:
			ch = '*';
			break;
		case 3:
			ch = '&';
			break;
		case 4:
			ch = '%';
			break;
		case 5:
			ch = '@';
			break;
		}
		if (ch == c)
			n = rand() % 5;
		else
			flag = false;
	}
	return ch;
}
//this function is for easy mode switchment between the blocks 
void movement(char array[][8])
{
	int i = 1, j = 0;
	move_cursor_to_xy(i, j);
	moves = 15;
	char c;
	clock_t clockVariable;
	clockVariable = clock();
	clockVariable = clock() - clockVariable;
	c = _getch();
	while (1 && clockVariable < 60)
	{

		if (j != 0 && c == KEY_UP)
		{
			j = j - 4;
			move_cursor_to_xy(j, i);
		}
		else if (j != 28 && c == KEY_DOWN)
		{
			j = j + 4;
			move_cursor_to_xy(j, i);
		}
		else if (i != 0 && c == KEY_LEFT)
		{
			i = i - 1;
			move_cursor_to_xy(j, i);
		}
		else if (i != 8 && c == KEY_RIGHT)
		{
			i = i + 1;
			move_cursor_to_xy(j, i);
		}
		else if (c == ENTER)
		{

			swapping(i, j, array, moves);
			grid1(array);
		}
		c = _getch();

	}
	if (clockVariable >= 60)
		cout << "times up";

}

//this function is for hard mode switchment between the blocks 

void movement2(char array[][10])
{
	int i = 1, j = 0;
	move_cursor_to_xy(i, j);
	moves = 15;
	char c;
	clock_t clockVariable;
	clockVariable = clock();
	clockVariable = clock() - clockVariable;
	c = _getch();
	while (1 && clockVariable < 60)
	{

		if (j != 0 && c == KEY_UP)
		{
			j = j - 4;
			move_cursor_to_xy(j, i);
		}
		else if (j != 36 && c == KEY_DOWN)
		{
			j = j + 4;
			move_cursor_to_xy(j, i);
		}
		else if (i != 0 && c == KEY_LEFT)
		{
			i = i - 1;
			move_cursor_to_xy(j, i);
		}
		else if (i != 10 && c == KEY_RIGHT)
		{
			i = i + 1;
			move_cursor_to_xy(j, i);
		}
		else if (c == ENTER)
		{

			swapping2(i, j, array, moves);
			grid2(array);
		}
		c = _getch();

	}
	if (clockVariable >= 60)
		cout << "times up";

}

//this function will make the grid for easy mode
void grid1(char a[8][8])
{

	SetConsoleTextAttribute(hConsole, 7);
	cout << "_______________________________\n";
	for (int i = 0; i < 8; i++)
	{

		for (int j = 0; j < 8; j++)
		{
			if (a[i][j] == '#')
				SetConsoleTextAttribute(hConsole, 4);
			else if (a[i][j] == '*')
				SetConsoleTextAttribute(hConsole, 5);
			else if (a[i][j] == '&')
				SetConsoleTextAttribute(hConsole, 6);
			else if (a[i][j] == '%')
				SetConsoleTextAttribute(hConsole, 7);
			else if (a[i][j] == '@')
				SetConsoleTextAttribute(hConsole, 9);
			cout << a[i][j];
			SetConsoleTextAttribute(hConsole, 7);
			cout << " | ";
		}
		cout << endl;
	}
	cout << "_______________________________\n";
	SetConsoleTextAttribute(hConsole, 7);

	movement(a);


}
//this function will make the grid for hard mode
void grid2(char a[10][10])
{

	SetConsoleTextAttribute(hConsole, 7);
	cout << "_______________________________________\n";
	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 10; j++)
		{
			if (a[i][j] == '#')
			{
				SetConsoleTextAttribute(hConsole, 4);
				cout << a[i][j];
			}
			else if (a[i][j] == '*')
			{
				SetConsoleTextAttribute(hConsole, 5);
				cout << a[i][j];
			}
			else if (a[i][j] == '&')
			{
				SetConsoleTextAttribute(hConsole, 6);
				cout << a[i][j];
			}
			else if (a[i][j] == '%')
			{
				SetConsoleTextAttribute(hConsole, 7);
				cout << a[i][j];
			}
			else if (a[i][j] == '@')
			{
				SetConsoleTextAttribute(hConsole, 9);
				cout << a[i][j];
			}

			else if (a[i][j] == '!')
			{
				SetConsoleTextAttribute(hConsole, 10);
				cout << a[i][j];
			}
			else if (a[i][j] == '^')
			{
				SetConsoleTextAttribute(hConsole, 11);
				cout << a[i][j];
			}
			SetConsoleTextAttribute(hConsole, 7);
			cout << " | ";
		}
		cout << endl;
	}
	cout << "_______________________________________\n";
	SetConsoleTextAttribute(hConsole, 7);

	movement2(a);


}


//for swapping the candies in easy mode
void swapping(int& i, int& j, char array[8][8], int& moves)
{
	char temp;
	char c;
	c = _getch();
	if (c == KEY_LEFT) {

		//if (j != 0) 
		{
			//system("cls");
			temp = array[i][j];
			array[i][j] = array[i][j - 1];
			array[i][j - 1] = temp;
			cout << timer;
			grid1(array);
			moves--;
		}

	}
	else if (c == KEY_RIGHT) {

		//if (j != 8) 
		{
			//system("cls");
			temp = array[i][j];
			array[i][j] = array[i][j + 1];
			array[i][j + 1] = temp;
			cout << timer;
			grid1(array);
			moves--;
		}

	}
	else if (c == KEY_UP) {

		//if (i != 0)
		{
			//system("cls");
			temp = array[i][j];
			array[i][j] = array[i - 1][j];
			array[i - 1][j] = temp;
			grid1(array);
			moves--;
		}

	}
	else if (c == KEY_DOWN) {

		//if (i != 8)
		{
			//system("cls");
			temp = array[i][j];
			array[i][j] = array[i + 1][j];
			array[i + 1][j] = temp;
			grid1(array);
			moves--;
		}

	}
	system("cls");

	crush(array, i, j);
	grid1(array);
}

//for swapping in hard mode

void swapping2(int& i, int& j, char array[][10], int& moves)
{
	char temp;
	char c;
	c = _getch();
	if (c == KEY_LEFT) {

		//if (j != 0) 
		{
			//system("cls");
			temp = array[i][j];
			array[i][j] = array[i][j - 1];
			array[i][j - 1] = temp;
			grid2(array);
			moves--;
		}

	}
	else if (c == KEY_RIGHT) {

		//if (j != 8) 
		{
			//system("cls");
			temp = array[i][j];
			array[i][j] = array[i][j + 1];
			array[i][j + 1] = temp;
			grid2(array);
			moves--;
		}

	}
	else if (c == KEY_UP) {

		//if (i != 0)
		{
			//system("cls");
			temp = array[i][j];
			array[i][j] = array[i - 1][j];
			array[i - 1][j] = temp;
			grid2(array);
			moves--;
		}

	}
	else if (c == KEY_DOWN) {

		//if (i != 8)
		{
			//system("cls");
			temp = array[i][j];
			array[i][j] = array[i + 1][j];
			array[i + 1][j] = temp;
			grid2(array);
			moves--;
		}

	}
	system("cls");

	crush2(array, i, j);
	grid2(array);
}

//cursor movement
void move_cursor_to_xy(int row, int col)
{

	static HANDLE h = NULL;
	if (!h) {
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	COORD cordinates;
	cordinates.X = row;
	cordinates.Y = col;
	SetConsoleCursorPosition(h, cordinates);
}

//to crush the candies and add up in the score in easy mode
void crush(char array[][8], int i, int j)
{
	
	if ((array[i][j] == array[i - 1][j] && array[i][j] == array[i + 1][j]) || (array[i][j] == array[i + 1][j] && array[i][j] == array[i + 2][j]) || (array[i][j] == array[i - 1][j] && array[i][j] == array[i - 2][j]))
		score = score + 10;

	else if ((array[i][j] == array[i][j - 1] && array[i][j] == array[i][j + 1]) || (array[i][j] == array[i][j + 1] && array[i][j] == array[i][j + 2]) || (array[i][j] == array[i][j - 1] && array[i][j] == array[i][j - 2]))
		score = score + 10;
}
//to crush the candies and add up in the score in hard mode
void crush2(char array[][10], int i, int j)
{
	int score = 0;
	if ((array[i][j] == array[i - 1][j] && array[i][j] == array[i + 1][j]) || (array[i][j] == array[i + 1][j] && array[i][j] == array[i + 2][j]) || (array[i][j] == array[i - 1][j] && array[i][j] == array[i - 2][j]))
		score = score + 10;

	else if ((array[i][j] == array[i][j - 1] && array[i][j] == array[i][j + 1]) || (array[i][j] == array[i][j + 1] && array[i][j] == array[i][j + 2]) || (array[i][j] == array[i][j - 1] && array[i][j] == array[i][j - 2]))
		score = score + 10;
}

void SaveScore(char name[20]) //save score
{
	ofstream Database;
	Database.open("test2.txt");
	Database << score <<name<< "\n";


	Database.seekp(0, std::ios::end); //to ensure the put pointer is at the end
	Database.close();
}


int main()
{
	bool gameover = false;
	int gametime;
	char c = ENTER;
	char mode;
	char name[20];
	gametime = clock() / 1000;
	timer = clock() / 1000 - gametime;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "\n                                  WELCOME TO CANDY CRUSH               \n\n";
	SetConsoleTextAttribute(hConsole, 3);
	cout << " THIS GAME IS CREATED BY \"AYMAN cHAUDRY\" and \"KASHMALA AHMAD\"";
	SetConsoleTextAttribute(hConsole, 8);
	cout << "\n\n INSTRUCTIONS:\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	cout << "\t1: Click on the arrow keys for the movement.\n\t2.Swap the candies to make the match.\n\t3.Slect the mode which you want to play\n\n";
	cout << "ENTER 'E' FOR EASY MODE AND 'H' FOR HARD MODE";
	cin >> mode;
	SetConsoleTextAttribute(hConsole, 4);
	cout << "ENTER YOUR First-Name  \n";
	cin >> name;

	if (mode == 'e' || mode == 'E')
	{
		while (moves > 0 && !gameover)
		{

			system("cls");
			random();
			if (timer >= 60)
				gameover = true;

			timer = clock() / 1000 - gametime;
		}
		cout << timer;
	}

	else if (mode == 'H' || mode == 'h')
	{
		while (moves > 0 && !gameover)
		{
			system("cls");
			random2();
			if (timer >= 40)
				gameover = true;

			timer = clock() / 1000 - gametime;
		}
	}
	SaveScore(name);
	system("pause");
}