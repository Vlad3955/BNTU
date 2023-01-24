#ifndef AEROFLOT_H
#define AEROFLOT_H
#include <QString>

struct Aeroflot {
    QString dest;
    QString flight_num = 0;
    Aeroflot(QString d, QString fn) : dest(d), flight_num(fn) {}
};

#endif // AEROFLOT_H
