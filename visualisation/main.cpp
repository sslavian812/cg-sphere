#include <QApplication>

#include "example.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Example p;
    p.show();

    return app.exec();
}
