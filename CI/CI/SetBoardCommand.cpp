#include "SetBoardCommand.h"
#include"API.h"
void SetBoardCommand::exec(const shared_ptr<Data> p)
{
	api->SetBoard(this->p->board, this->p->S1);
}
