#include <QApplication>
#include <QPushButton>
#include <QLabel>

#include "widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent)
{
	QPushButton* quit = new QPushButton("Quit", this);
	quit->resize(75, 35);
	QLabel* label = new QLabel("<font color=blue>Hello</font>", this);
	label->setGeometry(10, 50, 75, 35);
	label->setObjectName("label1");
	
	connect(quit, SIGNAL(clicked()), this, SLOT(slotQuit()));
}

Widget::~Widget()
{
}

void Widget::slotQuit()
{
	qDebug("slotQuit");
	QLabel* label = findChild<QLabel*>("label1");
	qDebug("%s", qPrintable(label->metaObject()->className()));
	label->setText("World");
	//QMetaObject::invokeMethod(qApp, "quit");
}
