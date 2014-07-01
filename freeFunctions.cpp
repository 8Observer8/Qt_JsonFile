#include <string>
#include <iostream>

#include <QFile>
#include <QString>
#include <QJsonArray>
#include <QJsonObject>

#include "freeFunctions.h"

void parsePersonsToContent( const std::vector<Person> &persons,
                            QJsonDocument &content )
throw ( EmptyArgument )
{
    std::string functionName = "parsePersonsToContent()";

    // Check the input argument
    if ( persons.empty( ) ) {
        throw EmptyArgument( functionName );
    }

    // Fill the output array
    QJsonArray personsObjectArray;
    for( std::size_t i = 0; i < persons.size( ); ++i ) {
        QJsonObject personObject;
        persons[i].write( personObject );
        personsObjectArray.append( personObject );
    }

    // Result
    content.setArray( personsObjectArray );
}

void parseContentToPersons( const QJsonDocument &content,
                            std::vector<Person> &persons )
throw ( EmptyArgument )
{
    std::string functionName = "parseContentToPersons()";

    // Check the input argument
    if ( content.isEmpty( ) ) {
        throw EmptyArgument( functionName );
    }

    QJsonArray personsObjectArray = content.array( );
    for ( std::size_t i = 0; i < personsObjectArray.size( ); ++i ) {
        Person person;
        QJsonObject personObject = personsObjectArray[i].toObject( );
        person.read( personObject );
        persons.push_back( person );
    }
}

void writeData( const QString &fileName,
                const QJsonDocument &content )
throw ( EmptyArgument, FileOpenError, FileWriteError )
{
    std::string functionName = "writeData()";

    // Check arguments
    if ( fileName.isEmpty( ) || content.isEmpty( ) ) {
        throw EmptyArgument( functionName );
    }

    // Open the output file
    QFile file( fileName );
    if ( !file.open( QIODevice::WriteOnly ) ) {
        throw FileOpenError( fileName.toStdString( ), functionName );
    }

    // Write data to the output file
    if ( !file.write( content.toJson( ) ) ) {
        throw FileWriteError( fileName.toStdString( ), functionName );
    }
}

void readData(const QString &fileName,
              QJsonDocument &content )
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
    content = content.fromJson( data );
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
