#include "miesfera.h"

miesfera::miesfera()
{

}

QRectF miesfera::boundingRect() const
{
    return QRectF(10,10,10,10);
}

void miesfera::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}

