#include "racket1.h"

#include <QRect>
#include <QWidget>

Racket1::Racket1(QWidget *parent)
{
    this->parent=parent;

    this->y= rand() % (parent->height()-50);
}

void Racket1::draw(QPainter &painter)
{
    painter.drawRect(QRect(0,this->y, 10, 50));
}

void Racket1::update(QKeyEvent *event)
{
    switch ( event->key() )
    {
        case Qt::Key_Up:
            if(this->y>0)
                this->y-=step;
            break;
        case Qt::Key_Down:
            if(this->y<parent->height()-50)
                this->y+=step;
            break;
    }
}
