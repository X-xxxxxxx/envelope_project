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


//

#include <qDebug>
#include <QMessageBox>
#include <QImageReader>
#include <QPixmap>
//
#include "workerThread.h"


//
#include "LoadingFrom.h"
//
#include <QAxObject>
//
#include "word.h"



class inter : public QWidget
{
	Q_OBJECT

signals:
	void this_to_fath();


public:
	inter(QWidget *parent = nullptr);

	void get_datapath(QString datapath);
	void closeEvent(QCloseEvent*);
	~inter();

	int degree;
	int interval;
	QString datapath;
	workerThread* worker;
	QString curtime;


private:
	Ui::interClass ui;
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
	//
	//QWord* word;
	private slots:

		void change_interval();
		void change_degree();

		void create_thread();

		void handle_results(double, double, double);

		void handle_img1(QString);
		void handle_img2(QString);
		void handle_img3(QString);
		void handle_img4(QString);


		void report_output();

};
