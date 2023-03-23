#include <QApplication>
#include <QStackedLayout>
#include <QHBoxLayout>
#include <QDial>
#include <QLabel>
#include <QCalendarWidget>
#include <QTextEdit>

#include "widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent)
{
	QDial* dial = new QDial(this);
	dial->setRange(0, 2);

	QLabel* label = new QLabel("Stack 1", this);
	QCalendarWidget* calendarWidget = new QCalendarWidget(this);
	QTextEdit* textEdit = new QTextEdit("Stack 3", this);

	QStackedLayout* stackedLayout = new QStackedLayout;
	stackedLayout->addWidget(label);
	stackedLayout->addWidget(calendarWidget);
	stackedLayout->addWidget(textEdit);

	connect(dial, SIGNAL(valueChanged(int)),
			stackedLayout, SLOT(setCurrentIndex(int)));

	QHBoxLayout* hBoxLayout = new QHBoxLayout(this);
	hBoxLayout->addWidget(dial);
	hBoxLayout->addLayout(stackedLayout);

	setLayout(hBoxLayout);
}

Widget::~Widget()
{
}
