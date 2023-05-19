#include "gausgen.h"

GausGen::GausGen(QWidget *parent) : QWidget(parent)
{

}

float GausGen::gaussrand(float MO, float sko)
{

    float sum=0, x;

    for (int i=0;i<25;i++)
        sum+=1.0*rand()/RAND_MAX;
    x = (sqrt(2.0)*(sko)*(sum-12.5))/1.99661 + MO;

    return x;
}
void GausGen::gen_array( const double N, const double M, const int Z, double *array )
{
  double average = ( N + M ) / 2.;
  double sigma = ( average - N ) / 3.;

  for( int i=0; i<Z; i++ ) {
    double new_value = gaussrand( average, sigma );

    //есть вероятность (0.3%) что сгенерированное число выйдет за нужный нам диапазон
    while( new_value < N || new_value > M )
      new_value = gaussrand( average, sigma ); //если это произошло генерируем новое число.

    array[i] = new_value;
  }
}
void GausGen::CreateGausArray(int id)
{
//-----------------------------Создание последовательности с Гауссовским распределением----------------------------------------
     double GausBuf[40];
     gen_array(-100,100,40,GausBuf);
     double randK;
     int x =-10;
     int y = 10;

     for(int i = 0 ; i<40 ; i++)
      {

          srand(time(0));
          randK=rand()%x +y;
          if ((GausBuf[i]+randK>100)||GausBuf[i]+randK<-100){x--;y--;}

      }
      randK=rand()%x +y;
      for(int i = 0 ; i<40 ; i++){ GausBuf[i]+=randK;GausBuf[i]=round(GausBuf[i]*100)/100; }

          for(int i = 0 ; i<40 ; i++) GausArray[i]=GausBuf[i];


//-----------------------------Создание координат для построение гистограмм----------------------------------------

//X
    int j = 100;
     for (int i =0;i<21;i++)
     {
         X[i]=j;
         j-=10;
     }
//Y
     double cordY[40];
     for (int i = 0;i<40;i++)cordY[i]=GausBuf[i];
if (id==0){
     for (int i = 0;i<40;i++)
     {
         if (cordY[i]>0)
         {
         cordY[i]=qCeil(cordY[i]);
         cordY[i]= qCeil(cordY[i]/10)*10;
         }
         else if (cordY[i]<0)
         {
             cordY[i]=cordY[i]*-1;
             cordY[i]=qCeil(cordY[i]);
             cordY[i]= qCeil(cordY[i]/10)*10;
             cordY[i]=cordY[i]*-1;
         }

     }
}
else if (id==1){
     for (int i = 0;i<40;i++)
     {
         if (cordY[i]>0)
         {
         cordY[i]=qFloor(cordY[i]);
         cordY[i]= qFloor(cordY[i]/10)*10;
         }
         else if (cordY[i]<0)
         {
             cordY[i]=cordY[i]*-1;
             cordY[i]=qFloor(cordY[i]);
             cordY[i]= qFloor(cordY[i]/10)*10;
             cordY[i]=cordY[i]*-1;
         }

     }
}
     double cordYcount[21]={};
double count=100;
    for (int j=0;j<21;j++)
    {
        for(int i=0;i<40;i++)
        {
            if(cordY[i]==count) cordYcount[j]+=1;
        }
        count-=10;
    }

for (int i =0;i<21;i++) Y[i]=cordYcount[i];
}
double GausGen::genM()
{
    for(int i = 0;i<40;i++)
    {
    M+=GausArray[i];
    }
    M=M/40;
    return M;
}
double GausGen::genD()
{
    for (int i = 0;i<40;i++)
    {
        D+=pow(GausArray[i]-M,2);
        D=D/39;
        return D;
    }
}
void GausGen::genRasp()
{

}
