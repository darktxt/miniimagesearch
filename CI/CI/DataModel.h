#pragma once
#include"siftmatch.h"
#include"Video.h"
#include<qlabel.h>
#include<list>
#include<map>
#include"Tool.h"
class ThreadB;
class API;
class DataModel
{
public:
	struct Setting
	{
		enum { JPG, PNG };
		int ratio;
		int threshold;
		int format;
		Setting(int r = 0, int t = 0, int f = 0) :ratio(r), threshold(t), format(f) {}
	};
private:
	std::map<std::string, cv::Mat> Result;
	std::map<int, std::string> Postfix;
	imagematch match;
	Video video;
	float hanleratio;
	Mat pic;
	Setting setting;
	bool isvideo;
	int count;
	bool leftvalid;
	bool rightvalid;
public:
	DataModel();
	void SetQuery(const std::string &FileName) { match.SetQuery(FileName); }
	void SetTrain(const std::string &FileName) { match.SetTrain(FileName); }
	void SetVideo(const std::string &FileName) { video.SetVideoName(FileName); }
	//const Mat* GetResult();
	Mat* FindMat(const std::string &str);
	void Save(const std::string &FileName);
	void ReSet() { Result.clear(); count = 0; }
	Setting Getsetting() { return setting; }
	void Set(Setting set) { setting = set; video.SetThreshold(setting.threshold*1.0 / 100);}
	string CurName();
	void NextName() { ++count; }
	friend class ThreadB;
	friend class API;
};

