#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QWidget>
#include "flock.h"

namespace Ui {
class DisplayWindow;
}

class DisplayWindow : public QWidget
{
    Q_OBJECT

public:
    //constructor:
    explicit DisplayWindow(Flock *MyFlock, QWidget *parent = 0);

    //destructor:
    ~DisplayWindow();

private slots:
    //function to draw birds on the display window:
    void paintEvent(QPaintEvent *);

private:
    Ui::DisplayWindow *ui;

    //an object of a pointer to the flock
    Flock *fInputFlock_Display;
};

#endif // DISPLAYWINDOW_H
