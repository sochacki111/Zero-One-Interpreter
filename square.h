#ifndef SQUARE_H
#define SQUARE_H

#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QDebug>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>

class Square : public QGraphicsRectItem
{
public:
    Square(int x, int y);

    int getValue();
    void setValue(int value);

private:
    QPen pen;
    int value;
protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
};

#endif // SQUARE_H
