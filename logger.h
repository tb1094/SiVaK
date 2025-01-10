#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QFile>
#include <QMutex>

class Logger {
public:
    static Logger &instance(const QString &filePath = "application.log"); // Singleton instance

    void log(const QString &message);
    QString getLogFilePath() const;
    void setSuccess(bool value);
    bool isSuccess();

private:
    Logger(const QString &filePath); // Private constructor
    ~Logger();
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    QFile logFile;
    QMutex logMutex;
    bool success = true;
};

#endif // LOGGER_H
