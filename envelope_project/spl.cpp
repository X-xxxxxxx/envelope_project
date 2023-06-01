#include "spl.h"

spl::spl(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setFixedSize(QDesktopWidget().availableGeometry(this).size() * 0.7);

	// 左半部控件
	lb_para_set = new QLabel(QStringLiteral("参数设置"));
	lb_para_set->setAlignment(Qt::AlignCenter);
	le_para_set = new QLineEdit;
	le_para_set->setFixedHeight(30);


	lb_index1_hint = new QLabel(QStringLiteral("误差指标1"));
	lb_index1_hint->setAlignment(Qt::AlignCenter);
	lb_index1_show = new QLabel;
	//lb_index1_show->setFrameShape(QFrame::Box);
	lb_index1_show->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	lb_index1_show->setFixedHeight(30);

	lb_index2_hint = new QLabel(QStringLiteral("误差指标2"));
	lb_index2_hint->setAlignment(Qt::AlignCenter);
	lb_index2_show = new QLabel;
	//lb_index2_show->setFrameShape(QFrame::Box);
	lb_index2_show->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	lb_index2_show->setFixedHeight(30);

	lb_index3_hint = new QLabel(QStringLiteral("误差指标3"));
	lb_index3_hint->setAlignment(Qt::AlignCenter);
	lb_index3_show = new QLabel;
	//lb_index3_show->setFrameShape(QFrame::Box);
	lb_index3_show->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	lb_index3_show->setFixedHeight(30);

	print_report = new QPushButton(QStringLiteral("打印报告"));

	print_report->setFixedSize(QSize(500, 150));
	print_report->setFixedHeight(150);

	action = new QPushButton(QStringLiteral("开始运行"));
	action->setFixedSize(QSize(500, 150));
	action->setFixedHeight(150);
	//右半部控件

	lb_image1_hint = new QLabel(QStringLiteral("原始图片"));
	lb_image1_hint->setAlignment(Qt::AlignCenter);
	lb_image1_hint->setFixedHeight(20);


	lb_image1_show = new QLabel;
	lb_image1_show->setFrameShape(QFrame::Box);
	lb_image1_show->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	lb_image2_hint = new QLabel(QStringLiteral("最大最小值提取"));
	lb_image2_hint->setAlignment(Qt::AlignCenter);
	lb_image2_hint->setFixedHeight(20);

	lb_image2_show = new QLabel;
	lb_image2_show->setFrameShape(QFrame::Box);
	lb_image2_show->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	lb_image3_hint = new QLabel(QStringLiteral("移动后图片"));
	lb_image3_hint->setAlignment(Qt::AlignCenter);
	lb_image3_hint->setFixedHeight(20);

	lb_image3_show = new QLabel;
	lb_image3_show->setFrameShape(QFrame::Box);
	lb_image3_show->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	lb_image4_hint = new QLabel(QStringLiteral("包络图片"));
	lb_image4_hint->setAlignment(Qt::AlignCenter);
	lb_image4_hint->setFixedHeight(20);

	lb_image4_show = new QLabel;
	lb_image4_show->setFrameShape(QFrame::Box);
	lb_image4_show->setFrameStyle(QFrame::Panel | QFrame::Sunken);


	layout_left = new QGridLayout;

	layout_left->setMargin(20);

	layout_left->addWidget(lb_para_set, 0, 0);
	layout_left->addWidget(le_para_set, 0, 1);

	layout_left->addWidget(lb_index1_hint, 1, 0);
	layout_left->addWidget(lb_index1_show, 1, 1);

	layout_left->addWidget(lb_index2_hint, 2, 0);
	layout_left->addWidget(lb_index2_show, 2, 1);

	layout_left->addWidget(lb_index3_hint, 3, 0);
	layout_left->addWidget(lb_index3_show, 3, 1);
	layout_left->addWidget(action, 4, 0, 1, 2);
	layout_left->addWidget(print_report, 5, 0, 1, 2);

	layout_left->setColumnStretch(0, 1);
	layout_left->setColumnStretch(1, 2);

	layout_left->setRowStretch(0, 1);
	layout_left->setRowStretch(1, 1);
	layout_left->setRowStretch(2, 1);
	layout_left->setRowStretch(3, 1);
	layout_left->setRowStretch(4, 2);
	layout_left->setRowStretch(5, 2);

	layout_left->setHorizontalSpacing(-1);
	layout_left->setVerticalSpacing(50);


	layout_right = new QGridLayout;
	layout_right->addWidget(lb_image1_show, 0, 0);
	layout_right->addWidget(lb_image1_hint, 1, 0);

	layout_right->addWidget(lb_image2_show, 2, 0);
	layout_right->addWidget(lb_image2_hint, 3, 0);

	layout_right->addWidget(lb_image3_show, 0, 1);
	layout_right->addWidget(lb_image3_hint, 1, 1);

	layout_right->addWidget(lb_image4_show, 2, 1);
	layout_right->addWidget(lb_image4_hint, 3, 1);
	//layout_right->setAlignment(Qt::AlignHCenter);

	layout_right->setMargin(50);
	layout_right->setHorizontalSpacing(10);

	layout_main = new QHBoxLayout(this);

	layout_main->addLayout(layout_left);

	layout_main->addLayout(layout_right);
	layout_main->setStretchFactor(layout_left, 1);
	layout_main->setStretchFactor(layout_right, 3);
}

void spl::closeEvent(QCloseEvent* event)
{
	emit this_to_fath();
	event->accept();
}
spl::~spl()
{}
