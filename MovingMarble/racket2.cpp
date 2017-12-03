
#include "racket2.h"

#include <QRect>
#include <QWidget>

Racket2::Racket2(QWidget *parent)
{
    this->parent=parent;

    this->y= rand() % (parent->height()-50);
}

void Racket2::draw(QPainter &painter)
{
    painter.drawRect(QRect(parent->width()-10,this->y, 10, 50));
}

void Racket2::update(int x,int y, float sx)
{
    if(x>this->parent->height()/2 && sx>0){
        if(this->y > y-22)
            this->y-=step;
        else
            this->y+=step;
    }
}
