#ifndef VACIO_H
#define VACIO_H


#include <QGraphicsItem>
#include <QPainter>


class vacio: public QGraphicsItem
{
public:
    vacio();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // VACIO_H
