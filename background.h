#ifndef BACKGROUND_H
#define BACKGROUND_H


#include <iostream>
#include <fstream>

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>

#include "square.h"
#include "database.h"
#include "knn.h"

#define N 10
#define M 10
using namespace std;

class Background: public QGraphicsView
{
public:
    Background();
    void fillBackgroundWithSquares(QGraphicsScene *scene);
    void cleanBackground();
    void dispBackground();
protected:
    void keyReleaseEvent(QKeyEvent *event);
private:
    Square *squares[N][M];
    Database database;
    kNN knn;

};

#endif // BACKGROUND_H
