#pragma once
#include"BaseCommand.h"
class API;
class SetBoardCommand : public BaseCommand
{
private:
	API* api;
public:
	SetBoardCommand(API* api) : api(api) {}
	virtual void exec(const shared_ptr<Data>p = 0);
};
