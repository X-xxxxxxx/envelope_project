#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_envelopeMain.h"


// 
#include <QLabel>
#include <QPushButton>


// 
#include <QMessageBox>

//
#include <QGridLayout>


//
#include "init_window.h"

//
#include <QDesktopWidget>

class envelopeMain : public QMainWindow
{
    Q_OBJECT

public:
    envelopeMain(QWidget *parent = nullptr);

    // 创建菜单
    void create_menus();
    void create_actions();

    ~envelopeMain();

private:
    Ui::envelopeMainClass ui;

    QLabel* test_lb;
    QMenu* file_mn;  // 文件菜单
    QMenu* about_mn; // 关于菜单


    // 文件菜单动作选项
    QAction* openfile_ac;
    QAction* savefile_ac;
    QAction* newfile_ac;
    QAction* exit_ac;


    // 关于菜单
    QAction* sys_info;

    // 

    init_window* center_window;



public slots:

    // 文件菜单栏目槽函数
    void new_file();
    void open_file();
    void save_file();
    void exit();

    // 关于菜单栏目槽函数

    void show_info();

    //

    void hide_this();
    void show_this();
};
