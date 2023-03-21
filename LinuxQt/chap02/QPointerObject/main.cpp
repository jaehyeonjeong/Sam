#include "object.h"

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);

	QObject* obj1 = new QObject(nullptr);
	obj1->setObjectName("MyObject");

	QPointer<QObject> p(obj1);

	object obj2;
	obj2.widget = p;
	obj2.useWidget();

	delete obj1;
	obj2.useWidget();

	return a.exec();
}
