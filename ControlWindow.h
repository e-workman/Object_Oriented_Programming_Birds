#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H

#include <QMainWindow>
#include "flock.h"
#include "DisplayWindow.h"

namespace Ui {
class ControlWindow;
}

class ControlWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ControlWindow(QWidget *parent = 0);
    ~ControlWindow();

private slots:
    //slot which determines what happens when run button is clicked:
    void on_runButton_clicked();

    //slot connected to timer, calls simulate every time timer runs out:
    void DisplaySimulate();

private:
    //private variables

    Ui::ControlWindow *ui;

    //contains flock of birds:
    Flock* fInputFlock;

    //Display window variable:
    //creating an object of a pointer to display window:
    DisplayWindow *fBirdsDisplayWindow;
};

#endif // CONTROLWINDOW_H
