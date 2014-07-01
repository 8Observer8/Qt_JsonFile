
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include "gtest/gtest.h"
#include "freeFunctions.h"

TEST( writeData001, emptyArgumentTest )
{
    QString fileName = "";

    QJsonDocument content;
    QJsonArray personsObjectArray;
    // Add the first person to the array
    QJsonObject davidObject;
    Person david( "David", "White" );
    david.write( davidObject );
    personsObjectArray.append( davidObject );
    // Add the second person to the array
    QJsonObject ivanObject;
    Person ivan( "Ivan", "Green" );
    ivan.write( ivanObject );
    personsObjectArray.append( ivanObject );
    // Set the content
    content.setArray( personsObjectArray );

    ASSERT_THROW( {
                      writeData( fileName, content );
                  }, EmptyArgument );
}

TEST( writeData002, emptyArgumentTest )
{
    QString fileName = "output.json";

    QJsonDocument content;

    ASSERT_THROW( {
                      writeData( fileName, content );
                  }, EmptyArgument );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
