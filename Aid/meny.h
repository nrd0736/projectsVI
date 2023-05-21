#ifndef MENY_H
#define MENY_H

#include <QWidget>
#include <QtWidgets>
#include <QTimer>
#include <QDebug>

class meny : public QWidget
{
    Q_OBJECT

public:
    meny(QWidget *parent = 0);
    ~meny();

    QPushButton* start = new QPushButton("Начать");

    int time1;
    QTimer *timer1 = new QTimer;

public slots:
    void ckl_start();
    void time_start();
};

#endif // MENY_H
