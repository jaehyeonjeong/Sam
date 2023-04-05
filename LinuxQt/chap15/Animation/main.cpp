#include <QtWidgets>

int main(int argc, char** argv)
{
	QApplication a(argc, argv);
	QGraphicsRectItem* rect = new QGraphicsRectItem(0, 0, 40, 20);
	rect->setBrush(QBrush(Qt::blue));

	QTimeLine* timer = new QTimeLine(5000);
	timer->setFrameRange(0, 100);

	QGraphicsItemAnimation* animation = new QGraphicsItemAnimation;
	animation->setItem(rect);
	animation->setTimeLine(timer);

	for(int i = 0; i < 200; i++)
		animation->setPosAt(i / 200.0, QPoint(i, i));
	animation->setRotationAt(80.0 / 200.0, 30);
	animation->setRotationAt(180.0 / 200.0, 90);

	QGraphicsScene* scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, 250, 250);
	scene->addItem(rect);

	QGraphicsView* view = new QGraphicsView(scene);
	view->show();
	timer->start();

	return a.exec();
}
