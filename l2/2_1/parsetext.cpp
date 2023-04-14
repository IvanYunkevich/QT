#include "parsetext.h"

ParseText::ParseText(QString txt)
{
    str = txt;
}
QString ParseText::parse(){
    std::map<QString, QString> Symbols
    {
        {"copyright", "©"},
        {"ppm", "‰"},
        {"eur", "€"},
        {"dollar", "$"},
        {"rub", "₽"},
    };

    auto search = Symbols.find(str);
        if (search != Symbols.end())
        {
            return search->second;
        }
        else
        {
            return str;
        }
}
