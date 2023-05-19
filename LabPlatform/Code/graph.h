#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include <cmath>
#include"qcustomplot.h"


namespace Ui {
class graph;
}

class graph : public QWidget
{
    Q_OBJECT

public:
    explicit graph(QWidget *parent = nullptr);
        Ui::graph *ui;
    int id;
    double kX[21],kY[21];
     double xr1[40],xr2[40],yr1[40],yr2[40];
     double M1,M2,D1,D2;
public slots:
    void drawG();
private slots:


    void on_pushButton_clicked();

private:

};

#endif // GRAPH_H
