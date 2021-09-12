// ConsoleApplication1.23.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 20. Задача 1. Реализация записи в ведомость учёта.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ofstream file("C:\\Users\\Александр\\Documents\\text for program\\payment statement.txt", ios::app);
	string name, family, date, payouts;
	int month, input = 1;
	if (file.is_open()) {
		cout << "\nThe accounting statement is open for recording.";
	}
	else {
		cerr << "\nThe file is not found. ";
		return 1;
	}	
	cout << "\nEnter the name, family, payment amount and date sequentially.\n";
	while(input!=0){
	cin >> name >> family >> payouts;
	do {
		cin >> date;
		month = stoi(date.substr(3, 2));
		if (month < 1 || month>12) {
			cout << "\nEnter the correct date.";
		}
	} while (month < 1 || month> 12);
	file << name << " " << family << " " << payouts << " " << date << "\n";
	cout << "\nTo complete enter 0.";
	cout << "\nTo continue click any other number.";
	cin >> input;
}
	file.close();
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
