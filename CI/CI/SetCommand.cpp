#include "SetCommand.h"
#include"API.h"
void SetCommand::exec(const shared_ptr<Data> p)
{
	api->Set(this->p->Setting);
}
