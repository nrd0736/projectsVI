#include "bigformat.h"

bigformat::bigformat(QWidget *parent) : QWidget(parent)
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
    statusind1->setStyleSheet("color: #666;font-size: 12px;background-color: none;");
    statusind1->setFont(f1);

    lod1.setFileName(":/load/resors/30.gif");
    load1->setMovie(&lod1);
    load1->setStyleSheet("background-color: none;");

    QLabel * status1 = new QLabel("CТАТУС");
    status1->setStyleSheet(lbstyle);
    status1->setFont(f1);

    QPushButton* prepare = new QPushButton("   Подготовить лица\n    для поиска в ИСОД   ");
    prepare->setMinimumHeight(60);
    prepare->setStyleSheet(pbstyle);
    prepare->setFont(f1);


    cheksd->setMinimumHeight(35);
    cheksd->setStyleSheet(pbstyle);
    cheksd->setFont(f1);


    geosd->setMinimumHeight(35);
    geosd->setStyleSheet(pbstyle);
    geosd->setFont(f1);


    faces->setMinimumHeight(35);
    faces->setStyleSheet(pbstyle);
    faces->setFont(f1);


    connect(prepare,SIGNAL(clicked()),this,SLOT(scrapface()));

    connect(cheksd,SIGNAL(clicked()),this,SLOT(chek()));
    connect(geosd,SIGNAL(clicked()),this,SLOT(geo()));
    connect(faces,SIGNAL(clicked()),this,SLOT(face()));


    QHBoxLayout* lay1 = new QHBoxLayout;
    lay1->addWidget(status1);
    lay1->addStretch(100);
    lay1->addStretch(100);
    lay1->addWidget(load1);
    lay1->addStretch(10);
    lay1->addWidget(statusind1);

    QVBoxLayout* flay= new QVBoxLayout;
    flay->addStretch(2);
    flay->addWidget(prepare);
    flay->addStretch(2);
    flay->addLayout(lay1);
    flay->addStretch(10);

    QVBoxLayout* play = new QVBoxLayout;
    play->addLayout(flay);
    play->addStretch(10);
    play->addWidget(cheksd);
    play->addStretch(1);
    play->addWidget(geosd);
    play->addStretch(1);
    play->addWidget(faces);
    play->addStretch(1);

    play->addStretch(1);

    this->setLayout(play);
}
bool bigformat::copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist)
{
    QDir sourceDir(fromDir);
    QDir targetDir(toDir);
    if(!targetDir.exists()){    /* if directory don't exists, build it */
        if(!targetDir.mkdir(targetDir.absolutePath()))
            return false;
    }

    QFileInfoList fileInfoList = sourceDir.entryInfoList();
    foreach(QFileInfo fileInfo, fileInfoList){
        if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            continue;

        if(fileInfo.isDir()){    /* if it is directory, copy recursively*/
            if(!copyDirectoryFiles(fileInfo.filePath(),
                targetDir.filePath(fileInfo.fileName()),
                coverFileIfExist))
                return false;
        }
        else{            /* if coverFileIfExist == true, remove old file first */
            if(coverFileIfExist && targetDir.exists(fileInfo.fileName())){
                targetDir.remove(fileInfo.fileName());
            }

            // files copy
            if(!QFile::copy(fileInfo.filePath(),
                targetDir.filePath(fileInfo.fileName()))){
                    return false;
            }
        }
    }
    return true;
}

void bigformat::BDslot(QSqlDatabase bd)
{
    BD_bigformat = bd;
}

void bigformat::scrapface()
{
    lod1.start();
    statusind1->setText("обработка");
    statusind1->setStyleSheet("color: #f5b207;font-size: 12px;");
    QString comand1,comand2;
    comand1.append(QCoreApplication::applicationDirPath()+"/main/crop_face/");
    comand2= QString("%1/ScrapFace").arg(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));
    QDir().mkdir(comand2);
    copyDirectoryFiles(comand1,comand2,true);
    lod1.stop();
    load1->close();
    statusind1->setText("данные подготовлены");
    statusind1->setStyleSheet("color: #00b812;font-size: 12px;");

    int id = QFontDatabase::addApplicationFont(":/font/resors/ofont.ru_CutOut.ttf"); //путь к шрифту
        QString DatDot = QFontDatabase::applicationFontFamilies(id).at(0); //имя шрифта
        QFont f1(DatDot);  // QFont c вашим шрифтом

        QMessageBox helper;
    helper.setWindowFlags(Qt::FramelessWindowHint);
    helper.setWindowTitle("НАРКО-ЛОКАТОР      !");
    helper.setText("НАРКО-ЛОКАТОР создал папку ScrapFace на рабочем  "
                   "где находятся обрезанные фотографии лиц для отправки в ИСОД");

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

void bigformat::chek()
{
    for (;;){

    QString path,metach;
    path.append(QCoreApplication::applicationDirPath()+"/buf/chek/");



    BD_bigformat.open();
    QSqlQuery* qur1= new QSqlQuery(BD_bigformat) ;
    QSqlQuery* qur2= new QSqlQuery(BD_bigformat);


    qur1->prepare( "SELECT \"phHESH\" FROM public.cheks WHERE \"readyIMG\" = 'false' limit 1 ;");
    qur2->prepare( "SELECT meta FROM public.cheks WHERE \"readyIMG\" = 'false' limit 1 ;");
    qur1->exec();
    qur1->next();
    qur2->exec();
    qur2->next();
    if(!qur1->isNull(0) && !qur1->isNull(0))
    {
    path.append(qur1->value(0).toString());
    path.append(".jpg");

    metach.append(qur2->value(0).toString());


   BD_bigformat.close();


   //pchecks* chek = new pchecks(path,metach,BD_bigformat);
   pchecks * chek =new pchecks(path,metach,BD_bigformat);
   chek->exec();

    }
    else {break; ready[0]=true;}
    }
}



void bigformat::geo()
{
    for (;;){

    QString path,metach;
    path.append(QCoreApplication::applicationDirPath()+"/buf/geo/");



    BD_bigformat.open();
    QSqlQuery* qur1= new QSqlQuery(BD_bigformat) ;
    QSqlQuery* qur2= new QSqlQuery(BD_bigformat);


    qur1->prepare( "SELECT \"phHESH\" FROM public.geometki WHERE \"readyIMG\" = 'false' limit 1 ;");
    qur2->prepare( "SELECT meta FROM public.geometki WHERE \"readyIMG\" = 'false' limit 1 ;");
    qur1->exec();
    qur1->next();
    qur2->exec();
    qur2->next();
    if(!qur1->isNull(0) && !qur1->isNull(0))
    {
    path.append(qur1->value(0).toString());
    path.append(".jpg");

    metach.append(qur2->value(0).toString());


   BD_bigformat.close();


   pgeo * geo =new pgeo(path,metach,BD_bigformat);
   geo->exec();

    }
    else {break;ready[2]=true;}
    }
}

void bigformat::face()
{
    emit facered();
    for (;;){

    QString path,metach;
    path.append(QCoreApplication::applicationDirPath()+"/buf/face/");



    BD_bigformat.open();
    QSqlQuery* qur1= new QSqlQuery(BD_bigformat) ;
    QSqlQuery* qur2= new QSqlQuery(BD_bigformat);


    qur1->prepare( "SELECT \"phHESH\" FROM public.faces WHERE \"readyIMG\" = 'false' limit 1 ;");
    qur2->prepare( "SELECT meta FROM public.faces WHERE \"readyIMG\" = 'false' limit 1 ;");
    qur1->exec();
    qur1->next();
    qur2->exec();
    qur2->next();
    if(!qur1->isNull(0) && !qur1->isNull(0))
    {
    path.append(qur1->value(0).toString());
    path.append(".jpg");

    metach.append(qur2->value(0).toString());


   BD_bigformat.close();


   pface * face =new pface(path,metach,BD_bigformat);
   face->exec();

    }
    else {break;ready[1]=true; }
    }
}
