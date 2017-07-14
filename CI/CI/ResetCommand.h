#pragma once
#include"BaseCommand.h"
class API;
class ResetCommand : public BaseCommand
{
private:
	API* api;
public:
	ResetCommand(API* api) : api(api) {}
	virtual void exec(const shared_ptr<Data>p = 0);
};
