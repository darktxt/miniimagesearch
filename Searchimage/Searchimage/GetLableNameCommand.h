#pragma once
#include"BaseCommand.h"
class API;
class GetLableNameCommand : public BaseCommand
{
private:
	API* api;
public:
	GetLableNameCommand(API* api) : api(api) {}
	virtual shared_ptr<Data> reply(shared_ptr<Data>p = 0);
};
