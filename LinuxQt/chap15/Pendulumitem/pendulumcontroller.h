#ifndef PENDULUMCONTROL_H
#define PENDULUMCONTROL_H

#include <QTimeLine>
#include <QGraphicsItem>

class PendulumController : public QObject 
{
	Q_OBJECT
public:
	explicit PendulumnController(QGraphicsItem* pendulumn, QObject* parent = 0);
