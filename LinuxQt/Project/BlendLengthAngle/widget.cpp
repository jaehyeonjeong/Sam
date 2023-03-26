#include "widget.h"

#include <opencv2/opencv.hpp>
#include <QLineEdit>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QPointF>
#include <QLineF>
#include <QMouseEvent>
#include <QImage>
#include <QSlider>
#include <QRadioButton>
#include <QButtonGroup>
#include <QPushButton>
#include <QLabel>
#include <QAbstractButton>
#include <QDebug>
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
	alphaSlider->setRange(0, 10);
    alphaSlider->setOrientation(Qt::Horizontal);
    alphaSlider->setTickPosition(QSlider::TicksAbove);

    buttonGroup->addButton(lengthButton, 0);
    buttonGroup->addButton(angleButton, 1);

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
	connect(buttonGroup, SIGNAL(buttonToggled(int, bool)), this, SLOT(onButtonToggle(int, bool)));
}

void Widget::onBlending(int value)
{
	QGraphicsScene* sceneImage = new QGraphicsScene();
	QImage* image = new QImage();

	Mat img1 = imread("./Images/CocaCola.png");
	Mat img2 = imread("./Images/Pepsi.png");
	Mat result;

	firstImage->setText("CocaCola.png");
	lastImage->setText("Pepsi.png");

	double alpha = value / 10.0;
	double beta = 1.0 - alpha;

	addWeighted(img1, beta, img2, alpha, 0, result);

	imwrite("./Images/result.png", result, vector<int>(ImwriteFlags::IMWRITE_PNG_BILEVEL));
	image->load("./Images/result.png");
	if(image->isNull()) {
		return;
	}
	graphicsView->setScene(sceneImage);
	graphicsView->fitInView(sceneImage->sceneRect(), Qt::IgnoreAspectRatio);

	QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(*image));
	sceneImage->addItem(item);
	graphicsView->show();
}

/*void Widget::onButtonPoint(QAbstractButton* button)
{
	if(button == buttonGroup->button(0)) {
		firstImage->setText("RadioButton1 Check");
	} else if (button == buttonGroup->button(1)) {
		lastImage->setText("RadioButton2 Check ");
	}
}*/


void Widget::onButtonToggle(int id, bool checked)
{
	if(checked) {
		if(id == 0) {
			outputEdit->setText("RadioButton 1 Check");
		} else if(id == 1) {
			outputEdit->setText("RadioButton 2 Check");
		}
	}
}
/*
void Scene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	if(event->button() == Qt::LeftButton) {
		QPointF start_point = event->scenePos();
		QGraphicsLineItem* line = new QGraphicsLineItem(QLineF(start_point, start_point));
		QPen pen(Qt::green, 3);
		line->setPen(pen);
		addItem(line);
		currentLine = line;
	}
}


void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	if(currentLine) {
		QLineF newLine(currentLine->line().p1(), event->scenePos());
		currentLine->setLine(newLine);
	}
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	if(currentLine) {
		if(currentLine->line().length() < 10) {
			removeItem(currentLine);
			delete currentLine;
		}
		currentLine = nullptr;
	}
}
*/
