#pragma once
#include"BaseCommand.h"
class API;
class SetCommand : public BaseCommand
{
private:
	API* api;
public:
	SetCommand(API* api) : api(api) {}
	virtual void exec(const shared_ptr<Data>p = 0);
};
