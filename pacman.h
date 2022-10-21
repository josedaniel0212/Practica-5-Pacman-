#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsItem>
#include <QPainter>

class pacman: public QGraphicsItem
{
public:

    pacman();
    int x1=120;
    int y1=210;
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mover();
    void choque();

};

#endif // PACMAN_H
