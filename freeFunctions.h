#ifndef FREEFUNCTIONS_H
#define FREEFUNCTIONS_H

#include <string>
#include <vector>

#include <QString>
#include <QJsonDocument>

#include "Person.h"
#include "FileOpenError.h"
#include "FileReadError.h"
#include "FileWriteError.h"
#include "EmptyArgument.h"

void parsePersonsToContent( const std::vector<Person> &persons,
                            QJsonDocument &content )
throw ( EmptyArgument );

void parseContentToPersons( const QJsonDocument &content,
                            std::vector<Person> &persons )
throw ( EmptyArgument );

void writeData( const QString &fileName,
                const QJsonDocument &content )
throw ( EmptyArgument, FileOpenError, FileWriteError );

void readData(const QString &fileName,
               QJsonDocument &content )
throw ( EmptyArgument, FileOpenError, FileReadError );

void printData( const std::vector<Person> &persons )
throw ( EmptyArgument );

#endif // FREEFUNCTIONS_H
