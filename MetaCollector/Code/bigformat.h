#ifndef BIGFORMAT_H
#define BIGFORMAT_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "pchecks.h"
#include "pgeo.h"
#include "pface.h"

class bigformat : public QWidget
{
    Q_OBJECT
public:
    explicit bigformat(QWidget *parent = nullptr);

    QLabel * statusind1 = new QLabel("       данные не готовы");
    QLabel * load1 = new QLabel;
    QMovie lod1;
    QString nameBDr,usernamer,passwordr;
    QSqlDatabase BD_bigformat;
        QPushButton* cheksd = new QPushButton("   Обработать фото чеков   ");
        QPushButton* geosd = new QPushButton("   Обработать фото геометок   ");
        QPushButton* faces = new QPushButton("   Обработать фото лиц   ");

    bool ready[3]={false};
    bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);
    void gotoCHEK(QString pathimg,QString met,QSqlDatabase bd);
signals:
 void facered();
public slots:
    void BDslot(QSqlDatabase bd);
    void scrapface();
    void chek();

    void geo();
    void face();
};

#endif // BIGFORMAT_H
