#include "meny.h"

meny::meny(QWidget *parent) : QWidget(parent)
{
setWindowTitle("Менеджер лабораторных работ");
QIcon icon;
icon.addFile(":/res/icon.png");
setWindowIcon(icon);


QPalette mainpal;
  mainpal.setBrush(this->backgroundRole(), QBrush(QPixmap(":/res/menyFon.png")));
  this->setPalette(mainpal);

new QWidget(this);

setGeometry(0,0,300,100);



int id1 = QFontDatabase::addApplicationFont(":/res/pushfont1.ttf"); //путь к шрифту
     QString DatDot1 = QFontDatabase::applicationFontFamilies(id1).at(0); //имя шрифта
     QFont pushfont(DatDot1);  // QFont c вашим шрифтом

     QString namesty1("QLabel{"
                     "font-size: 45px;"
                     "color: rgb(4, 4, 194);"
                     "}");
QString groupst("QGroupBox {opacity: 0.8; font-size: 10pt;border: 1px solid #000069; margin-top:5ex; background-color: rgba(47, 48, 173, 0.50);}"
                "QGroupBox::title {subcontrol-origin:margin;background-color: #2F30AD;color:white; subcontrol-position:top center;padding:0 3px; }");

QString tabstyle1("QTabWidget::pane { border: 1px;background-color: none;}"
                  "QTabBar::tab {border: 2px solid #000069; height: 55px; width: 355px; color: #00008B; background-color: rgba(255, 255, 255, 0.6); font-weight: 400;font-size: 15pt;}"
                  "QTabBar::tab:selected {border: 2px solid #000069; height: 55px; width: 355px; color: white; background-color: #0000de; font-weight: 400;}");

QString sty("QPushButton{"
                                "color: #00008B;"
                                "font-size: 15pt;"
                                "background-color: rgba(255, 255, 255, 0.6);"
                                "border: 2px solid #000069;}"
                                "QPushButton:hover{"
                                "color:white;"
                                "background-color: #0000de;} "
                                "QPushButton:pressed  {"
                                "background-color: #f26172;"
                                "border: 3px dotted #000069;"
                                " } ");



tabWidget->addTab(pageWidget_0,QIcon(":/tabicon/res/tabicon/FIZ.png"), "   Физика  ");
tabWidget->addTab(pageWidget_1,QIcon(":/tabicon/res/tabicon/BJD.png"), "   Безопасность жизнедеятельности   ");
tabWidget->addTab(pageWidget_2,QIcon(":/tabicon/res/tabicon/KvIop.png"), "   Квантвая и\nоптическая электроника   ");
tabWidget->addTab(pageWidget_3,QIcon(":/tabicon/res/tabicon/RTS.png"), "   Радиотехнические\nцепи и сигналы   ");
tabWidget->addTab(pageWidget_4,QIcon(":/tabicon/res/tabicon/EDiRS.png"), "   Электродинамика и\nраспростанение радиоволн   ");

tabWidget->setStyleSheet(tabstyle1);
pushfont.setPointSize(12);
tabWidget->setFont(pushfont);


QSize iconsize;
iconsize.setWidth(30);
iconsize.setHeight(30);
tabWidget->setIconSize(iconsize);




//-----------------------------------------------DOS---------------------------------------------------------------------------------
QGroupBox *dosGr = new QGroupBox(tr("Лабораторные работы в системе MS-DOS"));
dosGr->setFont(pushfont);
dosGr->setStyleSheet(groupst);
dosGr->setAlignment(Qt::AlignLeft);
QPushButton *dos1= new QPushButton(tr("Автоматизированная обработка результатов измерений в лабораторных работах по физике"));
dos1->setStyleSheet(sty);
dos1->setFont(pushfont);
QPushButton *dos10= new QPushButton(tr("Расчёт ошибок измерений на примере определения объёма цилиндра"));
dos10->setStyleSheet(sty);
dos10->setFont(pushfont);
QPushButton *dos5= new QPushButton(tr("Кинематика теория и решение задач"));
dos5->setStyleSheet(sty);
dos5->setFont(pushfont);
QPushButton *dos3= new QPushButton(tr("Закон сохранения момента импульса"));
dos3->setStyleSheet(sty);
dos3->setFont(pushfont);
QPushButton *dos8= new QPushButton(tr("Напряженность и потенциал электростатического поля"));
dos8->setStyleSheet(sty);
dos8->setFont(pushfont);
QPushButton *dos4= new QPushButton(tr("Исследование затухающих и вынужденных механических колебаний"));
dos4->setStyleSheet(sty);
dos4->setFont(pushfont);
QPushButton *dos11= new QPushButton(tr("Стоячие волны"));
dos11->setStyleSheet(sty);
dos11->setFont(pushfont);
QPushButton *exe4= new QPushButton(tr("Эффект Доплера"));
exe4->setStyleSheet(sty);
exe4->setFont(pushfont);
QPushButton *dos6= new QPushButton(tr("Кольца Ньютона"));
dos6->setStyleSheet(sty);
dos6->setFont(pushfont);
QPushButton *dos7= new QPushButton(tr("Микрочастица в потенциальной яме"));
dos7->setStyleSheet(sty);
dos7->setFont(pushfont);
QPushButton *dos9= new QPushButton(tr("Прохождение микрочастиц через щель"));
dos9->setStyleSheet(sty);
dos9->setFont(pushfont);
QPushButton *dos2= new QPushButton(tr("Атом водорода в квановой механике"));
dos2->setStyleSheet(sty);
dos2->setFont(pushfont);
QPushButton *exe3= new QPushButton(tr("Колоквиум по молекулярной физике"));
exe3->setStyleSheet(sty);
exe3->setFont(pushfont);

dosGr->setMaximumWidth(900);

QGridLayout *dosGrlay = new QGridLayout;
dosGrlay->addWidget(dos1,0,0);
dosGrlay->addWidget(dos10,1,0);
dosGrlay->addWidget(dos5,2,0);
dosGrlay->addWidget(dos3,3,0);
dosGrlay->addWidget(dos8,4,0);
dosGrlay->addWidget(dos4,5,0);
dosGrlay->addWidget(dos11,6,0);
dosGrlay->addWidget(exe4,7,0);
dosGrlay->addWidget(dos6,8,0);
dosGrlay->addWidget(dos7,9,0);
dosGrlay->addWidget(dos9,10,0);
dosGrlay->addWidget(dos2,11,0);
dosGrlay->addWidget(exe3,12,0);

dosGr->setLayout(dosGrlay);

//------------------------------------------------------EXE----------------------------------------------------------------
QGroupBox *exeGr = new QGroupBox(tr("Лабораторные работы формата exe"));
exeGr->setAlignment(Qt::AlignLeft);
exeGr->setFont(pushfont);
exeGr->setStyleSheet(groupst);
QPushButton *exe1= new QPushButton(tr("Распространения одиночных импульсов и кодовых последовательностей по кабельным цепям"));
exe1->setStyleSheet(sty);
exe1->setFont(pushfont);
QPushButton *exe2= new QPushButton(tr("Прохождение оптических импульсов по одномодовым волоконным световодам"));
exe2->setStyleSheet(sty);
exe2->setFont(pushfont);
QPushButton *dos12= new QPushButton(tr("Исследование прохождения световых импульсов по многомодовым волоконным светодиодам"));
dos12->setStyleSheet(sty);
dos12->setFont(pushfont);

QVBoxLayout *exeGrlay = new QVBoxLayout;
exeGrlay->addWidget(exe1);
exeGrlay->addWidget(exe2);
exeGrlay->addWidget(dos12);


exeGr->setLayout(exeGrlay);

//------------------------------------------------------WEB----------------------------------------------------------------
QGroupBox *webGr = new QGroupBox(tr("Лабораторные работы Физикон"));
webGr->setAlignment(Qt::AlignLeft);
webGr->setFont(pushfont);
webGr->setStyleSheet(groupst);
QPushButton *web1= new QPushButton(tr("Движение с постоянным ускорением"));
web1->setStyleSheet(sty);
web1->setFont(pushfont);
QPushButton *web2= new QPushButton(tr("Движение под действием постоянной силы"));
web2->setStyleSheet(sty);
web2->setFont(pushfont);
QPushButton *web3= new QPushButton(tr("Свободные механические колебания"));
web3->setStyleSheet(sty);
web3->setFont(pushfont);
QPushButton *web4= new QPushButton(tr("Упругие и неупругие удары"));
web4->setStyleSheet(sty);
web4->setFont(pushfont);
QPushButton *web5= new QPushButton(tr("Соударения упругих шаров"));
web5->setStyleSheet(sty);
web5->setFont(pushfont);
QPushButton *web6= new QPushButton(tr("Движение заряженной частицы\n в электрическом поле"));
web6->setStyleSheet(sty);
web6->setFont(pushfont);
QPushButton *web7= new QPushButton(tr("Электрическое поле точечных зарядов"));
web7->setStyleSheet(sty);
web7->setFont(pushfont);
QPushButton *web8= new QPushButton(tr("Цепи постоянного тока"));
web8->setStyleSheet(sty);
web8->setFont(pushfont);
QPushButton *web9= new QPushButton(tr("Магнитное поле"));
web9->setStyleSheet(sty);
web9->setFont(pushfont);
QPushButton *web10= new QPushButton(tr("Электромагнитная индукция"));
web10->setStyleSheet(sty);
web10->setFont(pushfont);
QPushButton *web11= new QPushButton(tr("Свободные колебания в RLC-контуре"));
web11->setStyleSheet(sty);
web11->setFont(pushfont);
QPushButton *web12= new QPushButton(tr("Вынужденные колебания в RLC-контуре"));
web12->setStyleSheet(sty);
web12->setFont(pushfont);
QPushButton *web13= new QPushButton(tr("Вынужденные колебания в RLC-контуре\n (с упрощенной теорией)"));
web13->setStyleSheet(sty);
web13->setFont(pushfont);
QPushButton *web14= new QPushButton(tr("Интерференция"));
web14->setStyleSheet(sty);
web14->setFont(pushfont);
QPushButton *web15= new QPushButton(tr("Дифракционная решетка"));
web15->setStyleSheet(sty);
web15->setFont(pushfont);
QPushButton *web16= new QPushButton(tr("Внешний фотоэффект"));
web16->setStyleSheet(sty);
web16->setFont(pushfont);
QPushButton *web17= new QPushButton(tr("Спектр излучения атомарного водорода"));
web17->setStyleSheet(sty);
web17->setFont(pushfont);
QPushButton *web18= new QPushButton(tr("Эффект Комптона"));
web18->setStyleSheet(sty);
web18->setFont(pushfont);
QPushButton *web19= new QPushButton(tr("Дифракция электронов"));
web19->setStyleSheet(sty);
web19->setFont(pushfont);
QPushButton *web20= new QPushButton(tr("Прохождение электромагнитного\n излучения через вещество"));
web20->setStyleSheet(sty);
web20->setFont(pushfont);
QPushButton *web21= new QPushButton(tr("Ядра атомов"));
web21->setStyleSheet(sty);
web21->setFont(pushfont);
QPushButton *web22= new QPushButton(tr("Адиабатический процесс"));
web22->setStyleSheet(sty);
web22->setFont(pushfont);
QPushButton *web23= new QPushButton(tr("Теплоемкость идеального газа"));
web23->setStyleSheet(sty);
web23->setFont(pushfont);
QPushButton *web24= new QPushButton(tr("Распределение Максвелла"));
web24->setStyleSheet(sty);
web24->setFont(pushfont);
QPushButton *web25= new QPushButton(tr("Диффузия в газах"));
web25->setStyleSheet(sty);
web25->setFont(pushfont);
QPushButton *web26= new QPushButton(tr("Уравнение состояния Ван-дер-Ваальса"));
web26->setStyleSheet(sty);
web26->setFont(pushfont);
webGr->setMaximumWidth(900);

QGridLayout* webGrlay = new QGridLayout;
webGrlay->addWidget(web1,0,0);
webGrlay->addWidget(web2,1,0);
webGrlay->addWidget(web3,2,0);
webGrlay->addWidget(web4,3,0);
webGrlay->addWidget(web5,4,0);
webGrlay->addWidget(web6,5,0);
webGrlay->addWidget(web7,6,0);
webGrlay->addWidget(web8,7,0);
webGrlay->addWidget(web9,8,0);
webGrlay->addWidget(web10,9,0);
webGrlay->addWidget(web11,10,0);
webGrlay->addWidget(web12,11,0);
webGrlay->addWidget(web13,12,0);

webGrlay->addWidget(web14,0,1);
webGrlay->addWidget(web15,1,1);
webGrlay->addWidget(web16,2,1);
webGrlay->addWidget(web17,3,1);
webGrlay->addWidget(web18,4,1);
webGrlay->addWidget(web19,5,1);
webGrlay->addWidget(web20,6,1);
webGrlay->addWidget(web21,7,1);
webGrlay->addWidget(web22,8,1);
webGrlay->addWidget(web23,9,1);
webGrlay->addWidget(web24,10,1);
webGrlay->addWidget(web25,11,1);
webGrlay->addWidget(web26,12,1);

webGr->setLayout(webGrlay);

QPushButton *exit= new QPushButton("Выход");
exit->setFixedSize(100,25);
exit->setStyleSheet(sty);
exit->setFont(pushfont);
QPushButton *info= new QPushButton("Cправка");
info->setFixedSize(100,25);
info->setStyleSheet(sty);
info->setFont(pushfont);

QLabel* name1 = new QLabel;
name1->setText("Менеджер лабораторных работ");
name1->setStyleSheet(namesty1);
name1->setFont(pushfont);

//------------------------------------------------------OPEN PYS-----------------------------------------------------------------
QGroupBox *opGr = new QGroupBox(tr("Комплекс <Открытая физика>"));
opGr->setAlignment(Qt::AlignLeft);
opGr->setFont(pushfont);
opGr->setStyleSheet(groupst);
QPushButton* op1=new QPushButton("Открытая Физика (часть 1)");
op1->setStyleSheet(sty);
op1->setFont(pushfont);
QPushButton* op2=new QPushButton("Открытая Физика (часть 2)");
op2->setStyleSheet(sty);
op2->setFont(pushfont);
QVBoxLayout* opGrLay= new QVBoxLayout;
opGrLay->addWidget(op1);
opGrLay->addWidget(op2);
opGr->setLayout(opGrLay);
opGr->setMaximumWidth(900);
//------------------------------------------------------JAVA----------------------------------------------------------------------
QGroupBox *javGr = new QGroupBox(tr("Лабораторные работы <java>"));
javGr->setAlignment(Qt::AlignLeft);
javGr->setFont(pushfont);
javGr->setStyleSheet(groupst);
QPushButton* jav1=new QPushButton("Исследование явлений, возникающих при стекании тока в землю");
jav1->setStyleSheet(sty);
jav1->setFont(pushfont);
QPushButton* jav2=new QPushButton("Изучение действия защитного заземления и защитного зануления");
jav2->setStyleSheet(sty);
jav2->setFont(pushfont);
QVBoxLayout* javGrLay= new QVBoxLayout;
javGrLay->addWidget(jav1);
javGrLay->addWidget(jav2);
javGrLay->addStretch(10);
javGr->setLayout(javGrLay);

//------------------------------------------------------DOS RTS----------------------------------------------------------------------
QGroupBox *dosrtsGr = new QGroupBox(tr("Лабораторные работы в системе MS-DOS"));
dosrtsGr->setAlignment(Qt::AlignLeft);
dosrtsGr->setFont(pushfont);
dosrtsGr->setStyleSheet(groupst);
QPushButton *dosrts1= new QPushButton(tr("Исследование импульсной РЛС"));
dosrts1->setStyleSheet(sty);
dosrts1->setFont(pushfont);
QPushButton *dosrts2= new QPushButton(tr("Исследование многоканальной радиотехнической системы передачи информации"));
dosrts2->setStyleSheet(sty);
dosrts2->setFont(pushfont);
QPushButton *dosrts3= new QPushButton(tr("Исследование одноканальной радиотехнической системы передачи информации"));
dosrts3->setStyleSheet(sty);
dosrts3->setFont(pushfont);
QPushButton *dosrts4= new QPushButton(tr("Исследование оптимального обнаружителя сигналов (на основе коррелятора)"));
dosrts4->setStyleSheet(sty);
dosrts4->setFont(pushfont);
QPushButton *dosrts5= new QPushButton(tr("Исследование оптимального обнаружителя сигналов (на основе согласованного фильтра)"));
dosrts5->setStyleSheet(sty);
dosrts5->setFont(pushfont);
QPushButton *dosrts6= new QPushButton(tr("Исследование оптимального приемника фазоманипулированных сигналов"));
dosrts6->setStyleSheet(sty);
dosrts6->setFont(pushfont);
QPushButton *dosrts7= new QPushButton(tr("Исследование РТС с ЛЧМ сигналами"));
dosrts7->setStyleSheet(sty);
dosrts7->setFont(pushfont);
QPushButton *dosrts8= new QPushButton(tr("Прохождение случайных сигналов через линейные цепи"));
dosrts8->setStyleSheet(sty);
dosrts8->setFont(pushfont);
QPushButton *gausrts= new QPushButton(tr("Генератор с Гауссовским распределением"));
gausrts->setStyleSheet(sty);
gausrts->setFont(pushfont);


QVBoxLayout *dosrtsGrlay = new QVBoxLayout;
dosrtsGrlay->addWidget(dosrts1);
dosrtsGrlay->addWidget(dosrts2);
dosrtsGrlay->addWidget(dosrts3);
dosrtsGrlay->addWidget(dosrts4);
dosrtsGrlay->addWidget(dosrts5);
dosrtsGrlay->addWidget(dosrts6);
dosrtsGrlay->addWidget(dosrts7);
dosrtsGrlay->addWidget(dosrts8);
dosrtsGrlay->addStretch(10);


dosrtsGr->setLayout(dosrtsGrlay);

//------------------------------------------------------DOS IPV----------------------------------------------------------------------
QGroupBox *dosipvGr = new QGroupBox(tr("Лабораторные работы в системе MS-DOS"));
dosipvGr->setAlignment(Qt::AlignLeft);
dosipvGr->setFont(pushfont);
dosipvGr->setStyleSheet(groupst);
QPushButton *dosipv1= new QPushButton(tr("Исследование распространения радиоволн миллиметрового диапазона в атмосфере"));
dosipv1->setStyleSheet(sty);
dosipv1->setFont(pushfont);
QPushButton *dosipv2= new QPushButton(tr("Плоские однородные волны в диэлектриках и проводниках, поляризация и сложение волн"));
dosipv2->setStyleSheet(sty);
dosipv2->setFont(pushfont);
QPushButton *dosipv3= new QPushButton(tr("Расчёт радиотрасс через ионосферные каналы, диапазон коротких волн"));
dosipv3->setStyleSheet(sty);
dosipv3->setFont(pushfont);
QPushButton *dosipv4= new QPushButton(tr("Типы волн в плоском волноводе"));
dosipv4->setStyleSheet(sty);
dosipv4->setFont(pushfont);



QVBoxLayout *dosipvGrlay = new QVBoxLayout;
dosipvGrlay->addWidget(dosipv1);
dosipvGrlay->addWidget(dosipv2);
dosipvGrlay->addWidget(dosipv3);
dosipvGrlay->addWidget(dosipv4);
dosipvGrlay->addStretch(10);



dosipvGr->setLayout(dosipvGrlay);
//------------------------------------------------------КОМПАНОВКА----------------------------------------------------------------
//ОБЩЕЕ
QBoxLayout *lay2 = new QBoxLayout(QBoxLayout::RightToLeft);
lay2->addWidget(exit);
lay2->addStretch(10);
lay2->addWidget(info);

//ФИЗИКА
QVBoxLayout* lay1_page0 = new QVBoxLayout;
lay1_page0->addWidget(dosGr);
lay1_page0->addWidget(opGr);
lay1_page0->addStretch(20);
QGridLayout* lay2_page0 = new QGridLayout;
lay2_page0->addWidget(webGr,0,0);
lay2_page0->addLayout(lay1_page0,0,1);
pageWidget_0->setLayout(lay2_page0);

//БЖД
QVBoxLayout* lay_page1=new QVBoxLayout;
lay_page1->addWidget(javGr);
lay_page1->addStretch(10);
pageWidget_1->setLayout(lay_page1);

//КВантово и оптическая электр
QVBoxLayout* lay_page2 = new QVBoxLayout;
lay_page2->addWidget(exeGr);
lay_page2->addStretch(10);
pageWidget_2->setLayout(lay_page2);

//Радиотехнические цепи и сигналы
QVBoxLayout* lay_page3 = new QVBoxLayout;
lay_page3->addWidget(dosrtsGr);
lay_page3->addWidget(gausrts);
lay_page3->addStretch(10);
pageWidget_3->setLayout(lay_page3);

//Электродинамика и распростанение радиоволн
QVBoxLayout* lay_page4 = new QVBoxLayout;
lay_page4->addWidget(dosipvGr);
lay_page4->addStretch(10);
pageWidget_4->setLayout(lay_page4);

QHBoxLayout* name1lay=new QHBoxLayout;
name1lay->addStretch(10);
name1lay->addWidget(name1);
name1lay->addStretch(10);

//MAIN
QVBoxLayout* mainLay = new QVBoxLayout;
mainLay->addStretch(1);
mainLay->addLayout(name1lay);
mainLay->addStretch(10);
mainLay->addWidget(tabWidget);
mainLay->addStretch(400);
mainLay->addLayout(lay2);
mainLay->addStretch(1);
setLayout(mainLay);



//------------------------------------------------------SIGNALS DOS----------------------------------------------------------------
QSignalMapper* dosGrmaper= new QSignalMapper(this);
connect(dos1,SIGNAL(clicked()),dosGrmaper,SLOT(map()));
dosGrmaper->setMapping(dos1,1);
connect(dos2,SIGNAL(clicked()),dosGrmaper,SLOT(map()));
dosGrmaper->setMapping(dos2,2);
connect(dos3,SIGNAL(clicked()),dosGrmaper,SLOT(map()));
dosGrmaper->setMapping(dos3,3);
connect(dos4,SIGNAL(clicked()),dosGrmaper,SLOT(map()));
dosGrmaper->setMapping(dos4,4);
connect(dos5,SIGNAL(clicked()),dosGrmaper,SLOT(map()));
dosGrmaper->setMapping(dos5,5);
connect(dos6,SIGNAL(clicked()),dosGrmaper,SLOT(map()));
dosGrmaper->setMapping(dos6,6);
connect(dos7,SIGNAL(clicked()),dosGrmaper,SLOT(map()));
dosGrmaper->setMapping(dos7,7);
connect(dos8,SIGNAL(clicked()),dosGrmaper,SLOT(map()));
dosGrmaper->setMapping(dos8,8);
connect(dos9,SIGNAL(clicked()),dosGrmaper,SLOT(map()));
dosGrmaper->setMapping(dos9,9);
connect(dos10,SIGNAL(clicked()),dosGrmaper,SLOT(map()));
dosGrmaper->setMapping(dos10,10);
connect(dos11,SIGNAL(clicked()),dosGrmaper,SLOT(map()));
dosGrmaper->setMapping(dos11,11);
connect(dos12,SIGNAL(clicked()),dosGrmaper,SLOT(map()));
dosGrmaper->setMapping(dos12,12);

connect(dosGrmaper,SIGNAL(mapped(int)),this,SLOT(DOS(int)));
//------------------------------------------------------SIGNALS EXE----------------------------------------------------------------
QSignalMapper* exeGrmaper= new QSignalMapper(this);
connect(exe1,SIGNAL(clicked()),exeGrmaper,SLOT(map()));
exeGrmaper->setMapping(exe1,1);
connect(exe2,SIGNAL(clicked()),exeGrmaper,SLOT(map()));
exeGrmaper->setMapping(exe2,2);
connect(exe3,SIGNAL(clicked()),exeGrmaper,SLOT(map()));
exeGrmaper->setMapping(exe3,3);
connect(exe4,SIGNAL(clicked()),exeGrmaper,SLOT(map()));
exeGrmaper->setMapping(exe4,4);

connect(exeGrmaper,SIGNAL(mapped(int)),this,SLOT(EXE(int)));
//------------------------------------------------------SIGNALS OP----------------------------------------------------------------
QSignalMapper* opGrmaper= new QSignalMapper(this);
connect(op1,SIGNAL(clicked()),opGrmaper,SLOT(map()));
opGrmaper->setMapping(op1,1);
connect(op2,SIGNAL(clicked()),opGrmaper,SLOT(map()));
opGrmaper->setMapping(op2,2);
connect(opGrmaper,SIGNAL(mapped(int)),this,SLOT(OP(int)));
//------------------------------------------------------SIGNALS JAVA---------------------------------------------------------------
QSignalMapper* javGrmaper= new QSignalMapper(this);
connect(jav1,SIGNAL(clicked()),javGrmaper,SLOT(map()));
javGrmaper->setMapping(jav1,1);
connect(jav2,SIGNAL(clicked()),javGrmaper,SLOT(map()));
javGrmaper->setMapping(jav2,2);
connect(javGrmaper,SIGNAL(mapped(int)),this,SLOT(JAV(int)));
//------------------------------------------------------SIGNALS DOS RTS----------------------------------------------------------------
QSignalMapper* dosrtsGrmaper= new QSignalMapper(this);
connect(dosrts1,SIGNAL(clicked()),dosrtsGrmaper,SLOT(map()));
dosrtsGrmaper->setMapping(dosrts1,1);
connect(dosrts2,SIGNAL(clicked()),dosrtsGrmaper,SLOT(map()));
dosrtsGrmaper->setMapping(dosrts2,2);
connect(dosrts3,SIGNAL(clicked()),dosrtsGrmaper,SLOT(map()));
dosrtsGrmaper->setMapping(dosrts3,3);
connect(dosrts4,SIGNAL(clicked()),dosrtsGrmaper,SLOT(map()));
dosrtsGrmaper->setMapping(dosrts4,4);
connect(dosrts5,SIGNAL(clicked()),dosrtsGrmaper,SLOT(map()));
dosrtsGrmaper->setMapping(dosrts5,5);
connect(dosrts6,SIGNAL(clicked()),dosrtsGrmaper,SLOT(map()));
dosrtsGrmaper->setMapping(dosrts6,6);
connect(dosrts7,SIGNAL(clicked()),dosrtsGrmaper,SLOT(map()));
dosrtsGrmaper->setMapping(dosrts7,7);
connect(dosrts8,SIGNAL(clicked()),dosrtsGrmaper,SLOT(map()));
dosrtsGrmaper->setMapping(dosrts8,8);
connect(gausrts,SIGNAL(clicked()),&gauslab,SLOT(show()));

connect(dosrtsGrmaper,SIGNAL(mapped(int)),this,SLOT(DOSRTS(int)));
//------------------------------------------------------SIGNALS DOS IPV----------------------------------------------------------------

QSignalMapper* dosipvGrmaper= new QSignalMapper(this);
connect(dosipv1,SIGNAL(clicked()),dosipvGrmaper,SLOT(map()));
dosipvGrmaper->setMapping(dosipv1,1);
connect(dosipv2,SIGNAL(clicked()),dosipvGrmaper,SLOT(map()));
dosipvGrmaper->setMapping(dosipv2,2);
connect(dosipv3,SIGNAL(clicked()),dosipvGrmaper,SLOT(map()));
dosipvGrmaper->setMapping(dosipv3,3);
connect(dosipv4,SIGNAL(clicked()),dosipvGrmaper,SLOT(map()));
dosipvGrmaper->setMapping(dosipv4,4);

connect(dosipvGrmaper,SIGNAL(mapped(int)),this,SLOT(DOSIPV(int)));
//------------------------------------------------------SIGNALS WEB----------------------------------------------------------------
QSignalMapper* webGrmaper= new QSignalMapper(this);
connect(web1,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web1,1);
connect(web2,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web2,2);
connect(web3,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web3,3);
connect(web4,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web4,4);
connect(web5,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web5,5);
connect(web6,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web6,6);
connect(web7,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web7,7);
connect(web8,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web8,8);
connect(web9,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web9,9);
connect(web10,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web10,10);
connect(web11,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web11,11);
connect(web12,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web12,12);
connect(web13,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web13,13);
connect(web14,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web14,14);
connect(web15,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web15,15);
connect(web16,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web16,16);
connect(web17,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web17,17);
connect(web18,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web18,18);
connect(web19,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web19,19);
connect(web20,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web20,20);
connect(web21,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web21,21);
connect(web22,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web22,22);
connect(web23,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web23,23);
connect(web24,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web24,24);
connect(web25,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web25,25);
connect(web26,SIGNAL(clicked()),webGrmaper,SLOT(map()));
webGrmaper->setMapping(web26,26);

connect(webGrmaper,SIGNAL(mapped(int)),this,SLOT(WEB(int)));
//------------------------------------------------------ADDITIONAL SIGNALS ----------------------------------------------------------------
connect(exit,SIGNAL(clicked()),this,SLOT(close()));
connect(info,SIGNAL(clicked()),this,SLOT(show_inf()));
}

void meny::tabIC(int id)
{
}
void meny::DOS(int id)
{
  handler ds;
  ds.start_DOS_Lab(id);
}
void meny::EXE(int id)
{
    handler ex;
    ex.start_EXE_Lab(id);
}
void meny::WEB(int id)
{
    handler wb;
    wb.start_WEB_Lab(id);
}
void meny::OP(int id)
{
    handler op;
    op.start_OP_Lab(id);
}
void meny::JAV(int id)
{
    handler jav;
    jav.start_JAV_Lab(id);
}

void meny::DOSRTS(int id)
{
    handler rs;
    rs.start_DOSRTS_Lab(id);
}
void meny::DOSIPV(int id)
{
    handler ipv;
    ipv.start_DOSIPV_Lab(id);
}
void meny::show_inf()
{
QIcon icon;
icon.addFile(":/res/inf.png");
QMessageBox helper;
helper.setWindowTitle("Дополнительная информация");
helper.setText("Лабораторные работы сделанные для Web среды для корректной работы моделей"
               "и стабильной работы плагинов используют браузер Mozilla Firefox\n"
               "для коректной работы плагинов ActiveX и Java.\n"
               "Лабораторные работы MS-DOS используют DOSBox - эмулятор DOS окружения.\n\n"
               "Основные горячие клавиши DOSBox:\n"
               "ALT+ENTER - переход в полноэкранный режим\n"
               "CTRL+F5 - скриншот\n"
               "CTRL+F9 - закрыть DOSBox\n"
               "Alt-левый Shift - смена раскладки на английскую\n"
               "Alt-правый Shift - смена раскладки на русскую\n\n"
               "Разработчик ПО:\n"
               "заместитель командира взвода\n"
               "Воронежского института МВД России\n"
               "Бакулин Н.С.");
helper.setWindowIcon(icon);
helper.exec();
}
