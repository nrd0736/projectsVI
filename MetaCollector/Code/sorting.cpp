#include "sorting.h"

sorting::sorting(QWidget *parent) : QWidget(parent)
{
    int id = QFontDatabase::addApplicationFont(":/font/resors/ofont.ru_CutOut.ttf"); //путь к шрифту
        QString DatDot = QFontDatabase::applicationFontFamilies(id).at(0); //имя шрифта
        QFont f1(DatDot);  // QFont c вашим шрифтом

        this->setFixedWidth(500);
        this->setMinimumHeight(220);
    this->setStyleSheet("background-color: #292b6b");
    QString pbstyle;
    pbstyle.append("QPushButton{"
                    "font-size: 14px;"
                    "color: #fff;"
                    "background-color:  #292b6b;"
                    "border: 1px solid #494dab;}"
                    "QPushButton:hover{"
                    "background-color: black;} "
                    "QPushButton:pressed  {"
                    "color: #f5b207;"
                    "border: 3px solid black;"
                    " } ");
    QString lbstyle;
    lbstyle.append("color: #fff;font-size: 14px;background-color: none;");

    start->setFont(f1);
    start->setMinimumHeight(35);
    start->setStyleSheet(pbstyle);
    QLabel * status1 = new QLabel("CТАТУС");
    status1->setStyleSheet(lbstyle);
    status1->setFont(f1);

    lod1.setFileName(":/load/resors/30.gif");
    load1->setMovie(&lod1);
    load1->setStyleSheet("background-color: none;");

    statusind1->setStyleSheet("color: #666;font-size: 12px;background-color: none;");
    statusind1->setFont(f1);

    connect(start,SIGNAL(clicked()),this,SLOT(startsort()));
    connect(process,SIGNAL(finished(int)),this,SLOT(endsort()));


    QHBoxLayout* lay1 = new QHBoxLayout;
    lay1->addWidget(status1);
    lay1->addStretch(100);
    lay1->addStretch(100);
    lay1->addWidget(load1);
    lay1->addStretch(10);
    lay1->addWidget(statusind1);

    QVBoxLayout* mlay = new QVBoxLayout;
    mlay->addStretch(10);
    mlay->addWidget(start);
    mlay->addStretch(10);
    mlay->addLayout(lay1);
    this->setLayout(mlay);
}

void sorting::startsort()
{//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    QString executable;
        executable.append("cd "+QCoreApplication::applicationDirPath());
        executable.append("/main");
        process->start("cmd.exe", QStringList() << "/c" <<executable +" & "+"main.exe" );


    lod1.start();
    statusind1->setText("обработка");
    statusind1->setStyleSheet("color: #f5b207;font-size: 12px;");
}

void sorting::endsort()
{
    lod1.stop();
    load1->close();
    statusind1->setText("данные обработаны");
    statusind1->setStyleSheet("color: #00b812;font-size: 12px;");
    ready=true;
}
