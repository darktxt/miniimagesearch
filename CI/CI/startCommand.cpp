#include "startCommand.h"
#include"API.h"
void StartCommand::exec(const shared_ptr<Data> p)
{
	api->Start();
}
