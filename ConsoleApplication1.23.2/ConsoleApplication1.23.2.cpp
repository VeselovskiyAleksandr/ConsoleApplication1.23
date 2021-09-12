// ConsoleApplication1.23.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 20. Задача 2. Реализация рисования случайных картин.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	const int max_x = 95, max_y = 601;
	int x, y, picture[max_x][max_y];
	ofstream file("C:\\Users\\Александр\\Documents\\text for program\\picture.txt");
	if (file.is_open()) {
		cout << "\nThe file is open for recording.";
	}
	else {
		cerr << "\nThe file is not found. ";
		return 1;
	}
	srand(time(nullptr));
	cout << "\nSet the image size X x Y.\n";
	do{
	cin >> x >> y;
	if (x<1 || x>max_x || y<1 || y>max_y) {
		cout << "\nSpecify the correct image size.";
	  }
	}while (x<1 || x>max_x || y<1 || y>max_y);
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			picture[i][j] = rand() % 2;
		}
	}
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			file << picture[i][j];
			if (j == x - 1) {
				file << "\n";
			}
		}
	}
		return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
