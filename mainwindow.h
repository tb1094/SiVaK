#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QStringList>
#include <QFileDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_addfile_srcBackup_clicked();

    void on_pushButton_remove_srcBackup_clicked();

    void on_pushButton_browse_dstBackup_clicked();

    void on_pushButton_startBackup_clicked();

    void on_pushButton_adddir_srcBackup_clicked();

private:
    Ui::MainWindow *ui;
    QStringListModel *src_model;
    int copying;
};
#endif // MAINWINDOW_H
