#ifndef STARTICON_H
#define STARTICON_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

class StartIcon : public QWidget
{
    Q_OBJECT
public:
    explicit StartIcon(QWidget *parent = nullptr);

         QPushButton* start = new QPushButton("НАЧАТЬ");
         QPushButton* exit = new QPushButton("ВЫХОД");
signals:

public slots:
};

#endif // STARTICON_H
