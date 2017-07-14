#pragma once
#include"BaseCommand.h"
class API;
class LoadRightLableCommand : public BaseCommand
{
private:
	API* api;
public:
	LoadRightLableCommand(API* api) : api(api) {}
	virtual shared_ptr<Data> reply(shared_ptr<Data>p = 0);
};
