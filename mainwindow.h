#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include "miesfera.h"
#include "miesfera2.h"
#include "pared.h"
#include "pacman.h"
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void aviso(int);
    void aviso2(int);
    void aviso3(int);

public slots:
    void animar();
    void aumentarPunt();
    void aumentarPunt2();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsRectItem* barra;
    QGraphicsRectItem* barra2;
    QGraphicsLineItem* l1;
    QGraphicsLineItem* l2;
    QGraphicsLineItem* l3;
    QGraphicsLineItem* l4;
    miesfera* bola[20][20];
    miesfera* bola1;
    miesfera2* bola2;
    pared* muro;
    pared* lab[20][20];
    miesfera2* bola3[20][20];
    pacman* pac;
    QTimer *timer;

    int puntuacion;
    bool moverIx1;
    bool moverDx1;
    bool moverUy1;
    bool moverDy1;
    bool mover2;
    bool moveri;
    bool moverd;
    bool movera;
    bool moverm;

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
};
#endif // MAINWINDOW_H

