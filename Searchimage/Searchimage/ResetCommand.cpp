#include "ResetCommand.h"
#include"API.h"
void ResetCommand::exec(const shared_ptr<Data> p)
{
	api->Reset();
}
