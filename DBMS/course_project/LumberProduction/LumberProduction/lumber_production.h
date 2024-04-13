#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>

using namespace std;

//struct Product {
//    std::string name;
//    std::string wood_type;
//    int quantity;
//};

struct RawMaterial {
    std::string name;
    int quantity;
};

struct Product {
    std::string name;
    RawMaterial type;
    int quantity;
};

struct Sale {
    Product product;
    time_t sale_date;
    int quantity_sold;
};

struct Supplier {
    std::string name;
    int num_of_pos;
    std::vector<RawMaterial> materials;
};

struct DeferredSale {
    Sale sale;
    std::string reason;
};


class LumberData
{
public:
	LumberData();
    LumberData(Product product, RawMaterial raw_material, Sale sale, Supplier supplier,
        DeferredSale deferred_sale);
	~LumberData();

    void Print();
    void LumberDataEntry(Product product, RawMaterial raw_material, Sale sale, Supplier supplier,
        DeferredSale deferred_sale);
    Product GetProduct() { return product_; };
    RawMaterial GetRawMaterial() { return raw_material_; };
    Sale GetSale() { return sale_; };
    Supplier GetSupplier() { return supplier_; };
    DeferredSale GetDeferredSale() { return deferred_sale_; };

    LumberData& operator=(LumberData data_old);

private:
    Product product_;
    RawMaterial raw_material_;
    Sale sale_;
    Supplier supplier_;
    DeferredSale deferred_sale_;
};
