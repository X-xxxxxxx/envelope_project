#pragma once

#include <QWidget>
#include "ui_init_window.h"
#include <QPushButton>


//
#include <QGridLayout>

//

#include "inter.h"
#include "spl.h"

//

#include <QFileDialog>
#include <QMessageBox>


class init_window : public QWidget
{
	Q_OBJECT

public:
	init_window(QWidget *parent = nullptr);
	~init_window();

	// ����·��

	QString datapath;
signals:
	void hide_mainwindow();
	void show_mainwindow();


private slots:
	void show_inter_widget();
	void show_spl_widget();

	void show_this(); // �Ӵ��ڹر� ��������

	void data_read();

	//void
private:
	Ui::init_windowClass ui;
	QPushButton* bt_dataread; // ���ݶ�ȡ��ť
	QPushButton* bt_inter; // ��ֵ������ť
	QPushButton* bt_spl; // ����������ť
	QLabel* lb_title;


	inter* inter_widget;
	spl* spl_widget;
	QGridLayout* layout_main;
};
