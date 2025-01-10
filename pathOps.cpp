#include "pathOps.h"
#include "logger.h"

// this function checks each provided path and checks if it's already contained in another one
// so we don't copy the same file(s) multiple times
bool checkPath(const QString &path, const QStringList &list) {
    QStringList pathTokens = path.split(u'/', Qt::SkipEmptyParts);
    QString newPath(pathTokens[0]);
    newPath.append('/');
    for (int i = 1; i <= pathTokens.length(); i++) {
        //qDebug() << "newPath: " << newPath;
        foreach (QString string, list) {
            if (string == newPath) {
                return false;
            }
        }
        if (newPath.back() != '/') {
            newPath.append('/');
        }
        if (i < pathTokens.length()) {
            newPath.append(pathTokens[i]);
        }
    }
    return true;
}

void dirCopy(const QString &src, const QString &dst) {
    //qDebug() << "source: " << src;
    //qDebug() << "destination: " << dst;
    QFile file(src);
    QFileInfo fileInfo(src);
    if (fileInfo.isDir()) {
        QDir dir(src);
        QString newDst = dst + "/" + dir.dirName();
        if (QDir(newDst).exists()) {
            Logger::instance().log(QString("Directory already exists: %1").arg(newDst));
            qDebug() << "Directory already exists:" << newDst;
        } else {
            if (QDir().mkpath(newDst)) {
                Logger::instance().log(QString("Directory created successfully: %1").arg(newDst));
                qDebug() << "Directory created successfully:" << newDst;
            } else {
                Logger::instance().log(QString("Failed to create directory: %1").arg(newDst));
                qDebug() << "Failed to create directory:" << newDst;
                Logger::instance().setSuccess(false);
            }
        }
        foreach (QFileInfo file, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries)) {
            dirCopy(file.canonicalFilePath(), dst + "/" + dir.dirName());
        }
    } else if (fileInfo.isFile()) {
        QString destination = dst + "/" + fileInfo.fileName();
        // to overwrite existing file, we have to first delete
        if (QFile::exists(destination)) {
            if (!QFile::remove(destination)) {
                Logger::instance().log(QString("Unable to remove existing file %1.").arg(destination));
                return;
            }
        }
        if (file.copy(destination)) {
            Logger::instance().log(QString("File %1 copied successfully.").arg(file.fileName()));
            qDebug() << "success";
        } else {
            qDebug() << "failure";
            Logger::instance().log(QString("Unable to copy file %1.").arg(file.fileName()));
            QString errorMsg = file.errorString();
            Logger::instance().log(QString("Error: %1").arg(errorMsg));
            qDebug() << "Error:" << errorMsg;
            Logger::instance().setSuccess(false);
        }
    }
}
