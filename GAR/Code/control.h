#ifndef CONTROL_H
#define CONTROL_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QXmlStreamReader>
#include <QtXml/QtXml>
#include "datebuf.h"
#include "inexel.h"
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
#include "parsdate.h"

#include <QDebug>

class control : public QWidget
{
    Q_OBJECT
public:
    explicit control(QWidget *parent = nullptr);
     datebuf* MAINDATE = new datebuf;
     parsdate* geetinginf = new parsdate;
     inexel inputDAT;
     QString FILE_PATH;
     QPushButton * start = new QPushButton("Начать обработку");
     QProgressBar *progress = new QProgressBar;
     QLabel *prog = new QLabel("");


     void cliningLEVEL_MAP();
     void cliningREZ_DATA();
     void cliningNUMB_DATA();
     QString createOUTPUTFILE();
     void outDATA(QString path);

signals:
 void sendprePATH(QString PATH);
public slots:
 void startdocgeneration();
 void createstartdoc();
 void chosestartdoc();
 void show_inf();
 void show_crSTATUS();
};

#endif // CONTROL_H
