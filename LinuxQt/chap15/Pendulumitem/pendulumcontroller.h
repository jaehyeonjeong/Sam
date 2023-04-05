#ifndef PENDULUMCONTROL_H
#define PENDULUMCONTROL_H

#include <QTimeLine>
#include <QGraphicsItem>
#include <QObject>

class PendulumController : public QObject 
{
	Q_OBJECT
public:
	explicit PendulumnController(QGraphicsItem* pendulumn, QObject* parent = 0);
private slots:
	void slotRotateItem(int r);
	void slotRestartTimeLine();
private:
	QTimeLine m_timeline;
	QGraphicsItem* m_pendulum;
};

#endif // PENDULUMCONTROL_H
