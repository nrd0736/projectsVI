#include "graph.h"
#include "ui_graph.h"

graph::graph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::graph)
{
    ui->setupUi(this);
    ui->widget->show();
}


void graph::drawG()
{
   }

void graph::on_pushButton_clicked()
{
    //Рисуем точки
        int N = 21; //Допустим, что у нас пять точек
        QVector<double> x1(N), y1(N) ,x2(40),y2(40),x3(40),y3(40); //Массивы координат точек


        //Зададим наши точки

        for (int i=0;i<21;i++)
        {
            x1[i]=kX[i];
            y1[i]=kY[i];
        }


        switch (id) {

        case 0:
        {

        //--------------------------------ГРАФИК--------------------------------------
        for (int j=0;j<40;j++)
        {
                yr1[j]=(1/(sqrt(2*M_PI*D1)))*qExp(-((pow(xr1[j]-M1,2)/(2*D1))));
                yr2[j]=(1/(sqrt(2*M_PI*D2)))*qExp(-((pow(xr2[j]-M2,2)/(2*D2))));
        }
        for (int j=0;j<40;j++)
        {
            y2[j]=yr1[j];
            y3[j]=yr2[j];
            x2[j]=xr1[j];
            x3[j]=xr2[j];
        }

        ui->widget->clearGraphs();//Если нужно, но очищаем все графики

        //Добавляем один график в widget
        ui->widget->addGraph();

        //Говорим, что отрисовать нужно график по нашим двум массивам x и y
        ui->widget->graph(0)->setData(x2, y2);
        ui->widget->graph(0)->setPen(QColor(200, 10, 10, 255));//задаем цвет точки
        //Rui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);//убираем линии
       ui->widget->addGraph();
        ui->widget->graph(1)->setData(x3, y3);
        ui->widget->graph(1)->setPen(QColor(0, 10, 10, 255));
        //формируем вид точек
        //ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
       // ui->widget->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
        //Подписываем оси Ox и Oy
        ui->widget->xAxis->setLabel("x");
        ui->widget->yAxis->setLabel("y");

        //Установим область, которая будет показываться на графике
        ui->widget->xAxis->setRange(-105, 105);//Для оси Ox
        ui->widget->yAxis->setRange(-0.01, 0.3);//Для оси Oy
            break;
        }
//--------------------------------ГИСТОГРАММА--------------------------------------
        case 1:
        {
        QCPBars *bars1 = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);
           bars1->setData(x1,y1);
           bars1->setWidth(7);

           QPen pen;
           pen.setWidthF(1);
           pen.setColor(QColor(200, 10, 10, 255));
           bars1->setPen(Qt::NoPen);
           bars1->setBrush(QColor(10, 10, 10, 255));
           bars1->setPen(pen);
               ui->widget->xAxis->setRange(-105, 105);//Для оси Ox
               ui->widget->yAxis->setRange(-1, 20);//Для оси Oy
        break;
        }
        }
               ui->widget->replot();//И перерисуем график на нашем widget


}
