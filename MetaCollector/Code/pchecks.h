#ifndef PCHECKS_H
#define PCHECKS_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

class pchecks : public QDialog
{
    Q_OBJECT
public:
    explicit pchecks(QString pathimg,QString met,QSqlDatabase bd,QDialog *parent = nullptr);


    QLineEdit *namebank = new QLineEdit;
    QLineEdit *date = new QLineEdit;
    QLineEdit *time = new QLineEdit;
    QLineEdit *sender = new QLineEdit;
    QLineEdit *taker = new QLineEdit;
    QLineEdit *docnum = new QLineEdit;
    QLineEdit *fio = new QLineEdit;
    QLineEdit *sum = new QLineEdit;

    QSqlDatabase BD_cheks;


    QString META;
    QString PATH_CHEK;

signals:

public slots:
    void delchek();
    void savechek();
};

#endif // PCHECKS_H
