
#include <gtest/gtest.h>
#include <string>

#include <QString>

#include "Person.h"

TEST( test001, firstNameTest ) {
    Person david( "David", "White" );

    QString actual = david.firstName( );
    QString expected = "David";

    ASSERT_EQ( expected.toStdString( ), actual.toStdString( ) );
}

TEST( test002, lastNameTest ) {
    Person david( "David", "White" );

    QString actual = david.lastName( );
    QString expected = "White";

    ASSERT_EQ( expected.toStdString( ), actual.toStdString( ) );
}

int main( int argc, char *argv[] ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
