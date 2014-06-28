#ifndef FREEFUNCTIONS_H
#define FREEFUNCTIONS_H

#include <string>
#include <vector>

#include <QString>

#include "Person.h"
#include "FileOpenError.h"
#include "FileReadError.h"
#include "FileWriteError.h"
#include "EmptyArgument.h"

void writeData( const QString &fileName,
                const std::vector<Person> &persons )
throw ( EmptyArgument, FileOpenError, FileWriteError );

void readData(const QString &fileName,
               std::vector<Person> &persons )
throw ( EmptyArgument, FileOpenError, FileReadError );

void printData( const std::vector<Person> &persons )
throw ( EmptyArgument );

#endif // FREEFUNCTIONS_H
