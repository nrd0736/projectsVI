#include "handler.h"

handler::handler(QWidget *parent) : QWidget(parent)
{

}
void handler::start_DOS_Lab(int id)
{
    QProcess proc;

    QString pathall;
    pathall.append(QCoreApplication::applicationDirPath());
    pathall.append("/Lab_baze/Lab(dos)/Лабораторные работы по физике/");

    QStringList name;
    name<<"1.Автоматихированная обработка результатов измерений в лабораторных работах по физике.bat"<<
          "2.Атом водорода в квановой механике.bat"<<
          "3.Закон сохранения момента импульса.bat"<<
          "4.Исследование затухающих и вынужденных механических колебаний.bat"<<
          "5.Кинематика теория и решение задач.bat"<<
          "6. Кольца Ньютона.bat"<<
          "7. Микрочастица в потенциальной яме.bat"<<
          "8. Напряженность и потенциал электростатического поля.bat"<<
          "9. Прохождение микрочастиц через щель.bat"<<
          "10.Расчёт ошибок измерений на примере определения объёма цилиндра.bat"<<
          "11. Стоячие волны.bat"<<
          "12.Исследование прохождения световых импульсов по многомодовым волоконным светодиодам.bat";

        pathall.append(name[id-1]);

        proc.startDetached("cmd.exe", QStringList() << "/c" <<  pathall);


}
 void handler::start_EXE_Lab(int id)
 {
     QProcess proc;

     QString pathall("start ");
     pathall.append(QCoreApplication::applicationDirPath());
     pathall.append("/Lab_baze/Lab(dos)/");

     QStringList name;
     name<<"CD_lab/CD1/GLAZPRO.EXE"<<
           "CD_lab/CD3/OMF4.exe"<<
           "KOL/KOLOK.EXE"<<
           "EfDp/inst_lab/effekdpl.exe";

         pathall.append(name[id-1]);
         qDebug()<<pathall;

         proc.startDetached("cmd.exe", QStringList() << "/c" <<  pathall);

 }

 void handler::start_WEB_Lab(int id)
 {
     QProcess proc;

     QString pathall;
     pathall.append(QCoreApplication::applicationDirPath());
     pathall.append("/Lab_baze/Ph/start_bats/");

     QStringList name;
     name<<"1.1.bat"<< /* Движение с постоянным ускорением"*/
           "1.2.bat"<< /* Движение под действием постоянной силы"*/
           "1.3.bat"<< /* Свободные механические колебания"*/
           "1.4.bat"<< /* Упругие и неупругие удары"*/
           "1.5.bat"<< /* Соударения упругих шаров"*/
           "2.1.bat"<< /* Движение заряженной частицы в электрическом поле"*/
           "2.2.bat"<< /* Электрическое поле точечных зарядов"*/
           "2.3.bat"<< /* Цепи постоянного тока"*/
           "2.4.bat"<< /* Магнитное поле"*/
           "2.5.bat"<< /* Электромагнитная индукция"*/
           "2.6.bat"<< /* Свободные колебания в RLC-контуре"*/
           "2.7.bat"<< /* Вынужденные колебания в RLC-контуре"*/
           "2.8.bat"<< /* Вынужденные колебания в RLC-контуре (с упрощенной теорией)"*/
           "2.9.bat"<< /* Интерференция"*/
           "2.10.bat"<< /* Дифракционная решетка"*/
           "3.1.bat"<< /* Внешний фотоэффект"*/
           "3.2.bat"<< /* Спектр излучения атомарного водорода"*/
           "3.3.bat"<< /* Эффект Комптона"*/
           "3.4.bat"<< /* Дифракция электронов"*/
           "3.5.bat"<< /* Прохождение электромагнитного излучения через вещество"*/
           "3.6.bat"<< /* Ядра атомов"*/
           "4.1.bat"<< /* Адиабатический процесс"*/
           "4.2.bat"<< /* Теплоемкость идеального газа"*/
           "4.3.bat"<< /* Распределение Максвелла"*/
           "4.4.bat"<< /* Диффузия в газах"*/
           "4.5.bat"; /* Уравнение состояния Ван-дер-Ваальса"*/

     pathall.append(name[id-1]);
     qDebug()<<pathall;
     proc.startDetached("cmd.exe", QStringList() << "/c" <<  pathall);
 }

 void handler::start_OP_Lab(int id)
 {
     QProcess proc;


     QString pathall;
     pathall.append(QCoreApplication::applicationDirPath());
     pathall.append("/Lab_baze/OpenPh/start_bats/");

     QStringList name;
     name<<"OP_p1.bat"<< /* Открытая физика часть 1 */
           "OP_p2.bat"; /* Открытая физика часть 2 */

           pathall.append(name[id-1]);
           qDebug()<<pathall;
           proc.startDetached("cmd.exe", QStringList() << "/c" <<  pathall);

 }
  void handler::start_JAV_Lab(int id)
  {
      QProcess proc;


      QString pathall("start ");
      pathall.append(QCoreApplication::applicationDirPath());
      pathall.append("/Lab_baze/BJD/");

      QStringList name;
      name<<"1bjd.bat"<< /* Исследование явлений, возникающих при стекании тока в землю */
            "2bjd.bat"; /* Изучение действия защитного заземления и защитного зануления */

            pathall.append(name[id-1]);
            qDebug()<<pathall;
            proc.startDetached("cmd.exe", QStringList() << "/c" <<  pathall);

  }
  void handler::start_DOSRTS_Lab(int id)
{
  QProcess proc;

  QString pathall;
  pathall.append(QCoreApplication::applicationDirPath());
  pathall.append("/Lab_baze/RTS/RTCS2/strat_bats/");

  QStringList name;
  name<<"Исследование импульсной РЛС.bat"<<
        "Исследование многоканальной радиотехнической системы передачи информации.bat"<<
        "Исследование одноканальной радиотехнической системы передачи информации.bat"<<
        "Исследование оптимального обнаружителя сигналов (на основе коррелятора).bat"<<
        "Исследование оптимального обнаружителя сигналов (на основе согласованного фильтра).bat"<<
        "Исследование оптимального приемника фазоманипулированных сигналов.bat"<<
        "Исследование РТС с ЛЧМ сигналами.bat"<<
        "Прохождение случайных сигналов через линейные цепи.bat";

      pathall.append(name[id-1]);

      proc.startDetached("cmd.exe", QStringList() << "/c" <<  pathall);

 }

  void handler::start_DOSIPV_Lab(int id)
  {
      QProcess proc;

      QString pathall;
      pathall.append(QCoreApplication::applicationDirPath());
      pathall.append("/Lab_baze/IPV/strat_bats/");

      QStringList name;
      name<<"Исследование распространения радиоволн миллиметрового диапазона в атмосфере.bat"<<
            "Плоские однородные волны в диэлектриках и проводниках, поляризация и сложение волн.bat"<<
            "Расчёт радиотрасс через ионосферные каналы, диапазон коротких волн.bat"<<
            "Типы волн в плоском волноводе.bat";

          pathall.append(name[id-1]);

          proc.startDetached("cmd.exe", QStringList() << "/c" <<  pathall);
  }
