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
	float threshold;					 //��ֵ
	int totalFrame;
	CvCapture* capture;
	array<float, 22> colorBefore; //���ڼ�¼֮ǰ����ɫ

	float similarity(array<float, 22>  x1, array<float, 22>  x2);//��֡�����ƶȣ� �ٷֱ�
	const array<float,22>  GetOneFrameColor(bool& flag);//�õ�һ֡����ɫ��Ϣ
	const array<float, 22>  GetOneFrameColor();//�õ�һ֡����ɫ��Ϣ
	int findMaxEntropyId(list<array<float, 22> >x, list<int> y); //Ѱ�����������֡
public:
	Video();
	Video(string& videoName);
	~Video();
	void SetVideoName(const string& videoName);
	bool HandleVideo(float& handleRatio,Mat& frame);// handleRatio ��ǰ�������
	void SetThreshold(float threshold = 0.8)  //������ֵ
	{
		this->threshold = threshold;
	}
};
const array<float, 22> operator +(const array<float, 22>  &x, const array<float, 22>  &y);
const array<float, 22> operator /(const array<float, 22>  &x, int s);
#endif
