#include "envelopeMain.h"

envelopeMain::envelopeMain(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);


    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/envelopeMain/background.png")));
    setPalette(pal);


    this->setFixedSize(QDesktopWidget().availableGeometry(this).size() * 0.7);
    create_actions();
    create_menus();


    test_lb = new QLabel();
    test_lb->setText(QStringLiteral("text"));
    test_lb->setGeometry(100, 100, 250, 250);
    //test_lb->setFont(QFont(tr("微软雅黑"), 20));
   // test_lb->setFrameStyle(1);
    test_lb->adjustSize();


    center_window = new init_window();

    connect(center_window, SIGNAL(hide_mainwindow()), this, SLOT(hide_this()));
    connect(center_window, SIGNAL(show_mainwindow()), this, SLOT(show_this()));
    setCentralWidget(center_window);



}

void envelopeMain::create_menus()
{
    file_mn = menuBar()->addMenu(QStringLiteral("文件"));
    file_mn->addAction(newfile_ac); // 新建
    file_mn->addAction(openfile_ac); // 打开
    file_mn->addAction(savefile_ac); // 保存
    file_mn->addAction(exit_ac); // 退出


    about_mn = menuBar()->addMenu(QStringLiteral("关于"));
    about_mn->addAction(sys_info);


}

void envelopeMain::create_actions()
{
    // 文件菜单动作
    newfile_ac = new QAction(QStringLiteral("新建"), this);
    newfile_ac->setStatusTip(QStringLiteral("新建一个文件"));
    connect(newfile_ac, SIGNAL(triggered()), this, SLOT(new_file()));

    openfile_ac = new QAction(QStringLiteral("打开"), this);
    openfile_ac->setStatusTip(QStringLiteral("打开一个文件"));
    connect(openfile_ac, SIGNAL(triggered()), this, SLOT(open_file()));

    savefile_ac = new QAction(QStringLiteral("保存"), this);
    savefile_ac->setStatusTip(QStringLiteral("保存一个文件"));
    connect(savefile_ac, SIGNAL(triggered()), this, SLOT(save_file()));

    exit_ac = new QAction(QStringLiteral("退出"), this);
    connect(exit_ac, SIGNAL(triggered()), this, SLOT(exit()));



    // 关于菜单动作

    sys_info = new QAction(QStringLiteral("关于"), this);
    sys_info->setStatusTip(QStringLiteral("关于系统"));
    connect(sys_info, SIGNAL(triggered()), this, SLOT(show_info()));
}

void envelopeMain::new_file()
{
    test_lb->setText(QStringLiteral("新建一个文件"));
    test_lb->adjustSize();
}
void envelopeMain::open_file()
{
    test_lb->setText(QStringLiteral("打开一个文件"));
    test_lb->adjustSize();
}

void envelopeMain::save_file()
{
    test_lb->setText(QStringLiteral("保存一个文件"));
    test_lb->adjustSize();
}

void envelopeMain::exit()
{
    switch (QMessageBox::question(this, QStringLiteral("退出提示"),
        QStringLiteral("你确定要退出吗？"),
        QMessageBox::Ok | QMessageBox::Cancel,
        QMessageBox::Ok))
    {
    case QMessageBox::Ok:
        this->close();
        break;
    case QMessageBox::Cancel:
        test_lb->setText(QStringLiteral("取消退出"));
        test_lb->adjustSize();
        break;
    default:
        break;
    }
}

void envelopeMain::show_info()
{
    test_lb->setText(QStringLiteral("系统信息"));
    test_lb->adjustSize();
}

void envelopeMain::hide_this()
{
    this->hide();
}



void envelopeMain::show_this()
{
    this->show();
}

envelopeMain::~envelopeMain()
{}
