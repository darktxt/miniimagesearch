#pragma once
#include<qdialog.h>
#include "ui_settingDialog.h"
#include"DataModel.h"
class settingDialog :public QDialog, public Ui::settingDialog
{
	Q_OBJECT
private:
	bool Apply;
	struct DataModel::Setting temp;
	private slots:
	void on_applyButton_clicked();
public:
	settingDialog(QWidget *parent = Q_NULLPTR);
	struct DataModel::Setting Setting();
	void SetDialog(struct DataModel::Setting set);
	void setApply(bool a) { Apply = a; }
	bool isApply() { return Apply; }
	struct DataModel::Setting GetApply() { return temp; }
};

