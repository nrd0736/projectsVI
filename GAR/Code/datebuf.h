#ifndef DATEBUF_H
#define DATEBUF_H

#include <QObject>
#include <QWidget>

#include <QDebug>

class datebuf : public QWidget
{
    Q_OBJECT
public:
    explicit datebuf(QWidget *parent = nullptr);
    QStringList START_ADDRES;
    QStringList REGION_CODE;
    QStringList prePATH;

    QList<QStringList> LEVEL_1;
    QList<QStringList> LEVEL_2;
    QList<QStringList> LEVEL_3;
    QList<QStringList> LEVEL_4;
    QList<QStringList> LEVEL_5;
    QList<QStringList> LEVEL_6;
    QList<QStringList> LEVEL_7;
    QList<QStringList> LEVEL_8;
    QList<QStringList> LEVEL_9;
    QList<QStringList> LEVEL_10;
    QList<QStringList> LEVEL_11;
    QList<QStringList> LEVEL_12;

    QList<QStringList> REZ_DATA;
    QList<QStringList> NUMB_DATA;
signals:


public slots:
    void IDbox(QString ID);
    void startADDbox(QString LIST);
    void boxDATALEVEL_1(QStringList LIST);
    void boxDATALEVEL_2(QStringList LIST);
    void boxDATALEVEL_3(QStringList LIST);
    void boxDATALEVEL_4(QStringList LIST);
    void boxDATALEVEL_5(QStringList LIST);
    void boxDATALEVEL_6(QStringList LIST);
    void boxDATALEVEL_7(QStringList LIST);
    void boxDATALEVEL_8(QStringList LIST);
    void boxDATALEVEL_9(QStringList LIST);
    void boxDATALEVEL_10(QStringList LIST);
    void boxDATALEVEL_11(QStringList LIST);
    void boxDATALEVEL_12(QStringList LIST);

    void boxREZ_DATA(QStringList LIST);
    void boxNUMB_DATA(QStringList LIST);
    void boxprePATH(QString PATH);
};

#endif // DATEBUF_H
