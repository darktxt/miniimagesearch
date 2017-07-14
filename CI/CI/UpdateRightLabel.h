#pragma once
#include"BaseCommand.h"
class API;
class UpdateRightLabel : public BaseCommand
{
private:
	API* api;
public:
	UpdateRightLabel(API* api) : api(api) {}
	virtual void exec(const shared_ptr<Data>p = 0);
};
