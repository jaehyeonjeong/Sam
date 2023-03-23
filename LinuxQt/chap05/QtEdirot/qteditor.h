#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>

class QtEditor : public QMainWindow
{
	Q_OBJECT
public:
	QtEditor(QWidget* parent = 0);
	~QtEditor();
};

#endif	// QTEDITOR_H
