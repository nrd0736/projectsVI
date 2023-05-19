#include "parsdate.h"
#define WARN_UNUSED __attribute__((warn_unused_result))

parsdate::parsdate(QObject *parent) : QObject(parent)
{ }


void parsdate::parsREGID()
{
    QXlsx::Document xlsxin(inpath);
    QXlsx::Cell* cell;
    QVariant var;
    QStringList  ADDR_OBJ_ATTRIB_LIST;
    QFile AS_ADDR_OBJ_TYPES__FILE(AS_ADDR_OBJ_TYPES__PATH);
    AS_ADDR_OBJ_TYPES__FILE.open(QIODevice::ReadOnly);

    QXmlStreamReader reader(&AS_ADDR_OBJ_TYPES__FILE);
    for (int i=3;;i++){


        if (xlsxin.cellAt(1000,1000)==xlsxin.cellAt(i,2) || xlsxin.cellAt(i,2)->value().isNull()  )
        {

            break;
        }

        cell = xlsxin.cellAt(i,2);
        var = cell->value();
        stringFULLlover= QVariant(var).toString().toLower();
        stringFULL= QVariant(var).toString();
        sendstartADD(stringFULL);




    if (reader.readNextStartElement()) {
        if (reader.name() == "ADDRESSOBJECTTYPES"){
            while(reader.readNextStartElement()){
                if(reader.name() == "ADDRESSOBJECTTYPE"){
                         ADDR_OBJ_ATTRIB_LIST<< reader.attributes().value("SHORTNAME").toString().toLower();
                         ADDR_OBJ_ATTRIB_LIST<< reader.attributes().value("NAME").toString().toLower();
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

        word_list=stringFULLlover.split(' ',QString::SkipEmptyParts);
        QString pointbuf;
        char countbuf[]={'0','1','2','3','4','5','6','7','8','9'};
        QRegExp rx("(\\d+)");

        for (int H = 0;H<word_list.size(); H++) {
         if (word_list.at(H).indexOf(",")>=0)
         {
             pointbuf =word_list.at(H);
             pointbuf.remove(pointbuf.indexOf(","),1);
             word_list[H]=pointbuf;
         }
         }

            for (int G=0;G<ADDR_OBJ_ATTRIB_LIST.size();G++) {
                for (int H = 0;H<word_list.size(); H++) {

                    if (word_list.at(H)==ADDR_OBJ_ATTRIB_LIST.at(G)) {word_list.takeAt(H);}

                }
            }



          for (int H = 0;H<word_list.size(); H++) {
              for (int numb = 0;numb<10;numb++) {
           if (word_list.at(H).indexOf(countbuf[numb])>=0)
           {
               pointbuf =word_list.at(H);
               pointbuf.fill(' ',1);
               word_list[H]=pointbuf;
           }
            }
          }

          for (int H = 0;H<word_list.size(); H++) {
           if ((word_list.at(H).indexOf("/")>=0) || word_list[H].size()<=3 || (word_list.at(H).indexOf(";")>=0))
           {
               pointbuf =word_list.at(H);
               pointbuf.fill(' ',1);
               word_list[H]=pointbuf;
           }
           }


          for (int H = 0;H<word_list.size(); H++) {
           if (word_list[H].endsWith(".") || word_list[H].contains("ул.") )
           {
               pointbuf =word_list.at(H);
               pointbuf.fill(' ',1);
               word_list[H]=pointbuf;
           }
           }


          for (int H = 0;H<word_list.size(); H++) {
           if (word_list[H].contains("г."))
           {
               pointbuf =word_list.at(H);
               pointbuf.remove(0,2);
               word_list[H]=pointbuf;
           }
           }

          for (int H = 0;H<word_list.size(); H++) {
           if (word_list[H].contains("обл.") || (word_list[H].contains("гор.")))
           {
               pointbuf =word_list.at(H);
               pointbuf.remove(0,3);
               word_list[H]=pointbuf;
           }
           }

          word_list.removeAll(QString(" "));


          QXlsx::Document xlsxregion(REGION_SUBJECT_PASS);
          QXlsx::Cell* cellreg1;
          QXlsx :: Cell *cellreg2;
          QXlsx :: Cell *cellreg3;
          QVariant varreg1,varreg2,varreg3;



          for (int H = 0;H<word_list.size(); H++) {
              for (int Xr= 1; ;Xr++) {

                  if (xlsxregion.cellAt(1000,1000)==xlsxregion.cellAt(i,2) || xlsxregion.cellAt(i,2)->value().isNull()  )
                  {

                      break;
                  }

                  cellreg1 = xlsxregion.cellAt(Xr,2);
                  varreg1 = cellreg1->value();

                  cellreg2 = xlsxregion.cellAt(Xr,3);
                  varreg2 = cellreg2->value();

                  if(word_list[H]==QVariant(varreg1).toString().toLower() ||  word_list[H]==QVariant(varreg2).toString().toLower() )
                  {
                      cellreg3 = xlsxregion.cellAt(Xr,1);
                      varreg3 = cellreg3->value();
                      QString ID;

                      ID=QVariant(varreg3).toString();
                      sendregID(ID);
                      regid_list<<ID;
                      goto reg;

                  }

              }
                if(H==word_list.size()-1) { sendregID("НЕУСТАНОВЛЕННЫЙ РЕГИОН"); regid_list<<"НЕУСТАНОВЛЕННЫЙ РЕГИОН";}

           }
    reg:


        stringFULLlover.clear();
        stringFULL.clear();
        word_list.clear();

    }

}

void parsdate::parsREGDATA()
{


    QXlsx::Document xlsxin(inpath);
    QXlsx::Cell* cell;
    QVariant var;
    QStringList  ADDR_OBJ_ATTRIB_LIST,AS_APPARTMEN_LIST,AS_HOUSE_LIST;
    QFile AS_ADDR_OBJ_TYPES__FILE(AS_ADDR_OBJ_TYPES__PATH);
    AS_ADDR_OBJ_TYPES__FILE.open(QIODevice::ReadOnly);
    QXmlStreamReader reader(&AS_ADDR_OBJ_TYPES__FILE);

    QString pointbuf;
    for (int i=3;;i++){

        if (xlsxin.cellAt(1000,1000)==xlsxin.cellAt(i,2) || xlsxin.cellAt(i,2)->value().isNull()  )
        {

            break;
        }
        cell = xlsxin.cellAt(i,2);
        var = cell->value();
        stringFULLlover= QVariant(var).toString().toLower();
        stringFULL= QVariant(var).toString();


    if (reader.readNextStartElement()) {
        if (reader.name() == "ADDRESSOBJECTTYPES"){
            while(reader.readNextStartElement()){
                if(reader.name() == "ADDRESSOBJECTTYPE"){
                         ADDR_OBJ_ATTRIB_LIST<< reader.attributes().value("SHORTNAME").toString().toLower();
                         ADDR_OBJ_ATTRIB_LIST<< reader.attributes().value("NAME").toString().toLower();
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

    while (stringFULLlover.contains(';')) {
        stringFULLlover.remove(stringFULLlover.indexOf(";"),' ');
    }
    while (stringFULLlover.contains(':')) {
        stringFULLlover.remove(stringFULLlover.indexOf(":"),' ');
    }
    while (stringFULLlover.contains('\"')) {
        stringFULLlover.remove(stringFULLlover.indexOf("\""),' ');
    }
    while (stringFULLlover.contains('(')) {
        stringFULLlover.remove(stringFULLlover.indexOf("("),' ');
    }
    while (stringFULLlover.contains(')')) {
        stringFULLlover.remove(stringFULLlover.indexOf(")"),' ');
    }

        word_list=stringFULLlover.split(' ',QString::SkipEmptyParts);


        for (int H = 0;H<word_list.size(); H++) {
         if (word_list.at(H).indexOf(",")>=0)
         {
             pointbuf =word_list.at(H);
             pointbuf.remove(pointbuf.indexOf(","),1);
             word_list[H]=pointbuf;
         }
         }

            for (int G=0;G<ADDR_OBJ_ATTRIB_LIST.size();G++) {
                for (int H = 0;H<word_list.size(); H++) {

                    if (word_list.at(H)==ADDR_OBJ_ATTRIB_LIST.at(G)) {word_list.takeAt(H);}

                }
            }



            QDir mDir1(AS_APPARTMEN_PATH);
            foreach (const QFileInfo &mitm, mDir1.entryInfoList(QStringList("AS_APARTMENT_TYPES*.XML"))){
            AS_APPARTMEN_PATH.clear();
            AS_APPARTMEN_PATH.append(mitm.absoluteFilePath());
            }

            QDir mDir2(AS_HOUSE_PATH);
            foreach (const QFileInfo &mitm, mDir2.entryInfoList(QStringList("AS_HOUSE_TYPES*.XML"))){
            AS_HOUSE_PATH.clear();
            AS_HOUSE_PATH.append(mitm.absoluteFilePath());
            }




            QFile AS_APPARTMEN__FILE(AS_APPARTMEN_PATH);
            AS_APPARTMEN__FILE.open(QIODevice::ReadOnly);
            QXmlStreamReader reader1(&AS_APPARTMEN__FILE);

            if (reader1.readNextStartElement()) {
                if (reader1.name() == "APARTMENTTYPES"){
                    while(reader1.readNextStartElement()){
                        if(reader1.name() == "APARTMENTTYPE"){
                                 AS_APPARTMEN_LIST<< reader1.attributes().value("SHORTNAME").toString().toLower();
                                 AS_APPARTMEN_LIST<< reader1.attributes().value("NAME").toString().toLower();
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


            QFile AS_HOUSE__FILE(AS_HOUSE_PATH);
            AS_HOUSE__FILE.open(QIODevice::ReadOnly);
            QXmlStreamReader reader2(&AS_HOUSE__FILE);

            if (reader2.readNextStartElement()) {
                if (reader2.name() == "HOUSETYPES"){
                    while(reader2.readNextStartElement()){
                        if(reader2.name() == "HOUSETYPE"){
                                 AS_HOUSE_LIST<< reader2.attributes().value("SHORTNAME").toString().toLower();
                                 AS_HOUSE_LIST<< reader2.attributes().value("NAME").toString().toLower();
                        }
                        else
                            reader2.skipCurrentElement();
                       reader2.readNext();
                    }
                    reader2.skipCurrentElement();
                }
                else
                    reader2.raiseError(QObject::tr("Incorrect file"));
            }

            for (int G=0;G<AS_APPARTMEN_LIST.size();G++) {
                for (int H = 0;H<word_list.size(); H++) {

                    if (word_list.at(H)==AS_APPARTMEN_LIST.at(G)) {word_list.takeAt(H);}


                }
            }
            for (int G=0;G<AS_HOUSE_LIST.size();G++) {
                for (int H = 0;H<word_list.size(); H++) {

                    if (word_list.at(H)==AS_HOUSE_LIST.at(G)) {word_list.takeAt(H);}


                }
            }
            for (int H = 0;H<word_list.size(); H++) {
             if (word_list[H].contains("г.") || word_list[H].contains("д.")|| word_list[H].contains("с.")|| word_list[H].contains("н.")|| word_list[H].contains("м.")|| word_list[H].contains("б."))
             {
                 pointbuf =word_list.at(H);
                 pointbuf.remove(0,2);
                 word_list[H]=pointbuf;
             }
             }
            for (int H = 0;H<word_list.size(); H++) {
             if (word_list[H].contains("обл.") || (word_list[H].contains("гор.")) || (word_list[H].contains("пос.")) )
             {
                 pointbuf =word_list.at(H);
                 pointbuf.remove(0,3);
                 word_list[H]=pointbuf;
             }
             }
            for (int H = 0;H<word_list.size(); H++) {
             if (word_list[H].endsWith(".") )
             {
                 pointbuf =word_list.at(H);
                 pointbuf.fill(' ',1);
                 word_list[H]=pointbuf;
             }
             }

            for (int H = 0;H<word_list.size(); H++) {
             if ( word_list[H].contains("ул.") || word_list[H].contains("кв.") ||  word_list[H].contains("ст.") )
             {
                 pointbuf =word_list.at(H);
                 pointbuf.remove(0,2);
                 word_list[H]=pointbuf;
             }
             }
            for (int H = 0;H<word_list.size(); H++) {
             if (word_list[H].startsWith(".") )
             {
                 pointbuf =word_list.at(H);
                 pointbuf.fill(' ',1);
                 word_list[H]=pointbuf;
             }
        }
            for (int H = 0;H<word_list.size(); H++) {
             if (word_list[H].size()<=3  )
             {
                 pointbuf =word_list.at(H);
                 pointbuf.fill(' ',1);
                 word_list[H]=pointbuf;
             }
        }


            for (int H = 0;H<word_list.size(); H++) {
                 pointbuf =word_list.at(H);
                 bool ok;
                 int decr = pointbuf.toInt(&ok, 10);
                 if (ok)
                 {
                     pointbuf.fill(' ',1);
                     word_list[H]=pointbuf;
                 }


             }

             word_list.removeAll(QString(" "));

             for (int H = 0;H<word_list.size(); H++) {
              if (word_list[H].startsWith(".") )
              {
                  pointbuf =word_list.at(H);
                  pointbuf.fill(' ',1);
                  word_list[H]=pointbuf;
              }
             }
              for (int H = 0;H<word_list.size(); H++) {
               if (word_list[H]=="россия" || word_list[H]=="республики" || word_list[H]=="р-на" || word_list[H]=="района" ||word_list[H]=="совхоз"||word_list[H]=="совхоза")
               {
                   pointbuf =word_list.at(H);
                   pointbuf.fill(' ',1);
                   word_list[H]=pointbuf;
               }
             }

              for (int H = 0;H<word_list.size(); H++) {
               if (word_list[H].contains("с.") ||word_list[H].contains("а.")||word_list[H].contains("л."))
               {
                   pointbuf =word_list.at(H);
                   pointbuf.remove(0,2);
                   word_list[H]=pointbuf;
               }
             }

              for (int H = 0;H<word_list.size(); H++) {
                   pointbuf =word_list.at(H);
                   bool ok;
                   int decr = pointbuf.toInt(&ok, 10);
                   if (ok)
                   {
                       pointbuf.fill(' ',1);
                       word_list[H]=pointbuf;
                   }


               }

             word_list.removeAll(QString(" "));

             sendREZ_DATA(word_list);


            QString nameADMsub;

             QXlsx::Document xlsxregion(REGION_SUBJECT_PASS);
             QXlsx :: Cell *cellreg4;
             QXlsx :: Cell *cellreg5;
             QVariant varreg4,varreg5;

                 for (int Xr= 1; ;Xr++) {
                     if (xlsxregion.cellAt(Xr,1)==xlsxregion.cellAt(100,100))
                     {
                         break;
                     }
                     cellreg4 = xlsxregion.cellAt(Xr,1);
                     varreg4 = cellreg4->value();

                    if(regid_list.at(i-3)==QVariant(varreg4).toString())
                    {
                        cellreg5 = xlsxregion.cellAt(Xr,2);
                        varreg5 = cellreg5->value();
                        nameADMsub=QVariant(varreg5).toString().toLower();
                    }

                 }

                 if (nameADMsub.isEmpty()) nameADMsub="Субъект не найден";

                 QString AS_ADDR_OBJ_REG_PATH;
                 QStringList AS_ADDR_OBJ_REG_LIST;
                 bool chek_level[12]={0};
                 AS_ADDR_OBJ_REG_PATH.append(QCoreApplication::applicationDirPath()+"/data/baze/"+regid_list.at(i-3)+"/");
                 QDir mDir3(AS_ADDR_OBJ_REG_PATH);

                 foreach (const QFileInfo &mitm, mDir3.entryInfoList(QStringList("AS_ADDR_OBJ_2*.XML"))){
                 AS_ADDR_OBJ_REG_PATH.clear();
                 AS_ADDR_OBJ_REG_PATH.append(mitm.absoluteFilePath());
                 }

                 QFile  AS_ADDR_OBJ_REG_FILE( AS_ADDR_OBJ_REG_PATH);
                 AS_ADDR_OBJ_REG_FILE.open(QIODevice::ReadOnly);
                 QXmlStreamReader reader3(&AS_ADDR_OBJ_REG_FILE);


                 if (reader3.readNextStartElement()) {
                     if (reader3.name() == "ADDRESSOBJECTS"){
                         while(reader3.readNextStartElement()){
                             if(reader3.name() == "OBJECT"){
                                 if (reader3.attributes().value("NAME").toString().toLower()==nameADMsub && reader3.attributes().value("LEVEL").toString() =="1")
                                    {
                                           AS_ADDR_OBJ_REG_LIST << reader3.attributes().value("NAME").toString();
                                           AS_ADDR_OBJ_REG_LIST << reader3.attributes().value("TYPENAME").toString();
                                           AS_ADDR_OBJ_REG_LIST << reader3.attributes().value("OBJECTID").toString();
                                           AS_ADDR_OBJ_REG_LIST << reader3.attributes().value("OBJECTGUID").toString();

                                           sendDATALEVEL_1(AS_ADDR_OBJ_REG_LIST);
                                           chek_level[0]=1;

                                 }

                             }
                             else
                                 reader3.skipCurrentElement();
                            reader3.readNext();
                         }
                         reader3.skipCurrentElement();
                     }
                     else
                         reader3.raiseError(QObject::tr("Incorrect file"));
                 }
                 AS_ADDR_OBJ_REG_FILE.close();
                if (chek_level[0]==0)
                {
                 AS_ADDR_OBJ_REG_LIST<<"НЕКОРРЕКТНЫЕ ДАННЫЕ";

                 sendDATALEVEL_1(AS_ADDR_OBJ_REG_LIST);
                }


                 QStringList AS_ADDR_OBJ_RAION_LIST,AS_ADDR_OBJ_GOR_LIST,AS_ADDR_OBJ_MUNRN_LIST,AS_ADDR_OBJ_SP_LIST,AS_ADDR_OBJ_NP_LIST;
                 QString lvlbuf;

                 for (int H = 0;H<word_list.size(); H++) {



                     QFile  AS_ADDR_OBJ_REG_FILE2( AS_ADDR_OBJ_REG_PATH);
                     AS_ADDR_OBJ_REG_FILE2.open(QIODevice::ReadOnly);
                     QXmlStreamReader reader4(&AS_ADDR_OBJ_REG_FILE2);


                            lvlbuf = word_list[H];

                     if (reader4.readNextStartElement()) {
                         if (reader4.name() == "ADDRESSOBJECTS"){
                             while(reader4.readNextStartElement()){

                                 if(reader4.name() == "OBJECT"){

                                     if (reader4.attributes().value("NAME").toString().toLower() == lvlbuf && reader4.attributes().value("LEVEL").toString() =="2")
                                        {
                                               AS_ADDR_OBJ_RAION_LIST << reader4.attributes().value("NAME").toString();
                                               AS_ADDR_OBJ_RAION_LIST << reader4.attributes().value("TYPENAME").toString();
                                               AS_ADDR_OBJ_RAION_LIST << reader4.attributes().value("OBJECTID").toString();
                                               AS_ADDR_OBJ_RAION_LIST << reader4.attributes().value("OBJECTGUID").toString();
                                               if (chek_level[1]!=1)
                                               {
                                                   sendDATALEVEL_2(AS_ADDR_OBJ_RAION_LIST);
                                                   chek_level[1]=1;

                                               }
                                               else if (chek_level[1]==1) continue;



                                     }
                                     if (reader4.attributes().value("NAME").toString().toLower() == lvlbuf && reader4.attributes().value("LEVEL").toString() =="3")
                                        {
                                               AS_ADDR_OBJ_MUNRN_LIST << reader4.attributes().value("NAME").toString();
                                               AS_ADDR_OBJ_MUNRN_LIST << reader4.attributes().value("TYPENAME").toString();
                                               AS_ADDR_OBJ_MUNRN_LIST << reader4.attributes().value("OBJECTID").toString();
                                               AS_ADDR_OBJ_MUNRN_LIST << reader4.attributes().value("OBJECTGUID").toString();
                                               if (chek_level[2]!=1)
                                               {
                                                   sendDATALEVEL_3(AS_ADDR_OBJ_MUNRN_LIST);
                                                   chek_level[2]=1;

                                               }
                                               else if (chek_level[2]==1) continue;

                                     }
                                     if (reader4.attributes().value("NAME").toString().toLower() == lvlbuf && reader4.attributes().value("LEVEL").toString() =="4")
                                        {
                                               AS_ADDR_OBJ_SP_LIST<< reader4.attributes().value("NAME").toString();
                                               AS_ADDR_OBJ_SP_LIST << reader4.attributes().value("TYPENAME").toString();
                                               AS_ADDR_OBJ_SP_LIST << reader4.attributes().value("OBJECTID").toString();
                                               AS_ADDR_OBJ_SP_LIST << reader4.attributes().value("OBJECTGUID").toString();
                                               if (chek_level[3]!=1)
                                               {
                                                   sendDATALEVEL_4(AS_ADDR_OBJ_SP_LIST);
                                                   chek_level[3]=1;

                                               }
                                               else if (chek_level[3]==1) continue;

                                     }

                                     if (reader4.attributes().value("NAME").toString().toLower()== lvlbuf & reader4.attributes().value("LEVEL").toString() =="5")
                                        {
                                              AS_ADDR_OBJ_GOR_LIST << reader4.attributes().value("NAME").toString();
                                              AS_ADDR_OBJ_GOR_LIST << reader4.attributes().value("TYPENAME").toString();
                                              AS_ADDR_OBJ_GOR_LIST << reader4.attributes().value("OBJECTID").toString();
                                              AS_ADDR_OBJ_GOR_LIST << reader4.attributes().value("OBJECTGUID").toString();
                                              if (chek_level[4]!=1)
                                              {
                                                  sendDATALEVEL_5(AS_ADDR_OBJ_GOR_LIST);
                                                  chek_level[4]=1;

                                              }
                                              else if (chek_level[4]==1) continue;


                                     }
                                     if (reader4.attributes().value("NAME").toString().toLower() == lvlbuf && reader4.attributes().value("LEVEL").toString() =="6")
                                        {
                                               AS_ADDR_OBJ_NP_LIST << reader4.attributes().value("NAME").toString();
                                               AS_ADDR_OBJ_NP_LIST << reader4.attributes().value("TYPENAME").toString();
                                               AS_ADDR_OBJ_NP_LIST << reader4.attributes().value("OBJECTID").toString();
                                               AS_ADDR_OBJ_NP_LIST << reader4.attributes().value("OBJECTGUID").toString();
                                               if (chek_level[5]!=1)
                                               {
                                                   sendDATALEVEL_6(AS_ADDR_OBJ_NP_LIST);
                                                   chek_level[5]=1;

                                               }
                                               else if (chek_level[5]==1) continue;

                                     }


                             }
                             else
                                 reader4.skipCurrentElement();
                            reader4.readNext();
                         }
                         reader4.skipCurrentElement();
                     }
                     else
                         reader4.raiseError(QObject::tr("Incorrect file"));
                 }
                 AS_ADDR_OBJ_REG_FILE2.close();

                 if (H==word_list.size()-1){
                 for(int cb=1;cb<6;cb++)
                 {
                        if (chek_level[cb]==0)
                        {
                            switch (cb) {
                            case 1:
                                AS_ADDR_OBJ_RAION_LIST<<"НЕКОРРЕКТНЫЕ ДАННЫЕ";

                                sendDATALEVEL_2(AS_ADDR_OBJ_RAION_LIST);
                                break;
                            case 2:
                                AS_ADDR_OBJ_MUNRN_LIST<<"НЕКОРРЕКТНЫЕ ДАННЫЕ";

                                sendDATALEVEL_3(AS_ADDR_OBJ_MUNRN_LIST);
                                break;
                            case 3:
                                AS_ADDR_OBJ_SP_LIST<<"НЕКОРРЕКТНЫЕ ДАННЫЕ";

                                sendDATALEVEL_4(AS_ADDR_OBJ_SP_LIST);
                                break;
                            case 4:
                                AS_ADDR_OBJ_GOR_LIST<<"НЕКОРРЕКТНЫЕ ДАННЫЕ";

                                sendDATALEVEL_5(AS_ADDR_OBJ_GOR_LIST);
                                break;
                            case 5:
                                AS_ADDR_OBJ_NP_LIST<<"НЕКОРРЕКТНЫЕ ДАННЫЕ";

                                sendDATALEVEL_6(AS_ADDR_OBJ_NP_LIST);
                                break;
                            }
                        }

                 }

}


                 }

}

}

void parsdate::parsNUMBDATA()
{
    QXlsx::Document xlsxin(inpath);
    QXlsx::Cell* cell;
    QVariant var;
    QStringList  ADDR_OBJ_ATTRIB_LIST;
    QFile AS_ADDR_OBJ_TYPES__FILE(AS_ADDR_OBJ_TYPES__PATH);
    AS_ADDR_OBJ_TYPES__FILE.open(QIODevice::ReadOnly);
    QXmlStreamReader reader(&AS_ADDR_OBJ_TYPES__FILE);
    for (int i=3;;i++){

        if (xlsxin.cellAt(i,2)->value().isNull())
        {

            break;
        }
        cell = xlsxin.cellAt(i,2);
        var = cell->value();
        stringFULLlover= QVariant(var).toString().toLower();
        while (stringFULLlover.contains(';')) {
            stringFULLlover.remove(stringFULLlover.indexOf(";"),' ');
        }
        while (stringFULLlover.contains(':')) {
            stringFULLlover.remove(stringFULLlover.indexOf(":"),' ');
        }
        while (stringFULLlover.contains('\"')) {
            stringFULLlover.remove(stringFULLlover.indexOf("\""),' ');
        }
        while (stringFULLlover.contains('(')) {
            stringFULLlover.remove(stringFULLlover.indexOf("("),' ');
        }
        while (stringFULLlover.contains(')')) {
            stringFULLlover.remove(stringFULLlover.indexOf(")"),' ');
        }
     word_list=stringFULLlover.split(' ',QString::SkipEmptyParts);

    QString pointbuf;
     for (int H = 0;H<word_list.size(); H++) {
      if (word_list.at(H).indexOf(",")>=0)
      {
          pointbuf =word_list.at(H);
          pointbuf.remove(pointbuf.indexOf(","),1);
          word_list[H]=pointbuf;
      }
      }

     for (int H = 0;H<word_list.size(); H++) {
      if (word_list[H].contains("с.") ||word_list[H].contains("а.")||word_list[H].contains("л.")||word_list[H].contains("д.")||word_list[H].contains("к."))
      {
          pointbuf =word_list.at(H);
          pointbuf.remove(0,2);
          word_list[H]=pointbuf;
      }
    }
     for (int H = 0;H<word_list.size(); H++) {
      if ( word_list[H].contains("ул.") || word_list[H].contains("кв.") ||  word_list[H].contains("ст.") )
      {
          pointbuf =word_list.at(H);
          pointbuf.remove(0,2);
          word_list[H]=pointbuf;
      }
      }

     for (int H = 0;H<word_list.size(); H++) {
      if (word_list[H]=="с." ||word_list[H]=="а."||word_list[H]=="л."||word_list[H]=="д."||word_list[H]=="к."||word_list[H]=="г."||word_list[H]=="гор."||word_list[H]=="респ."||word_list[H]=="пер."||word_list[H]=="г"||word_list[H]=="ул"||word_list[H]=="корп.")
      {   pointbuf =word_list.at(H);
          pointbuf.fill(' ',1);
          word_list[H]=pointbuf;
      }

    }
     for (int H = 0;H<word_list.size(); H++) {
      if (word_list[H]=="д."||word_list[H]=="мкр."||word_list[H]=="мкр"||word_list[H]=="наб."||word_list[H]=="р-н."||word_list[H]=="пгт.")
      {
          pointbuf =word_list.at(H);
          pointbuf.fill(' ',1);
          word_list[H]=pointbuf;
      }
     }
      for (int H = 0;H<word_list.size(); H++) {
       if (word_list[H].size()>5)
       {
           pointbuf =word_list.at(H);
           pointbuf.fill(' ',1);
           word_list[H]=pointbuf;
       }

    }
     for (int H = 0;H<word_list.size(); H++) {
      if (word_list[H].startsWith(".") )
      {
          pointbuf =word_list.at(H);
          pointbuf.remove(0,0);
          word_list[H]=pointbuf;
      }
     }

     for (int H = 0;H<word_list.size(); H++) {
          pointbuf =word_list.at(H);
          bool ok;
          QChar a;
          a=pointbuf[0];


          if (!a.isNumber())
          {
              pointbuf.fill(' ',1);
              word_list[H]=pointbuf;
          }


      }

word_list.removeAll(QString(" "));
word_list.removeAll(QString(""));
word_list.removeAll(QString("."));
           sendNUMB_DATA(word_list);

    }
}

void parsdate::setPATH(QString PATH_f)
{
    inpath.clear();
    inpath.append(PATH_f);

    AS_ADDR_OBJ_TYPES__PATH.append(QCoreApplication::applicationDirPath());
    AS_ADDR_OBJ_TYPES__PATH.append("/data/baze/");

    AS_APPARTMEN_PATH.append(QCoreApplication::applicationDirPath()+"/data/baze/");
    AS_HOUSE_PATH.append(QCoreApplication::applicationDirPath()+"/data/baze/");

    REGION_SUBJECT_PASS.append(QCoreApplication::applicationDirPath());
    REGION_SUBJECT_PASS.append("/data/input/subject.xlsx");

    QDir mDir(AS_ADDR_OBJ_TYPES__PATH);

    foreach (const QFileInfo &mitm, mDir.entryInfoList(QStringList("AS_ADDR_OBJ_TYPES*.XML"))){
    AS_ADDR_OBJ_TYPES__PATH.clear();
    AS_ADDR_OBJ_TYPES__PATH.append(mitm.absoluteFilePath());

    }

}
