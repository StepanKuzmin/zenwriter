#include <QtGui/QApplication>
#include "zenwriter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ZenWriter w;
    w.show();

    return a.exec();
}
