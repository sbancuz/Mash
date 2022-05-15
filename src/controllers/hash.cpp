#include "hash.h"

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

QString Hash::computeFileHash(QString path, QCryptographicHash::Algorithm method)
{
    if (method)
    {
        QIODevice *file = new QFile(path);
        if (!file->open(QIODevice::ReadOnly))
        {
            qWarning() << "ERROR: Could not open location data file: " << path;
            return nullptr;
        }
        QCryptographicHash *file_h = new QCryptographicHash(method);
        file_h->addData(file);
        QByteArray result = file_h->result().toHex();
        return QString(result);
    }

    return nullptr;
}
