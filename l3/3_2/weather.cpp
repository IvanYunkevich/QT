#include "weather.h"

Weather::Weather(QString txt)
{
    text = txt;
}

QString Weather::parse()
{
    QString city, temp,
    temp_feel,description,
    windDescription, pressure,
    humidity, answer;

    if (text.contains("\"weather\":", Qt::CaseSensitive))
    {
        text.remove(0,text.indexOf("\"weather\":"));
        text.remove(text.indexOf(",\"near\":"),text.length()-text.indexOf(",\"near\":"));
        city = text;
        city.remove(0,city.indexOf("\"city\":\"")+8);
        city.remove(city.indexOf("\","),text.length()-city.indexOf("\","));
        temp = text;
        temp.remove(0,temp.indexOf("\"temp\":\"")+8);
        temp.remove(temp.indexOf("\","),text.length()-temp.indexOf("\","));
        temp_feel = text;
        temp_feel.remove(0,temp_feel.indexOf("\"tempFeelsLike\":\"")+17);
        temp_feel.remove(temp_feel.indexOf("\","),text.length()-temp_feel.indexOf("\","));
        description = text;
        description.remove(0,description.indexOf("\"description\":\"")+15);
        description.remove(description.indexOf("\","),text.length()-description.indexOf("\","));
        windDescription = text;
        windDescription.remove(0,windDescription.indexOf("\"wind_description\":\"")+20);
        windDescription.remove(windDescription.indexOf("\","),text.length()-windDescription.indexOf("\","));
        pressure = text;
        pressure.remove(0,pressure.indexOf("\"pressure\":\"")+12);
        pressure.remove(pressure.indexOf("\","),text.length()-pressure.indexOf("\","));
        humidity = text;
        humidity.remove(0,humidity.indexOf("\"humidity\":\"")+12);
        humidity.remove(humidity.indexOf("\","),text.length()-humidity.indexOf("\","));

        answer = QString("%1, %2, %3\r\nТемпература: %4, ощущается как %5\r\nДавление: %6\r\nВлажность: %7")
                .arg(city)
                .arg(description)
                .arg(windDescription)
                .arg(temp)
                .arg(temp_feel)
                .arg(pressure)
                .arg(humidity);
    }
    else
    {
       answer = "Информация не найдена";
    }
    return answer;

}
