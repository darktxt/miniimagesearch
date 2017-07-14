#include "JudgeIsRunningCommand.h"
#include"API.h"

shared_ptr<Data> JudgeRunningCommand::reply(shared_ptr<Data> p)
{
	this->p->flag = api->isRunning();
	return this->p;
}