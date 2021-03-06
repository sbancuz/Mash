#include_directories(${GitWrapHeaders})

set(mash_SRCS
    main.cpp
    controllers/hash.cpp
    )

if(QUICK_COMPILER)
    qtquick_compiler_add_resources(mash_QML_QRC qml.qrc)
else()
    qt5_add_resources(mash_QML_QRC qml.qrc)
endif()

if(ANDROID)
    add_library(${PROJECT_NAME} SHARED
        ${mash_SRCS}
        ${mash_QML_QRC}
        )
else()
    add_executable(${PROJECT_NAME}
        ${mash_SRCS}
        ${mash_QML_QRC}
        )
endif()

target_compile_definitions(${PROJECT_NAME}
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

if(ANDROID)
    target_link_libraries(${PROJECT_NAME} MauiKit Qt5::AndroidExtras)
else()
    target_link_libraries(${PROJECT_NAME} MauiKit Qt5::Widgets )
endif()

target_link_libraries(${PROJECT_NAME} MauiKit MauiKit::FileBrowsing Qt5::Quick Qt5::Core KF5::CoreAddons KF5::I18n)

install(TARGETS ${PROJECT_NAME} ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})

add_subdirectory(controllers)

#TODO: port to ecm_install_icons()
# install(FILES assets/mash.svg DESTINATION ${KDE_INSTALL_ICONDIR}/hicolor/scalable/apps)
# install(FILES org.kde.booth.appdata.xml DESTINATION ${KDE_INSTALL_METAINFODIR})

