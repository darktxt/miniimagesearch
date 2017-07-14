/********************************************************************************
** Form generated from reading UI file 'settingDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_settingDialog
{
public:
	QGridLayout *gridLayout_2;
	QGridLayout *gridLayout;
	QSpinBox *ratioSpinBox;
	QSlider *thresholdSlider;
	QLabel *label;
	QRadioButton *jpgButton;
	QSpinBox *thresholdSpinBox;
	QPushButton *okButton;
	QPushButton *applyButton;
	QLabel *label_2;
	QPushButton *cancelButton;
	QRadioButton *pngButton;
	QLabel *label_3;
	QSlider *ratioSlider;

	void setupUi(QDialog *settingDialog)
	{
		if (settingDialog->objectName().isEmpty())
			settingDialog->setObjectName(QStringLiteral("settingDialog"));
		settingDialog->resize(317, 136);
		gridLayout_2 = new QGridLayout(settingDialog);
		gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
		gridLayout = new QGridLayout();
		gridLayout->setObjectName(QStringLiteral("gridLayout"));
		ratioSpinBox = new QSpinBox(settingDialog);
		ratioSpinBox->setObjectName(QStringLiteral("ratioSpinBox"));
		ratioSpinBox->setMaximum(100);

		gridLayout->addWidget(ratioSpinBox, 0, 1, 1, 1);

		thresholdSlider = new QSlider(settingDialog);
		thresholdSlider->setObjectName(QStringLiteral("thresholdSlider"));
		thresholdSlider->setOrientation(Qt::Horizontal);

		gridLayout->addWidget(thresholdSlider, 1, 2, 1, 2);

		label = new QLabel(settingDialog);
		label->setObjectName(QStringLiteral("label"));

		gridLayout->addWidget(label, 1, 0, 1, 1);

		jpgButton = new QRadioButton(settingDialog);
		jpgButton->setObjectName(QStringLiteral("jpgButton"));

		gridLayout->addWidget(jpgButton, 2, 1, 1, 2);

		thresholdSpinBox = new QSpinBox(settingDialog);
		thresholdSpinBox->setObjectName(QStringLiteral("thresholdSpinBox"));
		thresholdSpinBox->setMaximum(100);

		gridLayout->addWidget(thresholdSpinBox, 1, 1, 1, 1);

		okButton = new QPushButton(settingDialog);
		okButton->setObjectName(QStringLiteral("okButton"));

		gridLayout->addWidget(okButton, 3, 0, 1, 1);

		applyButton = new QPushButton(settingDialog);
		applyButton->setObjectName(QStringLiteral("applyButton"));

		gridLayout->addWidget(applyButton, 3, 3, 1, 1);

		label_2 = new QLabel(settingDialog);
		label_2->setObjectName(QStringLiteral("label_2"));

		gridLayout->addWidget(label_2, 0, 0, 1, 1);

		cancelButton = new QPushButton(settingDialog);
		cancelButton->setObjectName(QStringLiteral("cancelButton"));

		gridLayout->addWidget(cancelButton, 3, 1, 1, 2);

		pngButton = new QRadioButton(settingDialog);
		pngButton->setObjectName(QStringLiteral("pngButton"));

		gridLayout->addWidget(pngButton, 2, 3, 1, 1);

		label_3 = new QLabel(settingDialog);
		label_3->setObjectName(QStringLiteral("label_3"));

		gridLayout->addWidget(label_3, 2, 0, 1, 1);

		ratioSlider = new QSlider(settingDialog);
		ratioSlider->setObjectName(QStringLiteral("ratioSlider"));
		ratioSlider->setOrientation(Qt::Horizontal);

		gridLayout->addWidget(ratioSlider, 0, 2, 1, 2);


		gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


		retranslateUi(settingDialog);
		QObject::connect(ratioSpinBox, SIGNAL(valueChanged(int)), ratioSlider, SLOT(setValue(int)));
		QObject::connect(thresholdSpinBox, SIGNAL(valueChanged(int)), thresholdSlider, SLOT(setValue(int)));
		QObject::connect(ratioSlider, SIGNAL(valueChanged(int)), ratioSpinBox, SLOT(setValue(int)));
		QObject::connect(thresholdSlider, SIGNAL(valueChanged(int)), thresholdSpinBox, SLOT(setValue(int)));
		QObject::connect(cancelButton, SIGNAL(clicked()), settingDialog, SLOT(close()));
		QObject::connect(okButton, SIGNAL(clicked()), settingDialog, SLOT(accept()));

		QMetaObject::connectSlotsByName(settingDialog);
	} // setupUi

	void retranslateUi(QDialog *settingDialog)
	{
		settingDialog->setWindowTitle(QApplication::translate("settingDialog", "Setting", Q_NULLPTR));
		label->setText(QApplication::translate("settingDialog", "Threshold:", Q_NULLPTR));
		jpgButton->setText(QApplication::translate("settingDialog", "JPG", Q_NULLPTR));
		okButton->setText(QApplication::translate("settingDialog", "OK", Q_NULLPTR));
		applyButton->setText(QApplication::translate("settingDialog", "Apply", Q_NULLPTR));
		label_2->setText(QApplication::translate("settingDialog", "Ratio:", Q_NULLPTR));
		cancelButton->setText(QApplication::translate("settingDialog", "Cancel", Q_NULLPTR));
		pngButton->setText(QApplication::translate("settingDialog", "PNG", Q_NULLPTR));
		label_3->setText(QApplication::translate("settingDialog", "Format:", Q_NULLPTR));
	} // retranslateUi

};

namespace Ui {
	class settingDialog : public Ui_settingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
