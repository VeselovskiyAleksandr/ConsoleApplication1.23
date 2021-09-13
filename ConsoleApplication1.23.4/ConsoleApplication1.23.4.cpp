// ConsoleApplication1.23.4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 20. Задача 4. Реализация симуляции банкомата.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int factorial(int x) {
	int fact=1;
	if (x == 0) {
		fact = 1;
	}
	else if (x > 0) {
		fact = factorial(x - 1) * x;
	}
	return fact;
}

int main()
{
	int banknotes[7][2], denBank=100, amount=0, sum=0;
	char sign=1;
	string nominalValue, amountValue, str="RUB";
  fstream ATM_mashing("C:\\Users\\Александр\\Documents\\text for program\\ATM mashing.txt", ios::app);
  if (ATM_mashing.is_open()) {
	  cout << "\nThe file is found. \n";
  }
  else {
	  cerr << "\nThe file is not found. ";
	  return 1;
  }
  srand(time(nullptr));
  cout << "\nTo fill the ATM with a cash collector click C";
  cout << "\nElse if click M.";
  cin >> sign;
  if (sign=='C') {
	  do {
		  for (int i = 0; i < 3; i++) {
			  banknotes[i][0] = factorial(i) * i * denBank + 100;
			  banknotes[i][1] = rand() % 101+120;
			  sum += banknotes[i][1];
			  banknotes[i + 3][0] = (factorial(i) * i * denBank + 100) * 10;
			  banknotes[i + 3][1] = rand() % 101+120;
			  sum += banknotes[i + 3][1];
		  } 
		 if(sum>1000){
			  banknotes[5][1] -= (sum - 1000);
			  sum -= (sum - 1000);
		  }
	  } while ((sum<1000)||(banknotes[5][1]<0));
  }
       //Вводим номиналы банкнот.
      //Заполняем банкомат купюрами.
  else {
	  do {
		  for (int i = 0; i < 3; i++) {
			  banknotes[i][0] = factorial(i) * i * denBank + 100;
			  banknotes[i][1] = rand() % 301;
			  sum += banknotes[i][1];
			  banknotes[i + 3][0] = (factorial(i) * i * denBank + 100) * 10;
			  banknotes[i + 3][1] = rand() % 151;
			  sum += banknotes[i + 3][1];
		  }
	  } while (sum > 1000);
  }
  for (int i = 0; i < 6; i++) {
	  ATM_mashing << "\n" << banknotes[i][0] << " " << "RUB" << " " << banknotes[i][1];
  }
  cout << "\nTo view the contents of the ATM_mashing click 0.";
  cout << "\nTo withdraw or deposit cash click any other number.";
  cin >> sign;
  while (sign !='0') {
	  cout << "\nTo deposit cash click -, to withdraw cash, clic +";
	  cin >> sign;
	  if (sign == '-') {
		  cout << "\nSpecify the denomination of the banknotes.";
		  cin >> denBank;
		  cout << "\nSpecify the required amount.";
		  cin >> amount;
		  for (int i = 0; i < 6; i++) {
			  if ((banknotes[i][0] == denBank) && (banknotes[i][1] >= amount)) {
				  cout << "\nTake your money.";
				  banknotes[i][1] -= amount;
				  ATM_mashing << "\n" << banknotes[i][0] << " " << "RUB" << " " << banknotes[i][1];
				  sum -= amount;
				  break;
			  }
			  else if ((banknotes[i][0] == denBank) && (banknotes[i][1] < amount)) {
				  cout << "\nThe specified amount cannot be temporarily issued.";
				  break;
			  }
		  }
	  }
	  else  if (sign == '+') {
		  cout << "\nSpecify the denomination of the banknotes.";
		  cin >> denBank;
		  cout << "\nSpecify the amount to be deposited.";
		  cin >> amount;
		  for (int i = 0; i < 6; i++) {
			  if ((banknotes[i][0] == denBank) && (sum + amount <= 1000)) {
				  banknotes[i][1] += amount;
				  sum += amount;
				  cout << "\nYour money is credited to the account.";
				  ATM_mashing << "\n" << banknotes[i][0] << " " << "RUB" << " " << banknotes[i][1];
				  break;
			  }
			  else if ((banknotes[i][0] == denBank) && (sum + amount > 1000)) {
				  cout << "\nThe specified amount cannot be temporarily issued.";
				  break;
			  }
		  }
	  } 
	  cout << "\nTo complete enter 0.";
	  cout << "\nTo continue click any other number.";
	  cin >> sign;
  }
  ATM_mashing.clear();
  ATM_mashing.seekg(0);
  cout << "\nTo view the contents of the ATM_mashing click V.";
  cin >> sign;
  if (sign == 'V') {
	 ifstream ATM_mashing("C:\\Users\\Александр\\Documents\\text for program\\ATM mashing.txt");
	  while (!ATM_mashing.eof()) {
		  ATM_mashing >> nominalValue>>str >> amountValue;
		  cout << "\n" << nominalValue << " "<<str<<" " << amountValue;
	  }	
	  cout << "\ntotal number of  banknotes: " << sum;
  }
		  ATM_mashing.close();
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
