#pragma once
#include"BaseCommand.h"
class API;
class SaveCommand: public BaseCommand
{
private:
	API* api;
public:
	SaveCommand(API* api) : api(api) {}
	virtual void exec(const shared_ptr<Data>p = 0);
	virtual shared_ptr<Data> reply(shared_ptr<Data>p = 0);

};