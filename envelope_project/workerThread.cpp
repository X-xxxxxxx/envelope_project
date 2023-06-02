#include "workerThread.h"

#include <qDebug>

workerThread::workerThread(QString datapath, int interval, int degree, int choose_option)
	:datapath(datapath), interval(interval), degree(degree), choose_option(choose_option)
{
	qDebug() << QStringLiteral("���̳߳�ʼ���ɹ�") << endl;
}

void workerThread::run()
{		
	double icp = 0, imwp = 0, mwd = 0;
	qDebug() << QStringLiteral("���߳̿����ɹ�") << endl;
	if (polynomial_interpolationInitialize() && envo_splineInitialize())
	{
		qDebug() << QStringLiteral("dll ע��ɹ�") << endl;


		qDebug() << datapath << endl;
		qDebug() << interval << endl;
		qDebug() << degree << endl;
		// ·��ѡȡ
		std::string datapath_str = datapath.toStdString();
		const char* datapath_str_to_mw = datapath_str.c_str();
		mwArray data_path(datapath_str_to_mw);

		// �����С����
		mwArray interval_to_mw(interval, mxDOUBLE_CLASS);
		// �״�����
		mwArray degree_to_mw(degree, mxDOUBLE_CLASS);

		// ͼƬ����·��
		QString fig_savepath = "C:/Users/X_xx/Desktop/res_save";
		std::string fig_savepath_str = fig_savepath.toStdString();
		const char* fig_savepath_char = fig_savepath_str.c_str();
		mwArray fig_savepath_to_mw(fig_savepath_char);

		// ��ȡ���ڲ���
		QDateTime date_time = QDateTime::currentDateTime();//��ȡϵͳ��ǰ��ʱ��
		QString qstr = date_time.toString("yyyy-MM-dd_hh-mm-ss");//��ʽ��ʱ��
		std::string dateqstr_str = qstr.toStdString();
		const char* datestr_to_mw = dateqstr_str.c_str();

		qDebug() << datestr_to_mw << endl;

		mwArray cur_time(datestr_to_mw); // time str ����

		// ���ñ������� ���

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

		qDebug() << QStringLiteral("�����̷߳��͵�һ��ͼƬ") << endl;
		msleep(1000);
		emit send_image1(qstr); // ����Ϊ ��ǰʱ��


		qDebug() << QStringLiteral("�����̷߳��͵ڶ���ͼƬ") << endl;
		msleep(1000);
		emit send_image2(qstr); // ����Ϊ ��ǰʱ��


		qDebug() << QStringLiteral("�����̷߳��͵�����ͼƬ") << endl;
		msleep(1000);
		emit send_image3(qstr); // ����Ϊ ��ǰʱ��


		qDebug() << QStringLiteral("�����̷߳��͵�����ͼƬ") << endl;
		msleep(1000);
		emit send_image4(qstr); // ����Ϊ ��ǰʱ��

		qDebug() << icp << "    " << imwp << "    " << mwd << endl;

		polynomial_interpolationTerminate();

		envo_splineTerminate();
		mclTerminateApplication();
	}

	qDebug() << QStringLiteral("���߳�������ʱ1��") << endl;
	msleep(1000);

	qDebug() << QStringLiteral("��������� ׼�������̷߳��ͽ��") << endl;
	emit resultsReady(icp, imwp, mwd);
}
