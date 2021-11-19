#include <iostream>
#include "list.h"
#include <string>
class bilet //авиабилеты
{
private:
    const char *destination; //пункт назначения
    const char *surname; //фамилия
    int flight_number;
    char name, patronymic; //имя, отчество (инициалы)
    int year, month, day; //дата вылета
public:
    bilet(const char *destination, const char *surname, int flight_number, char name,
        char patronymic, int year, int month, int day);
    bilet();
    bool operator==(bilet b);
    void print();
    int getFlightNum();
    int getYear();
    int getMonth();
    int getDay();
};
//реализация

//class bilet
bilet::bilet(const char *destination, const char *surname, int flight_number, char name,
    char patronymic, int year, int month, int day)
{
    this->destination = destination;
    this->surname = surname;
    this->flight_number = flight_number;
    this->name = name;
    this->patronymic = patronymic;
    this->year = year;
    this->month = month;
    this->day = day;
}
bilet::bilet() : bilet(NULL, NULL, 0, '\0', '\0', 0, 0, 0)
{
}
bool bilet::operator==(bilet b)
{
    return (strcmp(destination, b.destination)) == 0 &&
           (strcmp(surname, b.surname)) == 0 && flight_number == b.flight_number &&
           name == b.name && patronymic == b.patronymic && year == b.year && 
           month == month && day == b.day;
}
void bilet::print()
{
    if (!surname || (!destination)) //пустой билет
        return;
    std::cout <<  surname << ' ' << name << '.' << patronymic << ".:" << std::endl
        << "\tDestination: " << destination << std::endl
        << "\tFlight nubmer: " << flight_number << std::endl
        << "\tDate: " << month << '.' << day << '.' << year << std::endl << std::endl;
}
int bilet::getFlightNum()
{
    return flight_number;
}
int bilet::getYear()
{
    return year;
}
int bilet::getMonth()
{
    return month;
}
int bilet::getDay()
{
    return day;
}
//предикат, в котором проверяется нужная дата в билете
bool isSuitableData(bilet &b)
{
    return b.getFlightNum() == 324 && b.getYear() == 2021 &&
        b.getMonth() == 6 && b.getDay() == 24;
}
int main()
{
    list<bilet> l;
    bilet Ivanov("Moscow", "Ivanov", 324, 'R', 'V', 2021, 6, 24), 
        Petrov("Paris", "Petrov", 324, 'B', 'N', 2021, 6, 24);
    l.add(Ivanov);
    l.add(Petrov);
    l.add(bilet("Kazan", "Sidorova", 144, 'V', 'E', 2021, 7, 14));
    l.add(bilet("Antalya", "Elmov", 574, 'I', 'B', 2021, 8, 24));
    l.add(bilet("Vladivostok", "Chernov", 574, 'D', 'S', 2021, 5, 1));
    std::cout << "Passengers who will fly away at 2021.6.24:\n\n";
    l.printAllWhere(isSuitableData);
    l.del(Ivanov);
    l.del(Petrov);
    std::cout << "Other:\n\n";
    l.printAll();
    std::cout << "Last passenger: \n\n";
    l.popBack().print();
}