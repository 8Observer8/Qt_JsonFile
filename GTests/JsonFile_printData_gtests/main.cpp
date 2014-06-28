
#include <vector>
#include "gtest/gtest.h"
#include "freeFunctions.h"
#include "Person.h"

TEST( printData001, emptyArgumentTest )
{
    std::vector<Person> persons;

    ASSERT_THROW( {
                      printData( persons );
                  }, EmptyArgument );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
