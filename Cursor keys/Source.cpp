#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursor;
	cursor.X = 0;
	cursor.Y = 0;
	cout << char(2);
	while (true)
	{
		int result = _getch();
		if (result == 224)
		{
			system("cls");
			result = _getch();
			switch (result)
			{
			case 72: // код клавиши UP
				cursor.Y--;
				break;
			case 75: // код клавиши LEFT
				cursor.X--;
				break;
			case 77: // код клавиши RIGHT
				cursor.X++;
				break;
			case 80: // код клавиши DOWN
				cursor.Y++;
				break;
			}
			SetConsoleCursorPosition(h, cursor);
			cout << char(2);
		}
	}

	return 0;
}