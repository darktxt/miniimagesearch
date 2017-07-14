#include "siftmatch.h"
#include<math.h>
imagematch::imagematch(string file) :D(0, 3, 0.04, 8.0)
{
	query_image = imread(file, 0);
	isnew = true;
}

imagematch::imagematch() :D(0, 3, 0.04, 8.0)
{
	isfit = false;
}



Mat & imagematch::Match(double ratio)
{
	isfit = false;
	train_keypoints.clear();
	vector<vector<DMatch>> matches;
	vector<DMatch> good_matches;
	if (isnew)
	{
		query_keypoints.clear();
		D.detect(query_image, query_keypoints);
		E.compute(query_image, query_keypoints, query_descriptors);
		isnew = false;
	}
	D.detect(train_image, train_keypoints);//提取特征点
	E.compute(train_image, train_keypoints, train_descriptors);//提取特征向量
	matcher.knnMatch(query_descriptors, train_descriptors, matches, 2);//每次匹配2个相近的特征值
	for (size_t i = 0; i < matches.size(); i++) //对所有的匹配特征值进行筛选
	{
		if (matches[i][0].distance < ratio*matches[i][1].distance)
		{
			good_matches.push_back(matches[i][0]);
		}
	}
	double max_dist = 0; double min_dist = 100;
	//-- Quick calculation of max and min distances between keypoints
	for (int i = 0; i < good_matches.size(); i++)
	{
		double dist = good_matches[i].distance;
		if (dist < min_dist) min_dist = dist;
		if (dist > max_dist) max_dist = dist;
	}
	std::vector< DMatch > verygood_matches;
	for (int i = 0; i < good_matches.size(); i++)
	{
		if (good_matches[i].distance < 3 * min_dist)
		{
			verygood_matches.push_back(good_matches[i]);
		}
	}
	std::vector<Point2f> query;
	std::vector<Point2f> train;
	for (int i = 0; i < verygood_matches.size(); i++)
	{
		//-- Get the keypoints from the good matches
		query.push_back(query_keypoints[verygood_matches[i].queryIdx].pt);
		train.push_back(train_keypoints[verygood_matches[i].trainIdx].pt);
	}
	if (train.size() < 5 || query.size() < 5)
	{
		isfit = false;
		return original_train_image;
	}
	Mat H = findHomography(query, train, CV_RANSAC);

	std::vector<Point2f> query_corners(4);
	query_corners[0] = cvPoint(0, 0); query_corners[1] = cvPoint(query_image.cols, 0);
	query_corners[2] = cvPoint(query_image.cols, query_image.rows); query_corners[3] = cvPoint(0, query_image.rows);
	std::vector<Point2f> train_corners(4);
	perspectiveTransform(query_corners, train_corners, H);
	//drawMatches(query_image, query_keypoints, train_image, train_keypoints, verygood_matches, match_image, \
		Scalar::all(-1), Scalar::all(-1), vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	//line(match_image, train_corners[0] + Point2f(query_image.cols, 0), train_corners[1] + Point2f(query_image.cols, 0), Scalar(0, 255, 0), 4);
	//line(match_image, train_corners[1] + Point2f(query_image.cols, 0), train_corners[2] + Point2f(query_image.cols, 0), Scalar(0, 255, 0), 4);
	//line(match_image, train_corners[2] + Point2f(query_image.cols, 0), train_corners[3] + Point2f(query_image.cols, 0), Scalar(0, 255, 0), 4);
	//line(match_image, train_corners[3] + Point2f(query_image.cols, 0), train_corners[0] + Point2f(query_image.cols, 0), Scalar(0, 255, 0), 4);
	//compute the area
	float l1 = pow((pow((train_corners[0].x - train_corners[1].x), 2) + pow((train_corners[0].y - train_corners[1].y), 2)), 0.5);
	float l2 = pow((pow((train_corners[1].x - train_corners[2].x), 2) + pow((train_corners[1].y - train_corners[2].y), 2)), 0.5);
	float l3 = pow((pow((train_corners[0].x - train_corners[2].x), 2) + pow((train_corners[0].y - train_corners[2].y), 2)), 0.5);
	float p1 = (l1 + l2 + l3) / 2;
	float S1 = pow((p1*(p1 - l1)*(p1 - l2)*(p1 - l3)), 0.5);
	float l4 = pow((pow((train_corners[2].x - train_corners[3].x), 2) + pow((train_corners[2].y - train_corners[3].y), 2)), 0.5);
	float l5 = pow((pow((train_corners[3].x - train_corners[0].x), 2) + pow((train_corners[3].y - train_corners[0].y), 2)), 0.5);
	float p2 = (l3 + l4 + l5) / 2;
	float S2 = pow((p2*(p2 - l3)*(p2 - l4)*(p2 - l5)), 0.5);
	float S = S1 + S2;
	if (S < train_image.rows*train_image.cols&&S>train_image.rows*train_image.cols / 10)
	{
		//if (train_corners[0].x<train_corners[1].x&&train_corners[2].x>train_corners[3].x&&train_corners[0].y < train_corners[3].y&&train_corners[1].y < train_corners[2].y)
			isfit = true;
	}
	if (isfit)
	{
		line(original_train_image, train_corners[0], train_corners[1], Scalar(0, 255, 0), 5);
		line(original_train_image, train_corners[1], train_corners[2], Scalar(0, 255, 0), 5);
		line(original_train_image, train_corners[2], train_corners[3], Scalar(0, 255, 0), 5);
		line(original_train_image, train_corners[3], train_corners[0], Scalar(0, 255, 0), 5);
	}
	return original_train_image;
}

bool imagematch::SetQuery(string file)
{
	query_image = imread(file, 0);
	isnew = true;
	return true;
}

bool imagematch::SetTrain(string file)
{
	original_train_image = imread(file);
	train_image = imread(file, 0);
	return true;
}

bool imagematch::SetTrain(Mat & train_image)
{
	train_image.copyTo(original_train_image);
	cvtColor(original_train_image, this->train_image, CV_BGR2GRAY);
	return true;
}
