#include "starticon.h"

StartIcon::StartIcon(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Менеджер лабораторных работ");
    QIcon icon;
    icon.addFile(":/res/icon.png");
    setWindowIcon(icon);
    QString namesty1("QLabel{"
                    "font-size: 50px;"
                    "color: #8ba3fc;"
                    "}");

    QString namesty2("QLabel{"
                    "font-size: 25px;"
                    "color: #8ba3fc;"
                    "}");

    QString buttonstyle("QPushButton{"
                        "color: #8ba3fc;"
                        "background-color: none;"
                        "border: none;"
                        "font-size: 20px;}"
                        "QPushButton:hover{"
                        "color: #8ba3fc;"
                        "background-color: #5d6b9e71;} "
                        "QPushButton:pressed  {"
                        "color: #0007d6;"
                        "background-color: none;"
                        "border: none;"
                        " } ");

    QPalette pal;
      pal.setBrush(this->backgroundRole(), QBrush(QPixmap(":/res/fon.jpg")));
      this->setPalette(pal);

    QLabel* labelIcon1=new QLabel;
        QPixmap img1;
        img1.load(":/res/vi.png");
        labelIcon1->clear();
        labelIcon1->setPixmap(img1);

     QLabel* name1 = new QLabel;
     name1->setText("Воронежский институт МВД России");
     name1->setStyleSheet(namesty1);
     QLabel* name2 = new QLabel;
     name2->setText("Кафедра физики и радиоэлектроники");
     name2->setStyleSheet(namesty2);


     start->setStyleSheet(buttonstyle);
     start->setFixedSize(150,40);

     exit->setStyleSheet(buttonstyle);
     exit->setFixedSize(150,40);

      QHBoxLayout*iconlay=new QHBoxLayout;
      iconlay->addStretch(10);
      iconlay->addWidget(labelIcon1);
      iconlay->addStretch(10);

      QHBoxLayout* name1lay=new QHBoxLayout;
      name1lay->addStretch(10);
      name1lay->addWidget(name1);
      name1lay->addStretch(10);

      QHBoxLayout* name2lay=new QHBoxLayout;
      name2lay->addStretch(10);
      name2lay->addWidget(name2);
      name2lay->addStretch(10);

      QHBoxLayout* buttonlay1=new QHBoxLayout;
      buttonlay1->addStretch(10);
      buttonlay1->addWidget(start);
      buttonlay1->addStretch(10);

      QHBoxLayout* buttonlay2=new QHBoxLayout;
      buttonlay2->addStretch(10);
      buttonlay2->addWidget(exit);
      buttonlay2->addStretch(10);

      QVBoxLayout* mainlay1= new QVBoxLayout;
      mainlay1->addStretch(10);
      mainlay1->addLayout(iconlay);
      mainlay1->addLayout(name1lay);
      mainlay1->addLayout(name2lay);
      mainlay1->addStretch(10);
      mainlay1->addLayout(buttonlay1);
      mainlay1->addLayout(buttonlay2);
      mainlay1->addStretch(10);

      QHBoxLayout* mainlay2=new QHBoxLayout;
      mainlay2->addStretch(10);
      mainlay2->addLayout(mainlay1);
      mainlay2->addStretch(10);
      this->setLayout(mainlay2);

      connect(exit,SIGNAL(clicked()),this,SLOT(close()));
}
