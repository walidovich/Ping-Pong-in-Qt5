#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QKeyEvent>
#include<QDebug>
#include<QThread>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->marble= new Marble(this);
    this->racket1= new Racket1(this);
    this->racket2= new Racket2(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(this->rect(),QBrush(QColor(Qt::darkGray)));

    painter.setPen(Qt::black);
    painter.setBrush(QBrush(QColor(Qt::white)));
    this->marble->draw(painter);

    painter.setBrush(QBrush(QColor(Qt::red)));
    this->racket1->draw(painter);

    painter.setBrush(QBrush(QColor(Qt::blue)));
    this->racket2->draw(painter);

    racket2->update(marble->getX(), marble->getY(), marble->getSX());

    if(marble->getX()<10 &&
            (racket1->y > marble->getY()+10 || racket1->y < marble->getY()-50-10))
    {
        stopGame();
    }
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    racket1->update(event);
}

void MainWindow::resetGame()
{
    this->marble= new Marble(this);
    this->racket1= new Racket1(this);
    this->racket2= new Racket2(this);
}

void MainWindow::stopGame()
{
    this->marble->stop();
    this->racket1->stop();
    this->racket2->stop();
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "You've lost !!","Would you like to play again?",
                                    QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        resetGame();
    }else{
        QApplication::quit();
    }
}
