#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

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


