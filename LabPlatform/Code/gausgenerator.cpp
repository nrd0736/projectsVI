#include "gausgenerator.h"

GausGenerator::GausGenerator(QWidget *parent) : QWidget(parent)
{
//-----------------------------------------Отображение значений сигналов--------------------------------------------------
    GausGen n1,n2;
     n1.CreateGausArray(0);
     n2.CreateGausArray(1);
    //y1=n1.retY();
    //y2=n2.retY();

QList<QTextEdit*> znX;
QList<QTextEdit*> znY;
QString  buf;

for(int i=0;i<40;i++)
{
    QTextEdit* txX=new QTextEdit;
    QTextEdit* txY=new QTextEdit;
    znX.append(txX);
    znY.append(txY);


    znX[i]->setReadOnly(true);
    znX[i]->setStyleSheet(" QTextEdit#inEditText { border-style:solid; border-width: 3px; border-color: #2D2DF0 }");
    buf=QString::number(n1.GausArray[i]);
    znX[i]->setText(buf);
    buf.clear();
    znX[i]->setAlignment(Qt::AlignCenter);
    znX[i]->setMaximumSize(45,25);


    znY[i]->setReadOnly(true);
    znY[i]->setStyleSheet(" QTextEdit#inEditText { border-style:solid; border-width: 3px; border-color: #2D2DF0 }");
    buf=QString::number(n2.GausArray[i]);
    znY[i]->setText(buf);
    buf.clear();

    znY[i]->setAlignment(Qt::AlignCenter);
    znY[i]->setMaximumSize(45,25);

}

QGroupBox *x1 = new QGroupBox(tr("Значения сигнала 1"));

x1->setAlignment(Qt::AlignLeft);

QGroupBox *x2 = new QGroupBox(tr("Значения сигнала 2"));
x2->setAlignment(Qt::AlignLeft);

QGridLayout *tabx1 = new QGridLayout;
QGridLayout *tabx2 = new QGridLayout;
int a = 0, b = 0 ;
for (int i=0;i<2;i++)
{
    a=0;
    b=0;
    for (int j = 0 ;j<40;j++)
    {
        if (i==0)
        {

            tabx1->addWidget(znX[j],a,b);
            a++;
            if(a%5==0){a=0;b++;}
        }
        else if (i==1)
        {

            tabx2->addWidget(znY[j],a,b);
            a++;
            if(a%5==0){a=0;b++;}
        }

    }
}
x1->setLayout(tabx1);
x2->setLayout(tabx2);
QHBoxLayout* znch = new QHBoxLayout;
znch->addWidget(x1);
znch->addWidget(x2);
//------------------------------------Создание гистограмм-----------------------------

graph *gist1=new graph;
gist1->id=1;
graph *gist2=new graph;
gist2->id=1;


gis->setAlignment(Qt::AlignLeft);
for(int i = 0;i<21;i++)
{
    gist1->kX[i]=n1.X[i];
    gist1->kY[i]=n1.Y[i];
    gist2->kX[i]=n2.X[i];
    gist2->kY[i]=n2.Y[i];
}
gist1->setMinimumSize(500,350);
gist2->setMinimumSize(500,350);
QHBoxLayout* gists = new QHBoxLayout;
gists->addWidget(gist1);
gists->addWidget(gist2);
gis->setLayout(gists);
//--------------------Дисперсия и математическое ожидание----------------------------
QTextEdit* mat1=new QTextEdit;
mat1->setMaximumSize(100,25);
QTextEdit* disp1=new QTextEdit;
disp1->setMaximumSize(100,25);
QTextEdit* mat2=new QTextEdit;
mat2->setMaximumSize(100,25);
QTextEdit* disp2=new QTextEdit;
disp2->setMaximumSize(100,25);

mat1->setReadOnly(true);
mat1->setStyleSheet(" QTextEdit#inEditText { border-style:solid; border-width: 3px; border-color: #2D2DF0 }");
disp1->setReadOnly(true);
disp1->setStyleSheet(" QTextEdit#inEditText { border-style:solid; border-width: 3px; border-color: #2D2DF0 }");
QString matbuf1;
matbuf1=QString::number(n1.genM());
mat1->setText(matbuf1);
QString dispbuf1;
dispbuf1=QString::number(n1.genD());
disp1->setText(dispbuf1);

mat2->setReadOnly(true);
mat2->setStyleSheet(" QTextEdit#inEditText { border-style:solid; border-width: 3px; border-color: #2D2DF0 }");
disp2->setReadOnly(true);
disp2->setStyleSheet(" QTextEdit#inEditText { border-style:solid; border-width: 3px; border-color: #2D2DF0 }");
QString matbuf2;
matbuf2=QString::number(n2.genM());
mat2->setText(matbuf2);
QString dispbuf2;
dispbuf2=QString::number(n2.genD());
disp2->setText(dispbuf2);

QLabel *mt1 =new QLabel ("Математическое ожидание равно:");
QLabel *dsp1 = new QLabel ("Дисперсия равна:");
QLabel *mt2 =new QLabel ("Математическое ожидание равно:");
QLabel *dsp2 = new QLabel ("Дисперсия равна:");

QGroupBox *r1 = new QGroupBox(tr("Расчётные данные"));
r1->setAlignment(Qt::AlignLeft);
QGroupBox *r2 = new QGroupBox(tr("Расчётные данные"));
r2->setAlignment(Qt::AlignLeft);

QGridLayout *raz1 = new QGridLayout;

raz1->addWidget(mt1,0,0);
raz1->addWidget(dsp1,1,0);
raz1->addWidget(mat1,0,1);
raz1->addWidget(disp1,1,1);
r1->setLayout(raz1);

QGridLayout *raz2 = new QGridLayout;
raz2->addWidget(mt2,0,0);
raz2->addWidget(dsp2,1,0);
raz2->addWidget(mat2,0,1);
raz2->addWidget(disp2,1,1);
r2->setLayout(raz2);


razlay->addWidget(r1);
razlay->addWidget(r2);
//------------------------------------------------График плотности вероятности---------------------------------------------
graph *gr= new graph;
gr->setMinimumSize(700,400);
gr->id=0;
for(int i=0;i<40;i++)
{
    gr->xr1[i]=n1.GausArray[i];
    gr->xr2[i]=n2.GausArray[i];
    gr->M1=n1.genM();
    gr->D1=n1.genD();
    gr->M2=n2.genM();
    gr->D2=n2.genD();
}

QHBoxLayout *plvLay=new QHBoxLayout;
plvLay->addStretch(1);
plvLay->addWidget(gr);
plvLay->addStretch(1);
plv->setLayout(plvLay);

//----------------------------------------------------------------Компановка---------------------------------------
chek->setMaximumSize(120,50);

mainLay->addLayout(znch);
mainLay->addWidget(chek);
this->setLayout(mainLay);

connect(chek,SIGNAL(clicked()),this,SLOT(cheking()));
connect(chekpass,SIGNAL(passT()),this,SLOT(showChek()));

}
void GausGenerator::cheking()
{

    chekpass->exec();

}
void GausGenerator::showChek()
{
    mainLay->addWidget(gis);
    mainLay->addLayout(razlay);
    mainLay->addWidget(plv);
    this->setLayout(mainLay);
}
