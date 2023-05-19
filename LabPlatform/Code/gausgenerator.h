#ifndef GAUSGENERATOR_H
#define GAUSGENERATOR_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "gausgen.h"
#include "graph.h"
#include "dialogi.h"

class GausGenerator : public QWidget
{
    Q_OBJECT
public:
    explicit GausGenerator(QWidget *parent = nullptr);
    QVBoxLayout* mainLay = new QVBoxLayout;
    QGroupBox *gis = new QGroupBox(tr("Гистограммы распределения"));
    QHBoxLayout *razlay=new QHBoxLayout;
    QGroupBox *plv = new QGroupBox(tr("График плотности вероятности"));
    QPushButton* chek=new QPushButton("Показать расчёты");
        DialogI *chekpass = new DialogI;
signals:
    int drawGist(int id);

public slots:
   void cheking();
   void showChek();
};

#endif // GAUSGENERATOR_H
