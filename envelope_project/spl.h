#pragma once

#include <QWidget>
#include "ui_spl.h"

//
#include <qDebug>

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

//

#include "workerThread.h"

//

#include <QMessageBox>


//

#include <QImageReader>
//

#include "LoadingFrom.h"

//
#include <QAxObject>
//
#include "word.h"

class spl : public QWidget
{
	Q_OBJECT

signals:
	void this_to_fath();
public:
	spl(QWidget *parent = nullptr);
	void closeEvent(QCloseEvent*);

	void get_datapath(QString datapath);
	~spl();


	int interval;
	int degree;
	QString datapath;
	workerThread* worker;

	QString curtime;

private:
	Ui::splClass ui;

	// 控件
		// 左边控件
	QLabel* lb_interval_set;
	QLineEdit* le_interval_set;

	QLabel* lb_degree_set;
	QLineEdit* le_degree_set;

	QLabel* lb_index1_hint;
	QLabel* lb_index1_show;

	QLabel* lb_index2_hint;
	QLabel* lb_index2_show;

	QLabel* lb_index3_hint;
	QLabel* lb_index3_show;

	QPushButton* print_report;
	QPushButton* action;
	//右边控件
	QLabel* lb_image1_hint;
	QLabel* lb_image1_show;

	QLabel* lb_image2_hint;
	QLabel* lb_image2_show;

	QLabel* lb_image3_hint;
	QLabel* lb_image3_show;

	QLabel* lb_image4_hint;
	QLabel* lb_image4_show;


	// 布局
	QGridLayout* layout_left; // 左半部布局
	QGridLayout* layout_right; // 右半部布局
	QHBoxLayout* layout_main; //主布局

	// 显示运行进度
	QWidget* loading;
	QString desktop_path;
private slots:
	void change_interval();
	void change_degree();


	void create_thread();

	// 接收子线程发送信号
	void handle_results(double, double, double);

	void handle_img1(QString);
	void handle_img2(QString);
	void handle_img3(QString);
	void handle_img4(QString);
	void report_output();
};
