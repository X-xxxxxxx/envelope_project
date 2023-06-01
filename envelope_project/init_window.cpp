#include "init_window.h"

#include <qDebug>


init_window::init_window(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

    
    lb_title = new QLabel(QStringLiteral("����ң�����ݺ������������ϵͳ"));
    lb_title->adjustSize();
    lb_title->setAlignment(Qt::AlignCenter);
    lb_title->setFont(QFont("΢���ź�", 30));
    bt_dataread = new QPushButton;
    bt_dataread->setText(QStringLiteral("���ݶ�ȡ"));
    bt_dataread->setFixedSize(QSize(500, 700));
    bt_inter = new QPushButton;
    bt_inter->setText(QStringLiteral("��ֵ"));
    bt_inter->setFixedSize(QSize(700, 350));

    bt_spl = new QPushButton;
    bt_spl->setText(QStringLiteral("����"));
    bt_spl->setFixedSize(QSize(700, 350));


    // ����

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

    //qDebug() << QStringLiteral("�źŴ��Ӵ��巢�� ׼�� �������ڷ�����ʾ��Ϣ") << endl;

    //this->show();
}

init_window::~init_window()
{
    
}

