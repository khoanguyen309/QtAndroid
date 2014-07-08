#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "beventure.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QStringList dataList;
    for (int i = 0; i < 20; ++i)
        dataList.append("Sample Item");
    (engine.rootContext())->setContextProperty("myModel", QVariant::fromValue(dataList));
    engine.load(QUrl(QStringLiteral("qrc:///Main.qml")));

    QObject* rootObject = engine.rootObjects().first();
    QObject* addAnsBtn = rootObject->findChild<QObject*>("addAnswer");

    return app.exec();
}
