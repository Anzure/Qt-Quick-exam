#include "modelcontroller.h"
#include <QDebug>

ModelController::ModelController(QObject *parent) : QObject(parent)
{

}

QString ModelController::getSampleValue() const
{
    return sampleValue;
}

void ModelController::setSampleValue(QString value)
{
    qDebug() << "Inndata verdi: " + value;
    if (value == nullptr)
    {
        emit sampleValueFailure("Ugyldig data");
    }
    else {
        QString responseStr = value;
        sampleValue = responseStr;
        emit sampleValueChanged();
    }

}
