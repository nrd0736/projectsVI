#include "dialogi.h"

DialogI::DialogI(QDialog *parent) : QDialog(parent)
{
setWindowTitle("Аутефикация");
QIcon icon;
icon.addFile(":/res/icon.png");
setWindowIcon(icon);
this->setMaximumSize(300,100);


passLog->setMaximumHeight(25);
passLog->setEchoMode(QLineEdit::Password);
QHBoxLayout* lay1=new QHBoxLayout;
lay1->addWidget(ok);
lay1->addWidget(exit);

QVBoxLayout* mainlay=new QVBoxLayout;
mainlay->addWidget(inf);
mainlay->addWidget(passLog);
mainlay->addLayout(lay1);
this->setLayout(mainlay);

connect(ok,SIGNAL(clicked()),this,SLOT(chekpass()));
connect(exit,SIGNAL(clicked()),this,SLOT(close()));
}
void DialogI::chekpass()
{
    QString buf;
    buf=passLog->text();
    if(buf !=pass)
    {

        inf->setText("НЕВЕРНЫЙ ПАРОЛЬ");
        passLog->setEchoMode(QLineEdit::Password);

    }
    else {
    inf->setText("ВЕРНЫЙ ПАРОЛЬ");
    this->close();
    emit passT();
    }
}
