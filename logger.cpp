#include "logger.h"
#include <QTextStream>
#include <QDateTime>
#include <QDebug>
#include <QFileInfo>

Logger::Logger(const QString &filePath) {
    logFile.setFileName(filePath);
    if (!logFile.open(QIODevice::Append | QIODevice::Text)) {
        qCritical() << "Unable to open log file:" << filePath;
    }
}

Logger::~Logger() {
    if (logFile.isOpen()) {
        logFile.close();
    }
}

Logger &Logger::instance(const QString &filePath) {
    static Logger instance(filePath); // single instance of Logger
    return instance;
}

void Logger::log(const QString &message) {
    QMutexLocker locker(&logMutex);

    if (!logFile.isOpen()) {
        qCritical() << "Log file is not open.";
        return;
    }

    QTextStream out(&logFile);
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    out << "[" << timestamp << "] " << message << "\n";
    out.flush();
}

QString Logger::getLogFilePath() const {
    return QFileInfo(logFile).absoluteFilePath();
}

void Logger::setSuccess(bool value) {
    QMutexLocker locker(&logMutex);
    success = value;
}

bool Logger::isSuccess() {
    QMutexLocker locker(&logMutex);
    return success;
}
