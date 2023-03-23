#include <QApplication>
#include <QFrame>

#include "widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent)
{
	QFrame* plainLine = new QFrame(this);
	plainLine->setGeometry(QRect(0, 0, 270, 16));
	plainLine->setLineWidth(2);
	plainLine->setFrameStyle(QFrame::HLine | QFrame::Plain);

	QFrame* raisedLine = new QFrame(this);
	raisedLine->setGeometry(QRect(0, 10, 270, 16));
	raisedLine->setLineWidth(2);
	raisedLine->setFrameStyle(QFrame::HLine | QFrame::Raised);

	QFrame* sunkenLine = new QFrame(this);
	sunkenLine->setGeometry(QRect(0, 20, 270, 16));
	sunkenLine->setLineWidth(2);
	sunkenLine->setFrameStyle(QFrame::HLine | QFrame::Sunken);
}

Widget::~Widget()
{
}
