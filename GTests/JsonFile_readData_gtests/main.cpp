
#include <QString>
#include <QJsonDocument>
#include "gtest/gtest.h"
#include "freeFunctions.h"

TEST( readData001, emptyArgumentTest )
{
    QString fileName = "";

    QJsonDocument content;

    ASSERT_THROW( {
                      readData( fileName, content );
                  }, EmptyArgument );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
