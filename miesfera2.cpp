#include "miesfera2.h"

miesfera2::miesfera2()
{
}

QRectF miesfera2::boundingRect() const
{
    return QRectF(15,15,15,15);
}

void miesfera2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

