#include "Widget.h"

#include <QDebug>
#include "script.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      btn1("btn 1"),
      btn2("btn 2")
{
    mainLayout.addWidget(&btn1);
    mainLayout.addWidget(&btn2);

    connect(&btn1, &QPushButton::released, this, &Widget::clickBtn1);
    connect(&btn2, &QPushButton::released, this, &Widget::clickBtn2);

    setLayout(&mainLayout);

    QJSValue  jsConsole = engine.newQObject(&console);
    engine.globalObject().setProperty("Console", jsConsole);
    engine.globalObject().setProperty("console", jsConsole);

    QJSValue jsBody = engine.evaluate(SCRIPT);
    if (jsBody.isError())
        qInfo()
                << "Uncaught exception at line"
                << jsBody.property("lineNumber").toInt()
                << ":" << jsBody.toString();

    t1 = engine.globalObject().property("t1");
    t2 = engine.globalObject().property("t2");
}

void Widget::clickBtn1()
{
    t1.call();
}

void Widget::clickBtn2()
{
    t2.call();
}
