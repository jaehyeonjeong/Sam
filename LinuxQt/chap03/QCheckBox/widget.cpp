#include <QApplication>
#include <QCheckBox>
#include <QButtonGroup>
#include <QLabel>

#include "widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent)
{
	resize(140, 110);
	buttonGroup = new QButtonGroup(this);
	buttonGroup->setExclusive(false);
	connect(buttonGroup, SIGNAL(buttonClicked(int)), SLOT(selectButton(int)));

	label = new QLabel("0", this);
	label->move(10, 10);

	for(int i = 0; i < 4; i++) {
		QString str = QString("Option %1").arg(i + 1);
		checkBox[i] = new QCheckBox(str, this);
		checkBox[i]->move(10, 30 + 20 * i);
		buttonGroup->addButton(checkBox[i], i);

	}
}

Widget::~Widget()
{
}

void Widget::selectButton(int id)
{
	QButtonGroup* buttonGroup = (QButtonGroup*)sender();
	QCheckBox* button = (QCheckBox*)buttonGroup->button(id);
	label->setText(QString::number(id + 1));
}
