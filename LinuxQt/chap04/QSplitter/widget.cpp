#include <QApplication>
#include <QSplitter>
#include <QLabel>
#include <QDial>

#include "widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent)
{
	QLabel* label = new QLabel("IP Address", this);
	QDial* dial = new QDial(this);

	QSplitter* splitter = new QSplitter(this);
	splitter->addWidget(label);
	splitter->addWidget(dial);

	resize(splitter->sizeHint());
}

Widget::~Widget()
{
}
