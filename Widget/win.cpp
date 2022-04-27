#include "win.h"
#include "QVBoxLayout"
#include "QMessageBox"
#include "QTextCodec

Win::Win(QWidget *parent):QWidget(parent)
{
 codec = QTextCodec::codecForName("UTF-8");
 this->setWindowTitle(codec->toUnicode("Счетчик"));
 label1 = new QLabel(codec->toUnicode("Cчет по 1"),this);
 label2 = new QLabel(codec->toUnicode("Cчет по 5"),this);
 edit1 = new Counter("0",this);
 edit2 = new Counter("0",this);
 calcbutton=new QPushButton("+1",this);
 exitbutton=new QPushButton(codec->toUnicode("Выход"),this);

 QHBoxLayout *layout1 = new QHBoxLayout(); // создание менеджера компоновки для управления размещением меток
 layout1->addWidget(label1); // метка "счет по 1"
 layout1->addWidget(label2); // метка "счет по 5"
 QHBoxLayout *layout2 = new QHBoxLayout(); // создание менеджера компоновки для управления размещением элементов ввода вывода
 layout2->addWidget(edit1); // поле ввода "счет по 1"
 layout2->addWidget(edit2); // поле ввода "счет по 5"
 QHBoxLayout *layout3 = new QHBoxLayout(); // создание менеджера компоновки для управления размещением кнопок
 layout3->addWidget(calcbutton); // кнопка +1
 layout3->addWidget(exitbutton); // кнопка выход
 QVBoxLayout *layout4 = new QVBoxLayout(this); // создание менеджера компоновки для управления размещением других менеджеров покмпоновок
 layout4->addLayout(layout1); // добавление компоновщика меток к общему компоновщику
 layout4->addLayout(layout2); // добавление компоновщика полей ввода к общему компоновщику
 layout4->addLayout(layout3); // добавление компоновщика кнопок к общему компоновщику
 // связь сигнала нажатия кнопки и слота закрытия окна
 connect(calcbutton,SIGNAL(clicked(bool)),
 edit1,SLOT(add_one())); // связь сигнала нажатия кнопки "+1" и вызова метода add_one
 connect(edit1,SIGNAL(tick_signal()),
 edit2,SLOT(add_one())); // связь сигнала tick_signal для прибавления поля "счет по 5"
 connect(exitbutton,SIGNAL(clicked(bool)),
 this,SLOT(close())); // связь сигнала нажатия кнопки и слота закрытия окна
}
