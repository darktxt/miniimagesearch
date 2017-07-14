#include "API.h"
#include"Tool.h"
#include<sstream>
void API::Start()
{
		B.start();
}
QString API::GetLabelName()
{
	string str = model->CurName();
	model->NextName();
	return QString::fromStdString(str);
}
bool API::SetLabel(QLabel *label, const QString &objectname)
{
	auto p = model->FindMat(objectname.toStdString());
	if (p != 0)
	{
		displayResult(label, *p);
		return true;
	}
	return false;
}
bool API::Save(const QString &objectname, const QString &path)
{
	auto p = model->FindMat(objectname.toStdString());
	if (p == 0)
		return false;
	return imwrite(path.toStdString(), *p);
}
void API::Save(const QString &path)
{
	model->Save(path.toStdString());
}
bool API::Loadleftlabel(QLabel *label, const QString &path)
{
	if (isPicture(path))
	{
		label->setPixmap(QPixmap(path).scaled(label->size()));//ÏÔÊ¾Í¼Æ¬  
		model->SetQuery(path.toStdString());
		model->leftvalid = true;
		//if (leftvalid&&rightvalid)
		//	startButton->setEnabled(true);
		return true;
	}
	return model->leftvalid = false;
}
bool API::Loadrightlabel(QLabel *label, const QString &path)
{
	bool &rightvalid=model->rightvalid;
	if (::isPicture(path))
	{
		label->setPixmap(QPixmap(path).scaled(label->size()));//ÏÔÊ¾Í¼Æ¬  
		model->SetTrain(path.toStdString());
		model->isvideo = false;
		rightvalid = true;
	}
	else if (::isVideo(path))
	{
		GetFirstMat(label, path);
		model->SetVideo(path.toStdString());
		model->isvideo = true;
		rightvalid = true;
	}
	else
		rightvalid = false;
	//if (leftvalid&&rightvalid)
	//	startButton->setEnabled(true);
	return rightvalid;
}
void API::SetBoard(QClipboard *Board, const QString &objectname)
{
	auto p = model->FindMat(objectname.toStdString());
	if (p != 0)
	{
		QImage temp = MattoQImage(*p);
		Board->setImage(MattoQImage(*p));
	}
}