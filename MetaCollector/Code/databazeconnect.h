#ifndef DATABAZECONNECT_H
#define DATABAZECONNECT_H

#include <QWidget>
#include <QtWidgets>
#include <QTextEdit>
#include <QObject>
#include <QtSql/QSqlDatabase>

class databazeconnect : public QWidget
{
    Q_OBJECT

public:
    databazeconnect(QWidget *parent = 0);
    ~databazeconnect();

    QSqlDatabase DB = QSqlDatabase::addDatabase("QPSQL");

    QLabel * statusind = new QLabel("       не подключено");
        QPushButton* connectr = new QPushButton("   Подключить   ");

    QLineEdit *p = new QLineEdit;
    QLineEdit *n = new QLineEdit;
    QLineEdit *nBd = new QLineEdit;

    bool ready=0;

    bool connectBD(QString nameBD, QString name, QString pass);

    QSqlDatabase giveBD();

signals:
    void sendbdtoreg( QSqlDatabase DB);
    void sendbdtoform( QSqlDatabase DB);
public slots:

    void connection();
};

#endif // DATABAZECONNECT_H
