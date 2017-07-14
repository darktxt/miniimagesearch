#include "mainwindow.h"
#include"API.h"
#include<signal.h>
#include<qlayout.h>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	API api;
	MainWindow w;
	DataModel model;
	api.Set(&model);
	w.Quit = api.qcom;
	w.JudgeIsRunning = api.jrcom;
	w.startButtonenabled = api.sbecom;
	w.Loadleftlabel = api.lllcom;
	w.Loadrightlabel = api.lrlcom;
	w.SetLabel = api.slcom;
	w.Set = api.setcom;
	w.GetLabelName = api.glncom;
	w.Start = api.stcom;
	w.Reset = api.rscom;
	w.Save = api.scom;
	w.SetBoard = api.sbcom;
	w.Updaterightlabel = api.urcom;
	w.Progress = api.pgcom;
	w.GetSetting = api.gscom;
	QObject::connect(api.GetThreadB(), &ThreadB::ifadd, &w, &MainWindow::videotask);
	QObject::connect(api.GetThreadB(), &ThreadB::appear, &w, &MainWindow::appeartask);
	QObject::connect(api.GetThreadB(), SIGNAL(finished()), &w, SLOT(initstartButton()));
	w.show();
	return a.exec();
}
