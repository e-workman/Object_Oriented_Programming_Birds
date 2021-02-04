#include "DisplayWindow.h"
#include "ui_DisplayWindow.h"

#include <QPainter>
#include <QTimer>
#include <iostream>
#include <cmath>
#include <QWidget>

DisplayWindow::DisplayWindow(Flock *MyFlock, QWidget *parent) :
    QWidget(parent), fInputFlock_Display(MyFlock),
    ui(new Ui::DisplayWindow)
{
    ui->setupUi(this);
    //background is set to black
    setStyleSheet("background-color:black");

    //using timer, function update() is called evert 20 ms:
    QTimer *timer = new QTimer(this);

    //timeout() is the signal emitted when timer times out - causes update() to be called
    //update() is a function inherited from QWidget which causes it to update
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    timer->start(15);
}

//destructor:
DisplayWindow::~DisplayWindow()
{
    delete ui;
}

void DisplayWindow::paintEvent(QPaintEvent *)
{
    //Instance of QPainter created:
    QPainter painter(this);

    //Background is set to black:
    painter.fillRect(QRect(0, 0, width() - 1, height() - 1),QPalette::Text);

    //Setting the colour of the pen drawing the objects.
    painter.setPen(palette().light().color());

    //draws each bird on the display window and loops over all birds in the flock
    for (int iBird=0; iBird < fInputFlock_Display->GetNBirds(); iBird++) {

        //Determining x position of bird:
        double position_x=fInputFlock_Display->GetBird(iBird)->GetPosition().X();

        //Determining y position of bird:
        double position_y=fInputFlock_Display->GetBird(iBird)->GetPosition().Y();

        //if bird is a starling:
        if (fInputFlock_Display->GetBird(iBird)->Species() == 1){
            int startAngle = 30 * 16;
            int spanAngle = 30 * 16;
            //drawing a sector of a circle at the position of a starling
            painter.drawPie(position_x, position_y, 15, 15, startAngle, spanAngle);
        }

        //if bird is a lark:
        if (fInputFlock_Display->GetBird(iBird)->Species() == 2){
            //Drawing a point at a positon of a lark:
            painter.drawPoint(position_x,  position_y);
        }
    }
}
