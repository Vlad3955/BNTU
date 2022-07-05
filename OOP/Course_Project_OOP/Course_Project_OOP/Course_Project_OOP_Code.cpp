#include "Course_Project_OOP_Header.h"

// CBookCard
//============================================================
CBookCard::CBookCard()
{
	rating = 0;
	comment = "";
}

CBookCard::CBookCard(string _author, string _title,
	string _publishing_house, string _BBK, int _year_publishing) : 
	author(_author), title(_title),
	publishing_house(_publishing_house), BBK(_BBK),
	year_publishing(_year_publishing) 
{
	rating = 0;
	comment = "";
}

string CBookCard::get_author() const
{
	return author;
}

string CBookCard::get_title() const
{
	return title;
}

string CBookCard::get_publishing_house() const
{
	return publishing_house;
}

string CBookCard::get_BBK() const
{
	return BBK;
}

int CBookCard::get_year_publishing() const
{
	return year_publishing;
}

void CBookCard::set_comment(string _comment)
{
	comment = _comment;
}

string CBookCard::get_comment() const
{
	return comment;
}

void CBookCard::set_rating(double _rating)
{
	if (_rating >= 0 && _rating <= 6)
	{
		rating = _rating;
	}
}

double CBookCard::get_rating() const
{
	return rating;
}

string CBookCard::book_description() const
{
	string tmp;
	tmp = "Author: " + author + '\n';
	tmp += "Title: " + title + '\n';
	tmp += "Publishing house: " + publishing_house + '\n';
	tmp += "The year of publishing: " + to_string(year_publishing) + '\n';
	tmp += BBK + '\n';
	tmp += "Rating: " + to_string(rating).erase(to_string(rating).size() - 5) + '\n' + '\n';
	return tmp;
}

void CBookCard::sort_book(vector <CBookCard>& _vec)
{
	sort(_vec.begin(), _vec.end(), [&](CBookCard l, CBookCard r) {return l.get_year_publishing() < r.get_year_publishing(); });
}

CBookCard::~CBookCard() {}
//============================================================
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Hierarchy vegetable
//============================================================
// abstract class Vegetable
Vegetable::Vegetable()
{
	kcal_per_100g = 0.0;
	weight = 0.0;
}
Vegetable::Vegetable(string _name) : name(_name) 
{ 
	kcal_per_100g = 0.0; 
	weight = 0.0;
}
Vegetable::Vegetable(string _name, double _kcal_per_100g) : name(_name), kcal_per_100g(_kcal_per_100g) 
{
	weight = 0.0;
}
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
	harvest_country = "";
	set_category("Cucurbitaceae Vegetable");
}

CucurbitaceaeVegetable::CucurbitaceaeVegetable(string _name, double _kcal_per_100g) 
	: Vegetable(_name, _kcal_per_100g) {}

CucurbitaceaeVegetable::CucurbitaceaeVegetable(string _name, double _kcal_per_100g, double _weight) 
	: Vegetable(_name, _kcal_per_100g, _weight) {}

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
	cout << "Name: "  << get_name() << '\n' 
		 << "Harvest country: " << get_harvest_country() << '\n'
		 << "Calories per 100 gramm: " << get_kcal_per_100g() << '\n' 
		 << "Weight: " << get_weight() << '\n' 
		 << "Total calories: " << get_total_calories() << endl;
}

CucurbitaceaeVegetable::~CucurbitaceaeVegetable() {}

// class Cucumber
Cucumber::Cucumber() {}

Cucumber::Cucumber(double _weight) : CucurbitaceaeVegetable("Cucumber", 41.0, _weight) {}

Cucumber::~Cucumber() {}
////============================================================
//
//
//// NightshadeVegetable classes
////============================================================
//NightshadeVegetable::NightshadeVegetable()
//{
//}
//
//NightshadeVegetable::~NightshadeVegetable()
//{
//}
//
//Potato::Potato()
//{
//}
//
//Potato::~Potato()
//{
//}
//
//Tomato::Tomato()
//{
//}
//
//Tomato::~Tomato()
//{
//}
////============================================================
//
//// RootVegetable classes
////============================================================
//RootVegetable::RootVegetable()
//{
//}
//
//RootVegetable::~RootVegetable()
//{
//}
//
//Carrot::Carrot()
//{
//}
//
//Carrot::~Carrot()
//{
//}
//
//Beet::Beet()
//{
//}
//
//Beet::~Beet()
//{
//}
////============================================================