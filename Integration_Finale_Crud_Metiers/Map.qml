import QtQuick
import QtQuick.Window
import QtPositioning
import QtLocation

    Map {
        id: map
        anchors.fill: parent
        // --- 1. Gestion de votre position actuelle ---
        PositionSource {
            id: myPosition
            updateInterval: 5000 // Essayer toutes les 5 secondes
            active: False

            // IMPORTANT : On accepte TOUT (Satellite pour l'extérieur, Wifi/IP pour l'intérieur)
            preferredPositioningMethods: PositionSource.AllPositioningMethods

            onPositionChanged: {
                var coord = myPosition.position.coordinate;
                console.log("Position trouvée :", coord.latitude, coord.longitude);
                console.log("Précision (mètres) :", myPosition.position.horizontalAccuracy);
            }

            onSourceErrorChanged: {
                if (sourceError == PositionSource.AccessError) {
                    console.log("Erreur : Accès GPS refusé par Windows/L'utilisateur");
                } else if (sourceError == PositionSource.ClosedError) {
                    console.log("Erreur : Le backend de localisation est fermé");
                } else {
                    console.log("Erreur de source GPS : " + sourceError);
                }
            }
        }

            // --- 2. Modèle pour le calcul d'itinéraire ---
                RouteModel {
                    id: routeModel
                    plugin: map.plugin // On utilise le même plugin (osm)
                    query: RouteQuery {}

                    onStatusChanged: {
                            if (status == RouteModel.Ready) {
                                var route = get(0);
                                var tempsSecondes = route.travelTime;
                                var minutes = Math.floor(tempsSecondes / 60);

                                infoBubble.text = "Temps estimé: " + minutes + " min (" + (route.distance/1000).toFixed(1) + " km)";
                                infoBubble.visible = true;

                                // --- ADD THIS LINE ---
                                // Automatically zooms the map to show both Start and End
                                map.visibleRegion = route.bounds
                        } else if (status == RouteModel.Error) {
                            console.log("Erreur de calcul d'itinéraire", errorString);
                        }
                    }
                }

                // --- 3. Dessin de la ligne bleue (Trajectoire) ---
                MapItemView {
                    model: routeModel
                    delegate: MapRoute {
                        route: routeData
                        line.color: "#3498db" // Bleu
                        line.width: 5
                        smooth: true
                    }
                }

                property var currentMarker: null   // Lieu Localisé
                property var startMarker: null // Moi

                // --- Bulle d'info pour le temps ---
                Rectangle {
                    id: infoBubble
                    visible: false
                    anchors.bottom: parent.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottomMargin: 20
                    width: 300
                    height: 40
                    color: "#2c3e50"
                    radius: 10
                    border.color: "white"

                    // On utilise un Row pour aligner Texte + Bouton
                            Row {
                                anchors.centerIn: parent
                                spacing: 15

                                Text {
                                    id: infoText
                                    text: parent.parent.text // Hack pour récupérer la propriété text du Rectangle
                                    color: "white"
                                    font.bold: true
                                    font.pixelSize: 14
                                    verticalAlignment: Text.AlignVCenter
                                }

                                // Le petit bouton OK
                                Rectangle {
                                    width: 40
                                    height: 30
                                    radius: 15
                                    color: "#e74c3c" // Rouge sympa
                                    border.color: "white"

                                    Text {
                                        anchors.centerIn: parent
                                        text: "OK"
                                        color: "white"
                                        font.bold: true
                                        font.pixelSize: 12
                                    }

                                    MouseArea {
                                        anchors.fill: parent
                                        cursorShape: Qt.PointingHandCursor
                                        onClicked: {
                                            infoBubble.visible = false; // Cacher la bulle
                                        }
                                    }
                                }
                            }
                            property string text: ""
                        }

        // Animation pour un déplacement smooth
        Behavior on center.latitude {
            NumberAnimation {
                duration: 1200
                easing.type: Easing.InOutQuad
            }
        }

        Behavior on center.longitude {
            NumberAnimation {
                duration: 1200
                easing.type: Easing.InOutQuad
            }
        }


        plugin: Plugin {
            name: "osm"

            PluginParameter {
                    name: "osm.mapping.custom.host"
                    value: "https://mt1.google.com/vt/lyrs=s&x={x}&y={y}&z={z}"
                }

                // Désactiver le fournisseur par défaut qui pose problème
                PluginParameter {
                    name: "osm.mapping.providersrepository.disabled"
                    value: "true"
                }
            }



        Component.onCompleted: {
                map.center = QtPositioning.coordinate(36.8065, 10.1815)
                map.zoomLevel = 10
            }

        function centerOn(lat, lon) {
                map.center.latitude = lat
                map.center.longitude = lon
            }

        function addMarker(lat, lon) {

            // Effacer ancien marqueur
            if (currentMarker !== null) {
                map.removeMapItem(currentMarker)
                currentMarker.destroy()
                currentMarker = null
            }

            // Créer un nouveau
            var marker = markerComponent.createObject(map, {
                coordinate: QtPositioning.coordinate(lat, lon)
            })

            if (marker !== null) {
                map.addMapItem(marker)
                currentMarker = marker
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

        // --- 4. NOUVELLE FONCTION APPELEE PAR C++ ---
        function calculateRoute(startLat, startLon, destLat, destLon) {
            routeModel.query.clearWaypoints();

            // 1. Setup Waypoints
            routeModel.query.addWaypoint(QtPositioning.coordinate(startLat, startLon));
            routeModel.query.addWaypoint(QtPositioning.coordinate(destLat, destLon));
            routeModel.update();

            // 2. Manage Start Marker (Green - You)
            if (startMarker !== null) {
                map.removeMapItem(startMarker);
                startMarker.destroy();
            }

            // Create a Green circle for the start
            var startComponent = Qt.createComponent("qrc:/greenMarker.qml"); // If you have a file
            // OR simply reuse the component but change color dynamically:
            startMarker = markerComponent.createObject(map, {
                coordinate: QtPositioning.coordinate(startLat, startLon)
            });

            // Hack to turn it green (Accessing the Rectangle inside)
            startMarker.sourceItem.color = "#2ecc71"; // Green color
            map.addMapItem(startMarker);

            // 3. Manage Destination Marker (Red - Event)
            addMarker(destLat, destLon);
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
        // --- 5. NOUVELLE FONCTION POUR NETTOYER LA CARTE ---
            function clearRoute() {
                // 1. Effacer les données de l'itinéraire (Ligne bleue)
                routeModel.reset();
                routeModel.query.clearWaypoints();

                // 2. Supprimer le marqueur vert (Départ)
                if (startMarker !== null) {
                    map.removeMapItem(startMarker);
                    startMarker.destroy();
                    startMarker = null;
                }

                // 3. Cacher la bulle d'info si elle est ouverte
                infoBubble.visible = false;
            }
            function addGreenMarker(lat, lon) {
                        // 1. Effacer l'ancien marqueur s'il existe
                        if (currentMarker !== null) {
                            map.removeMapItem(currentMarker)
                            currentMarker.destroy()
                            currentMarker = null
                        }

                        // 2. Créer le nouveau marqueur
                        var marker = markerComponent.createObject(map, {
                            coordinate: QtPositioning.coordinate(lat, lon)
                        })

                        // 3. LE Mettre en VERT (C'est ici que la magie opère)
                        if (marker !== null) {
                            marker.sourceItem.color = "#2ecc71" // Code couleur Vert (le même que l'itinéraire)
                            map.addMapItem(marker)
                            currentMarker = marker
                        }
                    }

    }
