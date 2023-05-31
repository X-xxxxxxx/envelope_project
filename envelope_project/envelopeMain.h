#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_envelopeMain.h"

class envelopeMain : public QMainWindow
{
    Q_OBJECT

public:
    envelopeMain(QWidget *parent = nullptr);
    ~envelopeMain();

private:
    Ui::envelopeMainClass ui;
};
