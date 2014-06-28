
#include <vector>
#include <iostream>

#include <QString>

#include "freeFunctions.h"
#include "Person.h"
#include "LogicError.h"
#include "FileError.h"

int main( )
{
    // Data
    Person david( "David", "White" );
    Person ivan( "Ivan", "Green" );
    std::vector<Person> personsOut;
    personsOut.push_back( david );
    personsOut.push_back( ivan );

    // Write data to the file
    QString fileName = "Persons.json";
    try {
        writeData( fileName, personsOut );
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

    // Read data from the file
    std::vector<Person> personsIn;
    try {
        readData( fileName, personsIn );
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

    // Print data
    try {
        printData( personsIn );
    } catch ( const LogicError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( ... ) {
        std::cerr << "Error: unknown exception" << std::endl;
        return 1;
    }

    return 0;
}
