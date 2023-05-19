#include "meny.h"

meny::meny(QWidget *parent) : QWidget(parent)
{
//    this->setStyleSheet("background-image: url'C:/Users/nrd/Desktop/MetaCollector/MetaCollector/resors/m3.jpg);");

    QPalette mainpal;
      mainpal.setBrush(this->backgroundRole(), QBrush(QPixmap(":/fimg/resors/m1.jpg")));

      this->setPalette(mainpal);


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
    QString groupst("QGroupBox {opacity: 0.8; font-size: 13pt;border: 1px solid #000069; margin-top:5ex; background-color: rgba(41, 43, 107, 0.80);}"
                    "QGroupBox::title {subcontrol-origin:margin;background-color: none;color:white; subcontrol-position:top center;padding:0 3px; }");


    progress->setMinimumWidth(580);
    progress->setRange(0,5);
    progress->setStyleSheet("QProgressBar {"
                            "background-color: black;"
                            "color: #1bb004;"
                            "border-style: outset;"
                            "border-width: 2px;"
                            "border-color: black;;"
                            "text-align: center; }"

                            "QProgressBar::chunk {"
                            "background-color: #f5b207; }");


    prog->setStyleSheet("color: #04ff00;font-size: 14px;background-color: none;");

QLabel * name = new QLabel("НАРКО-ЛОКАТОР");
name->setStyleSheet("color: #fff;font-size: 40px;");
name->setFont(f1);

QPushButton* prepardat = new QPushButton("   Выгрузить хранилище   ");
prepardat->setMinimumHeight(60);
prepardat->setStyleSheet(pbstyle);
prepardat->setFont(f1);




QPushButton* info = new QPushButton("   Справка   ");
info->setStyleSheet(pbstyle);
info->setFont(f1);
info->setMinimumHeight(35);

QPushButton* exit = new QPushButton("   Выход   ");
exit->setStyleSheet(pbstyle);
exit->setFont(f1);
exit->setMinimumHeight(35);

connect(dataconnect->connectr,SIGNAL(clicked()),this,SLOT(ps()));
connect(geterDATA->chosedat,SIGNAL(clicked()),this,SLOT(ps1()));
connect(geterDATA->startparsing,SIGNAL(clicked()),this,SLOT(ps1()));
connect(sortDATA->start,SIGNAL(clicked()),this,SLOT(ps2()));
connect(registrinbd->start,SIGNAL(clicked()),this,SLOT(ps3()));
connect(formdata,SIGNAL(facered()),this,SLOT(fr()));


connect(dataconnect,SIGNAL(sendbdtoreg(QSqlDatabase)),registrinbd,SLOT(BDslot(QSqlDatabase)));
connect(dataconnect,SIGNAL(sendbdtoform(QSqlDatabase)),formdata,SLOT(BDslot(QSqlDatabase)));
connect(exit,SIGNAL(clicked()),this,SLOT(close()));
connect(info,SIGNAL(clicked()),this,SLOT(shinf()));
connect(prepardat,SIGNAL(clicked()),this,SLOT(exhran()));


QVBoxLayout* namelay1= new QVBoxLayout;
namelay1->addStretch(4);
namelay1->addWidget(name);
namelay1->addStretch(7);

QHBoxLayout* mnamelay= new QHBoxLayout;
mnamelay->addStretch(10);
mnamelay->addLayout(namelay1);
mnamelay->addStretch(10);

QGroupBox *bcon = new QGroupBox(tr("Подключение базы данных"));
bcon->setAlignment(Qt::AlignCenter);
bcon->setFont(f1);
bcon->setStyleSheet(groupst);
QVBoxLayout* bconlay= new QVBoxLayout;
bconlay->addWidget(dataconnect);
bcon->setLayout(bconlay);

QGroupBox *getcon = new QGroupBox(tr("Получение данных"));
getcon->setAlignment(Qt::AlignCenter);
getcon->setFont(f1);
getcon->setStyleSheet(groupst);
QVBoxLayout* getconlay= new QVBoxLayout;
getconlay->addWidget(geterDATA);
getcon->setLayout(getconlay);

QGroupBox *sortcon = new QGroupBox(tr("Классифицирование данных"));
sortcon->setAlignment(Qt::AlignCenter);
sortcon->setFont(f1);
sortcon->setStyleSheet(groupst);
QVBoxLayout* sortconconlay= new QVBoxLayout;
sortconconlay->addWidget(sortDATA);
sortcon->setLayout(sortconconlay);

QGroupBox *mettcon = new QGroupBox(tr("Получение методанных"));
mettcon->setAlignment(Qt::AlignCenter);
mettcon->setFont(f1);
mettcon->setStyleSheet(groupst);
QVBoxLayout* mettconlay= new QVBoxLayout;
mettconlay->addWidget(registrinbd);
mettcon->setLayout(mettconlay);

QVBoxLayout* lay1= new QVBoxLayout;
lay1->addStretch(5);
lay1->addWidget(bcon);
lay1->addStretch(2);
lay1->addWidget(getcon);
lay1->addStretch(2);
lay1->addWidget(sortcon);
lay1->addStretch(5);

QGroupBox *formdatacon = new QGroupBox(tr("Обработка данных"));
formdatacon->setAlignment(Qt::AlignCenter);
formdatacon->setFont(f1);
formdatacon->setStyleSheet(groupst);
QVBoxLayout* formdataconlay= new QVBoxLayout;
formdataconlay->addWidget(formdata);
formdatacon->setLayout(formdataconlay);

QGroupBox *exdatcon = new QGroupBox(tr("Выходные данные"));
exdatcon->setAlignment(Qt::AlignCenter);
exdatcon->setFont(f1);
exdatcon->setStyleSheet(groupst);
QVBoxLayout* exdatconlay= new QVBoxLayout;
exdatconlay->addWidget(prepardat);

exdatcon->setLayout(exdatconlay);

QVBoxLayout* lay2= new QVBoxLayout;
lay2->addStretch(5);
lay2->addWidget(mettcon);
lay2->addStretch(2);
lay2->addWidget(formdatacon);
lay2->addStretch(2);
lay2->addWidget(exdatcon);
lay2->addStretch(5);


QHBoxLayout* bodylay = new QHBoxLayout;
bodylay->addStretch(3);
bodylay->addLayout(lay1);
bodylay->addStretch(8);
bodylay->addLayout(lay2);
bodylay->addStretch(3);

QHBoxLayout* fotlay = new QHBoxLayout;
fotlay->addStretch(5);
fotlay->addWidget(info);
fotlay->addStretch(20);
fotlay->addWidget(exit);
fotlay->addStretch(5);

QVBoxLayout* mlay= new QVBoxLayout;
mlay->addStretch(2);
mlay->addLayout(mnamelay);
mlay->addStretch(5);
mlay->addLayout(bodylay);
mlay->addStretch(5);
mlay->addWidget(progress);
mlay->addWidget(prog);
mlay->addStretch(5);
mlay->addLayout(fotlay);
mlay->addStretch(2);

geterDATA->setEnabled(false);
sortDATA->setEnabled(false);
registrinbd->setEnabled(false);
formdata->setEnabled(false);


this->setLayout(mlay);

}

void meny::exhran()
{
    QString comand1,comand2;
    comand1.append(QCoreApplication::applicationDirPath()+"/buf/");
    comand2= QString("%1/Хранилище").arg(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));
    QDir().mkdir(comand2);
    copyDirectoryFiles(comand1,comand2,true);


    int id = QFontDatabase::addApplicationFont(":/font/resors/ofont.ru_CutOut.ttf"); //путь к шрифту
        QString DatDot = QFontDatabase::applicationFontFamilies(id).at(0); //имя шрифта
        QFont f1(DatDot);  // QFont c вашим шрифтом

        QMessageBox helper;
    helper.setWindowFlags(Qt::FramelessWindowHint);
    helper.setWindowTitle("НАРКО-ЛОКАТОР      !");
    helper.setText("НАРКО-ЛОКАТОР создал папку Хранилище на рабочем  "
                   "где находятся все собранные за период работы фотографии");

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


bool meny::copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist)
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

void meny::shinf()
{
    int id = QFontDatabase::addApplicationFont(":/font/resors/ofont.ru_CutOut.ttf"); //путь к шрифту
        QString DatDot = QFontDatabase::applicationFontFamilies(id).at(0); //имя шрифта
        QFont f1(DatDot);  // QFont c вашим шрифтом

        QMessageBox helper;
    helper.setWindowFlags(Qt::FramelessWindowHint);
    helper.setWindowTitle("НАРКО-ЛОКАТОР     !");
    helper.setText("НАРКО-ЛОКАТОР - программное обеспечение для осуществления автоматизированной обработки данных используя базу данных POSTRGRESQL средствами языка C++ и библиотеки Qt c открытым искодным кодом ."
                   "Разработчики ПО:\n\n"



                   "заместитель командира взвода\n"
                   "Воронежского института МВД России\n"
                   "сержант полиции Бакулин Н.С\n\n"


                   "курсант Воронежского института МВД России\n"
                   "рядовой полиции Биктимирова Ю.В.\n\n"


                   "курсант Воронежского института МВД России\n"
                   "рядовой полиции Мишедченко А.В.\n\n"


                   "курсант Воронежского института МВД России\n"
                   "рядовой полицииа Ртищев Р.С\n\n"

                   "курсант Воронежского института МВД России\n"
                   "рядовой полиции Бахарев Д.А.\n\n"

                   "курсант Воронежского института МВД России\n"
                   "рядовой полиции Извеков Н.Р.\n\n");;

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

void meny::ps()
{
    if (dataconnect->ready==true)
    {geterDATA->setEnabled(true);
    dataconnect->sendbdtoreg(dataconnect->DB);
     dataconnect->sendbdtoform(dataconnect->DB);
     prog->setText("БД подключена. <получите входные данные>");
     prI++;
     progress->setValue(prI);

    }
}

void meny::ps1()
{
    if (geterDATA->ready==true) sortDATA->setEnabled(true);
    prog->setText("Данные получены. <запустите классификацию>");
    prI++;
    progress->setValue(prI);
}

void meny::ps2()
{
     registrinbd->setEnabled(true);
     prog->setText("Данные классифицированы. <запустите получение метаданных>");
     prI++;
     progress->setValue(prI);
}

void meny::ps3()
{
    registrinbd->setEnabled(true);
    prog->setText("Мета данные получены. <произведите обработку фото (поочерёдно)>");
    prI++;
    progress->setValue(prI);
    formdata->setEnabled(true);
}

void meny::fr()
{
    prog->setText("Фото обработаны. <данные внесены в БД, хранилище готово к выгрузке>");
    prI++;
    progress->setValue(prI);
}
