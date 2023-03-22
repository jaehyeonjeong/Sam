#include <QDate>
#include <QDateEdit>
#include <QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	QDateEdit* dateEdit = new QDateEdit(QDate::currentDate(), 0);
	dateEdit->setCalendarPopup(true);
	dateEdit->show();

	return a.exec();
}
