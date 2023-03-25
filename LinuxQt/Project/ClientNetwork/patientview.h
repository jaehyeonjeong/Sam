#ifndef PATIENTVIEW_H
#define PATIENTVIEW_H

#include <QObject>
#include <QEventLoop>

class Downloader;
class QNetworkAccessManager;

class PatientView : public QObject
{
	Q_OBJECT
public:
	explicit PatientView(QObject* parent = nullptr);
	void patientView(QString = "", QString = "", QString = "");
	~PatientView();

private:
	Downloader* downloader;
	QNetworkAccessManager* manager;
	QEventLoop eventLoop;

signals:
	void middlePatient();
};

#endif // PATIENTVIEW_H
