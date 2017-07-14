#include "LoadLeftLableCommand.h"
#include"API.h"
shared_ptr<Data> LoadLeftLableCommand::reply(shared_ptr<Data> p)
{
	this->p->flag = api->Loadleftlabel(this->p->L, this->p->S1);
	return this->p;
}
