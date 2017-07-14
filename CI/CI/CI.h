#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CI.h"

class CI : public QMainWindow
{
	Q_OBJECT

public:
	CI(QWidget *parent = Q_NULLPTR);

private:
	Ui::CIClass ui;
};
