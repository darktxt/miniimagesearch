#pragma once
#include"BaseCommand.h"
class API;
class JudgeRunningCommand : public BaseCommand
{
private:
	API* api;
public:
	JudgeRunningCommand(API* api) : api(api) {}
	virtual shared_ptr<Data> reply(shared_ptr<Data>p = 0);
};
