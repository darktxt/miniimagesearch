#pragma once
#include"BaseCommand.h"
class API;
class GetSettingCommand : public BaseCommand
{
private:
	API* api;
public:
	GetSettingCommand(API* api) : api(api) {}
	virtual shared_ptr<Data> reply(shared_ptr<Data>p = 0);
};