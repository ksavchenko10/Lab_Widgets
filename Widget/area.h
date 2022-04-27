#ifndef AREA_H
#define AREA_H
#include <figura.h>

class Area : public QWidget
{
    int myTimer; // идентификатор таймера
    float alpha; // угол поворота
public:
    Area(QWidget *parent = 0); // конструктор
    ~Area(); // деструктор
    MyLine *myline; // линия
    MyRect *myrect; // квадрат
protected:
// обработчики событий
    void paintEvent(QPaintEvent *event); // перерисовываем фигуры с новым углом
    void timerEvent(QTimerEvent *event); // события таймера для изменения угла
    void showEvent(QShowEvent *event); // создание таймера
    void hideEvent(QHideEvent *event); // уничтожение таймера
};

#endif // AREA_H
