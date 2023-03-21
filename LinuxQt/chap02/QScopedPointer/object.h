#include <QObject>

class Object : public QObject {
public : 
	explicit Object(QObject* parent = nullptr);
	~Object();
};
