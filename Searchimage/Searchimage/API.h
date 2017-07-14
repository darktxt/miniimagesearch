#pragma once
#include"siftmatch.h"
#include"Video.h"
#include<qlabel.h>
#include<list>
#include<map>
#include<qpushbutton.h>
#include"ThreadB.h"
#include"qclipboard.h"
#include<memory>
#include"command.h"
class API
{
private:
	ThreadB B;
	DataModel* model;
public:
	ThreadB* GetThreadB() { return &B; }
	void Set(DataModel* M) { model = M; B.Set(M); }
	bool isRunning() { return B.isRunning(); }
	void Quit() { B.terminate(); }
	QString GetLabelName();
	bool SetLabel(QLabel *label, const QString &objectname);
	bool Loadleftlabel(QLabel *label, const QString &path);
	bool Loadrightlabel(QLabel *label, const QString &path);
	bool Save(const QString &objectname, const QString &path);
	void Save(const QString &path);
	void Reset() { model->ReSet(); }
	void Start();
	void Updaterightlabel(QLabel *L) { displayResult(L, model->pic); }
	int Progress() { return 100 * model->hanleratio; }
	void SetBoard(QClipboard *Board,const QString &objectname);
	DataModel::Setting Getsetting() { return model->setting; }
	void Set(DataModel::Setting set) { model->Set(set); }
	bool isVideo() { return model->isvideo; }
	bool startButtonenabled() { return model->leftvalid&&model->rightvalid; }

	API()
	{
		stcom = static_pointer_cast<BaseCommand, StartCommand>(shared_ptr<StartCommand>(new StartCommand(this)));
		glncom = static_pointer_cast<BaseCommand, GetLableNameCommand>(shared_ptr<GetLableNameCommand>(new GetLableNameCommand(this)));
		slcom = static_pointer_cast<BaseCommand, SetLableCommand>(shared_ptr<SetLableCommand>(new SetLableCommand(this)));
		scom = static_pointer_cast<BaseCommand, SaveCommand>(shared_ptr<SaveCommand>(new SaveCommand(this)));
		lllcom = static_pointer_cast<BaseCommand, LoadLeftLableCommand>(shared_ptr<LoadLeftLableCommand>(new LoadLeftLableCommand(this)));
		lrlcom = static_pointer_cast<BaseCommand, LoadRightLableCommand>(shared_ptr<LoadRightLableCommand>(new LoadRightLableCommand(this)));
		sbcom = static_pointer_cast<BaseCommand, SetBoardCommand>(shared_ptr<SetBoardCommand>(new SetBoardCommand(this)));
		gscom = static_pointer_cast<BaseCommand, GetSettingCommand>(shared_ptr<GetSettingCommand>(new GetSettingCommand(this)));
		pgcom = static_pointer_cast<BaseCommand, ProgressCommand>(shared_ptr<ProgressCommand>(new ProgressCommand(this)));
		urcom = static_pointer_cast<BaseCommand, UpdateRightLabel>(shared_ptr<UpdateRightLabel>(new UpdateRightLabel(this)));
		rscom = static_pointer_cast<BaseCommand, ResetCommand>(shared_ptr<ResetCommand>(new ResetCommand(this)));
		setcom = static_pointer_cast<BaseCommand, SetCommand>(shared_ptr<SetCommand>(new SetCommand(this)));
		sbecom = static_pointer_cast<BaseCommand, StartButtonEnable>(shared_ptr<StartButtonEnable>(new StartButtonEnable(this)));
		jrcom = static_pointer_cast<BaseCommand, JudgeRunningCommand>(shared_ptr<JudgeRunningCommand>(new JudgeRunningCommand(this)));
		qcom = static_pointer_cast<BaseCommand, QuitCommand>(shared_ptr<QuitCommand>(new QuitCommand(this)));
	}
public:
	shared_ptr<BaseCommand> stcom;
	shared_ptr<BaseCommand>  glncom;
	shared_ptr<BaseCommand>  slcom;
	shared_ptr<BaseCommand>  scom;
	shared_ptr<BaseCommand>  lllcom;
	shared_ptr<BaseCommand>  lrlcom;
	shared_ptr<BaseCommand>  sbcom;
	shared_ptr<BaseCommand>  gscom;
	shared_ptr<BaseCommand>  pgcom;
	shared_ptr<BaseCommand>  urcom;
	shared_ptr<BaseCommand>  rscom;
	shared_ptr<BaseCommand>  setcom;
	shared_ptr<BaseCommand>  sbecom;
	shared_ptr<BaseCommand>  jrcom;
	shared_ptr<BaseCommand>  qcom;
};

