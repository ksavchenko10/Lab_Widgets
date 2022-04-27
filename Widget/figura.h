#ifndef FIGURA_H
#define FIGURA_H
#include <QtGui>
#include <QWidget>

class Figura
{
protected:
    int x,y,halflen,dx,dy,r; // параметры фигуры
    virtual void draw(QPainter *Painter)=0; // перерисовка
public:
    Figura(int X,int Y,int Halflen): // конструктор
                                 x(X),y(Y),halflen(Halflen){}
    void move(float Alpha,QPainter *Painter); // пересчитывания угла и вызов перерисовки
};
class MyLine:public Figura // класс линии
{
protected:
    void draw(QPainter *Painter);
public:
    MyLine(int x,int y,int halflen):Figura(x,y,halflen){} // конструктор
};
class MyRect:public Figura // класс квадрата
{
protected:
    void draw(QPainter *Painter);
public:
    MyRect(int x,int y,int halflen):Figura(x,y,halflen){} // конструктор
};
#endif // FIGURA_H
