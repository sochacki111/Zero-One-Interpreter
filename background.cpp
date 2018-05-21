#include "background.h"

using namespace std;

Background::Background()
{

}

void Background::fillBackgroundWithSquares(QGraphicsScene *scene)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            squares[i][j] = new Square(i*10,j*10);
            scene->addItem(squares[i][j]);
        }
}

void Background::cleanBackground()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if ( squares[i][j]->getValue() == 1 )
            {
                squares[i][j]->setBrush(Qt::cyan);
                squares[i][j]->setValue(0);
            }
}


void Background::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Shift)
    {
        knn.setSquares(squares);        knn.searchkNN();
        //database.putValuesIntoDatabase(squares);
    }
    cleanBackground();
}
