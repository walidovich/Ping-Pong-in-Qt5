#ifndef RACKET2_H
#define RACKET2_H

#include<QTimer>
#include<QTimerEvent>
#include<QPainter>

class Racket2 : public QTimer
{
public:
    Racket2(QWidget *parent);
    void draw(QPainter &painter);
    void update(int x, int y, float sx);
    void stopRacket2();

public:
    int y;
    int step=2;

protected:
    QWidget *parent=NULL;
};

#endif // RACKET_H
