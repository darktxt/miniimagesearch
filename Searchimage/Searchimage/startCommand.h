#pragma once
#include"BaseCommand.h"
class API;
class StartCommand: public BaseCommand
{
private:
	API* api;
public:
	StartCommand(API* api) : api(api) {}
	virtual void exec(const shared_ptr<Data>p = 0);
};
