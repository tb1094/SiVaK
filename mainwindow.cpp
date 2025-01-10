#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "logger.h"
#include "worker.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // initialize Logger
    Logger::instance("sivak.log").log("Application SiVaK started.");

    setFixedSize(400, 600);

    src_model = new QStringListModel(this);
    ui->listView_srcBackup->setModel(src_model);
    QStringList list;
    src_model->setStringList(list);
    copying = 0;
}


MainWindow::~MainWindow()
{
    delete ui;
    Logger::instance().log(QString("System exit."));
}


void MainWindow::on_pushButton_addfile_srcBackup_clicked()
{
    if (copying) {
        return;
    }

    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setWindowTitle(tr("Select File(s)"));
    dialog.setDirectory(QDir::homePath());

    dialog.setNameFilter(tr("All Files (*.*)"));

    QStringList list = src_model->stringList();

    if (dialog.exec()) {
        QStringList selected = dialog.selectedFiles();
        if (!selected.isEmpty()) {
            foreach (QString s, selected) {
                list.append(s);
            }
        }
    }
    src_model->setStringList(list);
}


void MainWindow::on_pushButton_adddir_srcBackup_clicked()
{
    if (copying) {
        return;
    }

    QString dirPath = QFileDialog::getExistingDirectory(this, tr("Select Directory"), QDir::homePath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    QStringList list = src_model->stringList();

    if (!dirPath.isEmpty()) {
        list.append(dirPath);
    }

    src_model->setStringList(list);
}


void MainWindow::on_pushButton_remove_srcBackup_clicked()
{
    if (copying) {
        return;
    }

    QModelIndex selectedIndex = ui->listView_srcBackup->currentIndex();

    if (selectedIndex.isValid()) {
        QStringList list = src_model->stringList();
        list.removeAt(selectedIndex.row());
        src_model->setStringList(list);
    }
}


void MainWindow::on_pushButton_browse_dstBackup_clicked()
{
    if (copying) {
        return;
    }

    QString dirPath = QFileDialog::getExistingDirectory(this, tr("Select Directory"), QDir::homePath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!dirPath.isEmpty()) {
        ui->lineEdit_dstBackup->setText(dirPath);
    }
}


void MainWindow::on_pushButton_startBackup_clicked()
{
    Logger::instance().log(QString("File backup started."));
    Logger::instance().setSuccess(true);
    copying = 1;
    ui->statusbar->showMessage(QString("File backup in progress..."));

    QString destination = ui->lineEdit_dstBackup->text();
    if (destination.isEmpty()) {
        QMessageBox::information(this, "File Backup Destination", "Please select the destination directory for backup.");
        copying = 0;
        ui->statusbar->clearMessage();
        return;
    }

    QStringList srcList = src_model->stringList();
    if (srcList.isEmpty()) {
        QMessageBox::information(this, "File Backup Source", "There must be at least one file or directory selected for backup.");
        copying = 0;
        ui->statusbar->clearMessage();
        return;
    }

    QDir dstDir(destination);
    if (!dstDir.exists() || !dstDir.isReadable()) {
        QMessageBox::information(this, "File Backup Destination", "The destination directory is either non-existent or not readable.");
        copying = 0;
        ui->statusbar->clearMessage();
        return;
    }

    Worker *worker = new Worker(srcList, destination);
    QThread *workerThread = new QThread;

    worker->moveToThread(workerThread);

    connect(workerThread, &QThread::started, worker, &Worker::process);
    connect(worker, &Worker::finished, this, [=](bool success) {
        workerThread->quit();
        workerThread->wait();

        if (success) {
            QMessageBox::information(this, "File Backup Completed", QString("File backup completed successfully. The log is available here:\n%1").arg(Logger::instance().getLogFilePath()));
        } else {
            QMessageBox::information(this, "File Backup Completed", QString("File backup completed but there was at least one error. The log is available here:\n%1").arg(Logger::instance().getLogFilePath()));
        }
        Logger::instance().log(QString("File backup complete."));
        copying = 0;
        ui->statusbar->clearMessage();

        worker->deleteLater();
        workerThread->deleteLater();
    });

    connect(worker, &Worker::progressUpdate, this, [=](const QString &message) {
        Logger::instance().log(message);
    });

    workerThread->start();
}










