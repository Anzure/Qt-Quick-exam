#ifndef MODELCONTROLLER_H
#define MODELCONTROLLER_H

#include <QObject>

class ModelController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString sampleValue READ getSampleValue WRITE setSampleValue NOTIFY sampleValueChanged)

public:
    explicit ModelController(QObject *parent = nullptr);
    QString getSampleValue() const;
    QString sampleValue = "Ingen data";

signals:
    void sampleValueFailure(const QString &error);
    void sampleValueChanged();

public slots:
    void setSampleValue(QString value);
};

#endif // MODELCONTROLLER_H
