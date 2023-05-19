#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include <QWidget>
#include <QProcess>
#include <QApplication>
#include <QtWidgets>
#include <QDebug>

class handler : public QWidget
{
    Q_OBJECT
public:
    explicit handler(QWidget *parent = nullptr);

   void start_DOS_Lab(int id);
   void start_EXE_Lab(int id);
   void start_WEB_Lab(int id);
   void start_OP_Lab(int id);
   void start_JAV_Lab(int id);
   void start_DOSRTS_Lab(int id);
   void start_DOSIPV_Lab(int id);

signals:


};

#endif // HANDLER_H
