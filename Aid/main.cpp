#include "meny.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    meny w;
    w.showFullScreen();

    return a.exec();
}
