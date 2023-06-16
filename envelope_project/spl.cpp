#include "spl.h"

spl::spl(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setFixedSize(QDesktopWidget().availableGeometry(this).size() * 0.7);
	QPalette pal = this->palette();
	pal.setBrush(QPalette::Background, QBrush(QPixmap(":/envelopeMain/background.png")));
	setPalette(pal);




	loading = new LoadingFrom(this);

	loading->setFixedSize(this->size());//设置窗口大小
	loading->setAutoFillBackground(true); //这个很重要，否则不会显示遮罩层
	QPalette pal_mask = loading->palette();
	//QColor color;
	//color.setRgb(0, 255, 255, 255);
	pal_mask.setColor(QPalette::Background, QColor(0x00, 0x00, 0x00, 0x30));
	loading->setPalette(pal_mask);


	loading->setVisible(false);//初始状态下隐藏，待需要显示时使用




	// 左半部控件
	lb_interval_set = new QLabel(QStringLiteral("区间大小"));
	lb_interval_set->setAlignment(Qt::AlignCenter);
	le_interval_set = new QLineEdit;
	le_interval_set->setFixedHeight(30);
	le_interval_set->setText(QString::number(20));
	this->interval = le_interval_set->text().toInt(); // 区间大小默认20

	connect(le_interval_set, SIGNAL(editingFinished()), this, SLOT(change_interval()));


	lb_degree_set = new QLabel(QStringLiteral("阶数设置"));
	lb_degree_set->setAlignment(Qt::AlignCenter);
	le_degree_set = new QLineEdit;
	le_degree_set->setFixedHeight(30);
	le_degree_set->setText(QString::number(3));
	this->degree = le_degree_set->text().toInt(); // 区间大小默认20

	connect(le_degree_set, SIGNAL(editingFinished()), this, SLOT(change_degree()));


	lb_index1_hint = new QLabel(QStringLiteral("区间覆盖率ICP"));
	lb_index1_hint->setAlignment(Qt::AlignCenter);
	lb_index1_show = new QLabel;
	//lb_index1_show->setFrameShape(QFrame::Box);
	lb_index1_show->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	lb_index1_show->setFixedHeight(30);

	lb_index2_hint = new QLabel(QStringLiteral("区间平均宽度百分比IMWP"));
	lb_index2_hint->setAlignment(Qt::AlignCenter);
	lb_index2_show = new QLabel;
	//lb_index2_show->setFrameShape(QFrame::Box);
	lb_index2_show->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	lb_index2_show->setFixedHeight(30);

	lb_index3_hint = new QLabel(QStringLiteral("平均带宽误差MWD"));
	lb_index3_hint->setAlignment(Qt::AlignCenter);
	lb_index3_show = new QLabel;
	//lb_index3_show->setFrameShape(QFrame::Box);
	lb_index3_show->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	lb_index3_show->setFixedHeight(30);

	print_report = new QPushButton(QStringLiteral("打印报告"));

	print_report->setFixedSize(QSize(500, 150));
	print_report->setFixedHeight(150);

	print_report->setFont(QFont("黑体", 18));
	print_report->setStyleSheet("background-color: #F6EBFF;");

	action = new QPushButton(QStringLiteral("开始运行"));
	action->setFixedSize(QSize(500, 150));
	action->setFixedHeight(150);

	action->setFont(QFont("黑体", 18));
	action->setStyleSheet("background-color: #F6EBFF;");



	connect(action, SIGNAL(clicked()), this, SLOT(create_thread()));


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

	layout_left->addWidget(lb_interval_set, 0, 0);
	layout_left->addWidget(le_interval_set, 0, 1);

	layout_left->addWidget(lb_degree_set, 1, 0);
	layout_left->addWidget(le_degree_set, 1, 1);

	layout_left->addWidget(lb_index1_hint, 2, 0);
	layout_left->addWidget(lb_index1_show, 2, 1);

	layout_left->addWidget(lb_index2_hint, 3, 0);
	layout_left->addWidget(lb_index2_show, 3, 1);

	layout_left->addWidget(lb_index3_hint, 4, 0);
	layout_left->addWidget(lb_index3_show, 4, 1);
	layout_left->addWidget(action, 5, 0, 1, 2);
	layout_left->addWidget(print_report, 6, 0, 1, 2);

	layout_left->setColumnStretch(0, 1);
	layout_left->setColumnStretch(1, 2);

	layout_left->setRowStretch(0, 1);
	layout_left->setRowStretch(1, 1);
	layout_left->setRowStretch(2, 1);
	layout_left->setRowStretch(3, 1);
	layout_left->setRowStretch(4, 1);
	layout_left->setRowStretch(5, 2);
	layout_left->setRowStretch(6, 2);

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



// 重写关闭事件
void spl::closeEvent(QCloseEvent* event)
{
	emit this_to_fath();
	event->accept();
}

void spl::change_interval()
{
	this->interval = le_interval_set->text().toInt();
	//qDebug() << this->interval << endl;
}

void spl::change_degree()
{
	this->degree = le_degree_set->text().toInt();

	//qDebug() << this->degree << endl;
}

void spl::create_thread()
{
	//qDebug() << QStringLiteral("槽函数连接成功") << endl;

	qDebug() << QStringLiteral("创建新线程") << endl;
	if (datapath == nullptr)
	{
		QMessageBox::information(this, QStringLiteral("数据路径选取失败提示窗口"),
			QStringLiteral("您的数据选取有误，请返回上一级重新选取"));
		this->close();
		return;
	}
	worker = new workerThread(datapath, interval, degree, 2); // para 4 代表选取当前方法

	loading->setVisible(true);

	qDebug() << datapath << "       " << interval  << "       " << degree << endl;
	connect(worker, SIGNAL(send_image1(QString)), this, SLOT(handle_img1(QString)));
	connect(worker, SIGNAL(send_image2(QString)), this, SLOT(handle_img2(QString)));
	connect(worker, SIGNAL(send_image3(QString)), this, SLOT(handle_img3(QString)));
	connect(worker, SIGNAL(send_image4(QString)), this, SLOT(handle_img4(QString)));
	// 误差结果接收槽
	connect(worker, SIGNAL(resultsReady(double, double, double)), this, SLOT(handle_results(double, double, double)));
	worker->start();

}

void spl::handle_results(double icp, double imwp, double mwd)
{
	// 显示误差结果
	QString idx1 = QString::number(icp, 'f', 4);
	lb_index1_show->setText(idx1);

	QString idx2 = QString::number(imwp, 'f', 4);
	lb_index2_show->setText(idx2);

	QString idx3 = QString::number(mwd, 'f', 4);
	lb_index3_show->setText(idx3);


	// 销毁线程
	worker->quit();
	worker->wait();

	qDebug() << QStringLiteral("子线程销毁成功") << endl;
	delete worker;
}

void spl::handle_img1(QString cur_time)
{
	loading->setVisible(false);
	QString imgfullpath = "C:/Users/X_xx/Desktop/res_save/" + tr("original_data_") + cur_time + ".jpg";

	qDebug() << imgfullpath << endl;
	QImageReader* reader = new QImageReader(imgfullpath);
	//reader -> setFileName(res);

	QPixmap  icon = QPixmap::fromImageReader(reader);
	icon.scaled(lb_image1_show->size(), Qt::KeepAspectRatio);
	lb_image1_show->setScaledContents(true);
	lb_image1_show->setPixmap(icon);
}

void spl::handle_img2(QString cur_time)
{
	QString imgfullpath = "C:/Users/X_xx/Desktop/res_save/" + tr("original_data_Max_Min_") + cur_time + ".jpg";

	qDebug() << imgfullpath << endl;
	QImageReader* reader = new QImageReader(imgfullpath);
	//reader -> setFileName(res);

	QPixmap  icon = QPixmap::fromImageReader(reader);
	icon.scaled(lb_image2_show->size(), Qt::KeepAspectRatio);
	lb_image2_show->setScaledContents(true);
	lb_image2_show->setPixmap(icon);
}

void spl::handle_img3(QString cur_time)
{
	QString imgfullpath = "C:/Users/X_xx/Desktop/res_save/" + tr("original_data_Max_UP_Min_LOW_") + cur_time + ".jpg";

	qDebug() << imgfullpath << endl;
	QImageReader* reader = new QImageReader(imgfullpath);
	//reader -> setFileName(res);

	QPixmap  icon = QPixmap::fromImageReader(reader);
	icon.scaled(lb_image3_show->size(), Qt::KeepAspectRatio);
	lb_image3_show->setScaledContents(true);
	lb_image3_show->setPixmap(icon);
}

void spl::handle_img4(QString cur_time)
{
	QString imgfullpath = "C:/Users/X_xx/Desktop/res_save/" + tr("original_data_upper_lower") + cur_time + ".jpg";

	qDebug() << imgfullpath << endl;
	QImageReader* reader = new QImageReader(imgfullpath);
	//reader -> setFileName(res);

	QPixmap  icon = QPixmap::fromImageReader(reader);
	icon.scaled(lb_image4_show->size(), Qt::KeepAspectRatio);
	lb_image4_show->setScaledContents(true);
	lb_image4_show->setPixmap(icon);
}


void spl::get_datapath(QString datapath)
{
	this->datapath = datapath;
}

spl::~spl()
{}