#include "LoadRightLableCommand.h"
#include"API.h"
shared_ptr<Data> LoadRightLableCommand::reply(shared_ptr<Data> p)
{
	this->p->flag = api->Loadrightlabel(this->p->L, this->p->S1);
	return this->p;
}
