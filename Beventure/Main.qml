import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Layouts 1.1
import QtQuick.Window 2.1

Window {
    id: root
    visible: true
    width: 540
    height: 960

    Rectangle {
        id: rect
        x: 0
        y: 0
        color: "black"
        width: root.width
        height: root.height

        Text {
            id: title
            text: qsTr("Beventure")
            color: "white"
            style: Text.Raised
            font.family: "Tahoma"
            font.bold: true
            font.pointSize: 30
            anchors.top: parent.top
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            width: rect.width
            height: 80
        }

        Text {
            id: heading1
            text: qsTr("Fastest Decision Maker")
            color: "white"
            font.italic: true
            font.pointSize: 20
            anchors.top: title.bottom
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            width: rect.width
            height: 60
        }

        GridLayout {
            id: grid
            columns: 2
            rows: 2
            anchors.top: heading1.bottom
            width: rect.width
            height: 200
            property int itemWidth: Math.round(width / columns)
            property int itemHeight: Math.round(height / rows)

            Rectangle {
                id: question
                Layout.column: 0
                Layout.row: 0
                anchors.left: grid.left
                anchors.top: grid.top
                anchors.leftMargin: 20
                anchors.topMargin: 50
                color: "black"
                width: 140
                height: 50
                Text {
                    text: "Question:"
                    color: "white"
                    font.pointSize: 18
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Rectangle {
                Layout.column: 1
                Layout.row: 0
                anchors.right: grid.right
                anchors.top: grid.top
                anchors.topMargin: 50
                anchors.rightMargin: 20
                border.width: 1
                border.color: "white"
                color: "black"
                width: root.width - (question.width + 10)
                height: 50
                TextInput {
                    id: questionInput
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    color: "white"
                    font.pointSize: 18
                }
            }

            Rectangle {
                id: answer
                Layout.column: 0
                Layout.row: 1
                anchors.left: grid.left
                anchors.top: question.top
                anchors.leftMargin: 20
                anchors.topMargin: 70
                color: "black"
                width: 140
                height: 50
                Text {
                    text: "Answer:"
                    color: "white"
                    font.pointSize: 18
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Rectangle {
                Layout.column: 1
                Layout.row: 1
                anchors.right: grid.right
                anchors.top: question.top
                anchors.topMargin: 70
                anchors.rightMargin: 20
                border.width: 1
                border.color: "white"
                color: "black"
                width: root.width - (answer.width + 10)
                height: 50
                TextInput {
                    id: answerInput
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    color: "white"
                    font.pointSize: 18
                }
            }
        }

        Row {
            id: addRect
            anchors.top: grid.bottom
            anchors.left: rect.left
            anchors.right: rect.right
            anchors.leftMargin: 15
            anchors.rightMargin: 15
            width: rect.width
            height: 80
            spacing: 10
            Button {
                id: addBtn
                signal myClicked(string answer)
                width: (rect.width - 40) / 2
                height: addRect.height
                objectName: "addAnswer"
                style: ButtonStyle {
                    label: Text {
                        text: qsTr("Add answer")
                        font.bold: true
                        font.pointSize: 20
                        anchors.centerIn: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
                onClicked: {
                    myClicked(answerInput.text)
                    answerInput.text = ""
                }
            }

            Button {
                id: clearBtn
                width: (rect.width - 40) / 2
                height: addRect.height
                objectName: "clearAnswer"
                style: ButtonStyle {
                    label: Text {
                        text: qsTr("Clear answer")
                        font.bold: true
                        font.pointSize: 20
                        anchors.centerIn: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
                onClicked: questionInput.text = ""
            }
        }

        ListView {
            anchors.top: addRect.bottom
            anchors.bottom: bestChoice.top
            anchors.topMargin: 50
            anchors.bottomMargin: 50
            width: rect.width
            height: rect.height - (title.height + heading1.height + grid.height + addRect.height + bestChoice.height + 100)
            model: myModel
            delegate: Text {
                text: modelData
                font.pointSize: 16
                color: "white"
            }
        }

        Button {
            id: bestChoice
            anchors.bottom: parent.bottom
            width: rect.width
            height: 80
            objectName: "bestChoiceBtn"
            style: ButtonStyle {
                label: Text {
                    text: qsTr("Get your answer")
                    font.bold: true
                    font.pointSize: 20
                    anchors.centerIn: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }
}
