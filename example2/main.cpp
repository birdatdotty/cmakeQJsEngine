#include <QApplication>

#include "Widget.h"

#include <QJSEngine>
#include <QDebug>

#include <Console.h>

#include "script.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QJSEngine engine;

    Widget widget;
    widget.show();
    return a.exec();
}
