#include "widget.h"

#include <opencv2/opencv.hpp>
#include <QLineEdit>
#include <QGraphicsView>
#include <QSlider>
#include <QRadioButton>
#include <QButtonGroup>
#include <QPushButton>
#include <QLabel>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGraphicsPixmapItem>

using namespace std;
using namespace cv;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    firstImage = new QLineEdit(this);
    lastImage = new QLineEdit(this);
    outputEdit = new QLineEdit(this);
    alphaSlider = new QSlider();
    graphicsView = new QGraphicsView(this);
    lengthButton = new QRadioButton("length", this);
    angleButton = new QRadioButton("angle", this);
    buttonGroup = new QButtonGroup(this);
    clearButton = new QPushButton("clear", this);
    firstLabel = new QLabel("first : ", this);
    lastLabel = new QLabel("last : ", this);

//    image1 = imread("./Images/Coca.png", IMREAD_COLOR);
//    image2 = imread("./Images/CocaCola.png", IMREAD_COLOR);

    layoutSetting();
    connectFunc();
}

Widget::~Widget()
{
}

void Widget::layoutSetting()
{
    firstImage->setReadOnly(true);
    lastImage->setReadOnly(true);
    alphaSlider->setOrientation(Qt::Horizontal);
    alphaSlider->setTickPosition(QSlider::TicksAbove);

    buttonGroup->addButton(lengthButton);
    buttonGroup->addButton(angleButton);

    QHBoxLayout* blendOutput = new QHBoxLayout;
    blendOutput->addWidget(firstLabel);
    blendOutput->addWidget(firstImage);
    blendOutput->addWidget(alphaSlider);
    blendOutput->addWidget(lastLabel);
    blendOutput->addWidget(lastImage);

    QHBoxLayout* dataOutput = new QHBoxLayout;
    dataOutput->addWidget(lengthButton);
    dataOutput->addWidget(angleButton);
    dataOutput->addWidget(outputEdit);
    dataOutput->addWidget(clearButton);

    QVBoxLayout* projectLayout = new QVBoxLayout;
    projectLayout->addLayout(blendOutput);
    projectLayout->addWidget(graphicsView);
    projectLayout->addLayout(dataOutput);

    setLayout(projectLayout);
}

void Widget::connectFunc()
{
    connect(alphaSlider, SIGNAL(valueChanged(int)), this, SLOT(onBlending(int)));
}

void Widget::onBlending(int value)
{
//    update();


//    /*image1과 image2가 비어 있는 경우 return 반환*/
//    if(image1.empty() || image2.empty()){
//        return;
//    }

//    CV_Assert(!(image1.empty() || image2.empty()));         // image1, image2의 이미지 유무 판단
//    alphaSlider->setRange(0, 10);                       // 슬라이더의 범위
//    alphaSlider->setTickPosition(QSlider::TicksAbove);  // 슬라이더의 눈금을 11개의 표시하여 0부터 10까지 표시

//    /*blending 결과 이미지 Mat 생성*/
//    Mat result;         // 결과 이미지 변수 선언

//    /*읽어온 이미지의 크기를 변경하는 이미지 생성(resize함수 내에서는 INTER_LAYER가 있음.)*/
//    cv::resize(image1, reImage1, Size(graphicsView->width() - 5, graphicsView->height() - 5));
//    cv::resize(image2, reImage2, Size(graphicsView->width() - 5, graphicsView->height() - 5));

//    double alpha = (double)value / 10;       // alpha 값은 들어오는 value(0 ~ 10)를 10으로 나눈 값
//    /*이미지의 가중치 alpha값에 맞추어 resize된 image1, image2의 0에 가까울 수록 image1을 선명하게 표시*/
//    addWeighted(reImage1, 1 - alpha, reImage2, alpha, 0, result);

//    /*변경된 이미지 쓰기, 저장할 이미지도 PNG형식으로 저장하기 위해 ImwriteFlags 조정*/
//    cv::imwrite("./Images/result.png", result, vector<int>(ImwriteFlags::IMWRITE_PNG_BILEVEL));
//    image->load("./Images/result.png");      // 해당 경로에 결과 이미지 호출

//    /*이미지에 어떤 정보도 들어가지 않으면 return*/
//    if(image->isNull()) {
//        return;
//    }

//    /*그래픽스 위의 Scene을 세팅*/
//    graphicsView->setScene(sceneImage);
//    graphicsView->fitInView(sceneImage->sceneRect(), Qt::IgnoreAspectRatio);

//    /*QGraphicsPixmapItem 으로 view->scene->item으로 이미지를 생성*/
//    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(*image));
//    sceneImage->addItem(item);
//    graphicsView->show();
}

