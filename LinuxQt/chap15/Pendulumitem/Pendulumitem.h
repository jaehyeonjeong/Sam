#include <QGraphicsItem>
class PendulumItem : public QGraphicsItem
{
public:
	QRectF boundingRect() const;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*);
};
