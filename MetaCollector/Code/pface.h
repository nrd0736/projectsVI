#ifndef PFACE_H
#define PFACE_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

class pface : public QDialog
{
    Q_OBJECT
public:
    explicit pface(QString pathimg,QString met,QSqlDatabase bd,QDialog *parent = nullptr);

    QLineEdit *name = new QLineEdit;
    QLineEdit *fam = new QLineEdit;
    QLineEdit *otch = new QLineEdit;
    QLineEdit *data = new QLineEdit;
    QLineEdit *seria = new QLineEdit;
    QLineEdit *num = new QLineEdit;

    QSqlDatabase BD_cheks;
     QString META;
    QString PATH_FACE;


signals:

public slots:
    void delchek();
    void savechek();
};

#endif // PFACE_H
