#include "square.h"

Square::Square(int x, int y)
{
    // draw a square
    setRect(x,y,10,10);
    pen.setBrush(Qt::NoBrush);
    // obramowanie kwadratu kolorem
    setPen(pen);
    // wypelnienie kwadratu kolorem
    setBrush(Qt::cyan);
    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::LeftButton);
    show();
    value = 0;

}

int Square::getValue()
{
    return value;
}

void Square::setValue(int value)
{
    this->value = value;
}


void Square::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{

    if ( brush().color() != Qt::black && event->modifiers() & Qt::ShiftModifier)
    {
        value = 1;
        //setValue(1);
        setBrush( Qt::black );
        update();
    }

}


