#include "init_window.h"

#include <qDebug>


init_window::init_window(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

    
    lb_title = new QLabel(QStringLiteral("基于遥测数据航天器故障诊断系统"));
    lb_title->adjustSize();
    lb_title->setAlignment(Qt::AlignCenter);
    lb_title->setFont(QFont("微软雅黑", 30));
    bt_dataread = new QPushButton;
    bt_dataread->setText(QStringLiteral("数据读取"));
    bt_dataread->setFixedSize(QSize(500, 700));
    bt_inter = new QPushButton;
    bt_inter->setText(QStringLiteral("插值"));
    bt_inter->setFixedSize(QSize(700, 350));

    bt_spl = new QPushButton;
    bt_spl->setText(QStringLiteral("样条"));
    bt_spl->setFixedSize(QSize(700, 350));


    // 布局

    layout_main = new QGridLayout(this);
    //layout_main->addWidget(test_lb);
    layout_main->addWidget(lb_title, 0, 0, 1, 2);
    layout_main->addWidget(bt_dataread, 1, 0, 2, 1);
    layout_main->addWidget(bt_inter, 1, 1);
    layout_main->addWidget(bt_spl, 2, 1);
    

    //layout_main->setMargin(100);
    layout_main->setAlignment(Qt::AlignCenter);
    layout_main->setVerticalSpacing(0);
    layout_main->setHorizontalSpacing(0);

    layout_main->setRowStretch(0, 1);
    layout_main->setRowStretch(1, 3);
    layout_main->setRowStretch(2, 3);


    inter_widget = new inter;
    connect(bt_inter, SIGNAL(clicked()), this, SLOT(show_inter_widget()));
    connect(inter_widget, SIGNAL(this_to_fath()), this, SLOT(show_this()));

    spl_widget = new spl;
    connect(bt_spl, SIGNAL(clicked()), this, SLOT(show_spl_widget()));
    connect(spl_widget, SIGNAL(this_to_fath()), this, SLOT(show_this()));
}

void init_window::show_inter_widget()
{
    inter_widget->show();
    emit hide_mainwindow(); 
   // this->hide();
}

void init_window::show_spl_widget()
{
    spl_widget->show();
    emit hide_mainwindow();

}

void init_window::show_this()
{
    emit show_mainwindow();

    //qDebug() << QStringLiteral("信号从子窗体发来 准备 向主窗口发送显示信息") << endl;

    //this->show();
}

init_window::~init_window()
{
    
}


