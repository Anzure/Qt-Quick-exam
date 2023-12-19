import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    title: "Qt Quick exam"
    width: 600
    height: 800
    visible: true

    Rectangle {
        id: mainContainer
        anchors.fill: parent
        Text {
            id: sampleText
            text: modelController.textValue
        }
    }
}
