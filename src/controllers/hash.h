#ifndef HASH_H
#define HASH_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QIODevice>
#include <qqml.h>
#include <QCryptographicHash>

class Hash : public QObject
{
    Q_OBJECT
    Q_ENUMS(QCryptographicHash::Algorithm)
    QML_ELEMENT

public:
    explicit Hash(QObject*parent = nullptr);
    Q_INVOKABLE QString computeHash(QString str, QCryptographicHash::Algorithm method);
    Q_INVOKABLE QString computeFileHash(QString path, QCryptographicHash::Algorithm method);
};

#endif // HASH_H
