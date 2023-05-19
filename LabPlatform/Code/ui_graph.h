/********************************************************************************
** Form generated from reading UI file 'graph.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_graph
{
public:
    QCustomPlot *widget;
    QPushButton *pushButton;

    void setupUi(QWidget *graph)
    {
        if (graph->objectName().isEmpty())
            graph->setObjectName(QString::fromUtf8("graph"));
        graph->resize(682, 325);
        widget = new QCustomPlot(graph);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 541, 311));
        pushButton = new QPushButton(graph);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(560, 10, 121, 31));

        retranslateUi(graph);

        QMetaObject::connectSlotsByName(graph);
    } // setupUi

    void retranslateUi(QWidget *graph)
    {
        graph->setWindowTitle(QApplication::translate("graph", "Form", nullptr));
        pushButton->setText(QApplication::translate("graph", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graph: public Ui_graph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_H
