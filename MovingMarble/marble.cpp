#include "marble.h"

#include <QRect>
#include <QWidget>
#include <QDebug>
#include <time.h>

Marble::Marble(QWidget *parent)
{
    this->parent=parent;

    //QRect rect= this->parent->rect();
    srand(time(NULL));
    this->x= 15+ rand() % (parent->width()-25)/2;
    this->y= rand() % (parent->height()-15);

    start(8);
}

void Marble::draw(QPainter &painter)
{
    painter.drawEllipse(this->x,this->y,15,15);
}

int Marble::getY()
{
    return this->y;
}

int Marble::getX()
{
    return this->x;
}

float Marble::getSX()
{
    return this->sx;
}

void Marble::timerEvent(QTimerEvent *event)
{
    QRect rect= this->parent->rect();
    if(this->x<10 || this->x >rect.width()-25) this->sx *=-1;
    if(this->y<0 || this->y >rect.height()-15) this->sy *=-1;

    this->x+=this->sx;
    this->y+=this->sy;
    this->parent->update();
}
