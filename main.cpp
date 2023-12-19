// main.cpp
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "smartlys.h"

int main(int argc, char *argv[])
{
    // Klargjør applikasjonen
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:Main/main.qml"_qs);

    // Registrer klassen for QML
    qmlRegisterType<SmartLys>("SmartHus", 1, 0, "SmartLys");

    // Start applikasjonen
    engine.load(url);
    return app.exec();
}
