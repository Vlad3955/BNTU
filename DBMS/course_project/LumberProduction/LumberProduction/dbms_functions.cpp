#include "dbms_functions.h"

void LumberDataEntry(LumberData* (&ld), int& n)
{
    Product product_;
    RawMaterial raw_material_;
    Sale sale_;
    Supplier supplier_;
    DeferredSale deferred_sale_;

    cout << "Введите размер массива: ";
    cin >> n;

    ld = new LumberData[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Ведите через пробел название продукта, тип сырья и количество: ";
        cin >> product_.name >> product_.type.name >> product_.quantity;

        cout << "Ведите через пробел название сырья и количество: ";
        cin >> raw_material_.name >> raw_material_.quantity;

        cout << "Ведите через пробел название проданого продукта, тип сырья, дату и количество: ";
        cin >> sale_.product.name >> sale_.product.type.name >> sale_.sale_date >> sale_.quantity_sold;

        cout << "Ведите название поставщика: ";
        cin >> supplier_.name;
        cout << "Ведите количество позиций поставляемого товара данным поставщиком: ";
        cin >> supplier_.num_of_pos;
        cout << "Ведите поставляемый " << supplier_.name << " материал: " << endl;
        for (int i = 0; i < supplier_.num_of_pos; i++)
        {
            RawMaterial rm;
            cout << "Введите название материала поставляемый "  << supplier_.name << ": ";
            cin >> rm.name;
            cout << "Введите количество материала поставляемый " << supplier_.name << ": ";
            cin >> rm.quantity;
            supplier_.materials.push_back(rm);
        }
        //while (true) {
        //    cout << "Введите название материала или 'q' для выхода: ";
        //    getline(cin, input);
        //    if (input == "q") break; // Прерывание цикла при вводе 'q'

        //    
        //    RawMaterial rm;
        //    rm.name = input;

        //    cout << "Введите количество: ";
        //    cin >> rm.quantity;
        //    cin.ignore(); // Очистка буфера ввода от символа новой строки

        //    supplier_.materials.push_back(rm);
        //}
        
        cout << "Ведите через пробел название продукта отложеной продажи, тип сырья, дата, количество и причина: ";
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

        cout << "Данные считаны!" << endl;
    
    }
    else
    {
        cout << "Ошибка открытия файла!" << endl;
    }

    reading.close();
}

void Print(LumberData* ld, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Данные №" << i + 1 << endl;

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

    cout << "Выедите номер нужного элемента (от 1 до " << n << "): ";
    cin >> _n;
    _n--;
}
