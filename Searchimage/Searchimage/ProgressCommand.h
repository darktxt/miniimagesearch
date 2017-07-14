#pragma once
#include"BaseCommand.h"
class API;
class ProgressCommand : public BaseCommand
{
private:
	API* api;
public:
	ProgressCommand(API* api) : api(api) {}
	virtual shared_ptr<Data> reply(shared_ptr<Data>p = 0);
};