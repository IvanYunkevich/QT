#ifndef WEATHER_H
#define WEATHER_H
#include <QString>

class Weather
{
public:
    Weather(QString);
    QString parse();
private:
    QString text;
};

#endif // WEATHER_H
