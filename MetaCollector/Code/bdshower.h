#ifndef BDSHOWER_H
#define BDSHOWER_H

#include <QObject>
#include <QWidget>
#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlTableModel>



class bdshower : public QWidget
{
    Q_OBJECT
public:
    explicit bdshower(QSqlDatabase bd,QWidget *parent = nullptr);

signals:

public slots:
};

#endif // BDSHOWER_H
