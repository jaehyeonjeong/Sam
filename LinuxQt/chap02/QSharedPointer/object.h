#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>

class Object : public QObject {
public : 
	explicit Object(QObject* parent = nullptr);
	~Object();
};

#endif 
