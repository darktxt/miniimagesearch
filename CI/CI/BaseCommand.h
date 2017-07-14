#pragma once
#include<memory>
#include<qlabel.h>
#include"DataModel.h"

using namespace std;
class Data {
public:
	bool flag;
	int progress;
	QLabel* L;
	QString S1;
	QString S2;
	QClipboard *board;
	DataModel::Setting Setting;
};
class BaseCommand {
public:
	shared_ptr<Data>p;
	BaseCommand() { p = shared_ptr<Data>(new Data); }
	virtual void exec(const shared_ptr<Data>p = 0) {};
	virtual shared_ptr<Data> reply(shared_ptr<Data>p = 0) { return p; }
	virtual ~BaseCommand(){}
};