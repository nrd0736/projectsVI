#include "control.h"
#include "control.h"
#include "control.h"

control::control(QWidget *parent) : QWidget(parent)
{


    connect(geetinginf,SIGNAL(sendregID(QString)),MAINDATE,SLOT(IDbox(QString)));
    connect(geetinginf,SIGNAL(sendstartADD(QString)),MAINDATE,SLOT(startADDbox(QString)));
    connect(geetinginf,SIGNAL(sendDATALEVEL_1(QStringList)),MAINDATE,SLOT(boxDATALEVEL_1(QStringList)));
    connect(geetinginf,SIGNAL(sendDATALEVEL_2(QStringList)),MAINDATE,SLOT(boxDATALEVEL_2(QStringList)));
    connect(geetinginf,SIGNAL(sendDATALEVEL_3(QStringList)),MAINDATE,SLOT(boxDATALEVEL_3(QStringList)));
    connect(geetinginf,SIGNAL(sendDATALEVEL_4(QStringList)),MAINDATE,SLOT(boxDATALEVEL_4(QStringList)));
    connect(geetinginf,SIGNAL(sendDATALEVEL_5(QStringList)),MAINDATE,SLOT(boxDATALEVEL_5(QStringList)));
    connect(geetinginf,SIGNAL(sendDATALEVEL_6(QStringList)),MAINDATE,SLOT(boxDATALEVEL_6(QStringList)));
    connect(geetinginf,SIGNAL(sendDATALEVEL_7(QStringList)),MAINDATE,SLOT(boxDATALEVEL_7(QStringList)));
    connect(geetinginf,SIGNAL(sendDATALEVEL_8(QStringList)),MAINDATE,SLOT(boxDATALEVEL_8(QStringList)));
    connect(geetinginf,SIGNAL(sendDATALEVEL_9(QStringList)),MAINDATE,SLOT(boxDATALEVEL_9(QStringList)));
    connect(geetinginf,SIGNAL(sendDATALEVEL_10(QStringList)),MAINDATE,SLOT(boxDATALEVEL_10(QStringList)));
    connect(geetinginf,SIGNAL(sendDATALEVEL_11(QStringList)),MAINDATE,SLOT(boxDATALEVEL_11(QStringList)));
    connect(geetinginf,SIGNAL(sendDATALEVEL_12(QStringList)),MAINDATE,SLOT(boxDATALEVEL_12(QStringList)));
    connect(geetinginf,SIGNAL(sendREZ_DATA(QStringList)),MAINDATE,SLOT(boxREZ_DATA(QStringList)));
    connect(geetinginf,SIGNAL(sendNUMB_DATA(QStringList)),MAINDATE,SLOT(boxNUMB_DATA(QStringList)));
    connect(this,SIGNAL(sendprePATH(QString)),MAINDATE,SLOT(boxprePATH(QString)));

    QString backstyle(" background-color: black ");
    QString frontstyle("color: #1bb004;");
    //setWindowTitle("")
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
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedHeight(320);
    this->setFixedWidth(600);

    progress->setMinimumWidth(580);
    progress->setRange(0,7);
    progress->setStyleSheet("QProgressBar {"
                            "background-color: black;"
                            "color: #1bb004;"
                            "border-style: outset;"
                            "border-width: 2px;"
                            "border-color: black;;"
                            "text-align: center; }"

                            "QProgressBar::chunk {"
                            "background-color: #f5b207; }");

    QPushButton * create = new QPushButton("Создать таблицу входных данных");
    create->setStyleSheet(buttonstyle);
    QPushButton * chose = new QPushButton("Выбрать таблицу входных данных");
    chose->setStyleSheet(buttonstyle);

    start->setStyleSheet(buttonstyle);
    start->setDisabled(true);

    QLabel*name =new QLabel("GAR FIAS ANALITIC");
    name->setStyleSheet("QLabel{color: #1bb004;background-color: black;font-size:24px; }");
    prog->setStyleSheet("QLabel{color: #1bb004;background-color: black;font-size:12px; }");

    QPushButton * exit = new QPushButton("Выход");
    exit->setStyleSheet(buttonstyle);

    QPushButton * info = new QPushButton("Справка");
    info->setStyleSheet(buttonstyle);
    start->setFixedSize(180,50);
    chose->setFixedSize(200,30);
    create->setFixedSize(200,30);
    exit->setFixedSize(200,30);
    info->setFixedSize(200,30);

    QHBoxLayout* layname = new QHBoxLayout;
    layname->addStretch(5);
    layname->addWidget(name);
    layname->addStretch(5);


    QHBoxLayout *lay1 = new QHBoxLayout;
    lay1->addWidget(create);
    lay1->addStretch(5);
    lay1->addWidget(chose);

    QHBoxLayout* lay2 = new QHBoxLayout;
    lay2->addStretch(5);
    lay2->addWidget(start);
    lay2->addStretch(5);

    QHBoxLayout* lay3 = new QHBoxLayout;
    lay3->addWidget(info);
     lay3->addStretch(5);
    lay3->addWidget(exit);



    QVBoxLayout * mainlay =new  QVBoxLayout;
    mainlay->addStretch(5);
    mainlay->addLayout(layname);
    mainlay->addStretch(5);
    mainlay->addStretch(5);
    mainlay->addLayout(lay1);
    mainlay->addStretch(5);
    mainlay->addLayout(lay2);
    mainlay->addStretch(5);
    mainlay->addStretch(5);
    mainlay->addWidget(progress);
    mainlay->addWidget(prog);
    mainlay->addStretch(5);
    mainlay->addStretch(5);
    mainlay->addLayout(lay3);

    this->setLayout(mainlay);



 connect(exit,SIGNAL(clicked()),this,SLOT(close()));
 connect(create,SIGNAL(clicked()),this,SLOT(createstartdoc()));
 connect(info,SIGNAL(clicked()),this,SLOT(show_inf()));
  connect(chose,SIGNAL(clicked()),this,SLOT(chosestartdoc()));
  connect(start,SIGNAL(clicked()),this,SLOT(startdocgeneration()));



}

void control::cliningLEVEL_MAP()
{
    QString AS_MUN_HIERARCHY_PATH,AS_ADM_HIERARCHY_PATH,AS_ADDR_OBJ_PATH;



    for(int i = 0 ;i<MAINDATE->LEVEL_1.size();i++)
    {
        bool chek_list[6]={0};
        if (MAINDATE->LEVEL_1.at(i).at(0)!="НЕКОРРЕКТНЫЕ ДАННЫЕ") chek_list[0]=1;
        if (MAINDATE->LEVEL_2.at(i).at(0)!="НЕКОРРЕКТНЫЕ ДАННЫЕ") chek_list[1]=1;
        if (MAINDATE->LEVEL_3.at(i).at(0)!="НЕКОРРЕКТНЫЕ ДАННЫЕ") chek_list[2]=1;
        if (MAINDATE->LEVEL_4.at(i).at(0)!="НЕКОРРЕКТНЫЕ ДАННЫЕ") chek_list[3]=1;
        if (MAINDATE->LEVEL_5.at(i).at(0)!="НЕКОРРЕКТНЫЕ ДАННЫЕ") chek_list[4]=1;
        if (MAINDATE->LEVEL_6.at(i).at(0)!="НЕКОРРЕКТНЫЕ ДАННЫЕ") chek_list[5]=1;
        if(chek_list[4]==1)
        {
            MAINDATE->LEVEL_3[i].clear();
            MAINDATE->LEVEL_4[i].clear();
            MAINDATE->LEVEL_6[i].clear();
            MAINDATE->LEVEL_3[i].append("0");
            MAINDATE->LEVEL_4[i].append("0");
            MAINDATE->LEVEL_6[i].append("0");
            chek_list[2]=0;
            chek_list[3]=0;
            chek_list[5]=0;

        }
        if(chek_list[5]==1)
        {
            MAINDATE->LEVEL_3[i].clear();
            MAINDATE->LEVEL_3[i].append("0");
            chek_list[2]=0;

        }
        if(chek_list[3]==1)
        {
            MAINDATE->LEVEL_2[i].clear();
            MAINDATE->LEVEL_6[i].clear();
            MAINDATE->LEVEL_2[i].append("0");
            MAINDATE->LEVEL_6[i].append("0");
            chek_list[1]=0;
            chek_list[5]=0;

        }


        AS_MUN_HIERARCHY_PATH.append(QCoreApplication::applicationDirPath()+"/data/baze/"+MAINDATE->REGION_CODE.at(i) + "/");
        AS_ADM_HIERARCHY_PATH.append(QCoreApplication::applicationDirPath()+"/data/baze/"+MAINDATE->REGION_CODE.at(i) + "/");
        AS_ADDR_OBJ_PATH.append(QCoreApplication::applicationDirPath()+"/data/baze/"+MAINDATE->REGION_CODE.at(i) + "/");

        QDir mDir1(AS_ADM_HIERARCHY_PATH);
        foreach (const QFileInfo &mitm, mDir1.entryInfoList(QStringList("AS_ADM_HIERARCHY_2*.XML"))){
        AS_ADM_HIERARCHY_PATH.clear();
        AS_ADM_HIERARCHY_PATH.append(mitm.absoluteFilePath());
        }

        QDir mDir2(AS_MUN_HIERARCHY_PATH);
        foreach (const QFileInfo &mitm, mDir2.entryInfoList(QStringList("AS_MUN_HIERARCHY_2*.XML"))){
        AS_MUN_HIERARCHY_PATH.clear();
        AS_MUN_HIERARCHY_PATH.append(mitm.absoluteFilePath());
        }
        QDir mDir3(AS_ADDR_OBJ_PATH);
        foreach (const QFileInfo &mitm, mDir3.entryInfoList(QStringList("AS_ADDR_OBJ_2*.XML"))){
        AS_ADDR_OBJ_PATH.clear();
        AS_ADDR_OBJ_PATH.append(mitm.absoluteFilePath());
        }


        QString clearbuf;
        if (chek_list[0]==1 && chek_list[4]==1 && chek_list[1]==0)
        {
            QString level2buf,level2GAR;
            QStringList level2list;
        QFile AS_ADM_HIERARCHY__FILE(AS_ADM_HIERARCHY_PATH);
        AS_ADM_HIERARCHY__FILE.open(QIODevice::ReadOnly);
        QXmlStreamReader reader(&AS_ADM_HIERARCHY__FILE);

        if (reader.readNextStartElement()) {
            if (reader.name() == "ITEMS"){
                while(reader.readNextStartElement()){
                    if(reader.name() == "ITEM"){
                            if( MAINDATE->LEVEL_1.at(i).at(2)+"."+MAINDATE->LEVEL_5.at(i).at(2) == reader.attributes().value("PATH").toString())
                            {
                                 MAINDATE->LEVEL_2[i].clear();
                                 MAINDATE->LEVEL_2[i].append("0");
                                 level2GAR="0";
                                 break;
                            }
                            if(reader.attributes().value("PATH").toString().contains( MAINDATE->LEVEL_1.at(i).at(2)+".") && reader.attributes().value("PATH").toString().contains( "."+MAINDATE->LEVEL_5.at(i).at(2)) )
                            {
                                level2buf=reader.attributes().value("PATH").toString();
                                level2list=level2buf.split(".",QString::SkipEmptyParts);
                                level2GAR=level2list.at(1);
                            }



                    }
                    else
                        reader.skipCurrentElement();
                   reader.readNext();
                }
                reader.skipCurrentElement();
            }
            else
                reader.raiseError(QObject::tr("Incorrect file"));
        }



        AS_ADM_HIERARCHY__FILE.close();

        QStringList OBJbufer;
        QFile AS_ADDR_OBJ__FILE(AS_ADDR_OBJ_PATH);
        AS_ADDR_OBJ__FILE.open(QIODevice::ReadOnly);
        QXmlStreamReader reader1(&AS_ADDR_OBJ__FILE);
        if (reader1.readNextStartElement()) {
            if (reader1.name() == "ADDRESSOBJECTS"){
                while(reader1.readNextStartElement()){
                    if(reader1.name() == "OBJECT"){

                            if(reader1.attributes().value("OBJECTID").toString()==level2GAR)
                            {
                                OBJbufer << reader1.attributes().value("NAME").toString();
                                OBJbufer << reader1.attributes().value("TYPENAME").toString();
                                OBJbufer << reader1.attributes().value("OBJECTID").toString();
                                OBJbufer << reader1.attributes().value("OBJECTGUID").toString();

                                for (int obj=0;obj<OBJbufer.size();obj++) {

                                    MAINDATE->LEVEL_2[i].append(OBJbufer.at(obj));
                                    chek_list[1]=1;
                                }
                                break;
                            }
                    }
                    else
                        reader1.skipCurrentElement();
                   reader1.readNext();
                }
                reader1.skipCurrentElement();
            }
            else
                reader1.raiseError(QObject::tr("Incorrect file"));
        }


        AS_ADDR_OBJ__FILE.close();
    clearbuf=MAINDATE->LEVEL_2[i].at(0);
    clearbuf.fill(' ',1);
    MAINDATE->LEVEL_2[i][0]=clearbuf;
    MAINDATE->LEVEL_2[i].removeAll(QString(" "));
    }
         if (chek_list[0]==1 && chek_list[5]==1 && chek_list[1]==0)
        {
            QString level2buf,level2GAR;
            QStringList level2list;
        QFile AS_ADM_HIERARCHY__FILE(AS_ADM_HIERARCHY_PATH);
        AS_ADM_HIERARCHY__FILE.open(QIODevice::ReadOnly);
        QXmlStreamReader reader(&AS_ADM_HIERARCHY__FILE);

        if (reader.readNextStartElement()) {
            if (reader.name() == "ITEMS"){
                while(reader.readNextStartElement()){
                    if(reader.name() == "ITEM"){
                            if( MAINDATE->LEVEL_1.at(i).at(2)+"."+MAINDATE->LEVEL_6.at(i).at(2) == reader.attributes().value("PATH").toString())
                            {
                                 MAINDATE->LEVEL_2[i].clear();
                                 MAINDATE->LEVEL_2[i].append("0");
                                 level2GAR="0";
                                 break;
                            }
                            if(reader.attributes().value("PATH").toString().contains( MAINDATE->LEVEL_1.at(i).at(2)+".") && reader.attributes().value("PATH").toString().contains( "."+MAINDATE->LEVEL_6.at(i).at(2)) )
                            {
                                level2buf=reader.attributes().value("PATH").toString();
                                level2list=level2buf.split(".",QString::SkipEmptyParts);
                                level2GAR=level2list.at(1);
                            }



                    }
                    else
                        reader.skipCurrentElement();
                   reader.readNext();
                }
                reader.skipCurrentElement();
            }
            else
                reader.raiseError(QObject::tr("Incorrect file"));
        }



        AS_ADM_HIERARCHY__FILE.close();
        QStringList OBJbufer;
        QFile AS_ADDR_OBJ__FILE(AS_ADDR_OBJ_PATH);
        AS_ADDR_OBJ__FILE.open(QIODevice::ReadOnly);
        QXmlStreamReader reader1(&AS_ADDR_OBJ__FILE);
        if (reader1.readNextStartElement()) {
            if (reader1.name() == "ADDRESSOBJECTS"){
                while(reader1.readNextStartElement()){
                    if(reader1.name() == "OBJECT"){
                            if(reader1.attributes().value("OBJECTID").toString()==level2GAR)
                            {
                                OBJbufer << reader1.attributes().value("NAME").toString();
                                OBJbufer << reader1.attributes().value("TYPENAME").toString();
                                OBJbufer << reader1.attributes().value("OBJECTID").toString();
                                OBJbufer << reader1.attributes().value("OBJECTGUID").toString();

                                for (int obj=0;obj<OBJbufer.size();obj++) {

                                    MAINDATE->LEVEL_2[i].append(OBJbufer.at(obj));
                                    chek_list[1]=1;
                                }
                                break;
                            }
                    }
                    else
                        reader1.skipCurrentElement();
                   reader1.readNext();
                }
                reader1.skipCurrentElement();
            }
            else
                reader1.raiseError(QObject::tr("Incorrect file"));
        }


        AS_ADDR_OBJ__FILE.close();
        clearbuf=MAINDATE->LEVEL_2[i].at(0);
        clearbuf.fill(' ',1);
        MAINDATE->LEVEL_2[i][0]=clearbuf;
        MAINDATE->LEVEL_2[i].removeAll(QString(" "));
    }
         if (chek_list[0]==1 && chek_list[3]==1 && chek_list[2]==0)
        {
            QString level2buf,level2GAR;
            QStringList level2list;
        QFile AS_MUN_HIERARCHY__FILE(AS_MUN_HIERARCHY_PATH);
        AS_MUN_HIERARCHY__FILE.open(QIODevice::ReadOnly);
        QXmlStreamReader reader(&AS_MUN_HIERARCHY__FILE);

        if (reader.readNextStartElement()) {
            if (reader.name() == "ITEMS"){
                while(reader.readNextStartElement()){
                    if(reader.name() == "ITEM"){
                            if( MAINDATE->LEVEL_1.at(i).at(2)+"."+MAINDATE->LEVEL_4.at(i).at(2) == reader.attributes().value("PATH").toString())
                            {
                                 MAINDATE->LEVEL_2[i].clear();
                                 MAINDATE->LEVEL_2[i].append("0");
                                 level2GAR="0";
                                 break;
                            }
                            if(reader.attributes().value("PATH").toString().contains( MAINDATE->LEVEL_1.at(i).at(2)+".") && reader.attributes().value("PATH").toString().contains( "."+MAINDATE->LEVEL_4.at(i).at(2)) )
                            {
                                level2buf=reader.attributes().value("PATH").toString();
                                level2list=level2buf.split(".",QString::SkipEmptyParts);
                                level2GAR=level2list.at(1);
                            }



                    }
                    else
                        reader.skipCurrentElement();
                   reader.readNext();
                }
                reader.skipCurrentElement();
            }
            else
                reader.raiseError(QObject::tr("Incorrect file"));
        }


        AS_MUN_HIERARCHY__FILE.close();
        QStringList OBJbufer;

        QFile AS_ADDR_OBJ__FILE(AS_ADDR_OBJ_PATH);
        AS_ADDR_OBJ__FILE.open(QIODevice::ReadOnly);
        QXmlStreamReader reader1(&AS_ADDR_OBJ__FILE);
        if (reader1.readNextStartElement()) {
            if (reader1.name() == "ADDRESSOBJECTS"){
                while(reader1.readNextStartElement()){
                    if(reader1.name() == "OBJECT"){
                            if(reader1.attributes().value("OBJECTID").toString()==level2GAR)
                            {
                                OBJbufer << reader1.attributes().value("NAME").toString();
                                OBJbufer << reader1.attributes().value("TYPENAME").toString();
                                OBJbufer << reader1.attributes().value("OBJECTID").toString();
                                OBJbufer << reader1.attributes().value("OBJECTGUID").toString();

                                for (int obj=0;obj<OBJbufer.size();obj++) {

                                    MAINDATE->LEVEL_3[i].append(OBJbufer.at(obj));
                                    chek_list[2]=1;
                                }
                                break;
                            }
                    }
                    else
                        reader1.skipCurrentElement();
                   reader1.readNext();
                }
                reader1.skipCurrentElement();
            }
            else
                reader1.raiseError(QObject::tr("Incorrect file"));
        }


        AS_ADDR_OBJ__FILE.close();

        clearbuf=MAINDATE->LEVEL_3[i].at(0);
        clearbuf.fill(' ',1);
        MAINDATE->LEVEL_3[i][0]=clearbuf;
        MAINDATE->LEVEL_3[i].removeAll(QString(" "));
    }

         QString pathBUF;
         for (int chP=0;chP<6;chP++)
         {
             if(chek_list[chP]==1)
             {
                 switch (chP) {
                 case 0: pathBUF.append(MAINDATE->LEVEL_1.at(i).at(2) + ".");
                     break;
                 case 1: pathBUF.append(MAINDATE->LEVEL_2.at(i).at(2) + ".");
                     break;
                 case 2: pathBUF.append(MAINDATE->LEVEL_3.at(i).at(2) + ".");
                     break;
                 case 3: pathBUF.append(MAINDATE->LEVEL_4.at(i).at(2) + ".");
                     break;
                 case 4: pathBUF.append(MAINDATE->LEVEL_5.at(i).at(2) + ".");
                     break;
                 case 5: pathBUF.append(MAINDATE->LEVEL_6.at(i).at(2) + ".");
                     break;

                 }
             }
         }
        sendprePATH(pathBUF);
        QString pathSTREET;
        QStringList pathSTREETlist;

        QStringList pathBUFlist,STREET;
        QFile AS_MUN_HIERARCHY__FILE1(AS_MUN_HIERARCHY_PATH);
        AS_MUN_HIERARCHY__FILE1.open(QIODevice::ReadOnly);
        QXmlStreamReader readerP1(&AS_MUN_HIERARCHY__FILE1);

        if (readerP1.readNextStartElement()) {
            if (readerP1.name() == "ITEMS"){
                while(readerP1.readNextStartElement()){
                    if(readerP1.name() == "ITEM"){
                        pathBUFlist=pathBUF.split(".",QString::SkipEmptyParts);

                if (pathBUFlist.size()==3)
                {


                if (readerP1.attributes().value("PATH").toString().contains(pathBUF) && readerP1.attributes().value("PATH").toString().length()<35)
                {
                pathSTREET=readerP1.attributes().value("PATH").toString();
                pathSTREETlist = pathSTREET.split(".",QString::SkipEmptyParts);

                pathSTREET=pathSTREETlist[3];
                STREET.append(pathSTREET);
                   }
                }
                if (pathBUFlist.size()==2)
                {

                if (readerP1.attributes().value("PATH").toString().contains(pathBUF) && readerP1.attributes().value("PATH").toString().length()<26)
                {

                pathSTREET=readerP1.attributes().value("PATH").toString();
                pathSTREETlist = pathSTREET.split(".",QString::SkipEmptyParts);

                pathSTREET=pathSTREETlist[2];
                STREET.append(pathSTREET);
                    }
                }
                    }
                    else
                        readerP1.skipCurrentElement();
                   readerP1.readNext();
                }
                readerP1.skipCurrentElement();
            }
            else
                readerP1.raiseError(QObject::tr("Incorrect file"));
        }

        AS_MUN_HIERARCHY__FILE1.close();

        QFile AS_ADM_HIERARCHY__FILE2(AS_ADM_HIERARCHY_PATH);
        AS_ADM_HIERARCHY__FILE2.open(QIODevice::ReadOnly);
        QXmlStreamReader readerP2(&AS_ADM_HIERARCHY__FILE2);

        if (readerP2.readNextStartElement()) {
            if (readerP2.name() == "ITEMS"){
                while(readerP2.readNextStartElement()){
                    if(readerP2.name() == "ITEM"){
                        pathBUFlist=pathBUF.split(".",QString::SkipEmptyParts);

                if (pathBUFlist.size()==3)
                {


                if (readerP2.attributes().value("PATH").toString().contains(pathBUF) && readerP2.attributes().value("PATH").toString().length()<35)
                {
                pathSTREET=readerP2.attributes().value("PATH").toString();
                pathSTREETlist = pathSTREET.split(".",QString::SkipEmptyParts);

                pathSTREET=pathSTREETlist[3];
                STREET.append(pathSTREET);
                   }
                }
                if (pathBUFlist.size()==2)
                {

                if (readerP2.attributes().value("PATH").toString().contains(pathBUF) && readerP2.attributes().value("PATH").toString().length()<26)
                {

                pathSTREET=readerP2.attributes().value("PATH").toString();

                pathSTREETlist = pathSTREET.split(".",QString::SkipEmptyParts);

                pathSTREET=pathSTREETlist[2];
                STREET.append(pathSTREET);

                    }
                }

                    }
                    else
                        readerP2.skipCurrentElement();
                   readerP2.readNext();
                }
                readerP2.skipCurrentElement();
            }
            else
                readerP2.raiseError(QObject::tr("Incorrect file"));
        }
         AS_ADM_HIERARCHY__FILE2.close();


        bool chekend_list[6]={0};
         QStringList endLEVELbuf;
        QFile AS_ADDR_OBJ__FILE(AS_ADDR_OBJ_PATH);
        AS_ADDR_OBJ__FILE.open(QIODevice::ReadOnly);
        QXmlStreamReader reader1(&AS_ADDR_OBJ__FILE);
        if (reader1.readNextStartElement()) {
            if (reader1.name() == "ADDRESSOBJECTS"){
                while(reader1.readNextStartElement()){
                    if(reader1.name() == "OBJECT"){
                        for (int GF=0;GF<STREET.size();GF++) {
                            for (int PF=0;PF<MAINDATE->REZ_DATA.at(i).size();PF++)
                            {

                                if(reader1.attributes().value("OBJECTID").toString()==STREET.at(GF) && reader1.attributes().value("NAME").toString().toLower()==MAINDATE->REZ_DATA.at(i).at(PF))
                                {
                                    if (reader1.attributes().value("LEVEL").toString()=="7")
                                    {
                                        endLEVELbuf << reader1.attributes().value("NAME").toString();
                                        endLEVELbuf<< reader1.attributes().value("TYPENAME").toString();
                                        endLEVELbuf << reader1.attributes().value("OBJECTID").toString();
                                        endLEVELbuf << reader1.attributes().value("OBJECTGUID").toString();
                                        MAINDATE->LEVEL_7.append(endLEVELbuf);
                                        MAINDATE->prePATH[i].append(reader1.attributes().value("OBJECTID").toString() + ".");
                                        chekend_list[0]=1;




                                    }
                                    if (reader1.attributes().value("LEVEL").toString()=="8")
                                    {
                                        endLEVELbuf << reader1.attributes().value("NAME").toString();
                                        endLEVELbuf<< reader1.attributes().value("TYPENAME").toString();
                                        endLEVELbuf << reader1.attributes().value("OBJECTID").toString();
                                        endLEVELbuf << reader1.attributes().value("OBJECTGUID").toString();
                                        MAINDATE->prePATH[i].append(reader1.attributes().value("OBJECTID").toString() + ".");
                                        MAINDATE->LEVEL_8.append(endLEVELbuf);
                                            chekend_list[1]=1;



                                    }

                                }

                            }
                        }



                    }
                    else
                        reader1.skipCurrentElement();
                   reader1.readNext();
                }
                reader1.skipCurrentElement();
            }
            else
                reader1.raiseError(QObject::tr("Incorrect file"));
        }


        AS_ADDR_OBJ__FILE.close();
        QStringList nullist;
        nullist<<"0";

            if(chekend_list[0]==0)
            {
                MAINDATE->LEVEL_7.append(nullist);
            }
            if(chekend_list[1]==0)
            {
                MAINDATE->LEVEL_8.append(nullist);
            }




        AS_MUN_HIERARCHY_PATH.clear();
        AS_ADM_HIERARCHY_PATH.clear();
        AS_ADDR_OBJ_PATH.clear();
    }

}

void control::cliningREZ_DATA()
{
    for (int i = 0 ;i<MAINDATE->LEVEL_1.size();i++) {
        QString rez,lvl;

        for(int j = 0; j < MAINDATE->REZ_DATA.at(i).size();j++){

            rez .append(MAINDATE->REZ_DATA.at(i).at(j).toLower());
            lvl.append(MAINDATE->LEVEL_1.at(i).at(0).toLower());

          if(rez==lvl)
          {
              rez.fill(' ',1);
              MAINDATE->REZ_DATA[i][j]=rez;

          }

          rez.clear();
          lvl.clear();
         }



 MAINDATE->REZ_DATA[i].removeAll(QString(" "));

        for(int j = 0; j < MAINDATE->REZ_DATA.at(i).size();j++){
           rez .append(MAINDATE->REZ_DATA.at(i).at(j).toLower());
           lvl.append(MAINDATE->LEVEL_2.at(i).at(0).toLower());
         if(rez==lvl)
         {
             rez.fill(' ',1);
             MAINDATE->REZ_DATA[i][j]=rez;

         }
         rez.clear();
         lvl.clear();
        }


 MAINDATE->REZ_DATA[i].removeAll(QString(" "));

        for(int j = 0; j < MAINDATE->REZ_DATA.at(i).size();j++){
           rez .append(MAINDATE->REZ_DATA.at(i).at(j).toLower());
           lvl.append(MAINDATE->LEVEL_3.at(i).at(0).toLower());
         if(rez==lvl)
         {
             rez.fill(' ',1);
             MAINDATE->REZ_DATA[i][j]=rez;

         }
         rez.clear();
         lvl.clear();
        }


 MAINDATE->REZ_DATA[i].removeAll(QString(" "));

        for(int j = 0; j < MAINDATE->REZ_DATA.at(i).size();j++){
           rez .append(MAINDATE->REZ_DATA.at(i).at(j).toLower());
           lvl.append(MAINDATE->LEVEL_4.at(i).at(0).toLower());
         if(rez==lvl)
         {
             rez.fill(' ',1);
             MAINDATE->REZ_DATA[i][j]=rez;

         }
         rez.clear();
         lvl.clear();
        }


 MAINDATE->REZ_DATA[i].removeAll(QString(" "));

        for(int j = 0; j < MAINDATE->REZ_DATA.at(i).size();j++){
           rez .append(MAINDATE->REZ_DATA.at(i).at(j).toLower());
           lvl.append(MAINDATE->LEVEL_5.at(i).at(0).toLower());
         if(rez==lvl)
         {
             rez.fill(' ',1);
             MAINDATE->REZ_DATA[i][j]=rez;

         }
         rez.clear();
         lvl.clear();
        }


 MAINDATE->REZ_DATA[i].removeAll(QString(" "));

        for(int j = 0; j < MAINDATE->REZ_DATA.at(i).size();j++){
           rez .append(MAINDATE->REZ_DATA.at(i).at(j).toLower());
           lvl.append(MAINDATE->LEVEL_6.at(i).at(0).toLower());
         if(rez==lvl)
         {
             rez.fill(' ',1);
             MAINDATE->REZ_DATA[i][j]=rez;

         }
         rez.clear();
         lvl.clear();
        }

 MAINDATE->REZ_DATA[i].removeAll(QString(" "));


    }
}

void control::cliningNUMB_DATA()
{
    QString AS_MUN_HIERARCHY_PATH,AS_ADM_HIERARCHY_PATH,AS_ADDR_OBJ_PATH;
    for (int i=0;i<MAINDATE->LEVEL_1.size();i++) {
        AS_MUN_HIERARCHY_PATH.append(QCoreApplication::applicationDirPath()+"/data/baze/"+MAINDATE->REGION_CODE.at(i) + "/");
        AS_ADM_HIERARCHY_PATH.append(QCoreApplication::applicationDirPath()+"/data/baze/"+MAINDATE->REGION_CODE.at(i) + "/");
        AS_ADDR_OBJ_PATH.append(QCoreApplication::applicationDirPath()+"/data/baze/"+MAINDATE->REGION_CODE.at(i) + "/");

        QDir mDir1(AS_ADM_HIERARCHY_PATH);
        foreach (const QFileInfo &mitm, mDir1.entryInfoList(QStringList("AS_ADM_HIERARCHY_2*.XML"))){
        AS_ADM_HIERARCHY_PATH.clear();
        AS_ADM_HIERARCHY_PATH.append(mitm.absoluteFilePath());
        }

        QDir mDir2(AS_MUN_HIERARCHY_PATH);
        foreach (const QFileInfo &mitm, mDir2.entryInfoList(QStringList("AS_MUN_HIERARCHY_2*.XML"))){
        AS_MUN_HIERARCHY_PATH.clear();
        AS_MUN_HIERARCHY_PATH.append(mitm.absoluteFilePath());
        }
        QDir mDir3(AS_ADDR_OBJ_PATH);
        foreach (const QFileInfo &mitm, mDir3.entryInfoList(QStringList("AS_HOUSES_2*.XML"))){
        AS_ADDR_OBJ_PATH.clear();
        AS_ADDR_OBJ_PATH.append(mitm.absoluteFilePath());
        }

        if(MAINDATE->LEVEL_7.at(i).at(0)!="0" && MAINDATE->LEVEL_7.at(i).at(0)!="0")
        {
            QString pathSTREET,pathBUF;
            QStringList pathSTREETlist;
            pathBUF=MAINDATE->prePATH.at(i);
            QStringList pathBUFlist,STREET;
            QFile AS_MUN_HIERARCHY__FILE1(AS_MUN_HIERARCHY_PATH);
            AS_MUN_HIERARCHY__FILE1.open(QIODevice::ReadOnly);
            QXmlStreamReader readerP1(&AS_MUN_HIERARCHY__FILE1);

            if (readerP1.readNextStartElement()) {
                if (readerP1.name() == "ITEMS"){
                    while(readerP1.readNextStartElement()){
                        if(readerP1.name() == "ITEM"){
                            pathBUFlist=pathBUF.split(".",QString::SkipEmptyParts);

                    if (pathBUFlist.size()==4)
                    {


                    if (readerP1.attributes().value("PATH").toString().contains(pathBUF) && readerP1.attributes().value("PATH").toString().length()<35)
                    {
                    pathSTREET=readerP1.attributes().value("PATH").toString();
                    pathSTREETlist = pathSTREET.split(".",QString::SkipEmptyParts);

                    pathSTREET=pathSTREETlist[4];
                    STREET.append(pathSTREET);
                       }
                    }
                    if (pathBUFlist.size()==3)
                    {

                    if (readerP1.attributes().value("PATH").toString().contains(pathBUF) && readerP1.attributes().value("PATH").toString().length()<26)
                    {

                    pathSTREET=readerP1.attributes().value("PATH").toString();
                    pathSTREETlist = pathSTREET.split(".",QString::SkipEmptyParts);

                    pathSTREET=pathSTREETlist[3];
                    STREET.append(pathSTREET);
                        }
                    }
                        }
                        else
                            readerP1.skipCurrentElement();
                       readerP1.readNext();
                    }
                    readerP1.skipCurrentElement();
                }
                else
                    readerP1.raiseError(QObject::tr("Incorrect file"));
            }

            AS_MUN_HIERARCHY__FILE1.close();

            QFile AS_ADM_HIERARCHY__FILE2(AS_ADM_HIERARCHY_PATH);
            AS_ADM_HIERARCHY__FILE2.open(QIODevice::ReadOnly);
            QXmlStreamReader readerP2(&AS_ADM_HIERARCHY__FILE2);

            if (readerP2.readNextStartElement()) {
                if (readerP2.name() == "ITEMS"){
                    while(readerP2.readNextStartElement()){
                        if(readerP2.name() == "ITEM"){
                            pathBUFlist=pathBUF.split(".",QString::SkipEmptyParts);

                    if (pathBUFlist.size()==4)
                    {


                    if (readerP2.attributes().value("PATH").toString().contains(pathBUF) && readerP2.attributes().value("PATH").toString().length()<35)
                    {
                    pathSTREET=readerP2.attributes().value("PATH").toString();
                    pathSTREETlist = pathSTREET.split(".",QString::SkipEmptyParts);

                    pathSTREET=pathSTREETlist[4];
                    STREET.append(pathSTREET);
                       }
                    }
                    if (pathBUFlist.size()==3)
                    {

                    if (readerP2.attributes().value("PATH").toString().contains(pathBUF) && readerP2.attributes().value("PATH").toString().length()<26)
                    {

                    pathSTREET=readerP2.attributes().value("PATH").toString();

                    pathSTREETlist = pathSTREET.split(".",QString::SkipEmptyParts);

                    pathSTREET=pathSTREETlist[3];
                    STREET.append(pathSTREET);

                        }
                    }

                        }
                        else
                            readerP2.skipCurrentElement();
                       readerP2.readNext();
                    }
                    readerP2.skipCurrentElement();
                }
                else
                    readerP2.raiseError(QObject::tr("Incorrect file"));
            }
             AS_ADM_HIERARCHY__FILE2.close();


             bool chekend_list[6]={0};
              QStringList endLEVELbuf;
             QFile AS_ADDR_OBJ__FILE(AS_ADDR_OBJ_PATH);
             AS_ADDR_OBJ__FILE.open(QIODevice::ReadOnly);
             QXmlStreamReader reader1(&AS_ADDR_OBJ__FILE);
             if (reader1.readNextStartElement()) {
                 if (reader1.name() == "HOUSES"){
                     while(reader1.readNextStartElement()){
                         if(reader1.name() == "HOUSE"){
                             for (int GF=0;GF<STREET.size();GF++) {
                                 for (int PF=0;PF<MAINDATE->NUMB_DATA.at(i).size();PF++)
                                 {

                                     if(reader1.attributes().value("OBJECTID").toString()==STREET.at(GF) && reader1.attributes().value("HOUSENUM").toString().toLower()==MAINDATE->NUMB_DATA.at(i).at(PF))
                                     {
                                         if (reader1.attributes().value("HOUSETYPE").toString()=="2")
                                         {
                                             endLEVELbuf << reader1.attributes().value("HOUSENUM").toString();
                                             endLEVELbuf<< reader1.attributes().value("HOUSETYPE").toString();
                                             endLEVELbuf << reader1.attributes().value("OBJECTID").toString();
                                             endLEVELbuf << reader1.attributes().value("OBJECTGUID").toString();
                                             MAINDATE->LEVEL_9.append(endLEVELbuf);
                                             MAINDATE->prePATH[i].append(reader1.attributes().value("OBJECTID").toString() + ".");
                                             chekend_list[0]=1;




                                         }
                                         if (reader1.attributes().value("HOUSETYPE").toString()=="10")
                                         {
                                             endLEVELbuf << reader1.attributes().value("HOUSENUM").toString();
                                             endLEVELbuf<< reader1.attributes().value("HOUSETYPE").toString();
                                             endLEVELbuf << reader1.attributes().value("OBJECTID").toString();
                                             endLEVELbuf << reader1.attributes().value("OBJECTGUID").toString();
                                             MAINDATE->prePATH[i].append(reader1.attributes().value("OBJECTID").toString() + ".");
                                             MAINDATE->LEVEL_10.append(endLEVELbuf);
                                                 chekend_list[1]=1;



                                         }

                                     }

                                 }
                             }



                         }
                         else
                             reader1.skipCurrentElement();
                        reader1.readNext();
                     }
                     reader1.skipCurrentElement();
                 }
                 else
                     reader1.raiseError(QObject::tr("Incorrect file"));
             }


             AS_ADDR_OBJ__FILE.close();
             QStringList nullist;
             nullist<<"0";

                 if(chekend_list[0]==0)
                 {
                     MAINDATE->LEVEL_9.append(nullist);
                 }
                 if(chekend_list[1]==0)
                 {
                     MAINDATE->LEVEL_10.append(nullist);
                 }
        }



        AS_MUN_HIERARCHY_PATH.clear();
        AS_ADM_HIERARCHY_PATH.clear();
        AS_ADDR_OBJ_PATH.clear();
    }
}

QString control::createOUTPUTFILE()
{
    QString impEXEL;

impEXEL = QString("%1/").arg(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));
QXlsx::Document xlsxinOUT;
QXlsx::Format defFormat;
QColor defColor;
defColor.setRgb(247, 208, 109);
defFormat.setPatternBackgroundColor(defColor);
defFormat.setFontSize(18);
xlsxinOUT.setColumnWidth(1,20.0);
xlsxinOUT.setColumnWidth(2,50.0);
xlsxinOUT.setColumnWidth(3,50.0);
xlsxinOUT.setColumnWidth(4,50.0);
xlsxinOUT.setColumnWidth(5,50.0);
xlsxinOUT.setColumnWidth(6,50.0);
xlsxinOUT.setColumnWidth(7,50.0);
xlsxinOUT.setColumnWidth(8,50.0);
xlsxinOUT.setColumnWidth(9,50.0);
xlsxinOUT.setColumnWidth(10,50.0);
xlsxinOUT.setColumnWidth(11,50.0);
xlsxinOUT.setColumnWidth(12,50.0);
xlsxinOUT.setColumnWidth(13,50.0);
xlsxinOUT.setColumnWidth(14,50.0);
xlsxinOUT.setColumnWidth(15,50.0);
xlsxinOUT.setColumnWidth(16,50.0);
xlsxinOUT.setColumnWidth(17,50.0);
xlsxinOUT.setColumnWidth(18,50.0);
xlsxinOUT.setColumnWidth(19,50.0);
xlsxinOUT.setColumnWidth(20,50.0);
xlsxinOUT.setColumnWidth(21,50.0);
defFormat.setVerticalAlignment(QXlsx::Format::AlignVCenter);
defFormat.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
xlsxinOUT.write("A1","№ п/п",defFormat);
xlsxinOUT.mergeCells("A1:A2");
xlsxinOUT.write("B1","Исходный адрес",defFormat);
xlsxinOUT.mergeCells("B1:B2");
xlsxinOUT.write("C1","Адрес в ГАР",defFormat);
xlsxinOUT.mergeCells("C1:C2");
xlsxinOUT.write("D1","Cубъект РФ",defFormat);
xlsxinOUT.mergeCells("D1:E1");
xlsxinOUT.write("D2","Наименование",defFormat);
xlsxinOUT.mergeCells("D2:D2");
xlsxinOUT.write("E2","Уникальный идентификатор",defFormat);
xlsxinOUT.mergeCells("E2:E2");

xlsxinOUT.write("F1","Административный район",defFormat);
xlsxinOUT.mergeCells("F1:G1");
xlsxinOUT.write("F2","Наименование",defFormat);
xlsxinOUT.mergeCells("F2:F2");
xlsxinOUT.write("G2","Уникальный идентификатор",defFormat);
xlsxinOUT.mergeCells("G2:G2");

xlsxinOUT.write("H1","Город",defFormat);
xlsxinOUT.mergeCells("H1:I1");
xlsxinOUT.write("H2","Наименование",defFormat);
xlsxinOUT.mergeCells("H2:H2");
xlsxinOUT.write("I2","Уникальный идентификатор",defFormat);
xlsxinOUT.mergeCells("I2:I2");

xlsxinOUT.write("J1","Населённый пункт",defFormat);
xlsxinOUT.mergeCells("J1:K1");
xlsxinOUT.write("J2","Наименование",defFormat);
xlsxinOUT.mergeCells("J2:J2");
xlsxinOUT.write("K2","Уникальный идентификатор",defFormat);
xlsxinOUT.mergeCells("K2:K2");

xlsxinOUT.write("L1","Элемент планировочной структуры",defFormat);
xlsxinOUT.mergeCells("L1:M1");
xlsxinOUT.write("L2","Наименование",defFormat);
xlsxinOUT.mergeCells("L2:L2");
xlsxinOUT.write("M2","Уникальный идентификатор",defFormat);
xlsxinOUT.mergeCells("M2:M2");

xlsxinOUT.write("N1","Элемент улично-дорожной сети",defFormat);
xlsxinOUT.mergeCells("N1:O1");
xlsxinOUT.write("N2","Наименование",defFormat);
xlsxinOUT.mergeCells("N2:N2");
xlsxinOUT.write("O2","Уникальный идентификатор",defFormat);
xlsxinOUT.mergeCells("O2:O2");

xlsxinOUT.write("P1","Земельный участок",defFormat);
xlsxinOUT.mergeCells("P1:Q1");
xlsxinOUT.write("P2","Наименование",defFormat);
xlsxinOUT.mergeCells("P2:P2");
xlsxinOUT.write("Q2","Уникальный идентификатор",defFormat);
xlsxinOUT.mergeCells("Q2:Q2");

xlsxinOUT.write("R1","Здание (сооружение)",defFormat);
xlsxinOUT.mergeCells("R1:S1");
xlsxinOUT.write("R2","Наименование",defFormat);
xlsxinOUT.mergeCells("R2:R2");
xlsxinOUT.write("S2","Уникальный идентификатор",defFormat);
xlsxinOUT.mergeCells("S2:S2");

xlsxinOUT.write("T1","Помещение",defFormat);
xlsxinOUT.mergeCells("T1:U1");
xlsxinOUT.write("T2","Наименование",defFormat);
xlsxinOUT.mergeCells("T2:T2");
xlsxinOUT.write("U2","Уникальный идентификатор",defFormat);
xlsxinOUT.mergeCells("U2:U2");



xlsxinOUT.saveAs(impEXEL + "out" + ".xlsx");
impEXEL.append("out.xlsx");

return impEXEL;
}

void control::outDATA(QString path)
{
    QXlsx::Document xlsxout(path);
    for (int i = 0;i<MAINDATE->LEVEL_1.size();i++) {

        QString buf = QString::number(i+3);
        QString buf1 = QString::number(i+1);

        xlsxout.write("B"+buf, MAINDATE->START_ADDRES[i]);
        xlsxout.save();
        QString bufGAR;
        xlsxout.write("A"+buf,buf1);
        if (MAINDATE->LEVEL_1[i].size()!=0){
        if (MAINDATE->LEVEL_1[i].at(0)!="0" )
        {
            bufGAR.append(MAINDATE->LEVEL_1.at(i).at(0));
            bufGAR.append(" "+MAINDATE->LEVEL_1.at(i).at(1));

            xlsxout.write("D"+buf,MAINDATE->LEVEL_1.at(i).at(0)+" "+MAINDATE->LEVEL_1.at(i).at(1));
            xlsxout.write("E"+buf,MAINDATE->LEVEL_1.at(i).at(3));
        }
       }

        if (MAINDATE->LEVEL_2[i].size()!=0){
        if (MAINDATE->LEVEL_2[i].at(0)!="0")
        {
            bufGAR.append(" "+MAINDATE->LEVEL_2.at(i).at(1));
            bufGAR.append(" "+MAINDATE->LEVEL_2.at(i).at(0));

            xlsxout.write("F"+buf,MAINDATE->LEVEL_2.at(i).at(1)+" "+MAINDATE->LEVEL_2.at(i).at(0));
            xlsxout.write("G"+buf,MAINDATE->LEVEL_2.at(i).at(3));
        }
        }

        if (MAINDATE->LEVEL_3[i].size()!=0){
          if (MAINDATE->LEVEL_3[i][0]!="0" )
        {
              bufGAR.append(" "+MAINDATE->LEVEL_3.at(i).at(1));
              bufGAR.append(" "+MAINDATE->LEVEL_3.at(i).at(0));
            xlsxout.write("F"+buf,MAINDATE->LEVEL_3.at(i).at(1)+" "+MAINDATE->LEVEL_3.at(i).at(0));
            xlsxout.write("G"+buf,MAINDATE->LEVEL_3.at(i).at(3));
        }
           }

           if (MAINDATE->LEVEL_5[i].size()!=0){
        if (MAINDATE->LEVEL_5[i][0]!="0" )
        {
            bufGAR.append(" "+MAINDATE->LEVEL_5.at(i).at(1));
            bufGAR.append(" "+MAINDATE->LEVEL_5.at(i).at(0));
            xlsxout.write("H"+buf,MAINDATE->LEVEL_5.at(i).at(1)+" "+MAINDATE->LEVEL_5.at(i).at(0));
            xlsxout.write("I"+buf,MAINDATE->LEVEL_5.at(i).at(3));
        }
         }

           if (MAINDATE->LEVEL_6[i].size()!=0){
        if (MAINDATE->LEVEL_6[i][0]!="0" )
        {
            bufGAR.append(" "+MAINDATE->LEVEL_6.at(i).at(1));
            bufGAR.append(" "+MAINDATE->LEVEL_6.at(i).at(0));
            xlsxout.write("J"+buf,MAINDATE->LEVEL_6.at(i).at(1)+" "+MAINDATE->LEVEL_6.at(i).at(0));
            xlsxout.write("K"+buf,MAINDATE->LEVEL_6.at(i).at(3));
        }
        }
           if (MAINDATE->LEVEL_7[i].size()!=0){
        if (MAINDATE->LEVEL_7[i][0]!="0" )
        {
            bufGAR.append(" "+MAINDATE->LEVEL_7.at(i).at(1));
            bufGAR.append(" "+MAINDATE->LEVEL_7.at(i).at(0));
            xlsxout.write("L"+buf,MAINDATE->LEVEL_7.at(i).at(1)+" "+MAINDATE->LEVEL_7.at(i).at(0));
            xlsxout.write("M"+buf,MAINDATE->LEVEL_7.at(i).at(3));
        }
         }
           if (MAINDATE->LEVEL_8[i].size()!=0){
        if (MAINDATE->LEVEL_8[i][0]!="0" )
        {
            bufGAR.append(" "+MAINDATE->LEVEL_8.at(i).at(1));
            bufGAR.append(" "+MAINDATE->LEVEL_8.at(i).at(0));

            xlsxout.write("N"+buf,MAINDATE->LEVEL_8.at(i).at(1)+" "+MAINDATE->LEVEL_8.at(i).at(0));
            xlsxout.write("O"+buf,MAINDATE->LEVEL_8.at(i).at(3));
        }
        }
    xlsxout.write("C"+buf,bufGAR);
    xlsxout.save();
    buf.clear();
    bufGAR.clear();
    }
  xlsxout.save();

}

void control::startdocgeneration()
{

    int i=0;
    //
    start->setText("Идёт обработка");
    i++;
    progress->setValue(i);
    prog->setText("Получение пути к входным данным");
    geetinginf->setPATH(FILE_PATH);
    i++;

    progress->setValue(i);

    prog->setText("Обнаружение регионов");

    geetinginf->parsREGID();

    i++;
    progress->setValue(i);
    prog->setText("Анализ данных регионального уровня");
    geetinginf->parsREGDATA();
    i++;
    progress->setValue(i);
    prog->setText("Фильтрация существующего потока");
    cliningREZ_DATA();
    i++;
    progress->setValue(i);
    prog->setText("Выравнивание хранилища");
    cliningLEVEL_MAP();
    i++;
    progress->setValue(i);
    prog->setText("Создание и заполнение выходной таблицы");
    outDATA(createOUTPUTFILE());
    i++;
    progress->setValue(i);
    prog->setText("Обработка выполнена");

    QMessageBox helper;
    helper.setWindowFlags(Qt::FramelessWindowHint);

    helper.setWindowTitle("GAR FIAS ANALITIC      Дополнительная информация");
    helper.setText("GAR FIAS ANALITIC обработал полученные данные, создал на вашем рабочем столе "
                   "xlsx файл под именем <out>, и разместил там обработанные данные");


    qApp->setStyleSheet(" QMessageBox{ background-color: black; color: #1bb004;}"
                        "QMessageBox QLabel { color: #1bb004;} "
                        "QMessageBox QPushButton{"
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


    helper.exec();
    this->close();

}

void control::createstartdoc()
{
    FILE_PATH.clear();
    FILE_PATH.append(inputDAT.createInFile());
    start->setDisabled(false);
    QMessageBox helper;
    helper.setWindowFlags(Qt::FramelessWindowHint);
    helper.setWindowTitle("GAR FIAS ANALITIC      Дополнительная информация");
    helper.setText("GAR FIAS ANALITIC создал на вашем рабочем столе "
                   "xlsx файл под именем <Input>, введите туда исходные данные");


    qApp->setStyleSheet(" QMessageBox{ background-color: black; color: #1bb004;}"
                        "QMessageBox QLabel { color: #1bb004;} "
                        "QMessageBox QPushButton{"
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


    helper.exec();
}

void control::chosestartdoc()
{
        QFileDialog chose;
        FILE_PATH.clear();
        FILE_PATH.append(chose.getOpenFileName(0, "GAR FIAS ANALITIC      Выбор файла с входными данными", "", "*.xlsx"));
    start->setDisabled(false);
}
void control::show_inf()
{

QMessageBox helper;

helper.setWindowFlags(Qt::FramelessWindowHint);

helper.setWindowTitle("GAR FIAS ANALITIC      Дополнительная информация");
helper.setText("GAR FIAS ANALITIC - прогрмное обеспечения для осуществления автоматизированной "
               "обработки данных используя базу данных ГАР ФИАС средствами языка С++ "
               "и библиотки Qt с открытым исходным кодом"
               "\n\n"
               "Разработчики ПО:\n"
               "\n"
               "заместитель командира взвода\n"
               "Воронежского института МВД России\n"
               "сержант полиции Бакулин Н.С.\n"
               "\n"
               "курсант\n"
               "Воронежского института МВД России\n"
               "рядовой полиции Биктимирова Ю.В.\n");


qApp->setStyleSheet(" QMessageBox{ background-color: black; color: #1bb004;}"
                    "QMessageBox QLabel { color: #1bb004;} "
                    "QMessageBox QPushButton{"
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

helper.exec();
}
void control::show_crSTATUS()
{
//QIcon icon;
//icon.addFile(":/res/inf.png");
QMessageBox helper;
helper.setWindowFlags(Qt::FramelessWindowHint);
helper.setWindowTitle("GAR FIAS ANALITIC      Дополнительная информация");
helper.setText("GAR FIAS ANALITIC создал на вашем рабочем столе "
               "xlsx файл под именем <Input>, введите туда исходные данные");


qApp->setStyleSheet(" QMessageBox{ background-color: black; color: #1bb004;}"
                    "QMessageBox QLabel { color: #1bb004;} "
                    "QMessageBox QPushButton{"
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


helper.exec();
}


