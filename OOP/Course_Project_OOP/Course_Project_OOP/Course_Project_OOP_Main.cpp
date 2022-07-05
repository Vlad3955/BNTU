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
	Cucumber a(110);
	a.all_info();
	return 0;
}