import QtQuick 2.15
import QtQuick.Controls 2.15
import QtLocation 6.7
import QtPositioning 6.7

Rectangle {
    width: 800
    height: 600

    Plugin {
        id: mapPlugin
        name: "osm"

        PluginParameter { name: "osm.mapping.provider"; value: "custom" }
        PluginParameter { name: "osm.mapping.custom.enabled"; value: true }
        PluginParameter {
            name: "osm.mapping.custom.host"
            value: "https://basemaps.cartocdn.com/light_all/${z}/${x}/${y}.png"
        }
        PluginParameter { name: "osm.mapping.cache.directory"; value: "carto_cache" }
    }

    Map {
        id: mapView
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(51.5074, -0.1278)
        zoomLevel: 13
        copyrightsVisible: false

        MapItemView {
            model: projetModel
            delegate: MapQuickItem {
                coordinate: QtPositioning.coordinate(model.latitude, model.longitude)
                anchorPoint.x: 15
                anchorPoint.y: 45

                sourceItem: Item {
                    width: 60
                    height: 60

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            projectInfoPopup.projectId = model.id_projet
                            projectInfoPopup.projectName = model.nom_projet
                            projectInfoPopup.projectDescription = model.description
                            projectInfoPopup.projectBudget = model.budget
                            projectInfoPopup.projectStartDate = model.date_debut
                            projectInfoPopup.projectEndDate = model.date_fin
                            projectInfoPopup.projectStatus = model.etat_projet
                            projectInfoPopup.open()
                        }
                    }

                    Column {
                        anchors.centerIn: parent
                        spacing: 2

                        Rectangle {
                            color: "white"
                            opacity: 0.8
                            radius: 4
                            visible: mapView.zoomLevel > 14
                            anchors.horizontalCenter: parent.horizontalCenter

                            Text {
                                id: projectLabel
                                text: model.nom_projet
                                color: "black"
                                font.pixelSize: 12
                                font.bold: true
                                padding: 4
                            }

                            width: projectLabel.width + 8
                            height: projectLabel.height + 4
                        }

                        Image {
                            id: markerImage
                            source: "qrc:/marker.png"
                            width: 30
                            height: 30
                        }
                    }
                }
            }
        }
    }

    PinchArea {
        anchors.fill: parent
        pinch.target: mapView
        onPinchUpdated: {
            mapView.zoomLevel += Math.log(pinch.scale) / Math.log(2)
        }

        MouseArea {
            anchors.fill: parent
            drag.target: draggable

            property int lastX: 0
            property int lastY: 0

            onPressed: {
                lastX = mouse.x
                lastY = mouse.y
            }

            onPositionChanged: {
                if (pressed) {
                    var dx = mouse.x - lastX
                    var dy = mouse.y - lastY
                    mapView.pan(-dx, -dy)
                    lastX = mouse.x
                    lastY = mouse.y
                }
            }

            Item { id: draggable }
        }
    }

    Button {
        id: zoomInButton
        text: "+"
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 10
        width: 40
        height: 40
        onClicked: mapView.zoomLevel += 1
    }

    Button {
        id: zoomOutButton
        text: "-"
        anchors.right: parent.right
        anchors.top: zoomInButton.bottom
        anchors.margins: 10
        width: 40
        height: 40
        onClicked: mapView.zoomLevel -= 1
    }

    Popup {
        id: projectInfoPopup
        width: 300
        height: 300
        anchors.centerIn: parent
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        property int projectId: 0
        property string projectName: ""
        property string projectDescription: ""
        property real projectBudget: 0
        property string projectStartDate: ""
        property string projectEndDate: ""
        property string projectStatus: ""

        Column {
            anchors.fill: parent
            anchors.margins: 10
            spacing: 10

            Label {
                text: "Project Details"
                font.bold: true
                font.pixelSize: 16
                horizontalAlignment: Text.AlignHCenter
            }

            Rectangle { width: parent.width; height: 1; color: "lightgray" }

            Label { text: "Name: " + projectInfoPopup.projectName }
            Label { text: "ID: " + projectInfoPopup.projectId }
            Label { text: "Description: " + projectInfoPopup.projectDescription; wrapMode: Text.WordWrap }
            Label { text: "Budget: $" + projectInfoPopup.projectBudget.toFixed(2) }
            Label { text: "Start Date: " + projectInfoPopup.projectStartDate }
            Label { text: "End Date: " + projectInfoPopup.projectEndDate }
            Label { text: "Status: " + projectInfoPopup.projectStatus }

            Button {
                text: "Close"
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: projectInfoPopup.close()
            }
        }
    }

    Text {
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 10
        text: "© OpenStreetMap contributors, © CARTO"
        color: "black"
        font.pixelSize: 12
        z: 1

        Rectangle {
            anchors.fill: parent
            anchors.margins: -3
            color: "white"
            opacity: 0.7
            z: -1
        }
    }

    function setPinLocation(lat, lon) {
        mapView.center = QtPositioning.coordinate(lat, lon)
        mapView.zoomLevel = 14
    }
}
