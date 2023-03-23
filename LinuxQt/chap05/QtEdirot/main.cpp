#include "qteditor.h"

#include <QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	QtEditor edit;
	edit.show();
	return a.exec();
}
