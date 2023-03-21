#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	QLabel hello("<font color=blue>"\
			"Hello <i>Qt!</i></font>", 0);
	hello.resize(75, 35);
	hello.show();
	return a.exec();
}
