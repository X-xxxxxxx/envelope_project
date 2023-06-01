#pragma once

#include <QWidget>
#include "ui_inter.h"

//
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

//
#include <QGridLayout>
#include <QHBoxLayout>

//
#include <QDesktopWidget>
#include <QCloseEvent>

class inter : public QWidget
{
	Q_OBJECT

signals:
	void this_to_fath();


public:
	inter(QWidget *parent = nullptr);

	void closeEvent(QCloseEvent*);
	~inter();

private:
	Ui::interClass ui;
	// �ؼ�
	// ��߿ؼ�
	QLabel* lb_para_set;
	QLineEdit* le_para_set;

	QLabel* lb_index1_hint;
	QLabel* lb_index1_show;

	QLabel* lb_index2_hint;
	QLabel* lb_index2_show;

	QLabel* lb_index3_hint;
	QLabel* lb_index3_show;

	QPushButton* print_report;
	QPushButton* action;
	//�ұ߿ؼ�
	QLabel* lb_image1_hint;
	QLabel* lb_image1_show;

	QLabel* lb_image2_hint;
	QLabel* lb_image2_show;

	QLabel* lb_image3_hint;
	QLabel* lb_image3_show;

	QLabel* lb_image4_hint;
	QLabel* lb_image4_show;


	// ����
	QGridLayout* layout_left; // ��벿����
	QGridLayout* layout_right; // �Ұ벿����
	QHBoxLayout* layout_main; //������
};
