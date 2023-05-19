#include <QApplication>
#include <QDebug>
#include "control.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    control pars;
    pars.show();
    return a.exec();

}
