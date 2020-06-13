#include <QCoreApplication>

#include <QJSEngine>
#include <QDebug>

#include <Console.h>

#include "script.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QJSEngine engine;

    Console console;
//    console.log("sadsad");

    QJSValue jsConsole = engine.newQObject(&console);
    engine.globalObject().setProperty("Console", jsConsole);
    engine.globalObject().setProperty("console", jsConsole);

    QJSValue result = engine.evaluate(SCRIPT);
    if (result.isError())
        qInfo()
                << "Uncaught exception at line"
                << result.property("lineNumber").toInt()
                << ":" << result.toString();

//    return a.exec();
}
