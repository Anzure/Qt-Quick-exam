import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    title: "Qt Quick exam"
    width: 600
    height: 800
    visible: true

    Connections {
        target: modelController
        onSampleValueChanged: {
            console.log("Retrived data:", modelController.sampleValue);
            errorView.visible = false;
            myInput.text = "";
        }
        onSampleValueFailure: {
            console.log("Data failure:", error);
            errorView.visible = true;
            errorText.text = error;
        }
    }

    ColumnLayout {
        id: mainView
        spacing: 20
        Layout.fillWidth: true

        Row {
            id: dataView
            width: parent.width
            Layout.fillWidth: true
            spacing: 10
            Text {
                id: outputHeader
                text: "Min data:"
                font.pixelSize: 24
            }
            TextField {
                id: myOutput
                text: modelController.sampleValue
                width: parent.width / 2
                readOnly: true
            }
        }

        Row {
            id: formView
            width: parent.width
            Layout.fillWidth: true
            spacing: 10
            Text {
                id: formHeader
                text: "Endre data:"
                font.pixelSize: 24
            }
            TextField {
                id: myInput
                width: parent.width / 2
            }
            Button {
                id: searchButton
                text: "OK"
                onClicked: {
                    console.log("Data requested:", myInput.text);
                    modelController.setSampleValue(myInput.text);
                }
            }
        }

        Row {
            id: errorView
            width: parent.width
            Layout.fillWidth: true
            visible: false
            Text {
                id: errorPrefix
                text: "Endring feilet! Feilmelding: '"
                color: "red"
                font.pixelSize: 16
            }
            Text {
                id: errorText
                text: ""
                color: "darkred"
                font.pixelSize: 16
            }
            Text {
                id: errorSuffix
                text: "' Prøv igjen."
                color: "red"
                font.pixelSize: 16
            }
        }
    }
}
