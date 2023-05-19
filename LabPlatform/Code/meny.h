#ifndef MENY_H
#define MENY_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "handler.h"
#include"gausgenerator.h"

class meny : public QWidget
{
    Q_OBJECT
public:
    explicit meny(QWidget *parent = nullptr);
    GausGenerator gauslab;

    QTabWidget *tabWidget = new QTabWidget;
    QWidget *pageWidget_0 = new QWidget;
    QWidget *pageWidget_1 = new QWidget;
    QWidget *pageWidget_2 = new QWidget;
    QWidget *pageWidget_3 = new QWidget;
    QWidget *pageWidget_4 = new QWidget;
public slots:
    void tabIC(int);
    void DOS(int);
    void EXE(int);
    void WEB(int);
    void OP(int);
    void JAV(int);
    void DOSRTS(int);
    void DOSIPV(int);
    void show_inf();
signals:

};

#endif // MENY_H
