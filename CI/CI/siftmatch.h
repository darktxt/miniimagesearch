#pragma once
#include<opencv2\opencv.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\features2d.hpp>
#include<opencv2\nonfree\nonfree.hpp>
#include<ostream>

using namespace cv;
class imagematch {
public:
	imagematch(string file);
	imagematch();
private:
	string file;
	Mat original_train_image;
	Mat query_image;
	Mat train_image;
	//Mat match_image;
	vector<KeyPoint> train_keypoints;
	vector<KeyPoint> query_keypoints;
	Mat train_descriptors;//no clear
	Mat query_descriptors;//no clear
	SiftFeatureDetector D;
	SiftDescriptorExtractor E;
	BFMatcher matcher;
	bool isnew;
	bool isfit;
public:
	Mat& Match(double ratio = 0.8);
	bool SetQuery(string file);
	bool SetTrain(string file);
	bool SetTrain(Mat& train_image);
	bool GetResult() { return isfit; }
	const Mat& GetQueryImage()const { return query_image; }
	const Mat& GetMatchImage()const { return original_train_image; }
	const Mat& GetTrainImage()const { return train_image; }
};