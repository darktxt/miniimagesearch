#include "QuitCommand.h"
#include"API.h"
void QuitCommand::exec(const shared_ptr<Data> p)
{
	api->Quit();
}
