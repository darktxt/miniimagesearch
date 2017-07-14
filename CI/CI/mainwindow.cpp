#include "mainwindow.h"
#include<qlayout.h>
#include"Tool.h"
#include"qmessagebox.h"
#include"qclipboard.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), count(0)
{
	setupUi(this);
	createActions();
	rightvalid = leftvalid = false;
	startButton->setEnabled(false);
	setting = new settingDialog;
	board = QApplication::clipboard();
	progressBar->setRange(0, 100);
	progressBar->setValue(0);
	leftlabel->addAction(actionPasteLeft);
	leftlabel->setContextMenuPolicy(Qt::ActionsContextMenu);
	rightlabel->addAction(actionPasteRight);
	rightlabel->setContextMenuPolicy(Qt::ActionsContextMenu);
	//A.Set(&api, scrollArea);
	layout()->setSizeConstraint(QLayout::SetFixedSize);
	//B.Set(&api);
}
void MainWindow::createActions()
{
	actionCopy = new QAction(tr("&Copy"), this);
	actionCopy->setIcon(QIcon(":/MainWindow/Resources/copy.png"));
	actionCopy->setShortcut(QKeySequence::Copy);
	actionCopy->setStatusTip(tr("Copy the current selection's contents "
		"to the clipboard"));
	connect(actionCopy, SIGNAL(triggered()), this, SLOT(copy()));

	actionPasteLeft = new QAction(tr("&Paste"), this);
	actionPasteLeft->setIcon(QIcon(":/MainWindow/Resources/paste.png"));
	actionPasteLeft->setShortcut(QKeySequence::Paste);
	actionPasteLeft->setStatusTip(tr("Paste the clipboard's contents"));
	connect(actionPasteLeft, SIGNAL(triggered()),this, SLOT(paste()));

	actionPasteRight = new QAction(tr("&Paste"), this);
	actionPasteRight->setIcon(QIcon(":/MainWindow/Resources/paste.png"));
	actionPasteRight->setShortcut(QKeySequence::Paste);
	actionPasteRight->setStatusTip(tr("Paste the clipboard's contents"));
	connect(actionPasteRight, SIGNAL(triggered()), this, SLOT(paste()));

	actionSaveoutput = new QAction(tr("Save"), this);
	actionSaveoutput->setIcon(QIcon(":/MainWindow/Resources/save.png"));
	actionSaveoutput->setStatusTip(tr("Save"));
	connect(actionSaveoutput, SIGNAL(triggered()), this, SLOT(saveoutput()));

	actionPreferences->setShortcut(QKeySequence::Preferences);
	actionSave->setShortcut(QKeySequence::Save);
	actionQuit->setShortcut(QKeySequence::Quit);
	connect(actionAboutQT, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}
void MainWindow::addScrollArea(QLabel *p)
{
	auto layout = scrollArea->widget()->layout();
	if(layout==0)
		layout = new QHBoxLayout;
	layout->addWidget(p);
	scrollArea->widget()->setLayout(layout);
}
void MainWindow::dragEnterEvent(QDragEnterEvent*event) 
{
	if (isRunning())
		return;
	if(isVideo(event->mimeData()->urls()[0].fileName())|| isPicture(event->mimeData()->urls()[0].fileName()))
		event->acceptProposedAction();
	else
		event->ignore();
}
void MainWindow::dropEvent(QDropEvent*event) 
{
	const QMimeData*qm = event->mimeData();
	if (isRunning())
	{
		event->ignore();
		return;
	}
	if (childAt(event->pos()) != NULL && !childAt(event->pos())->objectName().compare("leftlabel"))
	{
		//api->Loadleftlabel(leftlabel,qm->urls()[0].toLocalFile());
		Loadleftlabel->p->L = leftlabel;
		Loadleftlabel->p->S1 = qm->urls()[0].toLocalFile();
		Loadleftlabel->reply(Loadleftlabel->p);
		startButton->setEnabled(startButtonenabled->reply()->flag);
	}
	else if (childAt(event->pos()) != NULL && !childAt(event->pos())->objectName().compare("rightlabel"))
	{
		//api->Loadrightlabel(rightlabel, qm->urls()[0].toLocalFile());
		Loadrightlabel->p->L = rightlabel;
		Loadrightlabel->p->S1 = qm->urls()[0].toLocalFile();
		Loadrightlabel->reply(Loadrightlabel->p);
		startButton->setEnabled(startButtonenabled->reply()->flag);
	}
	else
		event->ignore();
}
void MainWindow::mousePressEvent(QMouseEvent*event)
{
	if (event->button() != Qt::LeftButton)
		return;
	auto pos = event->pos();
	auto curwidget = childAt(event->pos());
	if (curwidget == 0)
		return;
	QLabel *L = new QLabel;
	//if (api->SetLabel(L, curwidget->objectName()))
		//L->show();
	SetLabel->p->L = L;
	SetLabel->p->S1 = curwidget->objectName();
	if(SetLabel->reply(SetLabel->p)->flag)
		L->show();
	else
		delete L;

}
void MainWindow::mouseDoubleClickEvent(QMouseEvent*event)
{
	if (isRunning())
	{
		event->ignore();
		return;
	}
	if (childAt(event->pos()) != NULL && !childAt(event->pos())->objectName().compare("leftlabel"))
	{
		on_actionMatched_triggered();
	}
	else if (childAt(event->pos()) != NULL && !childAt(event->pos())->objectName().compare("rightlabel"))
	{
		on_actionMatching_triggered();
	}
	else
		event->ignore();
}
void MainWindow::on_actionPreferences_triggered()
{
	if (isRunning())
		return;
	setting->SetDialog(GetSetting->reply()->Setting);
	if (setting->exec())
	{
		//api->Set(setting->Setting());
		Set->p->Setting = setting->Setting();
		Set->exec(Set->p);
	}
	if (setting->isApply())
	{
		setting->setApply(false);
		//api->Set(setting->GetApply());
		Set->p->Setting = setting->GetApply();
		Set->exec(Set->p);
	}
}
void MainWindow::on_actionAbout_triggered()
{
	QMessageBox::about(this, tr("About SearchImage"),
		tr("<h2>SearchImage 1.0</h2>"
			"<p>Copyright &copy; 2017 Software Inc."
			"<p>SearchImage is a small application used to analyse videos and to match frames with the given image."
			"<p>By ZL,Stan and LB"));
}
QLabel* MainWindow::newLabel()
{
	QLabel *L = new QLabel;
	L->setObjectName(GetLabelName->reply()->S1);
	L->addAction(actionCopy);
	L->addAction(actionSaveoutput);
	L->setContextMenuPolicy(Qt::ActionsContextMenu);
	L->setFixedSize(QSize(300, 200));
	++count;
	return L;
}
void MainWindow::on_startButton_clicked()
{
	if (isRunning())
	{
		Quit->exec();
		startButton->setText("&Start");
		startButton->setEnabled(false);
		return;
	}
	startButton->setText("&Stop");
	Start->exec();
}
void MainWindow::on_clearButton_clicked()
{
	if (isRunning())
		return;
	Reset->exec();
	startButton->setText("&Start");
	auto layout = scrollArea->widget()->layout();
	while (auto child = layout->takeAt(0)) 
	{
		auto p = child->widget();
		delete p;
	}
	progressBar->setValue(0);
	scrollArea->update();
}
void MainWindow::on_actionSave_triggered()
{
	QString fileName = QFileDialog::getExistingDirectory(this,tr("Save Result"), ".");
	if (fileName.isEmpty())
		return;
	Save->p->S1 = fileName;
	Save->exec(Save->p);
}
bool MainWindow::on_actionMatched_triggered()
{
	if (isRunning())
		return false;
	QString fileName = QFileDialog::getOpenFileName(this,tr("Open Picture"), ".",
											tr("Picture(*.png;*.jpg;*.ico)\nAll(*)"));
	if (!fileName.isEmpty())
	{
		Loadleftlabel->p->L = leftlabel;
		Loadleftlabel->p->S1 = fileName;
		bool temp = Loadleftlabel->reply(Loadleftlabel->p)->flag;
		startButton->setEnabled(startButtonenabled->reply()->flag);
		return temp;
	}
	return false;
}
bool MainWindow::on_actionMatching_triggered()
{
	if (isRunning())
		return false;
	QString fileName = QFileDialog::getOpenFileName(this, tr("picture"), ".",
		tr("Picture(*.png;*.jpg;*.ico)\n"
			"Video(*.avi;*.mp4)\n"
		"All(*)"));
	if (!fileName.isEmpty())
	{
		Loadrightlabel->p->L = rightlabel;
		Loadrightlabel->p->S1 = fileName;
		bool temp = Loadrightlabel->reply(Loadrightlabel->p)->flag;
		startButton->setEnabled(startButtonenabled->reply()->flag);
		return temp;
	}
	return false;
}
void MainWindow::ShowMat(const Mat *pic)
{
	QLabel *label = new QLabel;
	displayResult(label, *pic);
	label->setFixedSize(label->sizeHint());
	label->show();
}
void MainWindow::ShowPicture(const QPixmap &pic)
{
	QDialog *dialog = new QDialog;
	QLabel *label = new QLabel;
	label->setFixedSize(QSize(500, 500));
	label->setPixmap(pic.scaled(label->size()));
	QLayout *layout=new QHBoxLayout;
	layout->addWidget(label);
	dialog->setLayout(layout);
	dialog->show();
	dialog->raise();
	dialog->activateWindow();
}
void MainWindow::copy()
{
	auto pos = QCursor::pos()-this->pos()- QMainWindow::centralWidget()->pos();
	auto curwidget = childAt(pos);
	if (curwidget == 0)
		return;
	SetBoard->p->board = board;
	SetBoard->p->S1 = curwidget->objectName();
	SetBoard->exec(SetBoard->p);
}
void MainWindow::paste()
{
	if (isRunning())
		return;
	auto *temp= sender();
	auto qm = board->mimeData();
	if (!qm->hasUrls())
		return;
	if (temp == actionPasteLeft)
	{//api->Loadleftlabel(leftlabel, qm->urls()[0].toLocalFile());
		Loadleftlabel->p->L = leftlabel;
		Loadleftlabel->p->S1 = qm->urls()[0].toLocalFile();
		Loadleftlabel->reply(Loadleftlabel->p);
	}
	else if (temp == actionPasteRight)
	{
		//api->Loadrightlabel(rightlabel, qm->urls()[0].toLocalFile());
		Loadrightlabel->p->L = rightlabel;
		Loadrightlabel->p->S1 = qm->urls()[0].toLocalFile();
		Loadrightlabel->reply(Loadrightlabel->p);
	}
	startButton->setEnabled(startButtonenabled->reply()->flag);
}
void MainWindow::appeartask()
{
	//api->Updaterightlabel(rightlabel);
	Updaterightlabel->p->L = rightlabel;
	Updaterightlabel->exec();
	progressBar->setValue(Progress->reply()->progress);
}
void MainWindow::videotask(bool ifadd)
{
	QLabel* L;
	if (ifadd)
	{
		L = newLabel();
		addScrollArea(L);
		SetLabel->p->L = L;
		SetLabel->p->S1= L->objectName();
		SetLabel->reply(SetLabel->p);
	}
}
void MainWindow::saveoutput()
{
	auto pos = QCursor::pos() - this->pos() - QMainWindow::centralWidget()->pos();
	auto curwidget = childAt(pos);
	if (curwidget == 0)
		return;
	QString path = QFileDialog::getSaveFileName(this,
		tr("Save Picture"), ".",
		tr("PNG Picture (*.png)"));
	if (path.isEmpty())
		return;
	//api->Save(curwidget->objectName(), path);
	Save->p->S1 = curwidget->objectName();
	Save->p->S2 = path;
	Save->reply(Save->p);
}