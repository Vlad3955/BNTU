#pragma once
#ifdef OOP_DLL_Lib
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC __declspec(dllimport)
#endif // OOP_DLL_Lib

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;



// Hierarchy vegetable
//============================================================
// abstract class Vegetable
class DECLSPEC Vegetable
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
class DECLSPEC CucurbitaceaeVegetable : public Vegetable
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

class DECLSPEC Cucumber : public CucurbitaceaeVegetable
{
public:
	Cucumber();
	Cucumber(double _weight);
	~Cucumber();
};
//============================================================


// NightshadeVegetable classes
//============================================================
class DECLSPEC NightshadeVegetable : public Vegetable
{
public:
	NightshadeVegetable();
	NightshadeVegetable(string _name, double _kcal_per_100g);
	NightshadeVegetable(string _name, double _kcal_per_100g, double _weight);
	void set_variety(string _variety);
	string get_variety();
	virtual void all_info() override;
	~NightshadeVegetable();
protected:
	string variety;
};

class DECLSPEC Potato : public NightshadeVegetable
{
public:
	Potato();
	Potato(double _weight);
	~Potato();
};

class DECLSPEC Tomato : public NightshadeVegetable
{
public:
	Tomato();
	Tomato(double _weight);
	~Tomato();
};
//============================================================

// RootVegetable classes
//============================================================
class DECLSPEC RootVegetable : public Vegetable
{
public:
	RootVegetable();
	RootVegetable(string _name, double _kcal_per_100g);
	RootVegetable(string _name, double _kcal_per_100g, double _weight);
	void set_crop_year(string _crop_year);
	string get_crop_year();
	virtual void all_info() override;
	~RootVegetable();
protected:
	string crop_year;
};

class DECLSPEC Carrot : public RootVegetable
{
public:
	Carrot();
	Carrot(double _weight);
	~Carrot();
};

class DECLSPEC Beet : public RootVegetable
{
public:
	Beet();
	Beet(double _weight);
	~Beet();
};
//============================================================

// Class __declspec(dllexport) Flavoring
//============================================================
//class Flavoring
//{
//public:
//	Flavoring();
//	Flavoring(string _name, double _kcal_per_100g, double _weight);
//	string get_name() const;
//	double get_kcal_per_100g() const;
//	double get_weight() const;
//	double get_total_calories() const;
//	~Flavoring();
//private:
//	string name;
//	double kcal_per_100g, weight;
//};
//============================================================


class DECLSPEC Salad
{
public:
	Salad();
	double get_total_calories() const;
	void add_ingredients(Vegetable* veg);
	void about_salad();
	~Salad();
private:
	vector<Vegetable*> salad;
	//Flavoring flavoring;
};