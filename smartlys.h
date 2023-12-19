// smartlys.h
#ifndef SMARTLYS_H
#define SMARTLYS_H

#include <QObject>

class SmartLys : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool status READ getStatus WRITE setStatus NOTIFY statusChanged)
public:
    explicit SmartLys(QObject *parent = nullptr);
    bool getStatus() const;
    void setStatus(bool newStatus);
signals:
    void statusChanged(); // signal for endring
private:
    bool m_status; // true = på, false = av
};

#endif // SMARTLYS_H
