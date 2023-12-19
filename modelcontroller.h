#ifndef MODELCONTROLLER_H
#define MODELCONTROLLER_H

#include <QObject>

class ModelController : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(int textValue READ getTextValue WRITE setTextValue NOTIFY textValueChanged)

public:
    explicit ModelController(QObject *parent = nullptr);
    int getTextValue() const;
    void setTextValue(int value);
    QString textValue = "Tomt objekt";

signals:
    void receiveData(const QString &data);
    void dataFailure(const QString &error);

public slots:
    void requestData(QString input);
};

#endif // MODELCONTROLLER_H
