#ifndef PARED_H
#define PARED_H

#include <QGraphicsItem>
#include <QPainter>

class pared: public QGraphicsItem
{
public:
    pared();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);

    //MODIFICADO
    char mapa[20][20]={
        //X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,"
       'X','X','X','X','X','0','0','X','X','X','0','0','X','X','X','X','X','X','X','X',
       'X',' ',' ',' ','X','0','0','X',' ','X','0','0','X','X',' ','3',' ',' ',' ','X',
       'X',' ','X',' ','X','0','0','X',' ','X','0','0','X',' ',' ','X',' ','X',' ','X',
       'X',' ','X',' ','X','X','X','X',' ','X','X','X','X',' ','X','X',' ','X',' ','X',
       'X','3',' ',' ',' ',' ',' ',' ',' ',' ','3',' ',' ',' ',' ',' ',' ','X','3','X',
       'X',' ','X',' ','X','X','X','X','X',' ','X','X',' ','X','X','X','X','X',' ','X',
       'X',' ','X',' ',' ',' ','X',' ',' ',' ',' ',' ','3',' ',' ',' ',' ',' ',' ','X',
       'X',' ','X',' ','X',' ','X',' ','X','X','X','X',' ','X',' ','X','X',' ','X','X',
       'X',' ',' ',' ','X',' ','3',' ','X',' ',' ','X',' ','X',' ',' ','X',' ',' ','X',
       'X','X','X',' ','X','X','X',' ',' ',' ','3','X',' ','X','X',' ','X','X',' ','X',
       'X','X','X',' ','X','X','X',' ',' ',' ','3','X',' ','X','X',' ','X','X',' ','X',
       'X',' ',' ',' ','X',' ','3',' ','X',' ',' ','X',' ','X',' ',' ','X',' ',' ','X',
       'X',' ','X',' ','X',' ','X',' ','X','X','X','X',' ','X',' ','X','X',' ','X','X',
       'X',' ','X',' ',' ',' ','X',' ',' ',' ',' ',' ','3',' ',' ',' ',' ',' ',' ','X',
       'X',' ','X',' ','X','X','X','X','X',' ','X','X',' ','X','X','X','X','X',' ','X',
       'X','3',' ',' ',' ',' ',' ',' ',' ',' ','3',' ',' ',' ',' ',' ',' ','X','3','X',
       'X',' ','X',' ','X','X','X','X',' ','X','X','X','X',' ','X','X',' ','X',' ','X',
       'X',' ','X',' ','X','0','0','X',' ','X','0','0','X',' ',' ','X',' ','X',' ','X',
       'X',' ',' ',' ','X','0','0','X',' ','X','0','0','X','X',' ','3',' ',' ',' ','X',
       'X','X','X','X','X','0','0','X','X','X','0','0','X','X','X','X','X','X','X','X',

    };


};

#endif // PARED_H
