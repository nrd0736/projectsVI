#include "geter.h"


geter::geter(QWidget *parent) : QWidget(parent)
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
    statusind2->setStyleSheet("color: #666;font-size: 12px;background-color: none;");
    statusind2->setFont(f1);


    startparsing->setMinimumHeight(60);
    startparsing->setStyleSheet(pbstyle);
    startparsing->setFont(f1);

    chosedat->setMinimumHeight(60);
    chosedat->setStyleSheet(pbstyle);
    chosedat->setFont(f1);


    lod1.setFileName(":/load/resors/30.gif");
    load1->setMovie(&lod1);
    load1->setStyleSheet("background-color: none;");



    lod2.setFileName(":/load/resors/30.gif");
    load2->setMovie(&lod2);
    load2->setStyleSheet("background-color: none;");



    QLabel * status1 = new QLabel("CТАТУС (ФАЙЛООБМЕННИК)");
    status1->setStyleSheet(lbstyle);
    status1->setFont(f1);

    QLabel * status2 = new QLabel("CТАТУС (ИМЕЮЩИЕСЯ ДАННЫЕ)");
    status2->setStyleSheet(lbstyle);
    status2->setFont(f1);

    connect(chosedat,SIGNAL(clicked()),this,SLOT(chosedir()));
    connect(startparsing,SIGNAL(clicked()),this,SLOT(startpars()));
    connect(process,SIGNAL(finished(int)),this,SLOT(endpars()));


    QHBoxLayout* lay1 = new QHBoxLayout;
    lay1->addWidget(startparsing);
    lay1->addStretch(10);
    lay1->addWidget(chosedat);

    QHBoxLayout* lay2 = new QHBoxLayout;
    lay2->addWidget(status1);
    lay2->addStretch(100);
    lay2->addStretch(100);
    lay2->addWidget(load1);
    lay2->addStretch(10);
    lay2->addWidget(statusind1);

    QHBoxLayout* lay3 = new QHBoxLayout;
    lay3->addWidget(status2);
    lay3->addStretch(100);
    lay3->addStretch(100);
    lay3->addWidget(load2);
    lay3->addStretch(10);
    lay3->addWidget(statusind2);

    QVBoxLayout* mlay = new QVBoxLayout;
    mlay->addLayout(lay1);
    mlay->addStretch(10);
    mlay->addLayout(lay2);
    mlay->addLayout(lay3);
    this->setLayout(mlay);
}

bool geter::redir()
{

    QString* comand1 = new QString;
    QString* comand2 = new QString;
    comand1->append(FILE_PATH);
    comand1->append("/");
    comand2->append(QCoreApplication::applicationDirPath()+"/main/images_browser");

    copyDirectoryFiles(*comand1,*comand2,true);

    return true;
}

void geter::chosedir()
{
    lod2.start();
    statusind2->setText("обработка");
    statusind2->setStyleSheet("color: #f5b207;font-size: 12px;background-color: none;");
    QFileDialog chose;
    chose.setFilter(QDir::Dirs);
    chose.setOptions(QFileDialog::ShowDirsOnly);
    chose.setOptions(QFileDialog::ShowDirsOnly);
    chose.setFileMode(QFileDialog::DirectoryOnly);
    FILE_PATH.clear();
    FILE_PATH.append(chose.getExistingDirectory(0, "НАРКО-ЛОКАТОР    Выбор файла с входными данными"));


    if(redir())
    {
        lod2.stop();
        load2->close();
        statusind2->setText("данные получены");
        statusind2->setStyleSheet("color: #00b812;font-size: 12px;background-color: none;");
        ready=true;
    }
}

void geter::startpars()
{
    QString executable;
        executable.append("cd "+QCoreApplication::applicationDirPath());
        executable.append("/main");
        process->start("cmd.exe", QStringList() << "/c" <<executable +" & "+"scrapy_img.exe" );
    lod1.start();
    statusind1->setText("обработка");
    statusind1->setStyleSheet("color: #f5b207;font-size: 12px;background-color: none;");

}

void geter::endpars()
{
    lod1.stop();
    load1->close();
    statusind1->setText("данные получены");
    statusind1->setStyleSheet("color: #00b812;font-size: 12px;background-color: none;");
    ready=true;
//    QString* comand1 = new QString;
//    QString* comand2 = new QString;
//    comand1->append(QCoreApplication::applicationDirPath()+"/scrapy_img/images_browser");

//    comand2->append(QCoreApplication::applicationDirPath()+"/main/images_browser");

//    copyDirectoryFiles(*comand1,*comand2,true);
}

bool geter::copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist)
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

