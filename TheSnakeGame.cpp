#include<iostream>
#include<fstream>
#include<conio.h>
#include<windows.h>

using namespace std;

bool iflose;

const int width = 80;

const int height = 40;

int x, y, foodX, foodY, nonfoodX, nonfoodY, point, highpoint, sv = '0';

char *snake;

char gametable[width][height];

void setup() {
	iflose = false;

	x = width / 2;

	y = height / 2;

	foodX = rand() % width;

	foodY = rand() % height;

	nonfoodX = rand() % width;

	nonfoodY = (rand() % height) + 1;

	point = 0;

	snake = &gametable[x][y];

	*snake = sv;
}
void show() {
	for (int j = 0; j < height; j++) {

		for (int i = 0; i < width; i++) {
			cout << gametable[i][j];
		}
		cout << endl;
	}
}
void Draw() {

	system("cls");

	for (int j = 0; j < height; j++)
		for (int i = 0; i < width; i++) {

			if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
				gametable[i][j] = '*';
			else
				gametable[i][j] = ' ';
			if (i == x && j == y)
				gametable[i][j] = sv;
			else if (i == foodX && j == foodY)
				gametable[i][j] = '$';
			else if (i == nonfoodX && j == nonfoodY)
				gametable[i][j] = '&';
		}


	show();


}

void Move() {
		
	char d;

	d = _getch();
	

	switch (d)

	{

	case 'a':

		*snake = ' ';
		x--;

		break;

	case 'd':

		*snake = ' ';
		x++;

		break;

	case 'w':
		*snake = ' ';
		y--;
		break;

	case 's':

		*snake = ' ';
		y++;
		break;

	}
	snake = &gametable[x][y];
	*snake = sv;
}
void Points() {

	if (x > width - 2 || x < 1 || y > height - 2 || y < 1)

		iflose = true;

	if (x == foodX && y == foodY)

	{
		point += rand() % height;

		foodX = rand() % width;

		foodY = rand() % height;

		sv++;

	}
	if (x == nonfoodX && y == nonfoodY)

	{

		point -= rand() % height;

		nonfoodX = rand() % width;

		nonfoodY = rand() % height;

		sv--;

	}

}

int main() {

	setup();

	while (!iflose)

	{

		Draw();

		Move();

		Points();

		Sleep(80);

	}

	if (point > highpoint) {
		highpoint = point;
		ofstream outFile;

		outFile.open("Score.txt", ios::out);

		outFile << highpoint;

		outFile.close();
	}
	ifstream inFile;
	inFile.open("Score.txt", ios::in);
	inFile >> highpoint;

	inFile.close();

	cout << "Your point is: " << point << endl << "High point is: " << highpoint;

	system("PAUSE");

}