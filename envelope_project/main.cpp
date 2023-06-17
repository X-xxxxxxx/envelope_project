#include "envelopeMain.h"
#include <QtWidgets/QApplication>
#include <windows.h>

#include <QStandardPaths>
#include <QSplashScreen>
#include <QDateTime>


class DataBase {
public:
    void readData() {
        for (int i = 0; i < 100000; ++i)
        {
            qDebug("reading data");
        }
    }
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QSplashScreen splash(QPixmap(":/envelopeMain/start.mp4"));
    QMovie mv(":/envelopeMain/start.gif");
  
    QPixmap pixmap(500, 500);//gif动画的尺寸大小
    QSplashScreen splash(pixmap);//利用QPixmap对象创建一个QSplashScreen对象
    QLabel label(&splash);

    //设置label大小和位置
    //QMovie mv(":/envelopeMain/start.gif");
    label.setMovie(&mv);
    mv.start();
    //显示此启动图片
    splash.show();
    splash.setCursor(Qt::BlankCursor);
    for (int i = 0; i < 4000; i += mv.speed()) {
        a.processEvents(); //使程序在显示启动画面的同时仍能响应鼠标等其他事件
        Sleep(mv.speed()); // 延时
    }


    CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    envelopeMain w;
    w.setWindowTitle(QStringLiteral("航天器遥测数据故障诊断系统"));
  
    w.show();
    splash.finish(&w);
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);



    //QString s = desktop_path;
    //QDesktopServices::openUrl(QUrl(desktop_path));
    QDir dir(desktop_path);
    //dir.cd("./project");  //进入某文件夹
    //dir.cd("./data");
    if (!dir.exists(QString::fromLocal8Bit("Result")))  //创建文件夹
    {
        qDebug() << QStringLiteral("不存在结果文件夹") << endl;
        dir.mkdir(QString::fromLocal8Bit("Result"));
        qDebug() << QStringLiteral("文件夹创建成功") << endl;
        dir.cd(QString::fromLocal8Bit("Result"));
        dir.mkdir(QString::fromLocal8Bit("Image"));

        dir.mkdir(QString::fromLocal8Bit("Report"));
    }

    return a.exec();
}
