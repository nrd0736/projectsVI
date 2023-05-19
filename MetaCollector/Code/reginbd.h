#ifndef REGINBD_H
#define REGINBD_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

class reginBD : public QWidget
{
    Q_OBJECT
public:
    explicit reginBD( QWidget *parent = nullptr);
    bool ready= false;;

    QLabel * statusind1 = new QLabel("       данные не получены");
    QLabel * load1 = new QLabel;
    QMovie lod1;
    QSqlDatabase DB ;

        QPushButton* start = new QPushButton("   Получить метаданные и\n   зарегистрировать данные в БД   ");
    void sentoBD(QString filename,QString metDAT,int id);

signals:

public slots:
    void getfile();
    void BDslot(QSqlDatabase db);
};

#endif // REGINBD_H
