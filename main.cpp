
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

    try {
        // Parse the person array to the Json-content
        QJsonDocument content;
        parsePersonsToContent( persons, content );

        // Write the Json-content to the file
        QString fileName = "Persons.json";
        writeData( fileName, content );

        // Read the Json-content from the file
        QJsonDocument readContent;
        readData( fileName, readContent );

        // Parse the Json-content to the person array
        std::vector<Person> readPersons;
        parseContentToPersons( readContent, readPersons );

        // Print the person array to the screen
        printData( readPersons );
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

    return 0;
}
