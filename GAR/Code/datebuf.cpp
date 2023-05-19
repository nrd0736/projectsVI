#include "datebuf.h"

datebuf::datebuf(QWidget *parent) : QWidget(parent)
{

}

void datebuf::IDbox(QString ID)
{
    REGION_CODE<<ID;
}

void datebuf::startADDbox(QString LIST)
{
    START_ADDRES.append(LIST);
}

void datebuf::boxDATALEVEL_1(QStringList LIST)
{
    LEVEL_1.append(LIST);

}
void datebuf::boxDATALEVEL_2(QStringList LIST)
{

LEVEL_2.append(LIST);

}
void datebuf::boxDATALEVEL_3(QStringList LIST)
{
LEVEL_3.append(LIST);

}
void datebuf::boxDATALEVEL_4(QStringList LIST)
{

LEVEL_4.append(LIST);

}
void datebuf::boxDATALEVEL_5(QStringList LIST)
{

LEVEL_5.append(LIST);

}
void datebuf::boxDATALEVEL_6(QStringList LIST)
{

LEVEL_6.append(LIST);

}
void datebuf::boxDATALEVEL_7(QStringList LIST)
{

LEVEL_7.append(LIST);

}
void datebuf::boxDATALEVEL_8(QStringList LIST)
{

LEVEL_8.append(LIST);

}
void datebuf::boxDATALEVEL_9(QStringList LIST)
{

LEVEL_9.append(LIST);

}
void datebuf::boxDATALEVEL_10(QStringList LIST)
{

LEVEL_10.append(LIST);

}
void datebuf::boxDATALEVEL_11(QStringList LIST)
{

LEVEL_11.append(LIST);

}
void datebuf::boxDATALEVEL_12(QStringList LIST)
{

LEVEL_12.append(LIST);

}

void datebuf::boxREZ_DATA(QStringList LIST)
{
    REZ_DATA.append(LIST);
}

void datebuf::boxNUMB_DATA(QStringList LIST)
{
    NUMB_DATA.append(LIST);
}

void datebuf::boxprePATH(QString PATH)
{
    prePATH.append(PATH);
}

