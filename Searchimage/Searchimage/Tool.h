#pragma once
#include<qlabel.h>
#include<opencv2\opencv.hpp>
void displayResult(QLabel *resultImageLabel, const cv::Mat &image);
void GetFirstMat(QLabel *label, const QString &Filename);
QImage MattoQImage(const cv::Mat &image);
bool isPicture(const QString &FileName);
bool isVideo(const QString &FileName);