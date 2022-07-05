#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

// CBookCard
//============================================================
class CBookCard
{
public:
	CBookCard();
	CBookCard(string _author, string _title,
		string _publishing_house, string _BBK,
		int _year_publishing);
	string get_author() const;
	string get_title() const;
	string get_publishing_house() const;
	string get_BBK() const;
	int get_year_publishing() const;
	void set_comment(string _comment);
	string get_comment() const;
	void set_rating(double _rating);
	double get_rating() const;
	string book_description() const;
	static void sort_book(vector <CBookCard>& _vec);
	~CBookCard();
private:
	string author, title, publishing_house, BBK, 
		comment;
	double rating;
	int	year_publishing;
};
//============================================================
//////////////////////////////////////////////////////////////


// Hierarchy vegetable
//============================================================
// abstract class Vegetable
class Vegetable
{
public:
	Vegetable();
	Vegetable(string _name);
	Vegetable(string _name, double _kcal_per_100g);
	Vegetable(string _name, double _kcal_per_100g, double _weight);
	virtual string get_name() const;
	virtual double get_kcal_per_100g() const;
	virtual double get_weight() const;
	virtual void set_category(string _category);
	virtual string get_category() const;
	double get_total_calories() const;
	virtual void all_info() = 0;
	virtual ~Vegetable();
protected:
	string name, category;
	double kcal_per_100g, weight;
};
//============================================================

// CucurbitaceaeVegetable classes
//============================================================
class CucurbitaceaeVegetable : public Vegetable
{
public:
	CucurbitaceaeVegetable();
	CucurbitaceaeVegetable(string _name, double _kcal_per_100g);
	CucurbitaceaeVegetable(string _name, double _kcal_per_100g, double _weight);
	void set_harvest_country(string _harvest_country);
	string get_harvest_country();
	virtual void all_info() override;
	~CucurbitaceaeVegetable();
protected:
	string harvest_country;
};

class Cucumber : public CucurbitaceaeVegetable
{
public:
	Cucumber();
	Cucumber(double _weight);
	~Cucumber();
};
////============================================================
//
//
//// NightshadeVegetable classes
////============================================================
//class NightshadeVegetable : public Vegetable
//{
//public:
//	NightshadeVegetable();
//	NightshadeVegetable(string _name, double _kcal_per_100g);
//	NightshadeVegetable(string _name, double _kcal_per_100g, double _weight);
//	virtual void all_info() override;
//	~NightshadeVegetable();
//protected:
//	string variety;
//};
//
//class Potato : public NightshadeVegetable
//{
//public:
//	Potato();
//
//	~Potato();
//};
//
//class Tomato : public NightshadeVegetable
//{
//public:
//	Tomato();
//
//	~Tomato();
//};
////============================================================
//
//// RootVegetable classes
////============================================================
//class RootVegetable : public Vegetable
//{
//public:
//	RootVegetable();
//	/*RootVegetable(string _name, double _kcal_per_100g);
//	RootVegetable(string _name, double _kcal_per_100g, double _weight);*/
//	virtual void all_info() override;
//	~RootVegetable();
//protected:
//	int crop_year;
//};
//
//class Carrot : public RootVegetable
//{
//public:
//	Carrot();
//
//	~Carrot();
//};
//
//class Beet : public RootVegetable
//{
//public:
//	Beet();
//
//	~Beet();
//};
//============================================================




