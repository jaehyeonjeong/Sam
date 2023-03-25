#include <QApplication>
#include "patientmodel.h"
#include "patientview.h"
#include "widget.h"

#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QListWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDir>

Widget::Widget(QWidget* parent) : QWidget(parent)
{
	doctorIDEdit = new QLineEdit(this);
	connectBtn = new QPushButton("connect", this);
	patientTable = new QTableView(this);
	pictureList = new QListWidget(this);

	manager = new QNetworkAccessManager(this);

	pictureList->setIconSize(QSize(130, 80));
	pictureList->setResizeMode(QListWidget::Adjust);
	pictureList->setFlow(QListWidget::LeftToRight);
	pictureList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	pictureList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	layoutSetting();
	connectFunc();
}

Widget::~Widget()
{
}

void Widget::layoutSetting()
{
	QHBoxLayout* searchLayout = new QHBoxLayout;
	searchLayout->addWidget(doctorIDEdit);
	searchLayout->addWidget(connectBtn);

	QVBoxLayout* patientLayout = new QVBoxLayout;
	patientLayout->addLayout(searchLayout);
	patientLayout->addWidget(patientTable);

	QHBoxLayout* projectLayout = new QHBoxLayout;
	projectLayout->addLayout(patientLayout);
	projectLayout->addWidget(pictureList);
	setLayout(projectLayout);
}

void Widget::connectFunc()
{
	connect(connectBtn, &QPushButton::clicked, this, &Widget::reactConnectBtn);
	connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	connect(patientTable, SIGNAL(clicked(const QModelIndex &)), this, 
			SLOT(onTableClicked(const QModelIndex &)));
}

void Widget::reactConnectBtn()
{
	QList<QString> contactName;
	QList<int> age;
	QList<QString> doctorID;

	QNetworkRequest req(QUrl(QString("http://" + hostName + ":" + portNum + "/api/patient/")));
	reply = manager->get(req);
	eventLoop.exec();

	if(reply->error() == QNetworkReply::NoError) {
		QString strReply = (QString)reply->readAll();
		QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
		QJsonArray jsonArr = jsonResponse["response"].toArray();
		for(int i = 0; i < jsonArr.size(); i++) {
			QJsonObject patientObj = jsonArr.at(i).toObject();
			QString ID = patientObj["_id"].toString(); 
			QString Name = patientObj["Name"].toString();
			int Age = patientObj["Age"].toInt();
			QString DoctorID = patientObj["DoctorID"].toString();

			if(doctorIDEdit->text() == DoctorID) {
				contactName.append(Name);
				age.append(Age);
				doctorID.append(DoctorID);
			}
		}
		delete reply;
		patientModel = new PatientModel(this);
		patientModel->patientData(contactName, age, doctorID);
		patientTable->show();
	}
}

void Widget::onTableClicked(const QModelIndex &index)
{
	QString path = "./Images";
	QDir dir(path);
	dir.setNameFilters(QStringList() << "*.png" << "*.jpg");
	dir.setFilter(QDir::Files);
	foreach(QString dirFile, dir.entryList()) {
		dir.remove(dirFile);
	}

	QString patient = index.data().toString();
	patView = new PatientView;
	connect(patView, &PatientView::middlePatient, [=]{
			loadImages();
	});

	patView->patientView(hostName, portNum, patient);
}

void Widget::loadImages()
{
	QDir dir("./Images");
	QStringList filters;
	filters << "*.png" << "*.jpg" << "*.bmp";
	QFileInfoList fileInfoList = dir.entryInfoList(filters, QDir::Files | QDir::NoDotAndDotDot);
	
	pictureList->clear();
	for(int i = 0; i < fileInfoList.count(); i++) {
		QListWidgetItem* item = new QListWidgetItem(QIcon("./Images/" + fileInfoList.at(i).fileName()),
				NULL, pictureList);
		item->setStatusTip("./Images/" + fileInfoList.at(i).fileName());
		pictureList->addItem(item);
	}
}
