#ifndef MENY_H
#define MENY_H

#include "databazeconnect.h"
#include "geter.h"
#include "sorting.h"
#include "bigformat.h"
#include "pchecks.h"
#include "pgeo.h"
#include "pface.h"
#include "reginbd.h"
#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

class meny : public QWidget
{
    Q_OBJECT
public:
    explicit meny(QWidget *parent = nullptr);

    databazeconnect* dataconnect = new databazeconnect;
    geter* geterDATA = new geter;
    sorting * sortDATA = new sorting;
    reginBD * registrinbd = new reginBD;
    bigformat *formdata = new bigformat;
    QProgressBar *progress = new QProgressBar;
    QLabel *prog = new QLabel("Подлключитесь БД");
    int prI=0;

bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);
signals:

public slots:
    void exhran();

    void shinf();
    void ps();
    void ps1();
    void ps2();
    void ps3();
    void fr();

};

#endif // MENY_H
