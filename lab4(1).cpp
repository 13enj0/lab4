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
	cout << "I�'�:  ";
	cin >> tovar.NAME;
	char change = 1;
	cout << "��������:\n 1 - ��������\n  2 - ʳ��������" << endl;
	while (true) {
		change = _getch();

		if (change == '1') {
			tovar.TYPE = "��.";
			break;
		}
		else if (change == '2') {
			tovar.TYPE = "��";
			break;
		}
	}
	cout << "����:  ";
	cin >> tovar.SORT;
	if (tovar.TYPE == "��.")cout << "�i���i���:  "; else if (tovar.TYPE == "��")cout << "���� ��.:  ";
	
	cin >> tovar.QUANTITY;
	cout << "����i��� ���:  ";
	cin >> tovar.COST;
}

void Print(TOVAR& tovar)
{
	
	if (tovar.TYPE == "��.")
	{
		
	cout << tovar.NAME << "\t\t" << tovar.SORT << "\t\t" << tovar.QUANTITY << "\t\t\t-\t\t\t" << tovar.COST << endl;
	}
	else if (tovar.TYPE == "��")
	{
		cout << tovar.NAME << "\t\t" << tovar.SORT << "\t\t-\t\t\t" << tovar.QUANTITY << "\t\t\t" << tovar.COST << endl;
	}
	
}



int main()
{
	SetConsoleCP(1251); // ������������ ��������� Windows-1251 �  ���� ��������
	SetConsoleOutputCP(1251); // ������������ ��������� Windows-1251 �  ���� ��������� 
	//��� ��������� ��������� � ������� ����� ���))
	int i = 0;
	float sum = 0;
	char change;
	TOVAR tovar1;
	vector<TOVAR> tovar;
	
	while (true) {
		cout << "\n1 - �������� �����\n2 - �������� ������\n";
		change = _getch();


		//���� 1 (���)
		if (change == '1') {
			tovar.push_back(tovar1);
			while(i < tovar.size()){
				system("cls");
				cout << "# " << i + 1 << endl;
				take_data(tovar[i]);
				++i;
			}
		}

		//���� 2 (����)
		if (change == '2') {
			system("cls");

			cout << "\n\n#\t��'� \t\t����\t\tʳ������ ��.\t\t���� � ��.\t\t������� ���" << endl;
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
			cout << "\n�������� ������:\t" << sum << endl;;


		}

		if (change == 'x')break;
	}
	return 0;
}