import QtQuick 2.0
import QtWebEngine 1.3

WebEngineView {
    onWindowCloseRequested: stackView.pop()
}
