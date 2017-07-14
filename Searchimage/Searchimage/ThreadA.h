#pragma once
#include"DataModel.h"
#include<QtWidgets\qmainwindow.h>
#include<QThread>
#include<qlabel.h>
class ThreadA :public QThread
{
private:
	QLabel *L;
	DataModel *pmodel;
public:
	void Set(DataModel *pmodel)
	{
		this->pmodel = pmodel;
	}
	void run()
	{
		pmodel->match.Match(pmodel->setting.ratio*1.0 / 100);
		//displayResult(L, *(pmodel->GetResult()));
	}
};