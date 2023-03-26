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
class PatientVIew;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
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

    QString hostName = "192.168.123.109";
    QString portNum = "40000";

    QNetworkAccessManager* manager;
    QNetworkReply* reply;
    QEventLoop eventLoop;

    PatientModel* patientModel;
    PatientVIew* patView;
};
#endif // WIDGET_H
