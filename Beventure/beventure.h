#ifndef BEVENTURE_H
#define BEVENTURE_H

#include "time.h"
#include <QObject>
#include <QtWidgets/QMessageBox>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "randomgenerator.h"

class Beventure : public QObject
{
    Q_OBJECT

    public:
        explicit Beventure(QObject *parent = 0, QQmlApplicationEngine* engine = 0);

        ~Beventure();

    signals:

    public slots:
        void addAnswer(QString);

        void clear();

        void bestAnswer();

    private:
        QQmlApplicationEngine& engine;
        QStringList answersList;
};

#endif // BEVENTURE_H
