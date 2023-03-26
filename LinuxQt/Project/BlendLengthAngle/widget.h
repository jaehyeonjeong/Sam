#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <opencv2/opencv.hpp>
#include <QFile>

class QSlider;
class QLineEdit;
class QGraphicsView;
class QRadioButton;
class QButtonGroup;
class QPushButton;
class QLabel;

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
#endif // WIDGET_H
