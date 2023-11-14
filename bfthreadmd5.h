#ifndef BFTHREADMD5_H
#define BFTHREADMD5_H

#include <QObject>
#include <QThread>

class BfThreadMD5: public QThread
{
    Q_OBJECT
public:
    explicit BfThreadMD5(QString s, char startCh, char endCh);

    void run();

signals:
    void send(QString word);
    void onFinish();

private:
    QString name;
    char startCh;
    char endCh;
};

#endif // BFTHREADMD5_H
