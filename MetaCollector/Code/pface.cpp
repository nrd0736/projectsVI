#include "pface.h"

pface::pface(QString pathimg,QString met,QSqlDatabase bd,QDialog *parent) : QDialog(parent)
{
    META.append(met);
    PATH_FACE.append(pathimg);
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

    QLabel *showChek = new QLabel;
    QPixmap pixmap(pathimg);
    QSize PicSize(500, 500);
    showChek->setScaledContents(true);
    pixmap.scaled(PicSize,Qt::KeepAspectRatio);
    showChek->setPixmap(pixmap);
    showChek->setMask(pixmap.mask());
    showChek->setMaximumSize(700,500);


    QLabel *nameT = new QLabel("Имя");
    nameT->setStyleSheet(lbstyle);
    nameT->setFont(f1);
    QLabel *famT = new QLabel("Фамилия");
    famT->setStyleSheet(lbstyle);
    famT->setFont(f1);
    QLabel *otchT = new QLabel("Отчество");
    otchT->setStyleSheet(lbstyle);
    otchT->setFont(f1);
    QLabel *dataT = new QLabel("Дата");
    dataT->setStyleSheet(lbstyle);
    dataT->setFont(f1);
    QLabel *seriaT = new QLabel("Серия паспорта");
    seriaT->setStyleSheet(lbstyle);
    seriaT->setFont(f1);
    QLabel *numT = new QLabel("Номер паспорта");
    numT->setStyleSheet(lbstyle);
    numT->setFont(f1);


    QLabel *metDT = new QLabel("Метаданные");
    metDT->setStyleSheet("color: #c36c66;font-size: 14px; border: none;");
    metDT->setFont(f1);

    QTextEdit *metD = new QTextEdit(META);
    metD->setStyleSheet("color: #fff;font-size: 12px;border: none;");
    metD->setFont(f1);
    metD->setMaximumWidth(500);
    metD->setEnabled(false);

    name->setStyleSheet(txedstyle);
    name->setFont(f1);

    fam->setStyleSheet(txedstyle);
    fam->setFont(f1);

    otch->setStyleSheet(txedstyle);
    otch->setFont(f1);

    data->setStyleSheet(txedstyle);
    data->setFont(f1);

    seria->setStyleSheet(txedstyle);
    seria->setFont(f1);

    num->setStyleSheet(txedstyle);
    num->setFont(f1);



    connect(del,SIGNAL(clicked()),this,SLOT(delchek()));
    connect(save,SIGNAL(clicked()),this,SLOT(savechek()));

    QGridLayout* lay1 = new QGridLayout;
    lay1->addWidget(nameT,0,0);
    lay1->addWidget(name,0,1);
    lay1->addWidget(famT,1,0);
    lay1->addWidget(fam,1,1);
    lay1->addWidget(otchT,2,0);
    lay1->addWidget(otch,2,1);
    lay1->addWidget(dataT,3,0);
    lay1->addWidget(data,3,1);
    lay1->addWidget(seriaT,4,0);
    lay1->addWidget(seria,4,1);
    lay1->addWidget(numT,5,0);
    lay1->addWidget(num,5,1);


    QHBoxLayout* lay2 = new QHBoxLayout;
    lay2->addStretch(1);
    lay2->addWidget(del);
    lay2->addStretch(3);
    lay2->addWidget(save);
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




void pface::delchek()
{
    QStringList buflist;
    QString buf=PATH_FACE;
    QString name;
    this->close();



    buflist=buf.split("/");
    name.append(buflist.at(buflist.size()-1));
    buflist.clear();
    buflist=name.split(".");
    name.clear();
    name.append(buflist.at(0));
        BD_cheks.open();

    BD_cheks.exec("DELETE FROM public.faces WHERE \"phHESH\"='"+name+"';");
    BD_cheks.close();
   QFile::remove(PATH_FACE);


}

void pface::savechek()
{
    this->close();

        QStringList buflist;
        QString buf=PATH_FACE;
        QString names;
        this->close();



        buflist=buf.split("/");
        names.append(buflist.at(buflist.size()-1));
        buflist.clear();
        buflist=names.split(".");
        names.clear();
        names.append(buflist.at(0));

        BD_cheks.open();


        if(name->text()=="")
        {name->setText("не найдено");}

        if(fam->text()=="")
        {fam->setText("не найдено");}

        if(otch->text()=="")
        {otch->setText("не найдено");}

        if(data->text()=="")
        {data->setText("не найдено");}

        if(seria->text()=="")
        {seria->setText("не найдено");}

        if(num->text()=="")
        {num->setText("не найдено");}




        BD_cheks.exec("UPDATE public.faces SET  name='"+name->text()+"',famil='"+fam->text()+"', otch='"+otch->text()+"',date='"+data->text()+"', \"serPASP\"='"+seria->text()+"', \"numPASP\"='"+num->text()+"', \"readyIMG\"=true WHERE \"phHESH\"='"+names+"';");






}
