#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>

class QAction;
class QTextEdit;
class QLabel;
class QMdiArea;

class QtEditor : public QMainWindow
{
	Q_OBJECT

public:
	QtEditor(QWidget* parent = 0);
	~QtEditor();

private:
	QLabel* statusLabel;
	QMdiArea* mdiArea;

	QAction* makeAction(QString icon, QString name, QString shortCut,
			QString toolTip, QObject* recv, const char* slot);

public slots:
	void newFile();
};

#endif // QTEDITOR_H
