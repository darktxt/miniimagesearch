#pragma once
#include"BaseCommand.h"
class API;
class LoadLeftLableCommand: public BaseCommand
{
private:
	API* api;
public:
	LoadLeftLableCommand(API* api) : api(api) {}
	virtual shared_ptr<Data> reply(shared_ptr<Data>p = 0);
};
