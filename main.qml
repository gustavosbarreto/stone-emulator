import QtQuick 2.0
import QtWebEngine 1.3
import QtWebChannel 1.0
import QtQuick.Controls 1.4

Image {
    source: "qrc:/images/stone.png"

    Component.onCompleted: {
        var HtmlAppView = Qt.createComponent("htmlappview.qml");

        StoneShell.openAppRequest.connect(function(type, url) {
            if (type == "html") {
                var obj = HtmlAppView.createObject();
                obj.url = url;
                stackView.push(obj);
            } else if (type == "qml") {
                var comp = Qt.createComponent(url);
                var obj = comp.createObject();
                stackView.push(obj);
            }
        });
    }

    StackView {
        id: stackView

        x: 42
        y: 158
        width: 220
        height: 294

        clip: true

        initialItem: webViewComponent

        Component {
            id: webViewComponent

            WebEngineView {
                id: webView

                webChannel: mainChannel
                url: "qrc:/html/index.html"
            }
        }
    }
}
