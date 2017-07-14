#include "ThreadB.h"
#include"Tool.h"
//#include"DataModel.h"
void ThreadB::Set(DataModel * a)
{
	 api = a;
}

void ThreadB::run()
{
	if (!api->isvideo)
	{
		api->match.Match(api->setting.ratio*1.0 / 100);
		if (api->match.GetResult())
		{
			api->match.GetMatchImage().copyTo(api->Result[api->CurName()]);
			emit ifadd(true);
		}
		else
			emit ifadd(false);
		return;
	}
	bool flag;
	do
	{
		flag = api->video.HandleVideo(api->hanleratio, api->pic);
		emit appear();
		api->match.SetTrain(api->pic);
		api->match.Match(api->setting.ratio*1.0/100);
		if (api->match.GetResult())
		{
			api->match.GetMatchImage().copyTo(api->Result[api->CurName()]);
			emit ifadd(true);
		}
		else
			emit ifadd(false);
	} while (flag);
}
