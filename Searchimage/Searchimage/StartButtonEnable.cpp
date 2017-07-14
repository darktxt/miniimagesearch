#include "StartButtonEnable.h"
#include"API.h"
shared_ptr<Data> StartButtonEnable::reply(shared_ptr<Data> p)
{
	this->p->flag = api->startButtonenabled();
	return this->p;
}
