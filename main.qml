// main.qml
import QtQuick 2.12
import QtQuick.Controls 2.5
// Importerer registrert klasse
import SmartHus 1.0 // C++-klasse

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "Smart Lysstyring"

    // Tilgjengeliggjør C++-klassen SmartLys
    SmartLys {
        id: smartLys // variabel som kan brukes i QML
    }

    // Viser en knapp og en tekst for lysstyring
    Column {
        anchors.centerIn: parent
        // Knapp slår av/på lyset (toogle)
        Button {
            text: "Lysbryter"
            onClicked: smartLys.status = !smartLys.status
        }
        // Viser status På / Av for lyset
        Text {
            text: "Status: " + (smartLys.status ? "På" : "Av")
        }
    }
}
