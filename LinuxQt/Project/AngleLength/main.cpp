#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QPointF>
#include <QMouseEvent>

class MyScene : public QGraphicsScene 
{
public:
	MyScene(QObject* parent = nullptr) : QGraphicsScene(parent) {}

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent* event) override
	{
		if(event->button() == Qt::LeftButton) {
			QPointF start_point = event->scenePos();
			QGraphicsLineItem* line = new QGraphicsLineItem(QLineF(start_point, start_point));
			QPen pen(Qt::black, 2);
			line->setPen(pen);
			addItem(line);
			m_current_line = line;
		}
	}

	void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override
	{
		if(m_current_line) {
			QLineF new_line(m_current_line->line().p1(), event->scenePos());
			m_current_line->setLine(new_line);
		}
	}

	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override
	{
		if(m_current_line) {
			if(m_current_line->line().length() < 10) {
				removeItem(m_current_line);
				delete m_current_line;
			}
			m_current_line = nullptr;
		}
	}
	
private:
	QGraphicsLineItem* m_current_line = nullptr;
};

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QGraphicsScene scene;
	QGraphicsView view(&scene);
	view.show();
	scene.setSceneRect(0, 0, 800, 600);
	MyScene my_scene;
	view.setScene(&my_scene);
	return app.exec();
}
