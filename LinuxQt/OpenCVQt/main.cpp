#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <opencv2/opencv.hpp>

class Picture : public QWidget
{
public:
	Picture(QWidget* parent = 0);
	~Picture();

protected:
	void paintEvent(QPaintEvent* event);
	void drawPicture(QPainter* qp);
	QImage Mat2QImage(cv::Mat const& src);
	cv::Mat QImage2Mat(QImage const& src);

private:
	int height;
	int width;
	QImage qtImage;
	cv::Mat cvImage;
};

Picture::Picture(QWidget* parent) : QWidget(parent)
{
	cvImage = cv::imread("./Pepsi.png", cv::IMREAD_COLOR);
	if(cvImage.empty())
	{
		std::cerr << "Image load failed." << std::endl;

		exit(EXIT_FAILURE);
	}

	cv::Mat tempCvImage;
	cv::cvtColor(cvImage, tempCvImage, cv::COLOR_RGB2GRAY);

	qtImage = Mat2QImage(tempCvImage);
	tempCvImage = QImage2Mat(qtImage);

	cv::resize(tempCvImage, tempCvImage, cv::Size(), 1.5, 1.5);
	cv::imshow("OpenCV", tempCvImage);

	height = qtImage.height();
	width = qtImage.width();

	this->resize(width, height);
}

Picture::~Picture()
{
}

void Picture::paintEvent(QPaintEvent* e)
{
	Q_UNUSED(e);

	QPainter qp(this);
	drawPicture(&qp);
}

void Picture::drawPicture(QPainter* qp)
{
	qp->drawImage(0, 0, qtImage);
}

QImage Picture::Mat2QImage(cv::Mat const& src)
{
	cv::Mat temp;
	cv::cvtColor(src, temp, cv::COLOR_BGR2RGB);
	QImage dest((const uchar*)temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
	dest.bits();

	return dest;
}

cv::Mat Picture::QImage2Mat(QImage const& src)
{
	cv::Mat temp(src.height(), src.width(), CV_8UC3, (uchar*)src.bits(), src.bytesPerLine());
	cv::Mat result;
	cv::cvtColor(temp, result, cv::COLOR_BGR2RGB);

	return result;
}

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	Picture window;
	window.setWindowTitle("Qt");

	window.show();

	return app.exec();
}
