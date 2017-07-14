#include "UpdateRightLabel.h"
#include"API.h"
void UpdateRightLabel::exec(const shared_ptr<Data> p)
{
	api->Updaterightlabel(this->p->L);
}
