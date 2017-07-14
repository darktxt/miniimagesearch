#include"Tool.h"
#include<sstream>
#include"DataModel.h"
DataModel::DataModel()
{
	Postfix[Setting::JPG] = ".jpg";
	Postfix[Setting::PNG] = ".png";
	setting.ratio = 70;
	setting.threshold = 80;
	isvideo=false;
	count=0;
	leftvalid = false;
	rightvalid = false;
}
Mat* DataModel::FindMat(const std::string &str)
{
	auto p = Result.find(str);
	if (p != Result.end())
	{
		return &(p->second);
	}
	return 0;
}
void DataModel::Save(const std::string &FileName)
{
	using namespace std;
	stringstream ss;
	string str;
	int i = 0;
	for (auto p = Result.begin(); p != Result.end(); ++p, ++i)
	{
		ss << i;
		ss >> str;
		ss.clear();
		imwrite(FileName + "//" + str + Postfix[setting.format], p->second);
	}
}
string DataModel::CurName()
{
	using namespace std;
	stringstream ss;
	string str;
	ss << count;
	ss >> str;
	return "result" + str;
}
