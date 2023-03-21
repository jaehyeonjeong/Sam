#include "object.h"
#include <QDebug>

Object::Object(QObject* parent) : QObject(parent)
{
	qInfo() << "Constructor" << this;
}

Object::~Object()
{
	qInfo() << "Deconstructor" << this;
}
