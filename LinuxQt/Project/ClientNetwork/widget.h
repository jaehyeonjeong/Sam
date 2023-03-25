#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QEventLoop>

class QLineEdit;
class QPushButton;
class QTableView;
class QListWidget;

class QNetworkAccessManager;
class QNetworkReply;

class PatientModel;
class PatientView;

class Widget : public QWidget
{
	Q_OBJECT
public:
	Widget(QWidget* parent = 0);
	~Widget();
	void layoutSetting();
	void connectFunc();
	void loadImages();

public slots:
	void reactConnectBtn();
	void onTableClicked(const QModelIndex &index);

private:
	QLineEdit* doctorIDEdit;
	QPushButton* connectBtn;
	QTableView* patientTable;
	QListWidget* pictureList;

	QString hostName = "10.0.2.15";
	QString portNum = "40000";

	QNetworkAccessManager* manager;
	QNetworkReply* reply;
	QEventLoop eventLoop;

	PatientModel* patientModel;
	PatientView* patView;
};

#endif	// WIDGET_H
