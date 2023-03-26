#include "patientview.h"
#include "downloader.h"

#include <QNetworkAccessManager>
#include <QEventLoop>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

PatientVIew::PatientVIew(QObject* parent)
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
}

PatientVIew::~PatientVIew()
{
    manager->deleteLater();
    downloader->deleteLater();
}

void PatientVIew::patientView(QString _hostName, QString _portNum, QString _patient)
{
    QNetworkRequest req(QUrl(QString("http://" + _hostName + ":" + _portNum + "/api/image/")));
    QNetworkReply *reply = manager->get(req);
    eventLoop.exec();

    if(reply->error() == QNetworkReply::NoError) {
        QString strReply = (QString)reply->readAll();

        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

        QJsonArray jsonArr = jsonResponse["response"].toArray();
        for(int i = 0; i < jsonArr.size(); i++) {
            QJsonObject patientObj = jsonArr.at(i).toObject();

            QString PatientName = patientObj["PatientName"].toString();
            QString ImageFile = patientObj["ImageFile"].toString();

            if(PatientName == _patient) {
                QString csvString = ImageFile.section("\\", 1, 1);

                downloader = new Downloader;
                connect(downloader, &Downloader::sendDownload, this, &PatientVIew::middlePatient);
                downloader->setFile(QString("http://" + _hostName + ":" + _portNum + "/uploads/%1").arg(csvString));
            }
        }
        delete reply;
    }
}
