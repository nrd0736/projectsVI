#include "logmeny.h"

logmeny::logmeny(QWidget *parent) : QWidget(parent)
{
    logD.append("admin");
    pasD.append("0736");

    QPalette pal(QPalette::Background);

      pal.setBrush(this->backgroundRole(), QBrush(QPixmap(":/fimg/resors/fon3.jpg")));
          this->setAutoFillBackground(true);
      this->setPalette(pal);

    int id = QFontDatabase::addApplicationFont(":/font/resors/ofont.ru_CutOut.ttf"); //путь к шрифту
        QString DatDot = QFontDatabase::applicationFontFamilies(id).at(0); //имя шрифта
        QFont f1(DatDot);  // QFont c вашим шрифтом
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
    QString txedstyle;
    txedstyle.append(" QLineEdit {"
                     "font-size: 13px;"
                     " color: #8182a3;"
                    "  border: 3px solid #494dab;"
                    "   padding: 5px 15px;"
                    "   }"
                     "QLineEdit::focus {"
                     " border: 3px solid #2327a6;}");
    QString groupst("QGroupBox {opacity: 0.8; font-size: 16pt;border: 1px solid #000069; margin-top:5ex; background-color: rgba(41, 43, 107, 0.50);}"
                    "QGroupBox::title {subcontrol-origin:margin;background-color: none;color:white; subcontrol-position:top center;padding:0 3px; }");

    QLabel * log = new QLabel("Логин");
    log->setStyleSheet(lbstyle);
    log->setFont(f1);
    QLabel * pas = new QLabel("Пароль");
    pas->setStyleSheet(lbstyle);
    pas->setFont(f1);
    QLabel * name = new QLabel("НАРКО-ЛОКАТОР");
    name->setStyleSheet("color: #fff;font-size: 40px;");
    name->setFont(f1);
    QLabel * status = new QLabel("CТАТУС");
    status->setStyleSheet(lbstyle);
    status->setFont(f1);
    QPushButton* go = new QPushButton("   Вход   ");
    go->setFont(f1);
    go->setStyleSheet(pbstyle);
    go->setMinimumHeight(35);
    QPushButton* exit = new QPushButton("   Выйти   ");
    exit->setFont(f1);
    exit->setStyleSheet(pbstyle);
    exit->setMinimumHeight(35);

    login->setStyleSheet(txedstyle);
    login->setFont(f1);


    pass->setStyleSheet(txedstyle);
    pass->setFont(f1);
    pass->setEchoMode(QLineEdit::Password);


    lod1.setFileName(":/load/resors/30.gif");
    load1->setMovie(&lod1);

    statusind1->setStyleSheet("color: #666;font-size: 12px;");
    statusind1->setFont(f1);

    connect(go,SIGNAL(clicked()),this,SLOT(ckl_start()));
    connect(exit,SIGNAL(clicked()),this,SLOT(close()));
    connect(timer1,SIGNAL(timeout()),this,SLOT(time_start()));

    QGroupBox *Gr = new QGroupBox(tr("Авторизация"));
    Gr->setAlignment(Qt::AlignCenter);
    Gr->setFixedSize(380,220);
    Gr->setStyleSheet(groupst);
    Gr->setFont(f1);

    QGridLayout* lay1 = new QGridLayout;
    lay1->addWidget(log,0,0);
    lay1->addWidget(login,0,1);
    lay1->addWidget(pas,1,0);
    lay1->addWidget(pass,1,1);

    QHBoxLayout* lay2 = new QHBoxLayout;
    lay2->addWidget(status);
    lay2->addStretch(100);
    lay2->addStretch(100);
    lay2->addWidget(load1);
    lay2->addStretch(10);
    lay2->addWidget(statusind1);

    QHBoxLayout* lay3 = new QHBoxLayout;
    lay3->addWidget(exit);
    lay3->addStretch(100);
    lay3->addWidget(go);

    QVBoxLayout* groplay = new QVBoxLayout;
    groplay->addLayout(lay1);
    groplay->addStretch(10);
    groplay->addLayout(lay3);
    groplay->addStretch(10);
    groplay->addStretch(10);
    groplay->addLayout(lay2);

    Gr->setLayout(groplay);

    QVBoxLayout* mlay1 = new QVBoxLayout;
    mlay1->addStretch(10);
    mlay1->addWidget(name);
    mlay1->addStretch(10);
    mlay1->addStretch(10);
    mlay1->addWidget(Gr);
    mlay1->addStretch(10);

    QHBoxLayout* mlay2 = new QHBoxLayout;
    mlay2->addStretch(10);
    mlay2->addLayout(mlay1);
    mlay2->addStretch(10);

    this->setLayout(mlay2);
}
void logmeny::ckl_start()
{
    time1=0;
    timer1->start(300);


}

void logmeny::time_start()
{
    time1++;
    if (time1!=11)
    {
        load1->show();
        lod1.start();
        statusind1->setText("проверка данных");
        statusind1->setStyleSheet("color: #f5b207;font-size: 12px;");
    }

    if (time1==11 && login->text()==logD && pass->text()==pasD)
    {
        lod1.stop();
        load1->close();
        statusind1->setText("вход подтверждён");
        statusind1->setStyleSheet("color: #00b812;font-size: 12px;");
        timer1->stop();
        meny *startprog = new meny;
        this->close();
        startprog->showFullScreen();
    }else if (time1==11 && (login->text()!=logD || pass->text()!=pasD)){
        lod1.stop();
        load1->close();
        statusind1->setText("ошибка авторизации");
        statusind1->setStyleSheet("color: #c70202;font-size: 12px;");
        timer1->stop();
}
}

