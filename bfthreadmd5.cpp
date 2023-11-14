#include "bfthreadmd5.h"
#include <QDebug>
#include <QCryptographicHash>

BfThreadMD5::BfThreadMD5(QString s, char startCh, char endCh): name(s), startCh(startCh), endCh(endCh)
{

}

void BfThreadMD5::run()
{
    qWarning() << "начало перебора";
    for (char c1 = startCh; c1 <= endCh; ++c1) {
        for (char c2 = 'a'; c2 <= 'z'; ++c2) {
            for (char c3 = 'a'; c3 <= 'z'; ++c3) {
                for (char c4 = 'a'; c4 <= 'z'; ++c4) {
                    for (char c5 = 'a'; c5 <= 'z'; ++c5) {
                        QString word = QString("%1%2%3%4%5").arg(c1).arg(c2).arg(c3).arg(c4).arg(c5);

                        if(QCryptographicHash::hash(word.toUtf8(), QCryptographicHash::Md5).toHex() == "1f3870be274f6c49b3e31a0c6728957f"
                            || QCryptographicHash::hash(word.toUtf8(), QCryptographicHash::Md5).toHex() == "d9308f32f8c6cf370ca5aaaeafc0d49b"
                            || QCryptographicHash::hash(word.toUtf8(), QCryptographicHash::Md5).toHex() == "81d45c9cf678fbaa8d64a6f29a6f97e3")
                        {
                            emit send(word);
                        }
                    }
                }
            }
        }
    }
    emit onFinish();
    qWarning() << "конец перебора";
}
