import QtQuick
import QtQuick.Window
import QtPositioning
import QtLocation

    Map {
        id: map
        anchors.fill: parent

        plugin: Plugin {
            name: "osm"

            // Utiliser Thunderforest
            PluginParameter {
            name: "osm.mapping.providers"
            value: "tile"
            }

            PluginParameter {
            name: "osm.tile.source"
            value: "https://tile.thunderforest.com/atlas/{z}/{x}/{y}.png?apikey=8336c76b07fc4c26b78c798a1deec14d"
                }
            }



        center: QtPositioning.coordinate(48.8566, 2.3522)
        zoomLevel: 10

        function centerOn(lat, lon) {
                map.center.latitude = lat
                map.center.longitude = lon
            }

        function addMarker(lat, lon) {
                var marker = markerComponent.createObject(map, {
                    coordinate: QtPositioning.coordinate(lat, lon)
                })
                if (marker !== null) {
                    map.addMapItem(marker)
                }
            }
        Component {
            id: markerComponent
            MapQuickItem {
                anchorPoint.x: 12
                anchorPoint.y: 12
                sourceItem: Rectangle {
                    width: 24
                    height: 24
                    color: "red"
                    radius: 12
                    border.color: "white"
                    border.width: 2
                }
            }
        }
        // Déplacement
        DragHandler {
            target: null
            property real speedFactor: 0.3   // plus petit = plus lent

            onTranslationChanged: {
                map.pan(-translation.x * speedFactor,
                        -translation.y * speedFactor)
            }
        }

        // Zoom pincement
        PinchHandler {
            target: null
            onScaleChanged: {
                map.zoomLevel += scaleDelta
            }
        }

        // Zoom molette (CORRIGÉ)
        WheelHandler {
            onWheel: function(wheel) {
                map.zoomLevel += wheel.angleDelta.y / 240
            }
        }

    }
