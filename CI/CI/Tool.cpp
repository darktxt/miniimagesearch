#include"Tool.h"
#include"qdebug.h"
QImage MattoQImage(const cv::Mat &mat)
{
	using namespace cv;
	// 8-bits unsigned, NO. OF CHANNELS = 1  
	if (mat.type() == CV_8UC1)
	{
		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
		// Set the color table (used to translate colour indexes to qRgb values)  
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		// Copy input Mat  
		uchar *pSrc = mat.data;
		for (int row = 0; row < mat.rows; row++)
		{
			uchar *pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mat.cols);
			pSrc += mat.step;
		}
		return image;
	}
	// 8-bits unsigned, NO. OF CHANNELS = 3  
	else if (mat.type() == CV_8UC3)
	{
		// Copy input Mat  
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat  
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return image.rgbSwapped();
	}
	else if (mat.type() == CV_8UC4)
	{
		qDebug() << "CV_8UC4";
		// Copy input Mat  
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat  
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
		return image.copy();
	}
	else
	{
		qDebug() << "ERROR: Mat could not be converted to QImage.";
		return QImage();
	}
}
void displayResult(QLabel *resultImageLabel, const cv::Mat &image)
{
	using namespace cv;
	Mat rgb;
	QImage scaledImg;
	QImage img;
	if (image.channels() == 3)    // RGB image
	{
		cvtColor(image, rgb, CV_BGR2RGB);
		img = QImage((const uchar*)(rgb.data),  //(const unsigned char*)
			rgb.cols, rgb.rows,
			rgb.cols*rgb.channels(),   //解决Mat图像与QImage图像不对齐问题
			QImage::Format_RGB888);
		scaledImg = img.scaled(resultImageLabel->size(), Qt::IgnoreAspectRatio);
	}
	else {                     // gray imag  
		img = QImage((const uchar*)(image.data),
			image.cols, image.rows,
			image.cols*image.channels(),    //解决Mat图像与QImage图像不对齐问题
			QImage::Format_Indexed8);
		scaledImg = img.scaled(resultImageLabel->size(), Qt::IgnoreAspectRatio);
	}
	resultImageLabel->setPixmap(QPixmap::fromImage(scaledImg));
	//resultImageLabel->show();
}
void GetFirstMat(QLabel *label,const QString &Filename)
{
	using namespace cv;
	Mat srcImage;
	VideoCapture videoCap(Filename.toStdString());
	videoCap.set(CV_CAP_PROP_POS_FRAMES, 100);
	videoCap >> srcImage;
	displayResult(label, srcImage);
}
bool isPicture(const QString &FileName)
{
	if (!FileName.right(3).compare("jpg")
		|| !FileName.right(3).compare("png"))
		return true;
	return false;
}
bool isVideo(const QString &FileName)
{
	if (!FileName.right(3).compare("avi")
		|| !FileName.right(3).compare("mp4"))
		return true;
	return false;
}