#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QJSEngine>

#include "Console.h"

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);

    QPushButton btn1;
    QPushButton btn2;
    QGridLayout mainLayout;

    QJSEngine engine;
    Console console;

    QJSValue t1;
    QJSValue t2;

private slots:
    void clickBtn1();
    void clickBtn2();
};

#endif // WIDGET_H
