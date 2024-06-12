#include "dbms_functions.h"
#define _CRT_SECURE_NO_WARNINGS

time_t StringToDate(const std::string& dateStr) {
    std::tm tm = {};
    std::istringstream ss(dateStr);
    ss >> std::get_time(&tm, "%d-%m-%Y");
    return mktime(&tm);
}

std::string DateToString(time_t date) {
    std::tm tm;
    gmtime_s(&tm, &date); // ������������� gmtime_s
    char buffer[80];
    strftime(buffer, 80, "%d-%m-%Y", &tm);
    return std::string(buffer);
}

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
        string date;
        cout << "������ ����� ������ �������� ��������, ��� ����� � ����������: ";
        cin >> product_.name >> product_.type.name >> product_.quantity;

        cout << "������ ����� ������ �������� ����� � ����������: ";
        cin >> raw_material_.name >> raw_material_.quantity;

        cout << "������ ����� ������ �������� ��������� ��������, ��� �����, ���� � ����������: ";
        //cin >> sale_.product.name >> sale_.product.type.name >> sale_.sale_date >> sale_.quantity_sold;
        cin >> sale_.product.name >> sale_.product.type.name >> date >> sale_.quantity_sold;
        sale_.sale_date = StringToDate(date);

        cout << "������ �������� ����������: ";
        cin >> supplier_.name;
        cout << "������ ���������� ������� ������������� ������ ������ �����������: ";
        cin >> supplier_.num_of_pos;
        supplier_.materials.clear();
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
            //>> deferred_sale_.sale.sale_date >> deferred_sale_.sale.quantity_sold 
            >> date >> deferred_sale_.sale.quantity_sold
            >> deferred_sale_.reason;
        deferred_sale_.sale.sale_date = StringToDate(date);
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
            string date;
            reading >> product_.name >> product_.type.name >> product_.quantity;
            reading >> raw_material_.name >> raw_material_.quantity;
            //reading >> sale_.product.name >> sale_.product.type.name >> sale_.sale_date >> sale_.quantity_sold;
            reading >> sale_.product.name >> sale_.product.type.name >> date >> sale_.quantity_sold;
            sale_.sale_date = StringToDate(date);
            reading >> supplier_.name;
            reading >> supplier_.num_of_pos;
            supplier_.materials.clear();
            for (int i = 0; i < supplier_.num_of_pos; i++)
            {
                RawMaterial rm;
                reading >> rm.name;
                reading >> rm.quantity;
                supplier_.materials.push_back(rm);
            }
            reading >> deferred_sale_.sale.product.name >> deferred_sale_.sale.product.type.name
                    //>> deferred_sale_.sale.sale_date >> deferred_sale_.sale.quantity_sold
                    >> date >> deferred_sale_.sale.quantity_sold
                    >> deferred_sale_.reason;
            deferred_sale_.sale.sale_date = StringToDate(date);
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

    if (_n >= 0 && _n < n)
    {
        cout << "������� ����� ������ ����� �������� ��������, ��� ����� � ����������: ";
        cin >> product_.name >> product_.type.name >> product_.quantity;

        cout << "������ ����� ������ ����� �������� ����� � ����������: ";
        cin >> raw_material_.name >> raw_material_.quantity;

        cout << "������ ����� ������ �������� ��������� ��������, ��� �����, ���� � ����������: ";
        cin >> sale_.product.name >> sale_.product.type.name >> sale_.sale_date >> sale_.quantity_sold;

        cout << "������ ����� �������� ����������: ";
        cin >> supplier_.name;
        cout << "������ ���������� ������� ������������� ������ ������ �����������: ";
        cin >> supplier_.num_of_pos;
        supplier_.materials.clear();
        ld[_n].GetSupplier().materials.clear();
        cout << "������ ������������ " << supplier_.name << " ��������: " << endl;
        for (int i = 0; i < supplier_.num_of_pos; i++)
        {
            RawMaterial rm;
            cout << "������� �������� ��������� ������������ " << supplier_.name << ": ";
            cin >> rm.name;
            cout << "������� ���������� ��������� ������������ " << supplier_.name << ": ";
            cin >> rm.quantity;
            supplier_.materials.push_back(rm);
        }

        cout << "������ ����� ������ ����� �������� �������� ��������� �������, ��� �����, ����, ���������� � �������: ";
        cin >> deferred_sale_.sale.product.name >> deferred_sale_.sale.product.type.name
            >> deferred_sale_.sale.sale_date >> deferred_sale_.sale.quantity_sold
            >> deferred_sale_.reason;
        ld[_n].LumberDataEntry(product_, raw_material_, sale_, supplier_, deferred_sale_);
    }
    else
    {
        cout << "����� ������ �� �����!" << endl;
    }
}

void Copy(LumberData* d_n, LumberData* d_o, int n)
{
    for (int i = 0; i < n; i++)
    {
        d_n[i] = d_o[i];
    }
}

void AddLumberData(LumberData* (&ld), int& n)
{
    Product product_;
    RawMaterial raw_material_;
    Sale sale_;
    Supplier supplier_;
    DeferredSale deferred_sale_;
    LumberData* buf = new LumberData[n];
    int size = n, new_size = ++n;

    Copy(buf, ld, size);

    ld = new LumberData[new_size];

    Copy(ld, buf, size);

    cout << "������� ����� ������ ����� �������� ��������, ��� ����� � ����������: ";
    cin >> product_.name >> product_.type.name >> product_.quantity;

    cout << "������ ����� ������ ����� �������� ����� � ����������: ";
    cin >> raw_material_.name >> raw_material_.quantity;

    cout << "������ ����� ������ �������� ��������� ��������, ��� �����, ���� � ����������: ";
    cin >> sale_.product.name >> sale_.product.type.name >> sale_.sale_date >> sale_.quantity_sold;

    cout << "������ ����� �������� ����������: ";
    cin >> supplier_.name;
    cout << "������ ���������� ������� ������������� ������ ������ �����������: ";
    cin >> supplier_.num_of_pos;
    supplier_.materials.clear();
    cout << "������ ������������ " << supplier_.name << " ��������: " << endl;
    for (int i = 0; i < supplier_.num_of_pos; i++)
    {
        RawMaterial rm;
        cout << "������� �������� ��������� ������������ " << supplier_.name << ": ";
        cin >> rm.name;
        cout << "������� ���������� ��������� ������������ " << supplier_.name << ": ";
        cin >> rm.quantity;
        supplier_.materials.push_back(rm);
    }

    cout << "������ ����� ������ ����� �������� �������� ��������� �������, ��� �����, ����, ���������� � �������: ";
    cin >> deferred_sale_.sale.product.name >> deferred_sale_.sale.product.type.name
        >> deferred_sale_.sale.sale_date >> deferred_sale_.sale.quantity_sold
        >> deferred_sale_.reason;
    ld[size].LumberDataEntry(product_, raw_material_, sale_, supplier_, deferred_sale_);

    cout << "������ ���������!" << endl;

    delete[] buf;
}

void DeleteLumberData(LumberData* (&ld), int& n)
{
    int _n;
    LumberData* buf = new LumberData[n];
    cout << "������� ����� ������� �������� (�� 1 �� " << n << "): ";
    cin >> _n;
    _n--;

    if (_n >= 0 && _n < n)
    {
        Copy(buf, ld, n);
        int q = 0;
        n--;

        ld = new LumberData[n];

        for (int i = 0; i <= n; i++)
        {
            if (i != _n)
            {
                ld[q] = buf[i];
                q++;
            }
        }

        cout << "������ �������!" << endl;
    }
    else
    {
        cout << "����� ������ �� �����!" << endl;
    }

    delete[] buf;
}

void SortingLumberData(LumberData* ld, int n)
{
    LumberData buf;
    int numOfSorted = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ld[i].GetProduct().name > ld[j].GetProduct().name)
            {/*
                buf = ld[i];
                ld[i].GetSupplier().materials.clear();
                ld[i] = ld[j];
                ld[j].GetSupplier().materials.clear();
                ld[j] = buf;*/
                
                // Variant 2
                Supplier tempSupplierI = ld[i].GetSupplier();
                Supplier tempSupplierJ = ld[j].GetSupplier();

                buf = ld[i];
                ld[i].GetSupplier().materials.clear();
                ld[i] = ld[j];
                ld[i].GetSupplier().materials = tempSupplierJ.materials;

                ld[j].GetSupplier().materials.clear();
                ld[j] = buf;
                ld[j].GetSupplier().materials = tempSupplierI.materials;

                numOfSorted++;
            } 
        }
    }

    cout << "������ �������������!\n���������� ����������: " << numOfSorted << endl;
}

void SaveLumberData(LumberData* ld, int n, string filename)
{
    ofstream record(filename);

    if (record)
    {
        record << n << endl;

        for (int i = 0; i < n; i++)
        {
            record << ld[i].GetProduct().name << " " << ld[i].GetProduct().type.name << " " << ld[i].GetProduct().quantity << endl;
            record << ld[i].GetRawMaterial().name << " " << ld[i].GetRawMaterial().quantity << endl;
            //record << ld[i].GetSale().product.name << " " << ld[i].GetSale().product.type.name << " " << ld[i].GetSale().sale_date << " " << ld[i].GetSale().quantity_sold << endl;
            record << ld[i].GetSale().product.name << " " << ld[i].GetSale().product.type.name << " " << DateToString(ld[i].GetSale().sale_date) << " " << ld[i].GetSale().quantity_sold << endl;
            record << ld[i].GetSupplier().name << endl;
            record << ld[i].GetSupplier().num_of_pos << endl;
            for (auto & it : ld[i].GetSupplier().materials)
            {
                record << it.name << " " << it.quantity << endl;
            }
            record << ld[i].GetDeferredSale().sale.product.name << " " << ld[i].GetDeferredSale().sale.product.type.name << " "
                //<< ld[i].GetDeferredSale().sale.sale_date << " " << ld[i].GetDeferredSale().sale.quantity_sold << " "
                << DateToString(ld[i].GetDeferredSale().sale.sale_date) << " " << ld[i].GetDeferredSale().sale.quantity_sold << " "
                << ld[i].GetDeferredSale().reason;

            if (i < n -1)
            {
                record << endl;
            }
        }
    }
    else
    {
        cout << "������ �������� �����!" << endl;
    }

    cout << "������ ��������� � ����!" << endl;

    record.close();
}


