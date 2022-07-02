#include "Course_Project_OOP_Header.h"

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