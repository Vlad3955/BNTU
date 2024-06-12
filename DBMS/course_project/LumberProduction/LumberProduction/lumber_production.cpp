#include "lumber_production.h"
#define _CRT_SECURE_NO_WARNINGS

LumberData::LumberData()
{
    product_.name = "";
    //product_.wood_type = "";
    product_.type.name = "";
    product_.quantity = 0;

    raw_material_.name = "";
    raw_material_.quantity = 0;

    sale_.product.name = "";
    //sale_.product.wood_type = "";
    sale_.product.type.name = "";
    sale_.product.quantity = 0;
    sale_.sale_date = 0;
    sale_.quantity_sold = 0;

    supplier_.name = "";
    supplier_.num_of_pos = 0;
    deferred_sale_.sale.product.name = "";
    //deferred_sale_.sale.product.wood_type = "";
    deferred_sale_.sale.product.type.name = "";
    deferred_sale_.sale.product.quantity = 0;
    deferred_sale_.sale.sale_date = 0;
    deferred_sale_.sale.quantity_sold = 0;
    deferred_sale_.reason = "";
}

LumberData::LumberData(Product product, RawMaterial raw_material, Sale sale, Supplier supplier,
    DeferredSale deferred_sale)
{
    product_.name = product.name;
    //product_.wood_type = product.wood_type;
    product_.type.name = product.type.name;
    product_.quantity = product.quantity;

    raw_material_.name = raw_material.name;
    raw_material_.quantity = raw_material.quantity;

    sale_.product.name = sale.product.name;
    //sale_.product.wood_type = sale.product.wood_type;
    sale_.product.type.name = sale.product.type.name;
    sale_.product.quantity = sale.product.quantity;
    sale_.sale_date = sale.sale_date;
    sale_.quantity_sold = sale.quantity_sold;

    supplier_.name = supplier.name;
    supplier_.num_of_pos = supplier.num_of_pos;

    deferred_sale_.sale.product.name = deferred_sale.sale.product.name;
    //deferred_sale_.sale.product.wood_type = deferred_sale.sale.product.wood_type;
    deferred_sale_.sale.product.type.name = deferred_sale.sale.product.type.name;
    deferred_sale_.sale.product.quantity = deferred_sale.sale.product.quantity;
    deferred_sale_.sale.sale_date = deferred_sale.sale.sale_date;
    deferred_sale_.sale.quantity_sold = deferred_sale.sale.quantity_sold;
    deferred_sale_.reason = deferred_sale.reason;
}

LumberData::~LumberData()
{
}

std::string LumberData::DateToString(time_t date) {
    std::tm tm;
    gmtime_s(&tm, &date); // Использование gmtime_s
    char buffer[80];
    strftime(buffer, 80, "%d-%m-%Y", &tm);
    return std::string(buffer);
}

void LumberData::Print()
{
    cout << "Изделие:" << endl;
    cout << " Название: " << product_.name << endl;
    cout << " Тип сырья: " << product_.type.name << endl;
    cout << " Количество: " << product_.quantity << endl;
    cout << endl;

    cout << "Сырьё:" << endl;
    cout << " Название: " << raw_material_.name << endl;
    cout << " Количество: " << raw_material_.quantity << endl;
    cout << endl;

    cout << "Продажи:" << endl;
    cout << " Название: " << product_.name << endl;
    cout << " Тип сырья: " << product_.type.name << endl;
    //cout << " Дата: " << sale_.sale_date << endl;
    cout << " Дата: " << DateToString(sale_.sale_date) << endl;
    cout << " Продано: " << sale_.quantity_sold << endl;
    cout << endl;

    cout << "Поставщики:" << endl;
    cout << " Наименование организации : " << endl;
    cout << "  " << supplier_.name << endl;
    cout << " Поставляемые материалы:" << endl;
    for (auto & it : supplier_.materials)
    {
        cout << "  " << it.name << endl;
        cout << " Количество:" << endl;
        cout << "  " << it.quantity << endl;
    }
    cout << endl;

    cout << "Отложеные продажи:" << endl;
    cout << " Название: " << deferred_sale_.sale.product.name << endl;
    cout << " Тип сырья: " << deferred_sale_.sale.product.type.name << endl;
    //cout << " Дата: " << deferred_sale_.sale.sale_date << endl;
    cout << " Дата: " << DateToString(deferred_sale_.sale.sale_date) << endl;
    cout << " Ожидаемое количество: " << deferred_sale_.sale.quantity_sold << endl;
    cout << " Причина: " << deferred_sale_.reason << endl;
    cout << endl;
}

void LumberData::LumberDataEntry(Product product, RawMaterial raw_material, Sale sale, Supplier supplier, DeferredSale deferred_sale)
{
    product_.name = product.name;
    //product_.wood_type = product.wood_type;
    product_.type.name = product.type.name;
    product_.quantity = product.quantity;

    raw_material_.name = raw_material.name;
    raw_material_.quantity = raw_material.quantity;

    sale_.product.name = sale.product.name;
    //sale_.product.wood_type = sale.product.wood_type;
    sale_.product.type.name = sale.product.type.name;
    sale_.product.quantity = sale.product.quantity;
    sale_.sale_date = sale.sale_date;
    sale_.quantity_sold = sale.quantity_sold;

    supplier_.name = supplier.name;
    supplier_.num_of_pos = supplier.num_of_pos;

    if (!supplier.materials.empty())
    {
        for (auto& it : supplier.materials)
        {
            RawMaterial rm;
            rm.name = it.name;
            rm.quantity = it.quantity;
            supplier_.materials.push_back(rm);
        }
    }

    deferred_sale_.sale.product.name = deferred_sale.sale.product.name;
    //deferred_sale_.sale.product.wood_type = deferred_sale.sale.product.wood_type;
    deferred_sale_.sale.product.type.name = deferred_sale.sale.product.type.name;
    deferred_sale_.sale.product.quantity = deferred_sale.sale.product.quantity;
    deferred_sale_.sale.sale_date = deferred_sale.sale.sale_date;
    deferred_sale_.sale.quantity_sold = deferred_sale.sale.quantity_sold;
    deferred_sale_.reason = deferred_sale.reason;
}

LumberData& LumberData::operator=(LumberData data_old)
{
    this->product_.name = data_old.product_.name;
    //this->product_.wood_type = data_old.product_.wood_type;
    this->product_.type.name = data_old.product_.type.name;
    this->product_.quantity = data_old.product_.quantity;

    this->raw_material_.name = data_old.raw_material_.name;
    this->raw_material_.quantity = data_old.raw_material_.quantity;

    this->sale_.product.name = data_old.sale_.product.name;
    //this->sale_.product.wood_type = data_old.sale_.product.wood_type;
    this->sale_.product.type.name = data_old.sale_.product.type.name;
    this->sale_.product.quantity = data_old.sale_.product.quantity;
    this->sale_.sale_date = data_old.sale_.sale_date;
    this->sale_.quantity_sold = data_old.sale_.quantity_sold;

    this->supplier_.name = data_old.supplier_.name;
    this->supplier_.num_of_pos = data_old.supplier_.num_of_pos;

    if (!data_old.supplier_.materials.empty())
    {
        for (auto& it : data_old.supplier_.materials)
        {
            RawMaterial rm;
            rm.name = it.name;
            rm.quantity = it.quantity;
            this->supplier_.materials.push_back(rm);
        }
    }

    this->deferred_sale_.sale.product.name = data_old.deferred_sale_.sale.product.name;
    //this->deferred_sale_.sale.product.wood_type = data_old.deferred_sale_.sale.product.wood_type ;
    this->deferred_sale_.sale.product.type.name = data_old.deferred_sale_.sale.product.type.name;
    this->deferred_sale_.sale.product.quantity = data_old.deferred_sale_.sale.product.quantity;
    this->deferred_sale_.sale.sale_date = data_old.deferred_sale_.sale.sale_date;
    this->deferred_sale_.sale.quantity_sold = data_old.deferred_sale_.sale.quantity_sold;
    this->deferred_sale_.reason = data_old.deferred_sale_.reason;

    return* this;
}

