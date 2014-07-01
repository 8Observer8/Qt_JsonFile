
#include <vector>
#include <iostream>
#include <QString>
#include <QJsonDocument>
#include "freeFunctions.h"
#include "Person.h"

int main( )
{
    // Input data
    Person david( "David", "White" );
    Person ivan( "Ivan", "Green" );
    std::vector<Person> persons;
    persons.push_back( david );
    persons.push_back( ivan );

    // Parse the person array to the Json-content
    QJsonDocument content;
    try {
        parsePersonsToContent( persons, content );
    } catch ( const LogicError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( ... ) {
        std::cerr << "Error: unknown exception" << std::endl;
        return 1;
    }

    // Write the Json-content to the file
    QString fileName = "Persons.json";
    try {
        writeData( fileName, content );
    } catch ( const LogicError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( const FileError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( ... ) {
        std::cerr << "Error: unknown exception" << std::endl;
        return 1;
    }

    // Read the Json-content from the file
    QJsonDocument readContent;
    try {
        readData( fileName, readContent );
    } catch ( const LogicError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( const FileError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( ... ) {
        std::cerr << "Error: unknown exception" << std::endl;
        return 1;
    }

    // Parse the Json-content to the person array
    std::vector<Person> readPersons;
    try {
        parseContentToPersons( readContent, readPersons );
    } catch ( const LogicError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( ... ) {
        std::cerr << "Error: unknown exception" << std::endl;
        return 1;
    }

    // Print the person array to the screen
    try {
        printData( readPersons );
    } catch ( const LogicError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( ... ) {
        std::cerr << "Error: unknown exception" << std::endl;
        return 1;
    }

    return 0;
}
