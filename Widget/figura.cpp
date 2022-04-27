#include <math.h>
#include "figura.h"

void Figura::move(float Alpha,QPainter *Painter) // перерисовываем фигуру с новым углом
{
    dx=halflen*cos(Alpha); // высчитываем смещение по х исходя из нового угла
    dy=halflen*sin(Alpha); // высчитываем смещение по y исходя из нового угла
    draw(Painter); // вызываем перерисовку фигуры
}
void MyLine::draw(QPainter *Painter)
{
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy); // рисуем линию по новым координатам
}
void MyRect::draw(QPainter *Painter)
{
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx); // рисуем сторону квадрата по новым координатам
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy); // рисуем сторону квадрата по новым координатам
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx); // рисуем сторону квадрата по новым координатам
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy); // рисуем сторону квадрата по новым координатам
}
