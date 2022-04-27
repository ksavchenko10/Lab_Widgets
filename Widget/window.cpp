#include "window.h"
#include <QVBoxLayout>

Window::Window()
{
    codec = QTextCodec::codecForName("UTF-8");
    this->setWindowTitle(codec->toUnicode("Обработка событий"));
    area = new Area( this );
    btn = new QPushButton(codec->toUnicode("Завершить"),this ); // создание кнопки завершить
    QVBoxLayout *layout = new QVBoxLayout(this); // создаем компановщик
    layout->addWidget(area); // добавляем холст к компановщику
    layout->addWidget(btn); // добавляем кнопку к компановщику
    connect(btn, SIGNAL(clicked(bool)),this,SLOT(close())); // связываем события нажатия кнопки выход
};
