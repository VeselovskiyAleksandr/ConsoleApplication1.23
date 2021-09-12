// ConsoleApplication1.23.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 20.Задача 3. Реализация симуляции игры "Рыбалка".

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string catchF, bite;
	int countFish=0, fishing=1;
	ifstream river("C:\\Users\\Александр\\Documents\\text for program\\river.txt");
    fstream basket("C:\\Users\\Александр\\Documents\\text for program\\basket.txt",ios::app);	
	if (river.is_open()) {
		cout << "\nThe file river is open.";
	}
	else {
		cout << "\nThe file river is not found.";;
	}
  if (basket.is_open()) {
		cout << "\nThe file basket is open.";
	}
	else {
		cout << "\nThe file basket is not found.";;
	}
  cout << "\nThe following types of fish are found in the river.";
  while (!river.eof()) {
	  river >> bite;
	  cout << "\n" << bite << " ";
  }
	  river.clear();
	  river.seekg(0);
  while(fishing != 0){
 river.seekg(0, ios::beg);
  cout << "\nSpecify the fish you are going to catch.\n";
  cin >> catchF;
  while (!river.eof()) {
	  river >> bite;
	  if (catchF == bite) {
		  basket << bite<<" ";
		  countFish++;	 
	  }
  }
  cout << "\nYou caught " << countFish << "  fish.";
  cout << "\nTo end fishing press 0.";
  cout << "\nTo continue fishing press any other number.";
  cin >> fishing;
  river.clear();
  } 
  river.close();
  basket.close();
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
