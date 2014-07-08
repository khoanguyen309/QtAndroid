#ifndef BEVENTURE_H
#define BEVENTURE_H

#include <QObject>

class Beventure : public QObject
{
    Q_OBJECT

public:
    explicit Beventure(QObject *parent = 0);

    ~Beventure();

signals:

public slots:
    void addAnswer();

};

#endif // BEVENTURE_H
