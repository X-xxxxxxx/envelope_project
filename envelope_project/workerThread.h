#pragma once
#include <qthread.h>

#include "polynomial_interpolation.h"
//
#include <mat.h>
#include <matrix.h>



#pragma comment (lib, "libmx.lib")
#pragma comment (lib, "libmat.lib")
#pragma comment (lib, "mclmcr.lib")
#pragma comment (lib, "mclmcrrt.lib")
#pragma comment (lib, "libmex.lib")
#pragma comment (lib, "libeng.lib")

#pragma comment(lib, "polynomial_interpolation.lib")

//
#include <QDateTime>
class workerThread :
    public QThread
{
    Q_OBJECT

public :

    // 文件路径
    QString datapath;
    // 区间大小
    int interval;
    // 阶次设置
    int degree;

    workerThread(QString datapath, int interval, int degree);
    void run() override;
signals:
    void resultsReady(double, double, double);

    // 图片 发送信号
    void send_image1(QString);
    void send_image2(QString);
    void send_image3(QString);
    void send_image4(QString);


};

