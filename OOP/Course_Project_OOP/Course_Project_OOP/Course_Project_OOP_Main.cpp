#include "Course_Project_OOP_Header.h"



int main()
{
	// CBookCard
    //============================================================
	/*CBookCard Glukhovsky("Dmitrii Glukhovsky", "Metro 2033", "Ecsmo", "KHG765", 2005);
	Glukhovsky.set_rating(4.5);
	CBookCard Diakov("Andrey Diakov", "To light", "AST", "84(2Ros=Rus)6", 2010);
	CBookCard Azimov("Isaac Azimov", "Fundamintation", "AM", "IJK11", 1942);
	CBookCard Cormen("Thomas H. Cormen", "Introduction to Algorithms, CLRS", "MIT Press", "231", 1990);
	Cormen.set_rating(6);
	CBookCard Knuth("Donald Ervin Knuth", "The Art of Computer Programming", "Addison - Wesley", "IJK11", 1968);
	Knuth.set_rating(6);
	vector <CBookCard> vec;
	vec.push_back(Glukhovsky);
	vec.push_back(Diakov);
	vec.push_back(Azimov);
	vec.push_back(Cormen);
	vec.push_back(Knuth);
	cout << "Before sorting: \n" << endl;
	for_each(vec.begin(), vec.end(), [&](const CBookCard& a) {cout << a.book_description(); });
	CBookCard::sort_book(vec);
	cout << "After sorting: \n" << endl;
	for_each(vec.begin(), vec.end(), [&](const CBookCard& a) {cout << a.book_description(); });*/
	//============================================================

	// Hierarchy vegetable
    //============================================================
	Carrot carrot(100);
	Beet beet(100);
	Potato potato(100);
	Tomato tomato(100);
	Cucumber cucumber(100);
	vector<Vegetable*> salad;
	/*salad.push_back(&carrot);
	salad.push_back(&beet);
	salad.push_back(&potato);
	salad.push_back(&tomato);
	salad.push_back(&cucumber);
	double sum = 0.0;
	for (auto& it : salad)
	{
		sum += it->get_total_calories();
	}
	cout << sum;*/

	Salad vinigrette;
	vinigrette.add_ingredients(&carrot);
	vinigrette.add_ingredients(&beet);
	vinigrette.add_ingredients(&potato);
	vinigrette.add_ingredients(&tomato);
	vinigrette.add_ingredients(&cucumber);

	vinigrette.about_salad();

	/*int size = 5;
	Vegetable** arrVeg = new Vegetable*[size];
	arrVeg[0] = &carrot;
	arrVeg[1] = &beet;
	arrVeg[2] = &potato;
	arrVeg[3] = &tomato;
	arrVeg[4] = &cucumber;
	double sum = 0.0;
	for (size_t i = 0; i < size; i++)
	{
		sum += arrVeg[i]->get_total_calories();
	}
	cout << sum;
	delete[] arrVeg;
	arrVeg = nullptr;*/
	//============================================================
	return 0;
}