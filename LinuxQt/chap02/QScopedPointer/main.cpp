#include "object.h"
#include <QCoreApplication>
#include <QDebug>
#include <QScopedPointer>

void Do(QScopedPointer<Object> &myPointer)
{
	qInfo() << ">>> Do" << myPointer.data();
}

void Use(Object* obj)
{
	if(!obj) return;
	qInfo() << ">>> Use" << obj;
}

void doStuff()
{
	QScopedPointer<Object> mypointer(new Object());

	Use(mypointer.data());
	Do(mypointer);
}

int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);

	for(int i = 0; i < 10; i++) {
		qInfo() << "-------------" << i;
		doStuff();
	}

	doStuff();

	return a.exec();
}
