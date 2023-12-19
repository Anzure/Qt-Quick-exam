#ifndef MODELCONTROLLER_H
#define MODELCONTROLLER_H

#include <QObject>

class ModelController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString myProperty READ getMyProperty WRITE setMyProperty NOTIFY myPropertyChanged)

public:
    explicit ModelController(QObject *parent = nullptr);
    QString getMyProperty() const;
    void setMyProperty(QString value);
    QString myProperty = "";

signals:
    void receiveData(const QString &data);
    void dataFailure(const QString &error);
    void myPropertyChanged();

public slots:
    void requestData(QString input);
};

#endif // MODELCONTROLLER_H
