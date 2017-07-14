#pragma once
#include"BaseCommand.h"
class API;
class QuitCommand: public BaseCommand
{
private:
	API* api;
public:
	QuitCommand(API* api) : api(api) {}
	virtual void exec(const shared_ptr<Data>p = 0);
};
