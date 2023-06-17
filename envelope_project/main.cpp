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
  
    QPixmap pixmap(500, 500);//gif�����ĳߴ��С
    QSplashScreen splash(pixmap);//����QPixmap���󴴽�һ��QSplashScreen����
    QLabel label(&splash);

    //����label��С��λ��
    //QMovie mv(":/envelopeMain/start.gif");
    label.setMovie(&mv);
    mv.start();
    //��ʾ������ͼƬ
    splash.show();
    splash.setCursor(Qt::BlankCursor);
    for (int i = 0; i < 4000; i += mv.speed()) {
        a.processEvents(); //ʹ��������ʾ���������ͬʱ������Ӧ���������¼�
        Sleep(mv.speed()); // ��ʱ
    }


    CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    envelopeMain w;
    w.setWindowTitle(QStringLiteral("������ң�����ݹ������ϵͳ"));
  
    w.show();
    splash.finish(&w);
    QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);



    //QString s = desktop_path;
    //QDesktopServices::openUrl(QUrl(desktop_path));
    QDir dir(desktop_path);
    //dir.cd("./project");  //����ĳ�ļ���
    //dir.cd("./data");
    if (!dir.exists(QString::fromLocal8Bit("Result")))  //�����ļ���
    {
        qDebug() << QStringLiteral("�����ڽ���ļ���") << endl;
        dir.mkdir(QString::fromLocal8Bit("Result"));
        qDebug() << QStringLiteral("�ļ��д����ɹ�") << endl;
        dir.cd(QString::fromLocal8Bit("Result"));
        dir.mkdir(QString::fromLocal8Bit("Image"));

        dir.mkdir(QString::fromLocal8Bit("Report"));
    }

    return a.exec();
}
