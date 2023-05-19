
#include "logmeny.h"

#include <QApplication>
#include <QDir>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    logmeny l;
    l.showFullScreen();


    return a.exec();
}
