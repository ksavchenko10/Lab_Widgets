#include "area.h"
#include <QWidget>

Area::Area(QWidget *parent):QWidget(parent)
{
     setFixedSize(QSize(300,200));
     myline=new MyLine(80,100,50); // создаем линию
     myrect=new MyRect(220,100,50); // создаем квадрат
     alpha=0; // угол
}
void Area::showEvent(QShowEvent *)
{
     myTimer=startTimer(50); // создать таймер
}
void Area::paintEvent(QPaintEvent *) // перерисовываем фигуры с новым углом
{
    QPainter painter(this);
    painter.setPen(Qt::red); // задаем красный цвет
    myline->move(alpha,&painter); // перерисовываем линию с новым углом
    myrect->move(alpha*(-0.5),&painter); // перерисовываем квадрат с новым углом
}
void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimer) // если наш таймер
    {
       alpha=alpha+0.2; // прибавить угол
       update(); // обновить внешний вид
    }
    else
       QWidget::timerEvent(event); // иначе передать для стандартной
 // обработки
}
void Area::hideEvent(QHideEvent *)
{
     killTimer(myTimer); // уничтожить таймер
}
Area::~Area() // деструктор
{
    delete myline; // уничтожаем  myline
    delete myrect; // уничтожаем  myrect
}
