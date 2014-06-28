
#include <vector>
#include <QString>
#include "gtest/gtest.h"
#include "freeFunctions.h"
#include "EmptyArgument.h"
#include "Person.h"

TEST( writeData001, emptyArgumentTest )
{
    QString fileName = "";

    Person david( "David", "White" );
    Person ivan( "Ivan", "Ivanov" );
    std::vector<Person> persons;
    persons.push_back( david );
    persons.push_back( ivan );

    ASSERT_THROW( {
                      writeData( fileName, persons );
                  }, EmptyArgument );
}

TEST( writeData002, emptyArgumentTest )
{
    QString fileName = "output.json";

    std::vector<Person> persons;

    ASSERT_THROW( {
                      writeData( fileName, persons );
                  }, EmptyArgument );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
