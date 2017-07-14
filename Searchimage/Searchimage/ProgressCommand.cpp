#include "ProgressCommand.h"
#include"API.h"
shared_ptr<Data> ProgressCommand::reply(shared_ptr<Data> p)
{
	this->p->progress = api->Progress();
	return this->p;
}
