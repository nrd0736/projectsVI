#include "meny.h"
#include "starticon.h"
#include <QObject>
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   meny *m= new meny;
   StartIcon *st = new StartIcon;
    QObject::connect(st->start,SIGNAL(clicked()),m,SLOT(showFullScreen()));
    QObject::connect(st->start,SIGNAL(clicked()),st,SLOT(close()));
    st->showFullScreen();

    return a.exec();
}

