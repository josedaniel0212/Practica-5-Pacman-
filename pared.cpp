#include "pared.h"

pared::pared()
{

}
QRectF pared::boundingRect() const
{
    return QRectF(30,30,30,30);
}

void pared::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::cyan);
    painter->drawRect(boundingRect());
}
