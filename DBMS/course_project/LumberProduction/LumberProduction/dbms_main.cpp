#include "dbms_functions.h"

int state_menu_;

void Menu() {
    cout << "�������� ��������: " << endl
        << "(0) ����� �� ���������: " << endl
        << "(1) ���� ������: " << endl
        << "(2) ����� ������: " << endl
        << "(3) ��������� ������: " << endl
        << "(4) ���������� ������: " << endl
        << "(5) �������� ������: " << endl
        << "(6) ���������� ������: " << endl
        << "(7) ���������� ������: " << endl
        << "��� �����: ";
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
            cout << "������ ������ � ������ ��� ������� � �����?: ";
            cin >> actions_;
            system("cls");

            if (actions_ == 1)
            {
                LumberDataEntry(ld, size_); // ���� � ������
            }
            else
            {
               /* cout << "������� �������� �����: ";
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
                cout << "������ �����!" << endl;
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
                cout << "������ �����!" << endl;
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
                cout << "������ �����!" << endl;
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
                cout << "������ �����!" << endl;
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
                cout << "������ �����!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;

        case 7:
            system("cls");

            if (size_ != 0)
            {
                /* cout << "������� �������� �����: ";
                cin >> fileName;
                SaveLumberData(ld, size_, fileName);*/

                SaveLumberData(ld, size_, "Out.txt");
            }
            else
            {
                cout << "������ �����!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;

        default:
            cout << "����� ���� ������ �� �����!" << endl;
            system("cls");
            Menu();
            break;
        }
    }

    system("cls");
    cout << "������ ���������!" << endl;
    system("pause");

    return 0;
}