#include "modelcontroller.h"
#include <QDebug>

ModelController::ModelController(QObject *parent) : QObject(parent)
{

}

QString ModelController::getMyProperty() const
{
    return myProperty;
}

void ModelController::setMyProperty(QString value)
{
    myProperty = value;
    emit myPropertyChanged();
}

void ModelController::requestData(QString input)
{
    qDebug() << "Inndata verdi: " + input;
    if (input == nullptr)
    {
        setMyProperty("{data: null, error: true}");
        emit dataFailure("Ugyldig verdi");
    }
    else {
        QString responseStr = input;
        setMyProperty("{data: '" + input + "', error: false}");
        emit receiveData(responseStr);
    }
}
