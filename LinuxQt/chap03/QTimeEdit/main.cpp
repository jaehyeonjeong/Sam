#include <QTime>
#include <QTimeEdit>
#include <QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	QTimeEdit* timeEdit = new QTimeEdit(0);
	timeEdit->setTime(QTime::currentTime());
	timeEdit->show();

	return a.exec();
}
