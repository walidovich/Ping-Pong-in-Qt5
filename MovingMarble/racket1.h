#ifndef RACKET1_H
#define RACKET1_H

#include<QTimer>
#include<QTimerEvent>
#include<QPainter>
#include<QKeyEvent>

class Racket1 : public QTimer
{
public:
    Racket1(QWidget *parent);
    void draw(QPainter &painter);
    void update(QKeyEvent *event);
    void stopRacket1();

public:
    int y;
    int step=10;

protected:
    QWidget *parent=NULL;
};

#endif // RACKET_H
