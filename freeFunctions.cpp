#include <string>
#include <iostream>

#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include "freeFunctions.h"

void writeData( const QString &fileName,
                const std::vector<Person> &persons )
throw ( EmptyArgument, FileOpenError, FileWriteError )
{
    std::string functionName = "writeData()";

    // Check arguments
    if ( fileName.isEmpty( ) || persons.empty( ) ) {
        throw EmptyArgument( functionName );
    }

    // Open the output file
    QFile file( fileName );
    if ( !file.open( QIODevice::WriteOnly ) ) {
        throw FileOpenError( fileName.toStdString( ), functionName );
    }

    // Write data to the output file
    QJsonArray jsonArray;
    for ( std::size_t i = 0; i < persons.size( ); i++ ) {
        QJsonObject person;
        persons[i].write( person );
        jsonArray.append( person );
    }

    QJsonObject jsonPersons;
    jsonPersons["Persons"] = jsonArray;
    QJsonDocument saveDoc( jsonPersons );
    if ( !file.write( saveDoc.toJson( ) ) ) {
        throw FileWriteError( fileName.toStdString( ), functionName );
    }
}

void readData(const QString &fileName,
              std::vector<Person> &persons )
throw ( EmptyArgument, FileOpenError, FileReadError )
{
    std::string functionName = "readData()";

    // Check argument
    if ( fileName.isEmpty( ) ) {
        throw EmptyArgument( functionName );
    }

    // Open the input file
    QFile file( fileName );
    if ( !file.open( QIODevice::ReadOnly ) ) {
        throw FileOpenError( fileName.toStdString( ), functionName );
    }

    // Read data from the file
    QByteArray data = file.readAll( );
    QJsonDocument readDoc( QJsonDocument::fromJson( data ) );
    QJsonObject personsObject = readDoc.object();
    QJsonArray personsArray = personsObject["Persons"].toArray();

    for ( std::size_t i = 0; i < personsArray.size( ); ++i ) {
        QJsonObject personObject = personsArray[i].toObject( );
        Person person;
        person.read( personObject );
        persons.push_back( person );
    }
}


void printData(const std::vector<Person> &persons)
throw ( EmptyArgument )
{
    // Check argument
    if ( persons.empty( ) ) {
        std::string functionName = "printData()";
        throw EmptyArgument( functionName );
    }

    // Print data
    for ( std::size_t i = 0; i < persons.size( ); ++i ) {
        std::cout << "First Name: " << persons[i].firstName( ).toStdString( ) << std::endl;
        std::cout << "Last Name: " << persons[i].lastName( ).toStdString( ) << std::endl;
        std::cout << std::endl;
    }
}
