#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QFileDialog>
#include<QDragEnterEvent>  
#include<QMimeData>  
#include<QDropEvent>  
#include<QUrl>  
//#include"API.h"
#include"Tool.h"
#include"qmetaobject.h"
#include<QThread>
#include "settingDialog.h"
#include"BaseCommand.h"
#include"ThreadB.h"
#include<qlabel.h>
#include<qpushbutton.h>

class MainWindow : public QMainWindow,public Ui::MainWindowClass
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	void addScrollArea(QLabel *p);
	shared_ptr<BaseCommand>  JudgeIsRunning;
	shared_ptr<BaseCommand>  Quit;
	shared_ptr<BaseCommand>  startButtonenabled;
	shared_ptr<BaseCommand>  Loadleftlabel;
	shared_ptr<BaseCommand>  Loadrightlabel;
	shared_ptr<BaseCommand>  SetLabel;
	shared_ptr<BaseCommand>  Set;
	shared_ptr<BaseCommand>  GetLabelName;
	shared_ptr<BaseCommand>  Start;
	shared_ptr<BaseCommand>  Reset;
	shared_ptr<BaseCommand>  Save;
	shared_ptr<BaseCommand>  SetBoard;
	shared_ptr<BaseCommand> Updaterightlabel;
	shared_ptr<BaseCommand> Progress;
	shared_ptr<BaseCommand> GetSetting;
public slots:
	void appeartask();
	void videotask(bool ifadd);
protected:
	void dragEnterEvent(QDragEnterEvent*event);
	void dropEvent(QDropEvent*event);
	void mousePressEvent(QMouseEvent*event);
	void mouseDoubleClickEvent(QMouseEvent*event);
private slots:
	void on_startButton_clicked();
	void on_clearButton_clicked();
	void on_actionAbout_triggered();
	void on_actionSave_triggered();
	bool on_actionMatched_triggered();
	bool on_actionMatching_triggered();
	void initstartButton()
	{
		startButton->setEnabled(false);
		startButton->setText("&Start");
	}
	void on_actionQuit_triggered()
	{
		//api->Quit();
		Quit->exec();
	}
	void on_actionPreferences_triggered();
	void saveoutput();
	void copy();
	void paste();
	bool isRunning() { return JudgeIsRunning->reply()->flag;/*B线程是否运行*/ }
private:
	//API* api;
	settingDialog *setting;
	QAction *actionSaveoutput;
	QAction *actionCopy;
	QAction *actionPasteLeft;
	QAction *actionPasteRight;
	QClipboard *board;
	int count;
	bool video;
	bool rightvalid;
	bool leftvalid;
	void ShowPicture(const QPixmap &pic);
	void ShowMat(const Mat *pic);
	void createActions();
	QLabel* newLabel();
};
