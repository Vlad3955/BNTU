#include "dbms_functions.h"

void LumberDataEntry(LumberData* (&ld), int& n)
{
    Product product_;
    RawMaterial raw_material_;
    Sale sale_;
    Supplier supplier_;
    DeferredSale deferred_sale_;

    cout << "������� ������ �������: ";
    cin >> n;

    ld = new LumberData[n];

    for (int i = 0; i < n; i++)
    {
        cout << "������ ����� ������ �������� ��������, ��� ����� � ����������: ";
        cin >> product_.name >> product_.type.name >> product_.quantity;

        cout << "������ ����� ������ �������� ����� � ����������: ";
        cin >> raw_material_.name >> raw_material_.quantity;

        cout << "������ ����� ������ �������� ��������� ��������, ��� �����, ���� � ����������: ";
        cin >> sale_.product.name >> sale_.product.type.name >> sale_.sale_date >> sale_.quantity_sold;

        cout << "������ �������� ����������: ";
        cin >> supplier_.name;
        cout << "������ ���������� ������� ������������� ������ ������ �����������: ";
        cin >> supplier_.num_of_pos;
        cout << "������ ������������ " << supplier_.name << " ��������: " << endl;
        for (int i = 0; i < supplier_.num_of_pos; i++)
        {
            RawMaterial rm;
            cout << "������� �������� ��������� ������������ "  << supplier_.name << ": ";
            cin >> rm.name;
            cout << "������� ���������� ��������� ������������ " << supplier_.name << ": ";
            cin >> rm.quantity;
            supplier_.materials.push_back(rm);
        }
        //while (true) {
        //    cout << "������� �������� ��������� ��� 'q' ��� ������: ";
        //    getline(cin, input);
        //    if (input == "q") break; // ���������� ����� ��� ����� 'q'

        //    
        //    RawMaterial rm;
        //    rm.name = input;

        //    cout << "������� ����������: ";
        //    cin >> rm.quantity;
        //    cin.ignore(); // ������� ������ ����� �� ������� ����� ������

        //    supplier_.materials.push_back(rm);
        //}
        
        cout << "������ ����� ������ �������� �������� ��������� �������, ��� �����, ����, ���������� � �������: ";
        cin >> deferred_sale_.sale.product.name >> deferred_sale_.sale.product.type.name 
            >> deferred_sale_.sale.sale_date >> deferred_sale_.sale.quantity_sold 
            >> deferred_sale_.reason;
        ld[i].LumberDataEntry(product_, raw_material_, sale_, supplier_, deferred_sale_);

        cout << "____________________________________________________________________\n";
    }
}

void LumberDataReading(LumberData* (&ld), int& n, string filename)
{
    ifstream reading(filename);

    if (reading)
    {
        Product product_;
        RawMaterial raw_material_;
        Sale sale_;
        Supplier supplier_;
        DeferredSale deferred_sale_;

        reading >> n;

        ld = new LumberData[n];

        for (int i = 0; i < n; i++)
        {
            reading >> product_.name >> product_.type.name >> product_.quantity;
            reading >> raw_material_.name >> raw_material_.quantity;
            reading >> sale_.product.name >> sale_.product.type.name >> sale_.sale_date >> sale_.quantity_sold;
            reading >> supplier_.name;
            reading >> supplier_.num_of_pos;
            for (int i = 0; i < supplier_.num_of_pos; i++)
            {
                RawMaterial rm;
                reading >> rm.name;
                reading >> rm.quantity;
                supplier_.materials.push_back(rm);
            }
            reading >> deferred_sale_.sale.product.name >> deferred_sale_.sale.product.type.name
                    >> deferred_sale_.sale.sale_date >> deferred_sale_.sale.quantity_sold
                    >> deferred_sale_.reason;
            ld[i].LumberDataEntry(product_, raw_material_, sale_, supplier_, deferred_sale_);
        }

        cout << "������ �������!" << endl;
    
    }
    else
    {
        cout << "������ �������� �����!" << endl;
    }

    reading.close();
}

void Print(LumberData* ld, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "������ �" << i + 1 << endl;

        ld[i].Print();
        cout << "_______________________________________________________\n";
    }
}

void LumberDataChange(LumberData* ld, int n)
{
    Product product_;
    RawMaterial raw_material_;
    Sale sale_;
    Supplier supplier_;
    DeferredSale deferred_sale_;
    int _n;

    cout << "������� ����� ������� �������� (�� 1 �� " << n << "): ";
    cin >> _n;
    _n--;
}
