#pragma once
#include"BaseCommand.h"
class API;
class SetLableCommand : public BaseCommand
{
private:
	API* api;
public:
	SetLableCommand(API* api) : api(api) {}
	virtual shared_ptr<Data> reply(shared_ptr<Data>p = 0);
};