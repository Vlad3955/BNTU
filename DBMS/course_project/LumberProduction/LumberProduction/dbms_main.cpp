#include "dbms_functions.h"

int state_menu_;

void Menu() {
    cout << "Выберите действие: " << endl
        << "(0) Выход из программы: " << endl
        << "(1) Ввод данных: " << endl
        << "(2) Вывод данных: " << endl
        << "(3) Изменение данных: " << endl
        << "(4) Добавление данных: " << endl
        << "(5) Удаление данных: " << endl
        << "(6) Сортировка данных: " << endl
        << "(7) Сохранение данных: " << endl
        << "Ваш выбор: ";
    cin >> state_menu_;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    Menu();
    int actions_;
    string fileName;

    int size_ = 0;
    LumberData* ld = new LumberData[size_];

    while (state_menu_ != 0)
    {
        switch (state_menu_)
        {
        case 1:
            system("cls");
            cout << "Ввести данные в ручную или считать с файла?: ";
            cin >> actions_;
            system("cls");

            if (actions_ == 1)
            {
                LumberDataEntry(ld, size_); // ввод в ручную
            }
            else
            {
               /* cout << "Введите название файла: ";
                cin >> fileName;
                LumberDataReading(ld, size_, fileName);*/

                LumberDataReading(ld, size_, "Input.txt");
            }
            system("pause");
            system("cls");
            Menu();
            break;

        case 2:
            system("cls");

            if (size_ != 0)
            {
                Print(ld, size_);
                //ld->Print();
            }
            else
            {
                cout << "Данные пусты!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;

        case 3:
            system("cls");

            if (size_ != 0)
            {
                LumberDataChange(ld, size_);
            }
            else
            {
                cout << "Данные пусты!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;

        case 4:
            system("cls");

            if (size_ != 0)
            {
                AddLumberData(ld, size_);
            }
            else
            {
                cout << "Данные пусты!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;

        case 5:
            system("cls");

            if (size_ != 0)
            {
                DeleteLumberData(ld, size_);
            }
            else
            {
                cout << "Данные пусты!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;

        case 6:
            system("cls");

            if (size_ != 0)
            {
                SortingLumberData(ld, size_);
            }
            else
            {
                cout << "Данные пусты!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;

        case 7:
            system("cls");

            if (size_ != 0)
            {
                /* cout << "Введите название файла: ";
                cin >> fileName;
                SaveLumberData(ld, size_, fileName);*/

                SaveLumberData(ld, size_, "Out.txt");
            }
            else
            {
                cout << "Данные пусты!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;

        default:
            cout << "Пункт меню введен не верно!" << endl;
            system("cls");
            Menu();
            break;
        }
    }

    system("cls");
    cout << "Работа завершена!" << endl;
    system("pause");

    return 0;
}