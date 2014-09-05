#include <QApplication>
#include <gtest/gtest.h>

#include "exampleclass.h"

int main(int argc, char *argv[])
{
#ifdef __TESTS
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#endif

    QApplication app(argc, argv);

    ExampleClass p;
    p.show();

    return app.exec();
}
