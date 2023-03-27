#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>

class QtEditor : public QMainWindow
{
	Q_OBJECT

public:
	QtEditor(QWidget* parent = 0);
	~QtEditor();

public slots:
	void newFile();
};

#endif // QTEDITOR_H
