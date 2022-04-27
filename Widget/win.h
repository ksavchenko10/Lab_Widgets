/*#ifndef WIN_H
#define WIN_H

#include <QtGui>
#include <QWidget>
#include <QTextCodec>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextCodec>

class Counter:public QLineEdit // класс поля ввода
{
 Q_OBJECT // макрос Qt, обеспечивающий корректное создание сигналов и слотов
public:
 Counter(const QString & contents, QWidget *parent=0): // конструктор
 QLineEdit(contents,parent){}
signals:
 void tick_signal(); // добавляем сигнал tick_signal
public slots:
 void add_one() // метод прибавляющий счетчик при нажатии кнопки +1
 {
 QString str=text(); // берем текст из поля "счет по 1"
 int r=str.toInt(); // переводим в число
 if (r!=0 && r%5 ==0) emit tick_signal(); // если произошло 5 щелчков, отправляем сигнал чтобы увеличит на 1 поле "счет по 5"
 r++; // прибавляем счетчик
 str.setNum(r); // переводим число в строку
 setText(str); // записываем в поле "счет по 1" новое число
 }
};
class Win: public QWidget
{
 Q_OBJECT
protected:
 QTextCodec *codec; // для отображения кириллицы
 QLabel *label1,*label2; // метка ввода
 Counter *edit1,*edit2; // счетчик
 QPushButton *calcbutton; // кнопка +1
 QPushButton *exitbutton; // кнопка Выход
public:
 Win(QWidget *parent = 0); // конструктор
};
#endif // WIN_H
*/
