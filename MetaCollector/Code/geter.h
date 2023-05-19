#ifndef GETER_H
#define GETER_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QProcess>

class geter : public QWidget
{
    Q_OBJECT
public:
    explicit geter(QWidget *parent = nullptr);

    QLabel * statusind1 = new QLabel("       данные отсутствуют");
    QLabel * statusind2 = new QLabel("       данные отсутствуют");
    QLabel * load1 = new QLabel;
    QLabel * load2 = new QLabel;
    QMovie lod1;
    QMovie lod2;
    QProcess *process = new QProcess(this);

    bool ready=0;
    QPushButton* chosedat = new QPushButton("   Выбрать имеющиеся   \n данные   ");
    QPushButton* startparsing = new QPushButton("   Получить данные\n  из файлообменника   ");

    QString FILE_PATH;

    bool redir();
    bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);


signals:

public slots:
    void chosedir();
    void startpars();
    void endpars();

};

#endif // GETER_H
