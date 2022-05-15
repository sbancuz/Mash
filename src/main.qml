import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

import org.kde.kirigami 2.7 as Kirigami

import org.mauikit.controls 1.3 as Maui
import org.mauikit.filebrowsing 1.3 as FB

import org.maui.mash 1.0 as Mash

Maui.ApplicationWindow
{
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Mash")
    readonly property font defaultFont : Qt.font({family: "Noto Sans Mono", pointSize: Maui.Style.fontSizes.huge})

    headBar.visible: false

    Mash.Hash
    {
        id: hash
    }

    Maui.FloatingButton
    {
        onClicked: {
            _dialogLoader.sourceComponent = _openFileDialogComponent
            dialog.singleSelection = true
            dialog.callback = function(paths)
            {
                // Remove "file:://"
                // TO-DO fix this file path problem so you can use different "sources" to open file
                const url = paths[0].substr(7)
                _textField.text = hash.computeFileHash(url, Mash.Hash.Md5)
            }
            dialog.open()
        }
    }
    Component
    {
        id: _openFileDialogComponent

        FB.FileDialog
        {

        }
    }
   Loader
    {
        id: _dialogLoader
    }


    property alias dialog : _dialogLoader.item

    Maui.TextField
    {
        id: _textField
        anchors.centerIn: parent
    }
}
