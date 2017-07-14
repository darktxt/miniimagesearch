#include "settingDialog.h"



settingDialog::settingDialog(QWidget *parent) : QDialog(parent)
{
	setupUi(this);
	Apply = false;
}
void settingDialog::SetDialog(struct DataModel::Setting set)
{
	ratioSpinBox->setValue(set.ratio);
	thresholdSpinBox->setValue(set.threshold);
	jpgButton->setChecked(true);
	if (set.format == set.PNG)
		pngButton->setChecked(true);
}
struct DataModel::Setting settingDialog::Setting()
{
	struct DataModel::Setting set;
	set.ratio = ratioSpinBox->value();
	set.threshold = thresholdSpinBox->value();
	if (jpgButton->isChecked())
		set.format = set.JPG;
	else if (pngButton->isChecked())
		set.format = set.PNG;
	else
		set.format = set.JPG;
	return set;
}
void settingDialog::on_applyButton_clicked()
{
	Apply = true;
	temp = Setting();
}
