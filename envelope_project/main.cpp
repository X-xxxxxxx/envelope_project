#include "envelopeMain.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    envelopeMain w;
    w.show();
    return a.exec();
}
