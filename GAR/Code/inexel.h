#ifndef INEXEL_H
#define INEXEL_H

#include <QObject>
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
#include "QFile"
#include <QCoreApplication>
#include <QDesktopServices>
#include <QWidget>

#include <QDebug>

class inexel : public QWidget
{
    Q_OBJECT
public:
    explicit inexel(QWidget *parent = nullptr);
    QString impEXEL;// путь к созданному xlsx
    QString createInFile();


signals:

public slots:
};

#endif // INEXEL_H
