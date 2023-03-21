#include "object.h"
#include <QDebug>

object::object(QObject* parent) : QObject(parent)
{
}

void object::useWidget()
{
	if(widget.data())
	{
		qInfo() << "Widget = " << widget.data();

		widget.data()->setObjectName("MyWidget");
	} else {
		qInfo() << "No Pointer!!!";
	}
}
