 #include "databazeconnect.h"

databazeconnect::databazeconnect(QWidget *parent)
    : QWidget(parent)
{
    int id = QFontDatabase::addApplicationFont(":/font/resors/ofont.ru_CutOut.ttf"); //путь к шрифту
        QString DatDot = QFontDatabase::applicationFontFamilies(id).at(0); //имя шрифта
        QFont f1(DatDot);  // QFont c вашим шрифтом

    this->setMinimumHeight(220);
        this->setFixedWidth(500);
    this->setStyleSheet("background-color: #292b6b");
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


    nBd->setStyleSheet(txedstyle);
    nBd->setFont(f1);

    n->setStyleSheet(txedstyle);
    n->setFont(f1);

    p->setStyleSheet(txedstyle);
    p->setFont(f1);
    p->setEchoMode(QLineEdit::Password);

    QLabel * nBdT = new QLabel("Название БД");
    nBdT->setStyleSheet(lbstyle);
    nBdT->setFont(f1);
    QLabel * nT = new QLabel("Логин");
    nT->setStyleSheet(lbstyle);
    nT->setFont(f1);
    QLabel * pT = new QLabel("Пароль");
    pT->setStyleSheet(lbstyle);
    pT->setFont(f1);
    QLabel * status = new QLabel("CТАТУС");
    status->setStyleSheet(lbstyle);
    status->setFont(f1);

    statusind->setStyleSheet("color: #666;font-size: 12px;background-color: none;");
    statusind->setFont(f1);


    connectr->setFont(f1);
    connectr->setMinimumHeight(35);
    connectr->setStyleSheet("QPushButton{"
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

    connect(connectr,SIGNAL(clicked()),this,SLOT(connection()));
    QGridLayout* lay1 = new QGridLayout;
    lay1->addWidget(nBdT,0,0);
    lay1->addWidget(nBd,0,1);
    lay1->addWidget(nT,1,0);
    lay1->addWidget(n,1,1);
    lay1->addWidget(pT,2,0);
    lay1->addWidget(p,2,1);

    QHBoxLayout* lay2 = new QHBoxLayout;
    lay2->addStretch(10);
    lay2->addWidget(connectr);

    QHBoxLayout* lay3 = new QHBoxLayout;
    lay3->addWidget(status);
    lay3->addStretch(10);
    lay3->addWidget(statusind);

    QVBoxLayout * mlay = new QVBoxLayout;
    mlay->addLayout(lay1);
    mlay->addStretch(10);
    mlay->addLayout(lay2);
    mlay->addStretch(10);
    mlay->addLayout(lay3);

    this->setLayout(mlay);
}

databazeconnect::~databazeconnect()
{

}

bool databazeconnect::connectBD(QString nameBD, QString name, QString pass)
{
    DB.setDatabaseName(nameBD);
    DB.setUserName(name);
    DB.setPassword(pass);

    if (DB.open()){

        return true;
    }
    else {


            return false;

    }

}

QSqlDatabase databazeconnect::giveBD()
{
    return DB;
}

void databazeconnect::connection()
{
    if(connectBD(nBd->text(),n->text(),p->text()))
    {
         statusind->setText("БД подключена");
         statusind->setStyleSheet("color: #00b812;font-size: 12px; background-color: none;");
         ready=true;
    }
    else
    {
        statusind->setText("ошибка подключения");
        statusind->setStyleSheet("color: #c70202;font-size: 12px;background-color: none;");
    }
}
