#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>

class QNetworkAccessManager;
class QNetworkReply;
class QFile;

class Downloader : public QObject
{
	Q_OBJECT
public:
	explicit Downloader(QObject* parent = 0);
	~Downloader();
	void setFile(QString fileURL);

private slots:
	void onDownloadProgress(qint64, qint64);
	void onFinished(QNetworkReply*);
	void onReplyFinished();

signals:
	void sendDownload();

private:
	QNetworkAccessManager* manager;
	QNetworkReply* reply;
	QFile* file;
};

#endif // DOWNLOADER_H
