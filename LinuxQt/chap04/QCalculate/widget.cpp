#include <QApplication>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QButtonGroup>

#include "widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent)
{
	const char ButtonChar[16][2] = {
		"7", "8", "9", "C",
		"4", "5", "6", "/",
		"1", "2", "3", "x",
		"0", "=", "+", "-",
	};

	label = new QLabel("0", this);
	label->setAlignment(Qt::AlignRight);
	label->setFrameShape(QFrame::Box);

	QPushButton* pushButton[16];
	QGridLayout* gridLayout = new QGridLayout();
	QButtonGroup* buttonGroup = new QButtonGroup(this);
	connect(buttonGroup, SIGNAL(buttonClicked(int)), SLOT(click(int)));
	for(int i = 0; i < 16; i++) {
		pushButton[i] = new QPushButton(ButtonChar[i], this);
		gridLayout->addWidget(pushButton[i], i/4, i%4);
		buttonGroup->addButton(pushButton[i], i);
	}
/*
	connect(pushButton[0], SIGNAL(clicked()), SLOT(setNum()));	// 7
	connect(pushButton[1], SIGNAL(clicked()), SLOT(setNum()));	// 8
	connect(pushButton[2], SIGNAL(clicked()), SLOT(setNum()));	// 9
	connect(pushButton[3], SIGNAL(clicked()), SLOT(setNum()));	// C
	connect(pushButton[4], SIGNAL(clicked()), SLOT(setNum()));	// 4
	connect(pushButton[5], SIGNAL(clicked()), SLOT(setNum()));	// 5
	connect(pushButton[6], SIGNAL(clicked()), SLOT(setNum()));	// 6
	connect(pushButton[7], SIGNAL(clicked()), SLOT(setNum()));	// /
	connect(pushButton[8], SIGNAL(clicked()), SLOT(setNum()));	// 1
	connect(pushButton[9], SIGNAL(clicked()), SLOT(setNum()));	// 2
	connect(pushButton[10], SIGNAL(clicked()), SLOT(setNum())); // 3
	connect(pushButton[11], SIGNAL(clicked()), SLOT(steNum())); // x
	connect(pushButton[12], SIGNAL(clicked()), SLOT(setNum())); // 0
	connect(pushButton[13], SIGNAL(clicked()), SLOT(setNum())); // =
	connect(pushButton[14], SIGNAL(clicked()), SLOT(setNum())); // +
	connect(pushButton[15], SIGNAL(clicked()), SLOT(setNum())); // -
*/

	QVBoxLayout* vBoxLayout = new QVBoxLayout(this);
	vBoxLayout->setMargin(6);
	vBoxLayout->addWidget(label);
	vBoxLayout->addLayout(gridLayout);
	setLayout(vBoxLayout);
}

Widget::~Widget()
{
	delete label;
}

void Widget::setNum()
{
#if 1
	QString result = (label->text() == "0")?
		(qobject_cast<QPushButton*>(sender()))->text()
		: label->text() + ((QPushButton*)sender())->text();
	label->setText(result);
#else
	label->setText((QString::number(label->text().toFloat()*10 + \
					((QPushButton*)sender())->text().toFloat()));
#endif
}

void Widget::operation()
{
	numberTemp = label->text();
	operate = ((QPushButton*)sender())->text();
	label->setText("0");
}

void Widget::calculate()
{
	float result;
	switch(operate.at(0).toLatin1()) {
	case '+': result = numberTemp.toFloat() + label->text().toFloat(); break;
	case '-': result = numberTemp.toFloat() - label->text().toFloat(); break;
	case 'x': result = numberTemp.toFloat() * label->text().toFloat(); break;
	case '/':
		if(label->text().toFloat()) {
			result = numberTemp.toFloat() / label->text().toFloat();
		} else {
			label->setText("Error : Cannot Divide by Zero");
			result = 0;
		}
		break;
	}

	label->setText(QString::number(result));
}

void Widget::clear()
{
	numberTemp.setNum(0);
	label->setText("0");
}

void Widget::click(int id)
{
	QPushButton* button = (QPushButton*)((QButtonGroup*)sender())->button(id);
	QString str = button->text();
	switch(id) {
		case 0: case 1: case 2: case 4: case 5: case 6: case 8: case 9: case 10: case 12:
			label->setText((label->text() == "0")?str:label->text() + str); break;
		case 3: clear(); break;
		case 7: case 11: case 14: case 15:
				numberTemp = label->text(); label->setText("0"); operate = str; break;
		case 13: calculate(); break;
	};
}
