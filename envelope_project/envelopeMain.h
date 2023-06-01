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

    // �����˵�
    void create_menus();
    void create_actions();

    ~envelopeMain();

private:
    Ui::envelopeMainClass ui;

    QLabel* test_lb;
    QMenu* file_mn;  // �ļ��˵�
    QMenu* about_mn; // ���ڲ˵�


    // �ļ��˵�����ѡ��
    QAction* openfile_ac;
    QAction* savefile_ac;
    QAction* newfile_ac;
    QAction* exit_ac;


    // ���ڲ˵�
    QAction* sys_info;

    // 

    init_window* center_window;



public slots:

    // �ļ��˵���Ŀ�ۺ���
    void new_file();
    void open_file();
    void save_file();
    void exit();

    // ���ڲ˵���Ŀ�ۺ���

    void show_info();

    //

    void hide_this();
    void show_this();
};
