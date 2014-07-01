
#include <QJsonArray>
#include "gtest/gtest.h"
#include "freeFunctions.h"

TEST( parsePersonsToContent_001, EmptyArgumentTest )
{
    // Input data
    std::vector<Person> persons;

    // Actual result
    QJsonDocument content;
    ASSERT_THROW( {
                      parsePersonsToContent( persons, content );
                  }, EmptyArgument );
}

TEST( parsePersonsToContent_002, firstNameOfFirstPerson )
{
    // Input data
    std::vector<Person> persons;
    Person david( "David", "White" );
    Person ivan( "Ivan", "Green" );
    persons.push_back( david );
    persons.push_back( ivan );

    // Get the actual result
    QJsonDocument content;
    ASSERT_NO_THROW( {
                         parsePersonsToContent( persons, content );
                     } );

    // Check the actual size
    std::size_t expectedSize = 2;
    QJsonArray personsObjectArray = content.array();
    std::size_t actualSize = personsObjectArray.size( );
    ASSERT_EQ( expectedSize, actualSize );

    // Actual result
    QJsonObject davidObject = personsObjectArray[0].toObject( );
    QString actual = davidObject["firstName"].toString() ;

    // Expected result
    QString expected = "David";

    // Check the actual result
    ASSERT_EQ( expected.toStdString( ), actual.toStdString( ) );
}

TEST( parsePersonsToContent_003, lastNameOfFirstPerson )
{
    // Input data
    std::vector<Person> persons;
    Person david( "David", "White" );
    Person ivan( "Ivan", "Green" );
    persons.push_back( david );
    persons.push_back( ivan );

    // Get the actual result
    QJsonDocument content;
    ASSERT_NO_THROW( {
                         parsePersonsToContent( persons, content );
                     } );

    // Check the actual size
    QJsonArray personsObjectArray = content.array( );
    std::size_t expectedSize = 2;
    std::size_t actualSize = personsObjectArray.size( );
    ASSERT_EQ( expectedSize, actualSize );

    // Actual result
    QJsonObject davidObject = personsObjectArray[0].toObject( );
    QString actual = davidObject["lastName"].toString( );

    // Expected result
    QString expected = "White";

    // Check the actual result
    ASSERT_EQ( expected.toStdString( ), actual.toStdString( ) );
}

TEST( parsePersonsToContent_004, firstNameOfSecondPerson )
{
    // Input data
    std::vector<Person> persons;
    Person david( "David", "White" );
    Person ivan( "Ivan", "Green" );
    persons.push_back( david );
    persons.push_back( ivan );

    // Get the actual result
    QJsonDocument content;
    ASSERT_NO_THROW( {
                         parsePersonsToContent( persons, content );
                     } );

    // Check the actual size
    QJsonArray personsObjectArray = content.array( );
    std::size_t expectedSize = 2;
    std::size_t actualSize = personsObjectArray.size( );
    ASSERT_EQ( expectedSize, actualSize );

    // Actual result
    QJsonObject ivanObject = personsObjectArray[1].toObject( );
    QString actual = ivanObject["firstName"].toString( );

    // Expected result
    QString expected = "Ivan";

    // Check the actual result
    ASSERT_EQ( expected.toStdString( ), actual.toStdString( ) );
}

TEST( parsePersonsToContent_005, lastNameOfSecondPerson )
{
    // Input data
    std::vector<Person> persons;
    Person david( "David", "White" );
    Person ivan( "Ivan", "Green" );
    persons.push_back( david );
    persons.push_back( ivan );

    // Get the actual result
    QJsonDocument content;
    ASSERT_NO_THROW( {
                         parsePersonsToContent( persons, content );
                     } );

    // Check the actual size
    QJsonArray personsObjectArray = content.array( );
    std::size_t expectedSize = 2;
    std::size_t actualSize = personsObjectArray.size( );
    ASSERT_EQ( expectedSize, actualSize );

    // Actual result
    QJsonObject ivanObject = personsObjectArray[1].toObject( );
    QString actual = ivanObject["lastName"].toString( );

    // Expected result
    QString expected = "Green";

    // Check the actual result
    ASSERT_EQ( expected.toStdString( ), actual.toStdString( ) );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
