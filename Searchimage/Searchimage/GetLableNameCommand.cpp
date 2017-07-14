#include"GetLableNameCommand.h"
#include"API.h"

shared_ptr<Data> GetLableNameCommand::reply(shared_ptr<Data>p)
{
	this->p->S1 = api->GetLabelName();
	return this->p;
}