//#define M 20

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "square.h"
#include "background.h"

#define N 10
#define M 10

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene(0,0,N*10,M*10);

    // background pelni role widoku oraz odpowiada za wypelnienie sceny kwadratami
    Background * background = new Background();
    background->fillBackgroundWithSquares(scene);

    // add a view
    background->setScene(scene);
    background->show();


    return a.exec();
}
