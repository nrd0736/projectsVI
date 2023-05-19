#ifndef PARSDATE_H
#define PARSDATE_H

#include <QObject>
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
#include <QFileInfo>
#include <QDir>
#include <QCoreApplication>
#include <QXmlStreamReader>
#include <QtXml/QtXml>
#include <QRegExp>
#include <QWidget>

#include "QDebug"
class parsdate : public QObject
{
    Q_OBJECT
public:
     explicit parsdate(QObject *parent = nullptr);


    QString inpath; // путь к xlsx
    QString stringFULL, stringFULLlover;// первая исходный адресс, вторая исходный адресс преобразуемый в нижний регистр
    QStringList  word_list,regid_list; // строка разбитая по словам без сокращений, все ID субъектов
    QString AS_ADDR_OBJ_TYPES__PATH,AS_APPARTMEN_PATH,AS_HOUSE_PATH;
    QString REGION_SUBJECT_PASS;



    void parsREGID();
    void parsREGDATA();
    void parsNUMBDATA();
    void setPATH(QString PATH_f);


signals:
    void sendregID(QString ID);
    void sendstartADD(QString LIST);
    void sendDATALEVEL_1(QStringList LIST);
    void sendDATALEVEL_2(QStringList LIST);
    void sendDATALEVEL_3(QStringList LIST);
    void sendDATALEVEL_4(QStringList LIST);
    void sendDATALEVEL_5(QStringList LIST);
    void sendDATALEVEL_6(QStringList LIST);
    void sendDATALEVEL_7(QStringList LIST);
    void sendDATALEVEL_8(QStringList LIST);
    void sendDATALEVEL_9(QStringList LIST);
    void sendDATALEVEL_10(QStringList LIST);
    void sendDATALEVEL_11(QStringList LIST);
    void sendDATALEVEL_12(QStringList LIST);

     void sendREZ_DATA(QStringList LIST);
     void sendNUMB_DATA(QStringList LIST);


public slots:

};

#endif // PARSDATE_H
