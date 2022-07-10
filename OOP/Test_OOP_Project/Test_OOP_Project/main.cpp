#include <iostream>
#include "Course_Project_OOP_DLL_Header.h"


int main()
{
	Carrot carrot(100);
	Beet beet(100);
	Potato potato(100);
	Tomato tomato(100);
	Cucumber cucumber(100);

	vector<Vegetable*> salad;
	
	Salad vinigrette;

	vinigrette.add_ingredients(&carrot);
	vinigrette.add_ingredients(&beet);
	vinigrette.add_ingredients(&potato);
	vinigrette.add_ingredients(&tomato);
	vinigrette.add_ingredients(&cucumber);

	vinigrette.about_salad();
	
	return 0;
}