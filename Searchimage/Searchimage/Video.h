#ifndef VIDEO_H
#define VIDEO_H
#include <opencv2/opencv.hpp>
#include<string>
#include<io.h>
#include<list>
#include<array>
using namespace std;
using namespace cv;
class Video
{
private:
	static const int STEP = 2;
	string videoName;
	int position;
	int fps;
	int frameH;
	int frameW;							
	float threshold;					 //阈值
	int totalFrame;
	CvCapture* capture;
	array<float, 22> colorBefore; //用于记录之前的颜色

	float similarity(array<float, 22>  x1, array<float, 22>  x2);//两帧的相似度， 百分比
	const array<float,22>  GetOneFrameColor(bool& flag);//得到一帧的颜色信息
	const array<float, 22>  GetOneFrameColor();//得到一帧的颜色信息
	int findMaxEntropyId(list<array<float, 22> >x, list<int> y); //寻找最大熵所在帧
public:
	Video();
	Video(string& videoName);
	~Video();
	void SetVideoName(const string& videoName);
	bool HandleVideo(float& handleRatio,Mat& frame);// handleRatio 当前处理比例
	void SetThreshold(float threshold = 0.8)  //设置阈值
	{
		this->threshold = threshold;
	}
};
const array<float, 22> operator +(const array<float, 22>  &x, const array<float, 22>  &y);
const array<float, 22> operator /(const array<float, 22>  &x, int s);
#endif
