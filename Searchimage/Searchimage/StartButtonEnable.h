#pragma once
#include"BaseCommand.h"
class API;
class StartButtonEnable : public BaseCommand
{
private:
	API* api;
public:
	StartButtonEnable(API* api) : api(api) {}
	virtual shared_ptr<Data> reply(shared_ptr<Data>p = 0);
};
