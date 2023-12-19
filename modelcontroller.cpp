#include "modelcontroller.h"
#include <QDebug>

ModelController::ModelController(QObject *parent) : QObject(parent)
{
    textValue = "Nytt objekt";
}

void ModelController::requestData(QString input)
{
    qDebug() << "Inndata verdi: " + input;
    if (input == nullptr)
    {
        emit dataFailure("Ugyldig verdi.");
    }
    QString responseStr = "Hallo verden!";
    emit receiveData(responseStr);
}
