import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
import org.kde.kirigami 2.7 as Kirigami

import org.mauikit.controls 1.3 as Maui
// import org.maui.mash 1.0 as Mash

Maui.ApplicationWindow
{
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Mash")
    readonly property font defaultFont : Qt.font({family: "Noto Sans Mono", pointSize: Maui.Style.fontSizes.huge})

    headBar.visible: true

    Maui.LabelDelegate
    {
        id: b
        text: "halooo"
    }
}
