import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
    color: "white"

    Column {
        Text {
            text: "Hello from QML Application!"
        }

        Button {
            text: "Back to StoneShell"

            onClicked: stackView.pop()
        }
    }
}
