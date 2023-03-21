#include <QCoreApplication>
#include <QDebug>
#include <QSharedPointer>
#include "object.h"
#include "consumer.h"

void doDeleteLater(Object* obj)
{
	qInfo() << "Deleteing : " << obj;
	obj->deleteLater();
}

QSharedPointer<Object> creatorPointer()
{
	Object *obj = new Object();
	obj->setObjectName("Test Object");
	QSharedPointer<Object> p(obj, doDeleteLater);
	return p;
}

void doStuff(QSharedPointer<Consumer> ptr)
{
	qInfo() << "In function:" << ptr.data()->objector;
	ptr.clear();
}

QSharedPointer<Consumer> makeConsumer()
{
	QSharedPointer<Consumer> c(new Consumer, &QObject::deleteLater);
	QSharedPointer<Object> obj = creatorPointer();
	c.data()->objector.swap(obj);
	doStuff(c);

	return c;
}

int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);

	QSharedPointer<Consumer> consume = makeConsumer();
	qInfo() << "In main : " << consume.data()->objector;

	consume.clear();
	return a.exec();
}
