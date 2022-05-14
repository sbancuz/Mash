#include "hash.h"
#include <stdlib.h>

Hash::Hash(QObject *parent) :
    QObject(parent)
{
}

QString Hash::computeHash(QString str, QCryptographicHash::Algorithm method)
{
    if (method)
    {
        QByteArray result = QCryptographicHash::hash(str.toUtf8(), method).toHex();

        return QString(result);
    }
    return QString("Could not hash your file");
}
