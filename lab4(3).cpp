#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <Windows.h>
#include <conio.h>

using namespace std;

// Структура для зберігання інформації про конспекти
struct Konsp {
    char n_dys[100]; // назва дисципліни
    char napr[100]; // напрям (технічна, математична або гуманітарна)
    char lektor[100]; // відомості про лектора
    int k_stor; // кількість сторінок
};

// Функція для побайтового додавання вмісту файлу до контрольної суми
int get_checksum(char* filename) {
    int checksum = 0;
    ifstream file(filename, ios::binary);
    char ch;
    while (file.get(ch)) {
        checksum += (int)ch;
    }
    file.close();
    return checksum;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Konsp konsp[100]; // масив для зберігання конспектів
    int n = 0; // кількість конспектів
    char filename[100] = "catalog.txt"; // ім'я файлу з каталогом
    ofstream catalog(filename); // створення файлу з каталогом
    if (!catalog) {
        cout << "Помилка створення файлу з каталогом!" << endl;
        return 1;
    }

    // Заповнення масиву конспектів
    cout << "Введіть дані про конспекти. Для завершення введення введіть 'stop'." << endl;
    while (true) {
        cout << "Назва дисципліни: ";
        cin.getline(konsp[n].n_dys, 100);
        if (strcmp(konsp[n].n_dys, "stop") == 0) break;
        cout << "Напрям: ";
        cin.getline(konsp[n].napr, 100);
        cout << "Відомості про лектора: ";
        cin.getline(konsp[n].lektor, 100);
        cout << "Кількість сторінок: ";
        cin >> konsp[n].k_stor;
        cin.get();
        n++;
    }

    // Виведення каталогу на екран і запис у файл
    cout << endl << "Каталог:" << endl;
    catalog << "Каталог:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << konsp[i].n_dys << ", " << konsp[i].napr << ", " << konsp[i].lektor << ", " << konsp[i].k_stor << " стор." << endl;
        catalog << i + 1 << ". " << konsp[i].n_dys << ", " << konsp[i].napr << "Контрольна сума: " << get_checksum(konsp[i].n_dys) << endl << endl;
    }


    catalog << "Контрольна сума каталогу: " << get_checksum(filename) << endl;
    catalog.close();

    cout << "Каталог збережено у файл " << filename << endl;
    return 0;
}