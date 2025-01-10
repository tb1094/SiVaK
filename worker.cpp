#include "Worker.h"
#include "pathOps.h"
#include "logger.h"

Worker::Worker(const QStringList &srcList, const QString &destination, QObject *parent)
    : QObject(parent), srcList(srcList), destination(destination) {}

void Worker::process() {
    bool overallSuccess = true;

    for (int i = 0; i < srcList.length(); ++i) {
        QString srcPath = srcList[i];
        QStringList slicedList(srcList);
        slicedList.removeAt(i);

        if (checkPath(srcPath, slicedList)) {
            dirCopy(srcPath, destination);
            emit progressUpdate(QString("Processed: %1").arg(srcPath));
        } else {
            overallSuccess = false;
            Logger::instance().log(QString("Path conflict detected for: %1").arg(srcPath));
        }
    }

    emit finished(overallSuccess);
}
