#include "inexel.h"

inexel::inexel(QWidget *parent) : QWidget(parent)
{


}
QString inexel::createInFile()
{
    QString nameFile;
    nameFile.append("Input");
    QString impEXEL;
impEXEL = QString("%1/").arg(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));
QXlsx::Document xlsxinOUT;
QXlsx::Format defFormat;
QColor defColor;
defColor.setRgb(247, 208, 109);
defFormat.setPatternBackgroundColor(defColor);
defFormat.setFontSize(18);
xlsxinOUT.setColumnWidth(1,20.0);
xlsxinOUT.setColumnWidth(2,50.0);
defFormat.setVerticalAlignment(QXlsx::Format::AlignVCenter);
defFormat.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
xlsxinOUT.write("A1","№ п/п",defFormat);
xlsxinOUT.mergeCells("A1:A2");
xlsxinOUT.write("B1","Исходный адрес",defFormat);
xlsxinOUT.mergeCells("B1:B2");
xlsxinOUT.saveAs(impEXEL + nameFile + ".xlsx");


impEXEL.append(nameFile  + ".xlsx");// ввод имени через интерфейс (В БУДУЩЕМ)

QString path;
path.append(QCoreApplication::applicationDirPath());
path.append("/data/input");
path.append("/bufEXML.txt");
QFile EXELbuf(path);
QTextStream in(&EXELbuf);
EXELbuf.open(QIODevice::Append);
in<<impEXEL<<"\n";
EXELbuf.close();

return  impEXEL;
}
