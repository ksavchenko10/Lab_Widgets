#include "win.h"
#include "QVBoxLayout"
#include "QMessageBox"
#include "QTextCodec"


Win::Win(QWidget *parent):QWidget(parent)
{
     codec = QTextCodec::codecForName("UTF-8");
     setWindowTitle(codec->toUnicode("Возведение в квадрат"));
     frame = new QFrame(this);
     frame->setFrameShadow(QFrame::Raised);
     frame->setFrameShape(QFrame::Panel);
     inputLabel = new QLabel(codec->toUnicode("Введите число:"),
     this);
     inputEdit = new QLineEdit("",this);
     StrValidator *v=new StrValidator(inputEdit);
     inputEdit->setValidator(v);
     outputLabel = new QLabel(codec->toUnicode("Результат:"),
     this);
     outputEdit = new QLineEdit("",this);
     nextButton = new QPushButton(codec->toUnicode("Следующее"),
     this);
     exitButton = new QPushButton(codec->toUnicode("Выход"),
     this);
     // компоновка приложения выполняется согласно рисунку 2.
     QVBoxLayout *vLayout1 = new QVBoxLayout(frame); // создание менеджера компоновки для управления размещением элементов ввода вывода в окне win
     vLayout1->addWidget(inputLabel); // добавление метки ввода к компоновщику
     vLayout1->addWidget(inputEdit); // добавление формы ввода к компоновщику
     vLayout1->addWidget(outputLabel); // добавление метки вывода к компоновщику
     vLayout1->addWidget(outputEdit); // добавление формы вывода к компоновщику
     vLayout1->addStretch(); //"Пружина", поджатие элементов друг к другу
     QVBoxLayout *vLayout2 = new QVBoxLayout();  // создание менеджера компоновки для управления размещением кнопок в окне win
     vLayout2->addWidget(nextButton);  // добавление кнопки "следующий" к компоновщику
     vLayout2->addWidget(exitButton); // добавление кнопки "выход" к компоновщику
     vLayout2->addStretch(); //"Пружина", поджатие элементов друг к другу
     QHBoxLayout *hLayout = new QHBoxLayout(this); //создание менеджера компоновки для управления фреймом в окне win
     hLayout->addWidget(frame); //добавление фрейма к компоновщику
     hLayout->addLayout(vLayout2); //добавление компоновщика кнопок к компоновику фрейма
     begin();
     connect(exitButton,SIGNAL(clicked(bool)),
     this,SLOT(close())); // закрытие окна на нажатие кнопки выход
     connect(nextButton,SIGNAL(clicked(bool)),
     this,SLOT(begin())); // вызов метода begin на нажатие кнопки следующий
     connect(inputEdit,SIGNAL(returnPressed()), // вызов метода  calc на завершение ввода в поле ввода "введите число"
     this,SLOT(calc()));
}
void Win::begin()
{
     inputEdit->clear(); // очистить поле ввода
     nextButton->setEnabled(false); // кнопку следующий сделать неактивной
     nextButton->setDefault(false); // сделать неактивной по умолчанию, чтобы при нажатии на enter кнопка не активировалась
     inputEdit->setEnabled(true); // поле ввода числа сделать неактивным
     outputLabel->setVisible(false); // поле метки вывода результата скрыть
     outputEdit->setVisible(false); // поле вывода результата скрыть
     outputEdit->setEnabled(false); // поле вывода результата сделать неактивным
     inputEdit->setFocus(); // установить фокус в поле ввода числа
}
void Win::calc() // запускается после окончания вводе числа
{
     bool Ok=true; float r,a;
     QString str=inputEdit->text();
     a=str.toDouble(&Ok); // переводим введенную строку в числовой формат
     if (Ok) // если число введено
     {
     r=a*a; // возводим в квадрат
     str.setNum(r); // переводим число в строку и приправаем к переменной str
     outputEdit->setText(str); // в поле вывода результат вводим получившийся результат
     inputEdit->setEnabled(false); // поле ввода числа делаем неактивным
     outputLabel->setVisible(true); // показываем метку поля вывода резльтата
     outputEdit->setVisible(true); // показываем  поле вывода резльтата
     nextButton->setDefault(true); // делаем кнопку следующий активной по умолчанию
     nextButton->setEnabled(true); // делаем кнопку следующий активной
     nextButton->setFocus(); // устанавливаем фокус на кнопке следующий
     }
     else
     if (!str.isEmpty()) // если введенная строка не пустая и не равна числу
     {
     QMessageBox msgBox(QMessageBox::Information,  // создаем окно уведомления
     codec->toUnicode("Возведение в квадрат."), // название окна
     codec->toUnicode("Введено неверное значение."), // текст окна
     QMessageBox::Ok); // добавляем кнопку ОК
     msgBox.exec(); // вызов окна с уведомлением
     }
}
