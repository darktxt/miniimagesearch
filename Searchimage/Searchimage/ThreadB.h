#pragma once
#include<QThread>
#include<signal.h>
#include"DataModel.h"
class ThreadB :public QThread 
{
	Q_OBJECT

public:
signals:
	void appear();
	void ifadd(bool);
public:
	void Set(DataModel *a);
	void run();
	void Set(QLabel *label) { L = label; }
private:
	DataModel *api;
	QLabel *L;
};