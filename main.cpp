#include <QApplication>
#include <QQmlApplicationEngine>

#include <QDebug>

#include "characters/dynasty.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    qDebug()  << qrand() % 2 << qrand() % 2 << qrand() % 2 << qrand() % 2 << qrand() % 2 << qrand() % 2 << qrand() % 2 << qrand() % 2;

//    Dynasty* d1 = new Dynasty(1, 2, 3, 4, 5);
//    Dynasty* d2 = new Dynasty(3, 4, 5, 6, 7);
//    Dynasty* d3 = new Dynasty(5, 6, 7, 8, 9);

//    Dynasty* d4 = new Dynasty(d1, d2);
//    Dynasty* d5 = new Dynasty(d3, d1);
//    Dynasty* d6 = new Dynasty(d2, d5);
//    Dynasty* d7 = new Dynasty(d5, d6);
//    Dynasty* d8 = new Dynasty(d4, d5);
//    Dynasty* d9 = new Dynasty(d7, d4);
//    Dynasty* d10 = new Dynasty(d8, d9);

//    qDebug() << d1->name() << d1->toString();
//    qDebug() << d2->name() << d2->toString();
//    qDebug() << d3->name() << d3->toString();
//    qDebug() << d4->name() << d4->toString();
//    qDebug() << d5->name() << d5->toString();
//    qDebug() << d6->name() << d6->toString();
//    qDebug() << d7->name() << d7->toString();
//    qDebug() << d8->name() << d8->toString();
//    qDebug() << d9->name() << d9->toString();
//    qDebug() << d10->name() << d10->toString();

    qDebug() << quint64(quint64(qrand() % UINT_MAX) << 32 | (qrand() % UINT_MAX)) << UINT64_MAX;

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
