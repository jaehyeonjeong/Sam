#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QCheckBox;
class QButtonGroup;
class QLabel;

class Widget : public QWidget
{
	Q_OBJECT
public:
	Widget(QWidget* parent = 0);
	~Widget();

private:
	QCheckBox* checkBox[4];
	QButtonGroup* buttonGroup;
	QLabel* label;

public slots:
	void selectButton(int id);
};

#endif
