#include "downloader.h"

#include <QDir>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QMessageBox>
#include <QFile>

Downloader::Downloader(QObject* parent) : QObject(parent)
{
    manager = new QNetworkAccessManager;
    file = new QFile;
}

Downloader::~Downloader()
{
    manager->deleteLater();
}

void Downloader::setFile(QString fileURL)
{
    QDir dir;
    if(dir.exists("./Images")) {

    } else {
        dir.mkdir("./Images");
    }

    QString filePath = fileURL;
    QString saveFilePath;
    QStringList filePathList = filePath.split('/');
    QString fileName = filePathList.at(filePathList.count() - 1);
    saveFilePath = QString("./Images/" + fileName);

    QNetworkRequest request;
    request.setUrl(fileURL);
    reply = manager->get(request);

    file->setFileName(saveFilePath);
    file->open(QIODevice::WriteOnly);

    connect(reply, SIGNAL(downloadProgress(qint64,qint64)),
            this, SLOT(onDownloadProgress(qint64,qint64)));
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(onFinished(QNetworkReply*)));
    connect(reply, &QNetworkReply::readyRead, [=]{
        file->write(reply->readAll());
    });

    connect(reply, SIGNAL(finished()), this, SLOT(onReplyFinished()));
}

void Downloader::onDownloadProgress(qint64 bytesRead, qint64 byteTotal)
{
    Q_UNUSED(bytesRead);
    Q_UNUSED(byteTotal);
}

void Downloader::onFinished(QNetworkReply* reply)
{
    if(file->isOpen())
    {
        file->close();
        file->deleteLater();
    }
    switch(reply->error())
    {
    case QNetworkReply::NoError:
    {
        emit sendDownload();
    }break;
    default:{

    };
    }
}

void Downloader::onReplyFinished()
{
    if(file->isOpen()) {
        file->close();
        file->deleteLater();
    }
}
