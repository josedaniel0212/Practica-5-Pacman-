#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
using namespace::std;
using std::vector;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    scene=new QGraphicsScene(0,0,600,600);
    ui->graphicsView->setScene(scene);

    puntuacion = -1;
    moverIx1=false;
    moverDx1=false;
    moverUy1=false;
    moverDy1=false;
    moveri=true;
    moverd=true;
    movera=true;
    moverm=true;

    //ui->graphicsView->setBackgroundBrush((Qt::black));
    //ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/fondo.jpg")));

    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(animar()));
    connect(this,SIGNAL(aviso(int)),this,SLOT(aumentarPunt()));
    connect(this,SIGNAL(aviso2(int)),this,SLOT(aumentarPunt2()));

    timer->start(100);

    muro=new pared();
    scene->addItem(muro);
    muro->setPos(30,30);

    pac=new pacman();
    scene->addItem(pac);
    pac->setPos(pac->x1,pac->y1);

    int h=0;
    int r=0;
    for(int i=0; i<20; i++){
        r=r+30;
        h=0;
        for(int j=0; j<20; j++){
            h=h+30;
       if(muro->mapa[i][j]=='X'){
           lab[i][j]=new pared();
           bola[i][j]=new miesfera();
           bola3[i][j]=new miesfera2();
           scene->addItem(lab[i][j]);
           lab[i][j]->setPos(0+(r-60),0+(h-60));
        }
       //AGREGADO
       else if(muro->mapa[i][j]==' '){
           lab[i][j]=new pared();
           bola[i][j]=new miesfera();
           bola3[i][j]=new miesfera2();
           scene->addItem(bola[i][j]);
           bola[i][j]->setPos(0+(r-30),0+(h-30));
       }
       else if(muro->mapa[i][j]=='3'){
           lab[i][j]=new pared();
           bola[i][j]=new miesfera();
           bola3[i][j]=new miesfera2();
           scene->addItem(bola3[i][j]);
           bola3[i][j]->setPos(0+(r-37),0+(h-37));
       }
       else{
           lab[i][j]=new pared();
           bola[i][j]=new miesfera();
           bola3[i][j]=new miesfera2();
       }
    }
    }

    l1=new QGraphicsLineItem(0,0,600,0);
    l2=new QGraphicsLineItem(0,0,0,600);
    l3=new QGraphicsLineItem(600,0,600,600);
    l4=new QGraphicsLineItem(0,600,600,600);
    scene->addItem(l1);
    scene->addItem(l2);
    scene->addItem(l3);
    scene->addItem(l4);
}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}

void MainWindow::animar()
{
    if(moverIx1)
    {
        pac->setPos(pac->x()-30,pac->y());
    }
    if(moverDx1)
    {
        pac->setPos(pac->x()+30,pac->y());
    }
    if(moverUy1)
    {
        pac->setPos(pac->x(),pac->y()-30);
    }
    if(moverDy1)
    {
        pac->setPos(pac->x(),pac->y()+30);
    }

    int d=0;
    int c=0;
    int g=0;
    int t=0;
    int l=0;
    int m=0;

    for(int i=0; i<20;i++){
        for(int j=0; j<20;j++){
            if(pac->collidesWithItem(lab[i][j])==true and muro->mapa[i][j]=='X'){
                d=j;
                c=i;
            }
            else if(pac->collidesWithItem(bola[i][j])==true and muro->mapa[i][j]==' '){
                g=i;
                t=j;
            }
            else if(pac->collidesWithItem(bola3[i][j])==true and muro->mapa[i][j]=='3'){
                l=i;
                m=j;
            }
         }
    }
    if(pac->collidesWithItem(bola[g][t]))
    {
        if(bola[g][t]->isVisible()){
            bola[g][t]->hide();
            emit aviso(1);
        }
    }
    else if(pac->collidesWithItem(bola3[l][m]))
    {
        if(bola3[l][m]->isVisible()){
            bola3[l][m]->hide();
            emit aviso2(2);
        }
    }
    else if(pac->collidesWithItem(lab[c][d]))
    {
        if(lab[c][d]->isVisible()){
            if(moverIx1)
            {
                pac->setPos(pac->x()+30,pac->y());
            }
            if(moverDx1)
            {
                pac->setPos(pac->x()-30,pac->y());
            }
            if(moverUy1)
            {
                pac->setPos(pac->x(),pac->y()+30);
            }
            if(moverDy1)
            {
                pac->setPos(pac->x(),pac->y()-30);
            }
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverIx1=true;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverDx1=true;
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverUy1=true;
    }
    else if(ev->key()==Qt::Key_Z)
    {
        moverDy1=true;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverIx1=false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverDx1=false;
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverUy1=false;
    }
    else if(ev->key()==Qt::Key_Z)
    {
        moverDy1=false;
    }
}

void MainWindow::aumentarPunt()
{
    puntuacion += 1;
    ui->lcdNumber->display(puntuacion);
    std::cout<<puntuacion<<std::endl;
}
void MainWindow::aumentarPunt2()
{
    puntuacion += 5;
    ui->lcdNumber->display(puntuacion);
    std::cout<<puntuacion<<std::endl;
}





