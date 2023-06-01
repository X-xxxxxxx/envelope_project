#pragma once

#include <QWidget>
#include "ui_init_window.h"
#include <QPushButton>


//
#include <QGridLayout>

//

#include "inter.h"
#include "spl.h"

class init_window : public QWidget
{
	Q_OBJECT

public:
	init_window(QWidget *parent = nullptr);
	~init_window();
signals:
	void hide_mainwindow();
	void show_mainwindow();


private slots:
	void show_inter_widget();
	void show_spl_widget();

	void show_this(); // 子窗口关闭 打开主窗口

	//void
private:
	Ui::init_windowClass ui;
	QPushButton* bt_dataread; // 数据读取按钮
	QPushButton* bt_inter; // 插值方法按钮
	QPushButton* bt_spl; // 样条方法按钮
	QLabel* lb_title;


	inter* inter_widget;
	spl* spl_widget;
	QGridLayout* layout_main;
};
