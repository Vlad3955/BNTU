#include "Course_Project_OOP_DLL_Header.h"


// Hierarchy vegetable
//============================================================
// abstract class Vegetable
Vegetable::Vegetable() : kcal_per_100g(0.0), weight(0.0) {}

Vegetable::Vegetable(string _name) : name(_name), kcal_per_100g(0.0), weight(0.0) {}

Vegetable::Vegetable(string _name, double _kcal_per_100g)
	: name(_name), kcal_per_100g(_kcal_per_100g), weight(0.0) {}

Vegetable::Vegetable(string _name, double _kcal_per_100g, double _weight)
	: name(_name), kcal_per_100g(_kcal_per_100g), weight(_weight) {}

string Vegetable::get_name() const
{
	return name;
}
double Vegetable::get_kcal_per_100g() const
{
	return kcal_per_100g;
}
double Vegetable::get_weight() const
{
	return weight;
}
void Vegetable::set_category(string _category)
{
	category = _category;
}
string Vegetable::get_category() const
{
	return category;
}
double Vegetable::get_total_calories() const
{
	return kcal_per_100g * weight / 100.0;
}
Vegetable::~Vegetable() {}
//============================================================

// CucurbitaceaeVegetable classes
//============================================================
CucurbitaceaeVegetable::CucurbitaceaeVegetable()
{
	set_category("Cucurbitaceae Vegetable");
}

CucurbitaceaeVegetable::CucurbitaceaeVegetable(string _name, double _kcal_per_100g)
	: Vegetable(_name, _kcal_per_100g), harvest_country("Unknow")
{
	set_category("Cucurbitaceae Vegetable");
}

CucurbitaceaeVegetable::CucurbitaceaeVegetable(string _name, double _kcal_per_100g, double _weight)
	: Vegetable(_name, _kcal_per_100g, _weight), harvest_country("Unknow")
{
	set_category("Cucurbitaceae Vegetable");
}

void CucurbitaceaeVegetable::set_harvest_country(string _harvest_country)
{
	harvest_country = _harvest_country;
}

string CucurbitaceaeVegetable::get_harvest_country()
{
	return harvest_country;
}

void CucurbitaceaeVegetable::all_info()
{
	cout << "Name: " << get_name() << '\n'
		<< "Harvest country: " << get_harvest_country() << '\n'
		<< "Category: " << get_category() << '\n'
		<< "Calories per 100 gramm: " << get_kcal_per_100g() << '\n'
		<< "Weight: " << get_weight() << '\n'
		<< "Total calories: " << get_total_calories() << endl;
}

CucurbitaceaeVegetable::~CucurbitaceaeVegetable() {}

// class Cucumber
Cucumber::Cucumber() {}

Cucumber::Cucumber(double _weight) : CucurbitaceaeVegetable("Cucumber", 41.0, _weight) {}

Cucumber::~Cucumber() {}
//============================================================


// NightshadeVegetable classes
//============================================================
NightshadeVegetable::NightshadeVegetable()
{
	variety = "Unknow";
	set_category("Nightshade Vegetable");
}

NightshadeVegetable::NightshadeVegetable(string _name, double _kcal_per_100g)
	: Vegetable(_name, _kcal_per_100g), variety("Unknow")
{
	set_category("Nightshade Vegetable");
}

NightshadeVegetable::NightshadeVegetable(string _name, double _kcal_per_100g, double _weight)
	: Vegetable(_name, _kcal_per_100g, _weight), variety("Unknow")
{
	set_category("Nightshade Vegetable");
}

void NightshadeVegetable::set_variety(string _variety)
{
	variety = _variety;
}

string NightshadeVegetable::get_variety()
{
	return variety;
}

void NightshadeVegetable::all_info()
{
	cout << "Name: " << get_name() << '\n'
		<< "Category: " << get_category() << '\n'
		<< "Variety: " << get_variety() << '\n'
		<< "Calories per 100 gramm: " << get_kcal_per_100g() << '\n'
		<< "Weight: " << get_weight() << '\n'
		<< "Total calories: " << get_total_calories() << endl;
}

NightshadeVegetable::~NightshadeVegetable() {}

// Class Potato
Potato::Potato() {}

Potato::Potato(double _weight) : NightshadeVegetable("Potato", 29, _weight) {}

Potato::~Potato() {}

// Class Tomato
Tomato::Tomato() {}

Tomato::Tomato(double _weight) : NightshadeVegetable("Tomato", 15, _weight) {}

Tomato::~Tomato()
{
}
//============================================================

// RootVegetable classes
//============================================================
RootVegetable::RootVegetable()
{
	set_category("Root Vegetable");
}

RootVegetable::RootVegetable(string _name, double _kcal_per_100g)
	: Vegetable(_name, _kcal_per_100g), crop_year("Unknow")
{
	set_category("Root Vegetable");
}

RootVegetable::RootVegetable(string _name, double _kcal_per_100g, double _weight)
	: Vegetable(_name, _kcal_per_100g, _weight), crop_year("Unknow")
{
	set_category("Root Vegetable");
}

void RootVegetable::set_crop_year(string _crop_year)
{
	crop_year = _crop_year;
}

string RootVegetable::get_crop_year()
{
	return crop_year;
}

void RootVegetable::all_info()
{
	cout << "Name: " << get_name() << '\n'
		<< "Category: " << get_category() << '\n'
		<< "Crop year: " << get_crop_year() << '\n'
		<< "Calories per 100 gramm: " << get_kcal_per_100g() << '\n'
		<< "Weight: " << get_weight() << '\n'
		<< "Total calories: " << get_total_calories() << endl;
}

RootVegetable::~RootVegetable() {}

// Class Carrot
Carrot::Carrot() {}

Carrot::Carrot(double _weight) : RootVegetable("Carrot", 22, _weight) {}

Carrot::~Carrot() {}

// Class Beet
Beet::Beet() {}

Beet::Beet(double _weight) : RootVegetable("Beet", 22, _weight) {}

Beet::~Beet() {}
//============================================================

// Class Flavoring
//============================================================
//Flavoring::Flavoring() : kcal_per_100g(0.0), weight(0.0) {}
//
//Flavoring::Flavoring(string _name = "", double _kcal_per_100g = 0.0, double _weight = 0.0)
//	: name(_name), kcal_per_100g(_kcal_per_100g), weight(_weight) {}
//
//string Flavoring::get_name() const
//{
//	return name;
//}
//double Flavoring::get_kcal_per_100g() const
//{
//	return kcal_per_100g;
//}
//double Flavoring::get_weight() const
//{
//	return weight;
//}
//
//double Flavoring::get_total_calories() const
//{
//	return kcal_per_100g * weight / 100.0;
//}
//
//Flavoring::~Flavoring() {}
//============================================================


Salad::Salad() {}

double Salad::get_total_calories() const
{
	double sum = 0.0;
	for (auto& it : salad)
	{
		sum += it->get_total_calories();
	}
	return sum;
}

void Salad::add_ingredients(Vegetable* veg)
{
	salad.push_back(veg);
}

void Salad::about_salad()
{
	cout << "Your salad ingredients: ";
	for (auto& it : salad)
	{
		cout << it->get_name() << "| ";
	}
	cout << endl << "Total calories: " << get_total_calories() << endl;
}

Salad::~Salad() {}