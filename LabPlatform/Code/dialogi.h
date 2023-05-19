#ifndef DIALOGI_H
#define DIALOGI_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

class DialogI : public QDialog
{
    Q_OBJECT
public:
    explicit DialogI(QDialog *parent = nullptr);
    QString pass="07362517";

    QPushButton* ok = new QPushButton("Принять");
    QPushButton * exit = new QPushButton("Отмена");
    QLabel*inf= new QLabel("Введите пароль преподователя");
    QLineEdit*passLog= new QLineEdit;
signals:
void passT();
public slots:
    void chekpass();
};

#endif // DIALOGI_H
