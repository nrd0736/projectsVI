#ifndef PGEO_H
#define PGEO_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

class pgeo : public QDialog
{
    Q_OBJECT
public:
    explicit pgeo(QString pathimg,QString met,QSqlDatabase bd,QDialog *parent = nullptr);

    QLineEdit *sh1 = new QLineEdit;
    QLineEdit *sh2 = new QLineEdit;
    QLineEdit *d1 = new QLineEdit;
    QLineEdit *d2 = new QLineEdit;
    QLineEdit *obl = new QLineEdit;

    QSqlDatabase BD_cheks;
    QString META;
    QString PATH_GEO;

signals:

public slots:
    void delchek();
    void savechek();
    void gotomap();
};

#endif // PGEO_H
