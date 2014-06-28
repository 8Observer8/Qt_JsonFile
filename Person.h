#ifndef PERSON_H
#define PERSON_H

#include <string>

#include <QString>
#include <QJsonObject>

class Person {
public:

    Person( const QString &firstName = "",
            const QString &lastName = "" ) :
        m_firstName( firstName ),
        m_lastName( lastName )
    {

    }

    QString firstName( ) const {
        return m_firstName;
    }

    QString lastName( ) const {
        return m_lastName;
    }

    void write( QJsonObject &json ) const {
        json["firstName"] = m_firstName;
        json["lastName"] = m_lastName;
    }

    void read( const QJsonObject &json ) {
        m_firstName = json["firstName"].toString( );
        m_lastName = json["lastName"].toString( );
    }

private:
    QString m_firstName;
    QString m_lastName;
};

#endif // PERSON_H
