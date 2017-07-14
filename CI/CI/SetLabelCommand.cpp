#include "SetLabelCommand.h"
#include"API.h"
shared_ptr<Data> SetLableCommand::reply(shared_ptr<Data> p)
{
	this->p->flag = api->SetLabel(this->p->L, this->p->S1);
	return this->p;
}