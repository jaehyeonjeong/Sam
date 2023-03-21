#include "consumer.h"

#include <QDebug>

Consumer::Consumer(QObject* parent) : QObject(parent)
{
	qInfo() << "Constructor" << this;
}

Consumer::~Consumer() 
{
	qInfo() << "Deconstructor" << this;
}
