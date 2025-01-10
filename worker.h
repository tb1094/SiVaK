#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QString>
#include <QStringList>

class Worker : public QObject {
    Q_OBJECT
public:
    explicit Worker(const QStringList &srcList, const QString &destination, QObject *parent = nullptr);

public slots:
    void process(); // slot to perform the file backup

signals:
    void finished(bool success); // signal to notify when the backup is complete
    void progressUpdate(const QString &message); // TODO: signal for progress updates

private:
    QStringList srcList;
    QString destination;
};

#endif // WORKER_H
