#include <QObject>
#include <QPointer>

class object : public QObject {
public :
	explicit object(QObject* parent = nullptr);
	void useWidget();

	QPointer<QObject> widget;
};
