#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include <QCommandLineParser>
#include <QDate>

#ifdef Q_OS_ANDROID
#include <QGuiApplication>
#else
#include <QApplication>
#endif

#ifdef Q_OS_MACOS
#include <MauiKit/Core/mauimacos.h>
#endif

#include <MauiKit/Core/mauiapp.h>

#include <KAboutData>
#include <KI18n/KLocalizedString>

#include "../build/mash_version.h"

#define MASH_URI "org.maui.mash"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps, true);

#ifdef Q_OS_ANDROID
        QGuiApplication app(argc, argv);
#else
        QApplication app(argc, argv);
#endif

        app.setOrganizationName(QStringLiteral("Maui"));
        // app.setWindowIcon(QIcon(":/assets/assets/mash.svg"));
        // MauiApp::instance()->setIconName("qrc:/assets/assets/mash.svg");

        KLocalizedString::setApplicationDomain("mash");
        KAboutData about(QStringLiteral("mash"), i18n("Mash"), MASH_VERSION_STRING, i18n("Quick hash calculator."), KAboutLicense::LGPL_V3, i18n("© 2021 Maui Development Team",QString::number(QDate::currentDate().year())), QString(GIT_BRANCH) + "/" + QString(GIT_COMMIT_HASH));

        about.addAuthor(i18n("Sbancuz"), i18n("Developer"), QStringLiteral("sbancuz@protonmail.com"));
        about.setHomepage("https://mauikit.org");
        about.setProductName("maui/mash");
        // about.setBugAddress("https://invent.kde.org/maui/mash/-/issues");
        about.setOrganizationDomain(MASH_URI);
        about.setProgramLogo(app.windowIcon());

        KAboutData::setApplicationData(about);

        QCommandLineParser parser;
        parser.setApplicationDescription(about.shortDescription());
        parser.process(app);
        about.processCommandLine(&parser);

        QQmlApplicationEngine engine;
        const QUrl url(QStringLiteral("qrc:/main.qml"));
        QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                                         &app, [url](QObject *obj, const QUrl &objUrl)
        {
                if (!obj && url == objUrl)
                        QCoreApplication::exit(-1);

        }, Qt::QueuedConnection);

        engine.rootContext()->setContextObject(new KLocalizedContext(&engine));

    engine.load(url);

#ifdef Q_OS_MACOS
        //    MAUIMacOS::removeTitlebarFromWindow();
        //    MauiApp::instance()->setEnableCSD(true); //for now index can not handle cloud accounts

#endif
        return app.exec();
}

