#include "beventure.h"

Beventure::Beventure(QObject *parent, QQmlApplicationEngine* engine) :
    QObject(parent),
    engine(*engine),
    rand(new RandomGenerator())
{
    this->engine.rootContext()->setContextProperty("myModel", QVariant::fromValue(answersList));
}

Beventure::~Beventure()
{
    delete rand;
}

void Beventure::addAnswer(QString answer)
{
    if (answer != "" || !answer.isEmpty()) {
        answersList.append(answer);
        engine.rootContext()->setContextProperty("myModel", QVariant::fromValue(answersList));
    }
}

void Beventure::clear()
{
    answersList.clear();
    engine.rootContext()->setContextProperty("myModel", QVariant::fromValue(answersList));
}

void Beventure::bestAnswer()
{
    if (answersList.size() > 0) {
        double value = rand->next();
        int randomNumber = ((int)qRound(value * 10));
        QString answer = answersList.at(randomNumber);
        answersList.clear();
        answersList.append(answer);
        engine.rootContext()->setContextProperty("myModel", QVariant::fromValue(answersList));
    }
}
