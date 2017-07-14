/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
	QAction *actionSave;
	QAction *actionQuit;
	QAction *actionAboutQT;
	QAction *actionAbout;
	QAction *actionMatched;
	QAction *actionMatching;
	QAction *actionPreferences;
	QWidget *centralWidget;
	QGridLayout *gridLayout;
	QHBoxLayout *horizontalLayout;
	QLabel *leftlabel;
	QLabel *rightlabel;
	QScrollArea *scrollArea;
	QWidget *scrollAreaWidgetContents;
	QHBoxLayout *horizontalLayout_2;
	QProgressBar *progressBar;
	QPushButton *clearButton;
	QPushButton *startButton;
	QMenuBar *menuBar;
	QMenu *menu_File;
	QMenu *menu_Open;
	QMenu *menu_Help;
	QMenu *menu_Setting;
	QToolBar *mainToolBar;
	QStatusBar *statusBar;

	void setupUi(QMainWindow *MainWindowClass)
	{
		if (MainWindowClass->objectName().isEmpty())
			MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
		MainWindowClass->resize(822, 683);
		MainWindowClass->setAcceptDrops(true);
		QIcon icon;
		icon.addFile(QStringLiteral(":/MainWindow/Resources/icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
		MainWindowClass->setWindowIcon(icon);
		actionSave = new QAction(MainWindowClass);
		actionSave->setObjectName(QStringLiteral("actionSave"));
		QIcon icon1;
		icon1.addFile(QStringLiteral(":/MainWindow/Resources/save.png"), QSize(), QIcon::Normal, QIcon::Off);
		actionSave->setIcon(icon1);
		actionQuit = new QAction(MainWindowClass);
		actionQuit->setObjectName(QStringLiteral("actionQuit"));
		QIcon icon2;
		icon2.addFile(QStringLiteral(":/MainWindow/Resources/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
		actionQuit->setIcon(icon2);
		actionAboutQT = new QAction(MainWindowClass);
		actionAboutQT->setObjectName(QStringLiteral("actionAboutQT"));
		QIcon icon3;
		icon3.addFile(QStringLiteral(":/MainWindow/Resources/Qt.png"), QSize(), QIcon::Normal, QIcon::Off);
		actionAboutQT->setIcon(icon3);
		actionAbout = new QAction(MainWindowClass);
		actionAbout->setObjectName(QStringLiteral("actionAbout"));
		QIcon icon4;
		icon4.addFile(QStringLiteral(":/MainWindow/Resources/help.png"), QSize(), QIcon::Normal, QIcon::Off);
		actionAbout->setIcon(icon4);
		actionMatched = new QAction(MainWindowClass);
		actionMatched->setObjectName(QStringLiteral("actionMatched"));
		QIcon icon5;
		icon5.addFile(QStringLiteral(":/MainWindow/Resources/open.png"), QSize(), QIcon::Normal, QIcon::Off);
		actionMatched->setIcon(icon5);
		actionMatching = new QAction(MainWindowClass);
		actionMatching->setObjectName(QStringLiteral("actionMatching"));
		actionMatching->setIcon(icon5);
		actionPreferences = new QAction(MainWindowClass);
		actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
		centralWidget = new QWidget(MainWindowClass);
		centralWidget->setObjectName(QStringLiteral("centralWidget"));
		gridLayout = new QGridLayout(centralWidget);
		gridLayout->setSpacing(6);
		gridLayout->setContentsMargins(11, 11, 11, 11);
		gridLayout->setObjectName(QStringLiteral("gridLayout"));
		horizontalLayout = new QHBoxLayout();
		horizontalLayout->setSpacing(6);
		horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
		horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
		leftlabel = new QLabel(centralWidget);
		leftlabel->setObjectName(QStringLiteral("leftlabel"));
		leftlabel->setMinimumSize(QSize(300, 300));
		leftlabel->setLocale(QLocale(QLocale::Chinese, QLocale::China));
		leftlabel->setScaledContents(false);
		leftlabel->setAlignment(Qt::AlignCenter);

		horizontalLayout->addWidget(leftlabel);

		rightlabel = new QLabel(centralWidget);
		rightlabel->setObjectName(QStringLiteral("rightlabel"));
		rightlabel->setMinimumSize(QSize(300, 300));
		rightlabel->setLocale(QLocale(QLocale::Chinese, QLocale::China));
		rightlabel->setScaledContents(false);
		rightlabel->setAlignment(Qt::AlignCenter);

		horizontalLayout->addWidget(rightlabel);


		gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

		scrollArea = new QScrollArea(centralWidget);
		scrollArea->setObjectName(QStringLiteral("scrollArea"));
		scrollArea->setMinimumSize(QSize(800, 250));
		scrollArea->setWidgetResizable(true);
		scrollAreaWidgetContents = new QWidget();
		scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
		scrollAreaWidgetContents->setGeometry(QRect(0, 0, 798, 248));
		scrollAreaWidgetContents->setMinimumSize(QSize(0, 0));
		scrollArea->setWidget(scrollAreaWidgetContents);

		gridLayout->addWidget(scrollArea, 1, 0, 1, 1);

		horizontalLayout_2 = new QHBoxLayout();
		horizontalLayout_2->setSpacing(6);
		horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
		horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
		progressBar = new QProgressBar(centralWidget);
		progressBar->setObjectName(QStringLiteral("progressBar"));
		progressBar->setMinimumSize(QSize(200, 0));
		progressBar->setValue(24);

		horizontalLayout_2->addWidget(progressBar);

		clearButton = new QPushButton(centralWidget);
		clearButton->setObjectName(QStringLiteral("clearButton"));

		horizontalLayout_2->addWidget(clearButton);

		startButton = new QPushButton(centralWidget);
		startButton->setObjectName(QStringLiteral("startButton"));

		horizontalLayout_2->addWidget(startButton);


		gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

		MainWindowClass->setCentralWidget(centralWidget);
		menuBar = new QMenuBar(MainWindowClass);
		menuBar->setObjectName(QStringLiteral("menuBar"));
		menuBar->setGeometry(QRect(0, 0, 822, 26));
		menu_File = new QMenu(menuBar);
		menu_File->setObjectName(QStringLiteral("menu_File"));
		menu_Open = new QMenu(menu_File);
		menu_Open->setObjectName(QStringLiteral("menu_Open"));
		menu_Help = new QMenu(menuBar);
		menu_Help->setObjectName(QStringLiteral("menu_Help"));
		menu_Setting = new QMenu(menuBar);
		menu_Setting->setObjectName(QStringLiteral("menu_Setting"));
		MainWindowClass->setMenuBar(menuBar);
		mainToolBar = new QToolBar(MainWindowClass);
		mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
		MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
		statusBar = new QStatusBar(MainWindowClass);
		statusBar->setObjectName(QStringLiteral("statusBar"));
		MainWindowClass->setStatusBar(statusBar);

		menuBar->addAction(menu_File->menuAction());
		menuBar->addAction(menu_Setting->menuAction());
		menuBar->addAction(menu_Help->menuAction());
		menu_File->addAction(menu_Open->menuAction());
		menu_File->addAction(actionSave);
		menu_File->addSeparator();
		menu_File->addAction(actionQuit);
		menu_Open->addAction(actionMatched);
		menu_Open->addAction(actionMatching);
		menu_Help->addAction(actionAbout);
		menu_Help->addAction(actionAboutQT);
		menu_Setting->addAction(actionPreferences);

		retranslateUi(MainWindowClass);
		QObject::connect(actionQuit, SIGNAL(triggered()), MainWindowClass, SLOT(close()));

		QMetaObject::connectSlotsByName(MainWindowClass);
	} // setupUi

	void retranslateUi(QMainWindow *MainWindowClass)
	{
		MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", Q_NULLPTR));
		actionSave->setText(QApplication::translate("MainWindowClass", "Save", Q_NULLPTR));
		actionQuit->setText(QApplication::translate("MainWindowClass", "&Quit", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
		actionQuit->setStatusTip(QApplication::translate("MainWindowClass", "Quit the application", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
		actionAboutQT->setText(QApplication::translate("MainWindowClass", "About QT", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
		actionAboutQT->setStatusTip(QApplication::translate("MainWindowClass", "Show the Qt library's About box", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
		actionAbout->setText(QApplication::translate("MainWindowClass", "About", Q_NULLPTR));
		actionMatched->setText(QApplication::translate("MainWindowClass", "Matched", Q_NULLPTR));
		actionMatching->setText(QApplication::translate("MainWindowClass", "Matching", Q_NULLPTR));
		actionPreferences->setText(QApplication::translate("MainWindowClass", "&Preferences", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
		leftlabel->setStatusTip(QApplication::translate("MainWindowClass", "Input picture here", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
		leftlabel->setText(QApplication::translate("MainWindowClass", "Input picture here", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
		rightlabel->setStatusTip(QApplication::translate("MainWindowClass", "Input picture or video here", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
		rightlabel->setText(QApplication::translate("MainWindowClass", "Input picture or video here", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
		scrollArea->setStatusTip(QApplication::translate("MainWindowClass", "Output", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
		clearButton->setStatusTip(QApplication::translate("MainWindowClass", "Clear output", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
		clearButton->setText(QApplication::translate("MainWindowClass", "&Clear", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
		startButton->setStatusTip(QApplication::translate("MainWindowClass", "Start", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
		startButton->setText(QApplication::translate("MainWindowClass", "&Start", Q_NULLPTR));
		menu_File->setTitle(QApplication::translate("MainWindowClass", "&File", Q_NULLPTR));
		menu_Open->setTitle(QApplication::translate("MainWindowClass", "&Open", Q_NULLPTR));
		menu_Help->setTitle(QApplication::translate("MainWindowClass", "&Help", Q_NULLPTR));
		menu_Setting->setTitle(QApplication::translate("MainWindowClass", "&Setting", Q_NULLPTR));
	} // retranslateUi

};

namespace Ui {
	class MainWindowClass : public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
