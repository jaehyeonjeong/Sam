#include "qteditor.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>

QtEditor::QtEditor(QWidget* parent) : QMainWindow(parent)
{
	QMenuBar* menubar = new QMenuBar(this);
	setMenuBar(menubar);

	QAction* newAct = new QAction(QIcon("./new.png"), "&New", this);
	newAct->setShortcut(tr("Ctrl+N"));
	newAct->setStatusTip(tr("make new file"));
	connect(newAct, SIGNAL(triggered()), SLOT(newFile()));

	QMenu* fileMenu = menubar->addMenu("&File");
	fileMenu->addAction(newAct);
}

QtEditor::~QtEditor()
{
}

void QtEditor::newFile()
{
	qDebug("Make New File");
}
