#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>

#include "widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent)
{
	QPushButton* pushButton1 = new QPushButton();
	pushButton1->setText("Button1");
	QPushButton* pushButton2 = new QPushButton("Button2");
	QPushButton* pushButton3 = new QPushButton("Button3", this);

	QVBoxLayout* vBoxLayout = new QVBoxLayout(this);
	vBoxLayout->setSpacing(6);
	vBoxLayout->addWidget(pushButton1);
	vBoxLayout->addWidget(pushButton2);
	vBoxLayout->addWidget(pushButton3);
}

Widget::~Widget()
{
}
