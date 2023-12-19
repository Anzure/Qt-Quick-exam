#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "modelcontroller.h"

int main(int argc, char *argv[])
{
    // Prepare startup
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ModelController modelController;
    engine.rootContext()->setContextProperty("modelController", &modelController);

    const QUrl url(u"qrc:Main/main.qml"_qs);
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");
    engine.addImportPath(":/");

    engine.load(url);

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    // Start application
    return app.exec();
}
