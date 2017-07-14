#include"Video.h"

float Video::similarity(array<float, 22> x1, array<float, 22> x2)
{
	float s1 = 0, s2 = 0, s3 = 0;
	float alpha1 = 0.5, alpha2 = 0.3, alpha3 = 0.2;
	for (int i = 0; i < 12; i++) {
		s1 += min(x1[i], x2[i]);
	}
	for (int i = 12; i < 17; i++) {
		s2 += min(x1[i], x2[i]);
	}
	for (int i = 17; i < 22; i++) {
		s3 += min(x1[i], x2[i]);
	}
	return s1*alpha1 + s2*alpha2 + s3*alpha3;
}

const array<float, 22> Video::GetOneFrameColor(bool& flag)
{
	uchar* h = new uchar[frameH * frameW];
	uchar* s = new uchar[frameH * frameW];
	uchar* v = new uchar[frameH * frameW];
	array<float, 22> color = {0};
	IplImage* frameimg;
	cvSetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES, position);
	frameimg= cvQueryFrame(capture); //获取一帧图片
	if (!frameimg)
	{
		flag = false;
		return color;
	}
	position += STEP;
	cvCvtColor(frameimg, frameimg, CV_BGR2HSV);
	uchar* data = (uchar *)frameimg->imageData;
	int step = frameimg->widthStep / sizeof(uchar);
	int channels = frameimg->nChannels;
	for (int i = 0; i < frameimg->height; i++) {
		for (int j = 0; j < frameimg->width; j++) {
			h[i*frameimg->height + j] = data[i*step + j*channels + 0] / 21;
			if (h[i*frameimg->height + j] > 11)h[i*frameimg->height + j] = 11;
			s[i*frameimg->height + j] = data[i*step + j*channels + 1] / 51;
			if (s[i*frameimg->height + j] > 4)s[i*frameimg->height + j] = 4;
			v[i*frameimg->height + j] = data[i*step + j*channels + 2] / 51;
			if (v[i*frameimg->height + j] > 4)v[i*frameimg->height + j] = 4;

			color[h[i*frameimg->height + j]]++;
			color[12 + s[i*frameimg->height + j]]++;
			color[17 + v[i*frameimg->height + j]]++;
		}
	}
	for (int i = 0; i < 22; i++) {
		color[i] /= frameimg->height*frameimg->width;
	}
	delete[] h;
	delete[] s;
	delete[] v;
	return color;
}

const array<float, 22> Video::GetOneFrameColor()
{
	uchar* h = new uchar[frameH * frameW];
	uchar* s = new uchar[frameH * frameW];
	uchar* v = new uchar[frameH * frameW];
	array<float, 22> color = { 0 };
	IplImage* frameimg;
	cvSetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES, position);
	frameimg = cvQueryFrame(capture); //获取一帧图片
	position += STEP;
	cvCvtColor(frameimg, frameimg, CV_BGR2HSV);
	uchar* data = (uchar *)frameimg->imageData;
	int step = frameimg->widthStep / sizeof(uchar);
	int channels = frameimg->nChannels;
	for (int i = 0; i < frameimg->height; i++) {
		for (int j = 0; j < frameimg->width; j++) {
			h[i*frameimg->height + j] = data[i*step + j*channels + 0] / 21;
			if (h[i*frameimg->height + j] > 11)h[i*frameimg->height + j] = 11;
			s[i*frameimg->height + j] = data[i*step + j*channels + 1] / 51;
			if (s[i*frameimg->height + j] > 4)s[i*frameimg->height + j] = 4;
			v[i*frameimg->height + j] = data[i*step + j*channels + 2] / 51;
			if (v[i*frameimg->height + j] > 4)v[i*frameimg->height + j] = 4;

			color[h[i*frameimg->height + j]]++;
			color[12 + s[i*frameimg->height + j]]++;
			color[17 + v[i*frameimg->height + j]]++;
		}
	}
	for (int i = 0; i < 22; i++) {
		color[i] /= frameimg->height*frameimg->width;
	}
	delete[] h;
	delete[] s;
	delete[] v;
	return color;
}

int Video::findMaxEntropyId(list<array<float, 22>> x, list<int> y)
{
	float s1, s2, s3, max;

	list<array<float, 22> >::iterator it;
	list<int>::iterator i = y.begin();
	int id = 0;

	for (it = x.begin(); it != x.end(); it++, i++) {
		s1 = 0.0f, s2 = 0.0f, s3 = 0.0f, max = 0.0f;
		for (int j = 0; j < 12; j++) {
			if ((*it)[j] != 0)s1 += -(*it)[j] * log((*it)[j]) / log(2);
		}
		for (int j = 12; j < 17; j++) {
			if ((*it)[j] != 0)s2 += -(*it)[j] * log((*it)[j]) / log(2);
		}
		for (int j = 17; j < 22; j++) {
			if ((*it)[j] != 0)s3 += -(*it)[j] * log((*it)[j]) / log(2);
		}
		float s = 0.5f*s1 + 0.3f*s2 + 0.2f*s3;
		//printf("s = %f\n", s);
		if (s>max) {
			max = s;
			id = *i;
		}
	}
	return id;
}

Video::Video() : capture(NULL)
{

}

Video::Video(string& videoName) : videoName(videoName), position(0)
{
	capture = cvCaptureFromAVI(videoName.c_str());
	fps = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);//视频的fps
	frameH = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);//视频的高度
	frameW = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);//视频的宽度
	totalFrame = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
	threshold = 0.8f;
	colorBefore = GetOneFrameColor();
}
Video::~Video()
{
	if (capture != NULL)
		cvReleaseCapture(&capture);
}
void Video::SetVideoName(const string& videoName)
{
	this->videoName = videoName;
	capture = cvCaptureFromAVI(videoName.c_str());
	position = 0;
	fps = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);//视频的fps
	frameH = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);//视频的高度
	frameW = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);//视频的宽度
	totalFrame = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
	threshold = 0.8f;
	colorBefore = GetOneFrameColor();
}

bool Video::HandleVideo(float& handleRatio,Mat& frame)
{
	IplImage* img = 0;//读入图像
	char image_name[100];//图像名字
	array<float, 22> color;
	float  ratio;
	list<array<float, 22> >content;
	list<int> number;
	bool flag = true;
	do
	{
		content.push_back(colorBefore);
		number.push_back(position - 2);
		color = GetOneFrameColor(flag);
		if (!flag)
			break;
		ratio = similarity(colorBefore, color);
		colorBefore = color;
	} while (ratio >= threshold);
	int id = findMaxEntropyId(content, number);
	cvSetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES, id);
	img = cvQueryFrame(capture);
	sprintf(image_name, "%s%d%s", "img", id, ".jpg");
	//cvSaveImage(image_name, img);
	handleRatio = (position * 1.0) / (totalFrame * 1.0);
	Mat(img).copyTo(frame);
	return flag;
}
const array<float, 22> operator +(const array<float, 22>  &x, const array<float, 22>  &y)
{
	array<float, 22>ans;
	for (int i = 0; i < 22; i++) {
		ans[i] = x[i] + y[i];
	}
	return ans;
}

const array<float, 22> operator /(const array<float, 22>  &x, int s)
{
	array<float, 22>ans;
	for (int i = 0; i < 22; i++) {
		ans[i] = x[i] / s;
	}
	return ans;
}


