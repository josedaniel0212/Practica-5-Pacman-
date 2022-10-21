#include "pacman.h"

pacman::pacman()
{

}

QRectF pacman::boundingRect() const
{

    return QRectF(0,0,30,30);
}

void pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes/pacman.jpg");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
