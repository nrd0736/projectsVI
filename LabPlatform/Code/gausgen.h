#ifndef GAUSGEN_H
#define GAUSGEN_H

#include <QObject>
#include <QWidget>
#include <cmath>
#include <QtCore/qmath.h>
#include <QVector>
#include <QDebug>

class GausGen : public QWidget
{
    Q_OBJECT
public:
    explicit GausGen(QWidget *parent = nullptr);
    void gen_array( const double N, const double M, const int Z, double *array );
    float gaussrand(float MO, float sko);
    double GausArray[40];
    double X[21],Y[21];
    double M=0,D=0;
    double genM();
    double genD();
    void genRasp();

signals:

public slots:
    void CreateGausArray(int id);
};

#endif // GAUSGEN_H
