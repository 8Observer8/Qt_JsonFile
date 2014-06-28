
#include <vector>
#include <QString>
#include "gtest/gtest.h"
#include "freeFunctions.h"
#include "Person.h"
#include "EmptyArgument.h"

TEST( readData001, emptyArgumentTest )
{
    QString fileName = "";
    std::vector<Person> persons;

    ASSERT_THROW( {
                      readData( fileName, persons );
                  }, EmptyArgument );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
