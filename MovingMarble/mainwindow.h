#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"marble.h"
#include"racket1.h"
#include"racket2.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Marble *marble;
    Racket1 *racket1;
    Racket2 *racket2;
    void resetGame();
    void stopGame();

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
