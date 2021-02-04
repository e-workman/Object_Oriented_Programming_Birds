#include "ControlWindow.h"
#include "ui_controlwindow.h"
#include <QTimer>
#include <iostream>
#include <cmath>
#include <QMessageBox>

ControlWindow::ControlWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlWindow)
{
    ui->setupUi(this);
    ui->runButton->setStyleSheet("background-color:green");
}

ControlWindow::~ControlWindow()
{
    delete ui;
}

//slot that determins what happens when run buttton is clicked:
void ControlWindow::on_runButton_clicked()
{
        //Sets data member fInputFlock equal to a new flock on the heap
        fInputFlock = new Flock();

        //user inputs number of starlings and number of larks:
        int NStarlings = ui->lineEdit->text().toInt();
        int NLarks = ui->lineEdit_2->text().toInt();

        //produces the flock:
        fInputFlock->CreateFlock(NStarlings, NLarks);

        //timer is created on the heap:
        QTimer * timer = new QTimer(this);
        //The timeout function of the timer, which is called every time the timer times out, is connected to DisplaySimulate via a signal-slot mechanism.
        //This means that every time the timer times out, DisplaySimulate is called.
        connect(timer, SIGNAL(timeout()), this, SLOT(DisplaySimulate()));

        //timer is started and runs every 15 ms.
        timer->start(15);

        //instance of display window is created and set equal to fBirdsDisplayWindow:
        fBirdsDisplayWindow = new DisplayWindow(fInputFlock);

        //display window is shown on the screen:
        fBirdsDisplayWindow->show();
}



//DisplaySimulate calls on Simulate in the flock:
void ControlWindow::DisplaySimulate() {
   fInputFlock->Simulate();
}


