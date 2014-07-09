#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "beventure.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    Beventure beventure (NULL, &engine);
    // Initialize
    engine.load(QUrl(QStringLiteral("qrc:///Main.qml")));
    QObject* rootObject = engine.rootObjects().first();
    QObject::connect(rootObject->findChild<QObject*>("addAnswer"), SIGNAL(myClicked(QString)), &beventure, SLOT(addAnswer(QString)));
    QObject::connect(rootObject->findChild<QObject*>("clearAnswer"), SIGNAL(clicked()), &beventure, SLOT(clear()));
    QObject::connect(rootObject->findChild<QObject*>("bestChoiceBtn"), SIGNAL(clicked()), &beventure, SLOT(bestAnswer()));
    return app.exec();
}
