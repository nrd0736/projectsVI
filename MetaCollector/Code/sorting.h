#ifndef SORTING_H
#define SORTING_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

class sorting : public QWidget
{
    Q_OBJECT
public:
    explicit sorting(QWidget *parent = nullptr);

    QLabel * statusind1 = new QLabel("       данные не обработаны");
    QLabel * load1 = new QLabel;
    QMovie lod1;
    QProcess *process = new QProcess(this);
    QPushButton* start = new QPushButton("   Классифицировать данные   ");
    bool ready=0;

signals:

public slots:
    void startsort();
    void endsort();
};

#endif // SORTING_H
