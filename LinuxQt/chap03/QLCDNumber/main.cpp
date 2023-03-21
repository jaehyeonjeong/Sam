#include <QApplication>
#include <QLCDNumber>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	QLCDNumber* lcd = new QLCDNumber();
	lcd->setDecMode();
	lcd->setSegmentStyle(QLCDNumber::Flat);
	lcd->display(2002);
	lcd->show();

	return a.exec();
}
