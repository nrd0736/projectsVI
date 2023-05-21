#include "meny.h"

meny::meny(QWidget *parent)
    : QWidget(parent)
{
    //this->setFocus(foc)
    QString backstyle(" background-color: black ");
    QString frontstyle("color: #1bb004;");

    QString buttonstyle("QPushButton{"
                        "color: #1bb004;"
                        "background-color: black;"
                        "border: 3px solid #1bb004;}"
                        "QPushButton:hover{"
                        "color:black;"
                        "background-color: #1bb004;} "
                        "QPushButton:pressed  {"
                        "background-color: #f5b207;"
                        "border: 3px dotted black;"
                        " } ");


    this->setStyleSheet(backstyle);

    int id = QFontDatabase::addApplicationFont(":/Res/Fonts/Res/Fonts/LCD5x8HRU.ttf"); //путь к шрифту
        QString DatDot = QFontDatabase::applicationFontFamilies(id).at(0); //имя шрифта
        QFont d1(DatDot);  // QFont c вашим шрифтом

    int id1 = QFontDatabase::addApplicationFont(":/Res/Fonts/Res/Fonts/Nikoleta.ttf"); //путь к шрифту
         QString DatDot1 = QFontDatabase::applicationFontFamilies(id1).at(0); //имя шрифта
         QFont d2(DatDot1);  // QFont c вашим шрифтом

    QLabel* labelIcon1=new QLabel;
        QPixmap img1;
        img1.load(":/Res/Img/Res/Img/aidIcon.jpg");
        labelIcon1->clear();
        labelIcon1->setPixmap(img1);

     QLabel* labelIcon2=new QLabel;
         QPixmap img2;
         img2.load(":/Res/Img/Res/Img/aidIcon.jpg");
         labelIcon2->clear();
         labelIcon2->setPixmap(img2);


    QLabel* name1=new QLabel("АИД");
        d1.setPointSize(40);
        name1->setFont(d1);
        name1->setStyleSheet(frontstyle);


    QLabel* name2=new QLabel("      СИСТЕМА МОДЕЛИРОВАНИЯ ЯДЕРНОГО БОЕСТОЛКНОВЕНИЯ      ");
        d1.setPointSize(15);
        name2->setFont(d1);
        name2->setStyleSheet(frontstyle);


        QHBoxLayout *namelay1=new QHBoxLayout;
            namelay1->addStretch(10);
            namelay1->addWidget(labelIcon1);
            namelay1->addWidget(name2);
            namelay1->addWidget(labelIcon2);
            namelay1->addStretch(10);
        QHBoxLayout *namelay2=new QHBoxLayout;
            namelay2->addStretch(10);
            namelay2->addWidget(name1);
            namelay2->addStretch(10);
        QVBoxLayout *namelay3=new QVBoxLayout;
            namelay3->addStretch(10);
            namelay3->addLayout(namelay1);
            namelay3->addLayout(namelay2);
            namelay3->addStretch(10);

        d1.setPointSize(12);

        start->setFont(d1);
        start->setFixedSize(250,40);
        start->setStyleSheet(buttonstyle);

        connect(start,SIGNAL(clicked()),this,SLOT(ckl_start()));
        connect(timer1,SIGNAL(timeout()),this,SLOT(time_start()));


        QPushButton* inf = new QPushButton("Информация о системе");
        inf->setFont(d1);
        inf->setFixedSize(250,40);
        inf->setStyleSheet(buttonstyle);

        QPushButton* exit = new QPushButton("Выйти");
        exit->setFont(d1);
        exit->setFixedSize(250,40);
        exit->setStyleSheet(buttonstyle);

        QVBoxLayout* pushlay1= new QVBoxLayout;
        pushlay1->addWidget(start);
        pushlay1->addWidget(inf);
        pushlay1->addWidget(exit);

        QHBoxLayout* pushlay2=new QHBoxLayout;
        pushlay2->addStretch(10);
        pushlay2->addLayout(pushlay1);
        pushlay2->addStretch(10);

        QVBoxLayout* mainlay=new QVBoxLayout;
        mainlay->addStretch(10);
        mainlay->addLayout(namelay3);
        mainlay->addStretch(10);
        mainlay->addLayout(pushlay2);
        mainlay->addStretch(10);

        this->setLayout(mainlay);
}

meny::~meny()
{

}

void meny::ckl_start()
{
    time1=0;
    timer1->start(300);


}

void meny::time_start()
{
    time1++;
    if (time1%2!=0)
    {
     start->setStyleSheet("QPushButton{background-color: #f5b207;"
                          "border: 3px dotted black;}");
    }

    if (time1%2==0)
    {
     start->setStyleSheet("QPushButton{color:black; background-color: #1bb004;"
                          "border: 3px solid #1bb004;}");
    }
    if (time1==11)
    {
        start->setStyleSheet("QPushButton{background-color: #db1f12;"
                             "border: 3px dotted black;}");
        timer1->stop();
    }
}
