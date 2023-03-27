#include "qteditor.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QToolBar>
#include <QFontComboBox>
#include <QDoubleSpinBox>
#include <QTextEdit>
#include <QLabel>
#include <QStatusBar>
#include <QDockWidget>
#include <QMdiArea>
#include <QMdiSubWindow>

QtEditor::QtEditor(QWidget* parent) : QMainWindow(parent)
{
	mdiArea = new QMdiArea(this);
	setCentralWidget(mdiArea);

	QLabel* label = new QLabel("Dock Widget", this);
	QDockWidget* dock = new QDockWidget("Dock Widget", this);
	dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	addDockWidget(Qt::RightDockWidgetArea, dock);
	dock->setWidget(label);

#if 0
	QTextEdit* textEdit = new QTextEdit(this);
	mdiArea->addSubWindow(textEdit);
#else
#endif
	
	QMenuBar* menubar = new QMenuBar(this);
	setMenuBar(menubar);

	QAction* newAct = makeAction("./new.png", "&New", "Ctrl+N",\
			"make new file", this, SLOT(newFile()));

	QAction* quitAct = makeAction("./quit.png", "&Quit", "Ctrl+Q",\
			"Quit this program", qApp, SLOT(quit()));

/*	QFontComboBox* fontComboBox = new QFontComboBox(this);
	connect(fontComboBox, SIGNAL(currentFontChanged(QFont)),
			textEdit, SLOT(setCurrentFont(QFont)));
	QDoubleSpinBox* sizeSpinBox = new QDoubleSpinBox(this);
	connect(sizeSpinBox, SIGNAL(valueChanged(double)),
			textEdit, SLOT(setFontPointSize(qreal)));*/

	QMenu* fileMenu = menubar->addMenu("&File");
	fileMenu->addAction(newAct);
	fileMenu->addSeparator();
	fileMenu->addAction(quitAct);

	QToolBar* fileToolBar = addToolBar("&File");
	fileToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	fileToolBar->addAction(newAct);

	addToolBarBreak();

	QToolBar* formatToolbar = addToolBar("&Format");
	
	formatToolbar->addSeparator();
	formatToolbar->addWidget(fontComboBox);
	formatToolbar->addWidget(sizeSpinBox);

	fileToolBar->addSeparator();
	fileToolBar->addAction(quitAct);

	QStatusBar* statusbar = statusBar();
	statusLabel = new QLabel("Qt Editor", statusbar);
	statusLabel->setObjectName("StatusLabel");
	statusbar->addPermanentWidget(statusLabel);
	statusbar->showMessage("started", 1500);

	QMenu* windowMenu = menubar->addMenu("&Window");
	windowMenu->addAction(fileToolBar->toggleViewAction());
	windowMenu->addAction(formatToolbar->toggleViewAction());
	windowMenu->addAction(dock->toggleViewAction());
	
	newFile();
}

QAction* QtEditor::makeAction(QString icon, QString name,\
		QString shortCut, QString toolTip,\
		QObject* recv, const char* slot)
{
	QAction* act = new QAction(name, this);
	if(icon.length())
		act->setIcon(QIcon(icon));
	act->setShortcut(shortCut);
	act->setStatusTip(toolTip);
	connect(act, SIGNAL(triggered()), recv, slot);
	return act;
}

QtEditor::~QtEditor()
{
}

void QtEditor::newFile()
{
	qDebug("Make New File");
	QTextEdit* textedit = new QTextEdit;
	QFontComboBox* fontComboBox = new QFontComboBox;
	QDoubleSpinBox* sizeSpinBox = new QDoubleSpinBox;
	connect(fontComboBox, SIGNAL(currentFontChanged(QFont)),
			textedit, SLOT(setCurrentFont(QFont)));
	connect(sizeSpinBox, SIGNAL(valueChanged(double)),
			textedit, SLOT(setFontPointSize(qreal)));
	mdiArea->addSubWindow(textedit);
	textedit->show();
}
