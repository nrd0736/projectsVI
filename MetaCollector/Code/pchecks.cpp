#include "pchecks.h"

pchecks::pchecks(QString pathimg,QString met,QSqlDatabase bd,QDialog *parent) : QDialog(parent)
{

    META.append(met);
    PATH_CHEK.append(pathimg);
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
    QPixmap pixmap(PATH_CHEK);
    QSize PicSize(500, 500);
    showChek->setScaledContents(true);
    pixmap.scaled(PicSize,Qt::KeepAspectRatio);
    showChek->setPixmap(pixmap);
    showChek->setMask(pixmap.mask());
    showChek->setMaximumSize(700,500);


    QLabel *namebankT = new QLabel("Название банка");
    namebankT->setStyleSheet(lbstyle);
    namebankT->setFont(f1);
    QLabel *dateT = new QLabel("Дата операции");
    dateT->setStyleSheet(lbstyle);
    dateT->setFont(f1);
    QLabel *timeT = new QLabel("Время операции");
    timeT->setStyleSheet(lbstyle);
    timeT->setFont(f1);
    QLabel *senderT = new QLabel("Отправитель");
    senderT->setStyleSheet(lbstyle);
    senderT->setFont(f1);
    QLabel *takerT = new QLabel("Получатель");
    takerT->setStyleSheet(lbstyle);
    takerT->setFont(f1);
    QLabel *docnumT = new QLabel("Номер документа");
    docnumT->setStyleSheet(lbstyle);
    docnumT->setFont(f1);
    QLabel *fioT = new QLabel("ФИО получателя");
    fioT->setStyleSheet(lbstyle);
    fioT->setFont(f1);
    QLabel *sumT = new QLabel("Сумма чека");
    sumT->setStyleSheet(lbstyle);
    sumT->setFont(f1);

    QLabel *metDT = new QLabel("Метаданные");
    metDT->setStyleSheet("color: #c36c66;font-size: 14px; border: none;");
    metDT->setFont(f1);

    QTextEdit *metD = new QTextEdit(META);
    metD->setStyleSheet("color: #fff;font-size: 12px;border: none;");
    metD->setFont(f1);
    metD->setMaximumWidth(500);
    metD->setEnabled(false);

    namebank->setStyleSheet(txedstyle);
    namebank->setFont(f1);

    date->setStyleSheet(txedstyle);
    date->setFont(f1);

    time->setStyleSheet(txedstyle);
    time->setFont(f1);

    sender->setStyleSheet(txedstyle);
    sender->setFont(f1);

    taker->setStyleSheet(txedstyle);
    taker->setFont(f1);

    docnum->setStyleSheet(txedstyle);
    docnum->setFont(f1);

    fio->setStyleSheet(txedstyle);
    fio->setFont(f1);

    sum->setStyleSheet(txedstyle);
    sum->setFont(f1);

    connect(del,SIGNAL(clicked()),this,SLOT(delchek()));
    connect(save,SIGNAL(clicked()),this,SLOT(savechek()));

    QGridLayout* lay1 = new QGridLayout;
    lay1->addWidget(namebankT,0,0);
    lay1->addWidget(namebank,0,1);
    lay1->addWidget(dateT,1,0);
    lay1->addWidget(date,1,1);
    lay1->addWidget(timeT,2,0);
    lay1->addWidget(time,2,1);
    lay1->addWidget(senderT,3,0);
    lay1->addWidget(sender,3,1);
    lay1->addWidget(takerT,4,0);
    lay1->addWidget(taker,4,1);
    lay1->addWidget(docnumT,5,0);
    lay1->addWidget(docnum,5,1);
    lay1->addWidget(fioT,6,0);
    lay1->addWidget(fio,6,1);
    lay1->addWidget(sumT,7,0);
    lay1->addWidget(sum,7,1);

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





void pchecks::delchek()
{

    QStringList buflist;
    QString buf=PATH_CHEK;
    QString name;
    this->close();



    buflist=buf.split("/");
    name.append(buflist.at(buflist.size()-1));
    buflist.clear();
    buflist=name.split(".");
    name.clear();
    name.append(buflist.at(0));
        BD_cheks.open();

    BD_cheks.exec("DELETE FROM public.cheks WHERE \"phHESH\"='"+name+"';");
    BD_cheks.close();
   QFile::remove(PATH_CHEK);

}

void pchecks::savechek()
{
this->close();

    QStringList buflist;
    QString buf=PATH_CHEK;
    QString name;
    this->close();



    buflist=buf.split("/");
    name.append(buflist.at(buflist.size()-1));
    buflist.clear();
    buflist=name.split(".");
    name.clear();
    name.append(buflist.at(0));

    BD_cheks.open();

    if(namebank->text()=="")
    {namebank->setText("не найдено");}

    if(date->text()=="")
    {date->setText("не найдено");}

    if(time->text()=="")
    {time->setText("не найдено");}

    if(sender->text()=="")
    {sender->setText("не найдено");}

    if(taker->text()=="")
    {taker->setText("не найдено");}

    if(docnum->text()=="")
    {docnum->setText("не найдено");}

    if(fio->text()=="")
    {fio->setText("не найдено");}

    if(sum->text()=="")
    {sum->setText("не найдено");}


    BD_cheks.exec("UPDATE public.cheks SET  \"bankName\"='"+namebank->text()+"',date='"+date->text()+"', \"time\"='"+time->text()+"',sender='"+sender->text()+"', taker='"+taker->text()+"', \"numDoc\"='"+docnum->text()+"', \"FIO\"='"+fio->text()+"',\"sumM\"='"+sum->text()+"', \"readyIMG\"=true WHERE \"phHESH\"='"+name+"';");



}
