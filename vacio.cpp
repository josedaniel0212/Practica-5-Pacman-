#include "vacio.h"

vacio::vacio()
{

}
QRectF vacio::boundingRect() const
{

    //0+(r-30),0+(h-30)
    return QRectF(0,0,30,30);
}

void vacio::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::darkBlue);
    //painter->drawEllipse(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/Imagenes/roca.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
