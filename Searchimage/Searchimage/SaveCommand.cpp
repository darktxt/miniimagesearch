#include "SaveCommand.h"
#include"API.h"
void SaveCommand::exec(const shared_ptr<Data> p)
{
	api->Save(p->S1);
}

shared_ptr<Data> SaveCommand::reply(shared_ptr<Data> p)
{
	this->p->flag = api->Save(this->p->S1, this->p->S2);
	return this->p;
}
