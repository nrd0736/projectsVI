#include "reginbd.h"

reginBD::reginBD(QWidget *parent) : QWidget(parent)
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
    start->setMinimumHeight(60);
    start->setStyleSheet(pbstyle);
    QLabel * status1 = new QLabel("CТАТУС");
    status1->setStyleSheet(lbstyle);
    status1->setFont(f1);

    lod1.setFileName(":/load/resors/30.gif");
    load1->setMovie(&lod1);
    load1->setStyleSheet("background-color: none;");

    statusind1->setStyleSheet("color: #666;font-size: 12px;background-color: none;");
    statusind1->setFont(f1);

    connect(start,SIGNAL(clicked()),this,SLOT(getfile()));



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

void reginBD::getfile()
{

    lod1.start();
    statusind1->setText("обработка");
    statusind1->setStyleSheet("color: #f5b207;font-size: 12px;background-color: none;");
    //--------------------------------------------ЧЕКИ-------------------------------------------
    QStringList cheksList;
    QString comand1;
    comand1.append(QCoreApplication::applicationDirPath()+"/main/img/chek");
    QDir chekdir(comand1);
    cheksList=chekdir.entryList();
    for (int H = 0;H<cheksList.size(); H++) {
        QString minbuf;
     if (cheksList[H].size()<=3  )
     {
         minbuf =cheksList.at(H);
         minbuf.fill(' ',1);
         cheksList[H]=minbuf;
     }
    }
    cheksList.removeAll(QString(" "));


    for (int i = 0;i<cheksList.size();i++)
    {

       QFile::copy(comand1+"/"+cheksList.at(i), QCoreApplication::applicationDirPath()+"/buf/chek/" +cheksList.at(i));

        //--------------------------------------ЧИТАЕМ МЕТА-------------------------------------------------
       QString metadat1;
        QFile meta(QCoreApplication::applicationDirPath()+"/main/img/metadata/chek.txt");
        meta.open(QIODevice::ReadOnly);

        bool rB=false;

        while (!meta.atEnd())
        {
            QString readbuf;
            readbuf=meta.readLine();
            if (readbuf=="hash["+cheksList.at(i)+"] {\r\n") {rB=true; continue;}
            if (rB==true && readbuf=="\tnone\r\n") { metadat1="ничего не найдено"; break;}
            if (rB==true && readbuf=="}\r\n") { if (metadat1 == "") metadat1="ничего не найдено"; break;}
            if (rB==true) {metadat1=metadat1.append(readbuf);}
        }
         meta.close();
                sentoBD(cheksList.at(i),metadat1,0);
       QFile::remove(comand1+"/"+cheksList.at(i));
    }
        //--------------------------------------------ГЕОМЕТКИ-------------------------------------------
    QStringList geoList;
    QString comand2;
    comand2.append(QCoreApplication::applicationDirPath()+"/main/img/mark,geometka");
    QDir geodir(comand2);
    geoList=geodir.entryList();
    for (int H = 0;H<geoList.size(); H++) {
        QString minbuf;
     if (geoList[H].size()<=3  )
     {
         minbuf =geoList.at(H);
         minbuf.fill(' ',1);
         geoList[H]=minbuf;
     }
    }
    geoList.removeAll(QString(" "));


    for (int i = 0;i<geoList.size();i++)
    {

        QFile::copy(comand2+"/"+geoList.at(i), QCoreApplication::applicationDirPath()+"/buf/geo/" +geoList.at(i));

        QString metadat1;
         QFile meta(QCoreApplication::applicationDirPath()+"/main/img/metadata/mark,geometka.txt");
         meta.open(QIODevice::ReadOnly);

         bool rB=false;

         while (!meta.atEnd())
         {
             QString readbuf;
             readbuf=meta.readLine();
             if (readbuf=="hash["+geoList.at(i)+"] {\r\n") {rB=true; continue;}
             if (rB==true && readbuf=="\tnone\r\n") { metadat1="ничего не найдено"; break;}
             if (rB==true && readbuf=="}\r\n") { if (metadat1 == "") metadat1="ничего не найдено"; break;}
             if (rB==true) {metadat1=metadat1.append(readbuf);}
         }
         meta.close();
                 sentoBD(geoList.at(i),metadat1,1);

        QFile::remove(comand2+"/"+geoList.at(i));
    }
    //--------------------------------------------ЛИЦА-------------------------------------------
QStringList faceList;
QString comand3;
comand3.append(QCoreApplication::applicationDirPath()+"/main/img/pasport,face,paper");
QDir facedir(comand3);
faceList=facedir.entryList();
for (int H = 0;H<faceList.size(); H++) {
    QString minbuf;
 if (faceList[H].size()<=3  )
 {
     minbuf =faceList.at(H);
     minbuf.fill(' ',1);
     faceList[H]=minbuf;
 }
}
faceList.removeAll(QString(" "));


for (int i = 0;i<faceList.size();i++)
{
    QFile::copy(comand3+"/"+faceList.at(i), QCoreApplication::applicationDirPath()+"/buf/face/" +faceList.at(i));

    QString metadat1;
     QFile meta(QCoreApplication::applicationDirPath()+"/main/img/metadata/pasport,face,paper.txt");
     meta.open(QIODevice::ReadOnly);

     bool rB=false;

     while (!meta.atEnd())
     {
         QString readbuf;
         readbuf=meta.readLine();
         if (readbuf=="hash["+faceList.at(i)+"] {\r\n") {rB=true; continue;}
         if (rB==true && readbuf=="\tnone\r\n") { metadat1="ничего не найдено"; break;}
         if (rB==true && readbuf=="}\r\n") { if (metadat1 == "") metadat1="ничего не найдено"; break;}
         if (rB==true) {metadat1=metadat1.append(readbuf);}
     }
      meta.close();
             sentoBD(faceList.at(i),metadat1,2);


    QFile::remove(comand3+"/"+faceList.at(i));
}

lod1.stop();
load1->close();
statusind1->setText("данные получены");
statusind1->setStyleSheet("color: #00b812;font-size: 12px;background-color: none;");
ready= true;
int id = QFontDatabase::addApplicationFont(":/font/resors/ofont.ru_CutOut.ttf"); //путь к шрифту
    QString DatDot = QFontDatabase::applicationFontFamilies(id).at(0); //имя шрифта
    QFont f1(DatDot);  // QFont c вашим шрифтом
QMessageBox helper;
helper.setWindowFlags(Qt::FramelessWindowHint);
helper.setWindowTitle("НАРКО-ЛОКАТОР      !");
helper.setText("НАРКО-ЛОКАТОР зарегистрировал все даннные в БД  "
           "обработайте фотографии чеков, лиц и геометок. "
               "Результаты обработыки по её окончании будут внесены в базу данных.");

helper.setFont(f1);
qApp->setStyleSheet(" QMessageBox{ background-color: black; color: white;border: 2px solid white;}"
                "QMessageBox QLabel { color: white;} "
                "QMessageBox QPushButton{"
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


helper.exec();

}

void reginBD::BDslot(QSqlDatabase db)
{
    DB=db;
}

void reginBD::sentoBD(QString filename,QString metDAT,int id)
{


    if (metDAT.size()>17) metDAT.replace(" ","");
     if (metDAT.size()>17) metDAT.replace("\r","");
      if (metDAT.size()>17) metDAT.replace("\t"," ");
      if (metDAT.size()>17) metDAT.replace("\n","");



    if (metDAT=="")metDAT.append("Не найдено");
    QStringList bufname;
    QString heshname;
    bufname=filename.split(".");
    heshname=bufname.at(0);
    switch (id) {
    case 0:
        DB.open();
        DB.exec("INSERT INTO public.cheks(\"phHESH\",\"readyUK\",\"readyIMG\",meta) VALUES ('" + heshname + "','false','false','" + metDAT +"');");
        DB.close();
        break;
    case 1:
        DB.open();
        DB.exec("INSERT INTO public.geometki(\"phHESH\",\"readyUK\",\"readyIMG\",meta) VALUES ('" + heshname + "','false','false','" + metDAT +"');");
        DB.close();
        break;
    case 2:
        DB.open();
        DB.exec("INSERT INTO public.faces(\"phHESH\",\"readyUK\",\"readyIMG\",meta) VALUES ('" + heshname + "','false','false','" + metDAT +"');");
        DB.close();
        break;

    }
}
