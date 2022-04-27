#ifndef WINDOW_H
#define WINDOW_H
#include <QtGui>
#include "area.h"
#include <QWidget>
#include <QPushButton>

class Window : public QWidget
{
protected:
    QTextCodec *codec;
    Area * area; // область отображения рисунка
    QPushButton * btn; // кнопка завершить
public:
    Window(); // конструктор
};
#endif // WINDOW_H
