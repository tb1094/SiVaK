#ifndef PATHOPS_H
#define PATHOPS_H

#include <QStringList>
#include <QDir>
#include <QFile>
#include <QFileInfo>

bool checkPath(const QString &path, const QStringList &list);

void dirCopy(const QString &src, const QString &dst);

#endif // PATHOPS_H
