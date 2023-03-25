#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
using namespace std;

struct TOVAR
{

	string NAME;
	string TYPE;
	string SORT;
	int QUANTITY;
	float COST;
};

void take_data(TOVAR &tovar)
{
	cout << "Iм'я:  ";
	cin >> tovar.NAME;
	char change = 1;
	cout << "Натисніть:\n 1 - Поштучно\n  2 - Кілограмах" << endl;
	while (true) {
		change = _getch();

		if (change == '1') {
			tovar.TYPE = "ШТ.";
			break;
		}
		else if (change == '2') {
			tovar.TYPE = "Кг";
			break;
		}
	}
	cout << "Сорт:  ";
	cin >> tovar.SORT;
	if (tovar.TYPE == "ШТ.")cout << "Кiлькiсть:  "; else if (tovar.TYPE == "Кг")cout << "Вага Кг.:  ";
	
	cin >> tovar.QUANTITY;
	cout << "Вартiсть грн:  ";
	cin >> tovar.COST;
}

void Print(TOVAR& tovar)
{
	
	if (tovar.TYPE == "ШТ.")
	{
		
	cout << tovar.NAME << "\t\t" << tovar.SORT << "\t\t" << tovar.QUANTITY << "\t\t\t-\t\t\t" << tovar.COST << endl;
	}
	else if (tovar.TYPE == "Кг")
	{
		cout << tovar.NAME << "\t\t" << tovar.SORT << "\t\t-\t\t\t" << tovar.QUANTITY << "\t\t\t" << tovar.COST << endl;
	}
	
}



int main()
{
	SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
	SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення 
	//для коректним виведення в консоль тільки так))
	int i = 0;
	float sum = 0;
	char change;
	TOVAR tovar1;
	vector<TOVAR> tovar;
	
	while (true) {
		cout << "\n1 - Добавить товар\n2 - Показати список\n";
		change = _getch();


		//Якщо 1 (ввід)
		if (change == '1') {
			tovar.push_back(tovar1);
			while(i < tovar.size()){
				system("cls");
				cout << "# " << i + 1 << endl;
				take_data(tovar[i]);
				++i;
			}
		}

		//Якщо 2 (Вивід)
		if (change == '2') {
			system("cls");

			cout << "\n\n#\tІм'я \t\tСорт\t\tКількість ШТ.\t\tВага в Кг.\t\tВартість грн" << endl;
			if (tovar.size() == 0)
			{
				cout << "-\n";
				
			}
			for (int i = 0; i < tovar.size(); i++)
			{
				sum += tovar[i].COST;
				cout << "________________________________________________________________________________________________________________" << endl;
				cout << i + 1 << "\t";
				Print(tovar[i]);
			}
			cout << "________________________________________________________________________________________________________________" << endl;
			cout << "\nЗагальна вартіст:\t" << sum << endl;;


		}

		if (change == 'x')break;
	}
	return 0;
}