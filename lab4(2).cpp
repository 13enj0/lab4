#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

struct Student {
	string Name;
	int math, it, phisics;

};

void input(Student& student)
{
	cout << "Ім'я студента: ";
	cin >> student.Name;
	cout << "Математика: ";
	cin >> student.math;
	cout << "Інформатика: ";
	cin >> student.it;
	cout << "Фізика: ";
	cin >> student.phisics;
}

void output(Student& student)
{
	cout <<"\n\t" << student.Name << "\t" << student.math << "\t\t" << student.it << "\t\t" << student.phisics << endl;
	cout << "_______________________________________________________________________";
}

void outputfour(Student& student, int &n)
{

	if ( (student.it == 4 && student.math !=4 && student.phisics!=4) || (student.it != 4 && student.math == 4 && student.phisics != 4) || (student.it != 4 && student.math != 4 && student.phisics == 4))
	{
		cout << "\n\t" << student.Name << "\t" << student.math << "\t\t" << student.it << "\t\t" << student.phisics << endl;
		cout << "_______________________________________________________________________";
		++n;
	}
}

void outputfive(Student& student, int& n)
{

	if (student.it == 5)
	{
		cout << "\n\t" << student.Name << "\t" << student.math << "\t\t" << student.it << "\t\t" << student.phisics << endl;
		cout << "_______________________________________________________________________";
		++n;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	const int N = 2;
	Student student[N];

	for (int i = 0; i < N; i++)
	{
		cout << "Студент №: " << i + 1 << endl;
		input(student[i]);
	}

		cout << "\nНомер\tІм'я\tМатематика\tІнформатика\tФізика" << endl;
	for (int i = 0; i < N; i++)
	{
		output(student[i]);
		
	}
	int n = 0;
	cout << "\n\nТільки з однією четвіркою: \n";

	for (int i = 0; i < N; i++)
	{
		outputfour(student[i], n);
		
	}

	cout << "\n\nКількість - " << n;

	n = 0;
	cout << "\n\nВідмінно Інформатика: \n";

	for (int i = 0; i < N; i++)
	{
		outputfive(student[i], n);
		
	}

	cout << "\n\nКількість - " << n;

	return 0;

}