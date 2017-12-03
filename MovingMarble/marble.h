#ifndef MARBLE_H
#define MARBLE_H

#include<QTimer>
#include<QTimerEvent>
#include<QPainter>

class Marble : public QTimer
{
public:
    Marble(QWidget *parent);
    void draw(QPainter &painter);
    int getY();
    int getX();
    float getSX();

protected:
    QWidget *parent=NULL;
    int x;
    int y;
    float sx=1;
    float sy=1;

    // QObject interface
protected:
    void timerEvent(QTimerEvent *event);
};

#endif // MARBLE_H
