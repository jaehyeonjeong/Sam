#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <opencv2/opencv.hpp>
#include <QFile>
#include <QGraphicsScene>

class QSlider;
class QLineEdit;
class QGraphicsView;
class QRadioButton;
class QButtonGroup;
class QPushButton;
class QLabel;
class QAbstractButton;
class QGraphicsLineItem;
class QGraphicsSceneMouseEvent;

/*Qt에서 제공하는 QClass 집합*/

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void layoutSetting();
    void connectFunc();

public slots:
    void onBlending(int);   // 슬라이더 위젯을 움직일 때 마다 가중치 값을 받는 함수
	//void onButtonPoint(QAbstractButton*);
	void onButtonToggle(int id, bool checked);
protected:
    //void resizeEvent(QResizeEvent *) override;  // resizeEvent 함수 override
private:
	QLabel* firstLabel;
    QLabel* lastLabel;
    QLineEdit* firstImage;
    QLineEdit* lastImage;
    QLineEdit* outputEdit;
    QSlider* alphaSlider;
    QGraphicsView* graphicsView;
    QRadioButton* lengthButton;
    QRadioButton* angleButton;
    QButtonGroup* buttonGroup;
    QPushButton* clearButton;
};

/*class Scene : public QGraphicsScene 
{
public:
	Scene(QObject* parent = nullptr) : QGraphicsScene(parent) {}

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;


private:
	QGraphicsLineItem* currentLine = nullptr;
};*/

#endif // WIDGET_H
