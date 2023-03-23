#include "qteditor.h"

#include <QTextEdit>

QtEditor::QtEditor(QWidget* parent) : QMainWindow(parent)
{
	QTextEdit* textedit = new QTextEdit(this);
	setCentralWidget(textedit);
}

QtEditor::~QtEditor()
{
}
