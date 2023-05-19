#include "pgeo.h"

pgeo::pgeo(QString pathimg,QString met,QSqlDatabase bd,QDialog *parent) : QDialog(parent)
{
    META.append(met);
    PATH_GEO.append(pathimg);
    BD_cheks = bd;
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setMaximumSize(1100,800);
    int id = QFontDatabase::addApplicationFont(":/font/resors/ofont.ru_CutOut.ttf"); //путь к шрифту
        QString DatDot = QFontDatabase::applicationFontFamilies(id).at(0); //имя шрифта
        QFont f1(DatDot);  // QFont c вашим шрифтом
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
    lbstyle.append("color: #fff;font-size: 14px;");
    QString txedstyle;
    txedstyle.append(" QLineEdit {"
                     "font-size: 13px;"
                     " color: #8182a3;"
                    "  border: 3px solid #494dab;"
                    "   padding: 5px 15px;"
                    "   }"
                     "QLineEdit::focus {"
                     " border: 3px solid #2327a6;}");

    QPushButton* save = new QPushButton("   сохранить   ");
    save->setMinimumHeight(35);
    save->setStyleSheet(pbstyle);
    save->setFont(f1);

    QPushButton* del = new QPushButton("   удалить   ");
    del->setMinimumHeight(35);
    del->setStyleSheet(pbstyle);
    del->setFont(f1);

    QPushButton* shmap = new QPushButton("   показать на карте   ");
    shmap->setMinimumHeight(35);
    shmap->setStyleSheet(pbstyle);
    shmap->setFont(f1);

    QLabel *showChek = new QLabel;
    QPixmap pixmap(pathimg);
    QSize PicSize(500, 500);
    showChek->setScaledContents(true);
    pixmap.scaled(PicSize,Qt::KeepAspectRatio);
    showChek->setPixmap(pixmap);
    showChek->setMask(pixmap.mask());
    showChek->setMaximumSize(700,500);


    QLabel *msh = new QLabel("Широта");
    msh->setStyleSheet(lbstyle);
    msh->setFont(f1);
    QLabel *md = new QLabel("Долгота");
    md->setStyleSheet(lbstyle);
    md->setFont(f1);
    QLabel *p1 = new QLabel(".");
    p1->setStyleSheet(lbstyle);
    p1->setFont(f1);
    QLabel *p2 = new QLabel(".");
    p2->setStyleSheet(lbstyle);
    p2->setFont(f1);
    QLabel *oblT = new QLabel("Субъект");
    oblT->setStyleSheet(lbstyle);
    oblT->setFont(f1);

    QLabel *metDT = new QLabel("Метаданные");
    metDT->setStyleSheet("color: #c36c66;font-size: 14px; border: none;");
    metDT->setFont(f1);

    QTextEdit *metD = new QTextEdit(META);
    metD->setStyleSheet("color: #fff;font-size: 12px;border: none;");
    metD->setFont(f1);
    metD->setMaximumWidth(500);
    metD->setEnabled(false);




    sh1->setStyleSheet(txedstyle);
    sh1->setFont(f1);
    sh1->setMaximumWidth(70);

    sh2->setStyleSheet(txedstyle);
    sh2->setFont(f1);

    d1->setStyleSheet(txedstyle);
    d1->setFont(f1);
    d1->setMaximumWidth(70);

    d2->setStyleSheet(txedstyle);
    d2->setFont(f1);

    obl->setStyleSheet(txedstyle);
    obl->setFont(f1);

    connect(del,SIGNAL(clicked()),this,SLOT(delchek()));
    connect(save,SIGNAL(clicked()),this,SLOT(savechek()));
    connect(shmap,SIGNAL(clicked()),this,SLOT(gotomap()));

    QGridLayout* lay11 = new QGridLayout;
    lay11->addWidget(msh,0,0);
    lay11->addWidget(sh1,0,1);
    lay11->addWidget(p1,0,2);
    lay11->addWidget(sh2,0,3);

    lay11->addWidget(md,1,0);
    lay11->addWidget(d1,1,1);
    lay11->addWidget(p2,1,2);
    lay11->addWidget(d2,1,3);


    QGridLayout* lay4 = new QGridLayout;
    lay4->addWidget(oblT,0,0);
    lay4->addWidget(obl,0,1);

    QVBoxLayout* lay1= new QVBoxLayout;
    lay1->addLayout(lay11);
    lay1->addLayout(lay4);


    QHBoxLayout* lay2 = new QHBoxLayout;
    lay2->addStretch(1);
    lay2->addWidget(del);
    lay2->addStretch(3);
    lay2->addWidget(save);
    lay2->addStretch(3);
    lay2->addWidget(shmap);
    lay2->addStretch(15);

    QHBoxLayout* lay3 = new QHBoxLayout;
    lay3->addWidget(showChek);
    lay3->addStretch(2);
    lay3->addLayout(lay1);

    QVBoxLayout* mlay1= new QVBoxLayout;
    mlay1->addStretch(1);
    mlay1->addLayout(lay3);
    mlay1->addStretch(1);
    mlay1->addWidget(metDT);
    mlay1->addWidget(metD);
    mlay1->addStretch(1);
    mlay1->addLayout(lay2);
    mlay1->addStretch(1);
    this->setLayout(mlay1);
}





void pgeo::delchek()
{
    {
        QStringList buflist;
        QString buf=PATH_GEO;
        QString name;
        this->close();



        buflist=buf.split("/");
        name.append(buflist.at(buflist.size()-1));
        buflist.clear();
        buflist=name.split(".");
        name.clear();
        name.append(buflist.at(0));
            BD_cheks.open();

        BD_cheks.exec("DELETE FROM public.geometki WHERE \"phHESH\"='"+name+"';");
        BD_cheks.close();
       QFile::remove(PATH_GEO);


    }

}

void pgeo::savechek()
{
this->close();


    this->close();

        QStringList buflist;
        QString buf=PATH_GEO;
        QString names;
        this->close();



        buflist=buf.split("/");
        names.append(buflist.at(buflist.size()-1));
        buflist.clear();
        buflist=names.split(".");
        names.clear();
        names.append(buflist.at(0));

        BD_cheks.open();




        if(sh1->text()=="")
        {sh1->setText("не найдено");}

        if(sh2->text()=="")
        {sh2->setText("не найдено");}

        if(d1->text()=="")
        {d1->setText("не найдено");}

        if(d2->text()=="")
        {d2->setText("не найдено");}

        if(obl->text()=="")
        {obl->setText("не найдено");}


        BD_cheks.exec("UPDATE public.geometki SET  sh1='"+sh1->text()+"',sh2='"+sh2->text()+"', d1='"+d1->text()+"',d2='"+d2->text()+"', obl='"+obl->text()+"',  \"readyIMG\"=true WHERE \"phHESH\"='"+names+"';");


}

void pgeo::gotomap()
{
    QString mapurl;
    mapurl.append("https://wikimapia.org/?ysclid=lhje68412x244954989#lang=ru&lat="+d1->text()+"."+d2->text()+"&lon="+sh1->text()+"."+sh2->text()+"&z=13&m=w&search="+sh1->text()+"."+sh2->text()+"%20"+d1->text()+"."+d2->text());
    QDesktopServices::openUrl(QUrl(mapurl));
    //"https://wikimapia.org/?ysclid=lhje68412x244954989#lang=ru&lat=51.398777&lon=51.225471&z=13&m=w&search=51.225489%2051.39878"
}
