#ifndef PARSE_H
#define PARSE_H
#include <QString>

class ParseCurrents
{
public:
    ParseCurrents(QString);
    QString parseCur(QString);
private:
    QString text;
};

#endif // PARSE_H
