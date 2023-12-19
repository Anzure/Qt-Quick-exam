// smartlys.cpp
#include "SmartLys.h"

SmartLys::SmartLys(QObject *parent) : QObject(parent), m_status(false) {}

bool SmartLys::getStatus() const {
    // Returnerer status
    return m_status;
}

void SmartLys::setStatus(bool newStatus) {
    // Oppdaterer status
    m_status = newStatus;

    // Signaliserer endring
    emit statusChanged();
}
