#include "GetSetting.h"
#include"API.h"
shared_ptr<Data> GetSettingCommand::reply(shared_ptr<Data> p)
{
	this->p->Setting = api->Getsetting();
	return this->p;
}
