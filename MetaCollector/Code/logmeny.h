#ifndef LOGMENY_H
#define LOGMENY_H
#include "meny.h"
#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QTimer>

class logmeny : public QWidget
{
    Q_OBJECT
public:
    explicit logmeny(QWidget *parent = nullptr);

    int time1;
    QTimer *timer1 = new QTimer;
    QString logD,pasD;
    QLabel * statusind1 = new QLabel("       неавторизован");
    QLabel * load1 = new QLabel;
    QMovie lod1;
    QLineEdit *login = new QLineEdit;
    QLineEdit *pass = new QLineEdit;
signals:

public slots:
    void ckl_start();
    void time_start();
};

#endif // LOGMENY_H
