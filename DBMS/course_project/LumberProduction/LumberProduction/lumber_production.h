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
    int quantity = 0;
};

struct Product {
    std::string name;
    RawMaterial type;
    int quantity = 0;
};

struct Sale {
    Product product;
    time_t sale_date = 0;
    int quantity_sold = 0;
};

struct Supplier {
    std::string name;
    int num_of_pos = 0;
    std::vector<RawMaterial> materials;

    Supplier() {}
    Supplier(const Supplier& other) : name(other.name), num_of_pos(other.num_of_pos), materials(other.materials) {}

    // Оператор присваивания
    Supplier& operator=(const Supplier& other) {
        if (this != &other) {
            name = other.name;
            num_of_pos = other.num_of_pos;
            materials = other.materials;
        }
        return *this;
    }
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
    Product& GetProduct() { return product_; };
    RawMaterial& GetRawMaterial() { return raw_material_; };
    Sale& GetSale() { return sale_; };
    Supplier& GetSupplier() { return supplier_; };
    DeferredSale& GetDeferredSale() { return deferred_sale_; };

    LumberData& operator=(LumberData data_old);

private:
    Product product_;
    RawMaterial raw_material_;
    Sale sale_;
    Supplier supplier_;
    DeferredSale deferred_sale_;
};
