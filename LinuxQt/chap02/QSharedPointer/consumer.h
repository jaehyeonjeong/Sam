#include "object.h"

#include <QObject>
#include <QSharedPointer>

class Consumer : public QObject {
public:
	explicit Consumer(QObject* parent = nullptr);
	~Consumer();

	QSharedPointer<Object> objector;
};
