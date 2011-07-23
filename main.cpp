#include <QtGui/QApplication>
#include "zenwriter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("ZenWriter");

    ZenWriter w;

    // Set default background
    /*
    QPalette palette;
    QString appDir = QApplication::applicationDirPath();
    palette.setBrush(w.backgroundRole(),QBrush(QImage(appDir +"/images/winter.jpg")));
    w.setPalette(palette);
    */
    
    w.show();
    //w.showFullScreen();
    return a.exec();
}
