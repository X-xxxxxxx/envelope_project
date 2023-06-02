#include "workerThread.h"

#include <qDebug>

workerThread::workerThread(QString datapath, int interval, int degree, int choose_option)
	:datapath(datapath), interval(interval), degree(degree), choose_option(choose_option)
{
	qDebug() << QStringLiteral("子线程初始化成功") << endl;
}

void workerThread::run()
{		
	double icp = 0, imwp = 0, mwd = 0;
	qDebug() << QStringLiteral("子线程开启成功") << endl;
	if (polynomial_interpolationInitialize() && envo_splineInitialize())
	{
		qDebug() << QStringLiteral("dll 注入成功") << endl;


		qDebug() << datapath << endl;
		qDebug() << interval << endl;
		qDebug() << degree << endl;
		// 路径选取
		std::string datapath_str = datapath.toStdString();
		const char* datapath_str_to_mw = datapath_str.c_str();
		mwArray data_path(datapath_str_to_mw);

		// 区间大小设置
		mwArray interval_to_mw(interval, mxDOUBLE_CLASS);
		// 阶次设置
		mwArray degree_to_mw(degree, mxDOUBLE_CLASS);

		// 图片保存路径
		QString fig_savepath = "C:/Users/X_xx/Desktop/res_save";
		std::string fig_savepath_str = fig_savepath.toStdString();
		const char* fig_savepath_char = fig_savepath_str.c_str();
		mwArray fig_savepath_to_mw(fig_savepath_char);

		// 获取日期参数
		QDateTime date_time = QDateTime::currentDateTime();//获取系统当前的时间
		QString qstr = date_time.toString("yyyy-MM-dd_hh-mm-ss");//格式化时间
		std::string dateqstr_str = qstr.toStdString();
		const char* datestr_to_mw = dateqstr_str.c_str();

		qDebug() << datestr_to_mw << endl;

		mwArray cur_time(datestr_to_mw); // time str 参数

		// 设置变量接收 结果

		mwArray idx1(1, mxDOUBLE_CLASS);
		mwArray idx2(1, mxDOUBLE_CLASS);
		mwArray idx3(1, mxDOUBLE_CLASS);



		if (this -> choose_option == 1)
			polynomial_interpolation(3, idx1, idx2, idx3,
			data_path, interval_to_mw, degree_to_mw, fig_savepath_to_mw, cur_time);
		else
		{
			envo_spline(3, idx1, idx2, idx3,
				data_path, interval_to_mw, degree_to_mw, fig_savepath_to_mw, cur_time);
		}





		idx1.GetData(&icp, 1);
		idx2.GetData(&imwp, 1);
		idx3.GetData(&mwd, 1);

		qDebug() << QStringLiteral("向主线程发送第一张图片") << endl;
		msleep(1000);
		emit send_image1(qstr); // 参数为 当前时间


		qDebug() << QStringLiteral("向主线程发送第二张图片") << endl;
		msleep(1000);
		emit send_image2(qstr); // 参数为 当前时间


		qDebug() << QStringLiteral("向主线程发送第三张图片") << endl;
		msleep(1000);
		emit send_image3(qstr); // 参数为 当前时间


		qDebug() << QStringLiteral("向主线程发送第四张图片") << endl;
		msleep(1000);
		emit send_image4(qstr); // 参数为 当前时间

		qDebug() << icp << "    " << imwp << "    " << mwd << endl;

		polynomial_interpolationTerminate();

		envo_splineTerminate();
		mclTerminateApplication();
	}

	qDebug() << QStringLiteral("子线程阻塞延时1秒") << endl;
	msleep(1000);

	qDebug() << QStringLiteral("计算结束， 准备往主线程发送结果") << endl;
	emit resultsReady(icp, imwp, mwd);
}
