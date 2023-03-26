#ifndef PATIENTVIEW_H
#define PATIENTVIEW_H

#include <QObject>
#include <QEventLoop>

class Downloader;
class QNetworkAccessManager;

class PatientVIew : public QObject
{
    Q_OBJECT

public:
    explicit PatientVIew(QObject* parent = nullptr);
    void patientView(QString = "", QString = "", QString = "");
    ~PatientVIew();

private:
    Downloader* downloader;
    QNetworkAccessManager* manager;
    QEventLoop eventLoop;

signals:
    void middlePatient();
};

#endif // PATIENTVIEW_H
