/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *vertical_srcBackup;
    QLabel *label_srcBackup;
    QListView *listView_srcBackup;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_addfile_srcBackup;
    QPushButton *pushButton_adddir_srcBackup;
    QPushButton *pushButton_remove_srcBackup;
    QVBoxLayout *vertical_startBackup;
    QPushButton *pushButton_startBackup;
    QVBoxLayout *vertical_dstBackup;
    QFrame *line;
    QLabel *label_dstBackup;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_dstBackup;
    QPushButton *pushButton_browse_dstBackup;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 630);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 401, 581));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(5, 5, 5, 5);
        vertical_srcBackup = new QVBoxLayout();
        vertical_srcBackup->setObjectName("vertical_srcBackup");
        label_srcBackup = new QLabel(gridLayoutWidget);
        label_srcBackup->setObjectName("label_srcBackup");
        QFont font;
        font.setPointSize(12);
        label_srcBackup->setFont(font);

        vertical_srcBackup->addWidget(label_srcBackup, 0, Qt::AlignmentFlag::AlignTop);

        listView_srcBackup = new QListView(gridLayoutWidget);
        listView_srcBackup->setObjectName("listView_srcBackup");
        QFont font1;
        font1.setPointSize(10);
        listView_srcBackup->setFont(font1);

        vertical_srcBackup->addWidget(listView_srcBackup);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_addfile_srcBackup = new QPushButton(gridLayoutWidget);
        pushButton_addfile_srcBackup->setObjectName("pushButton_addfile_srcBackup");

        horizontalLayout_2->addWidget(pushButton_addfile_srcBackup);

        pushButton_adddir_srcBackup = new QPushButton(gridLayoutWidget);
        pushButton_adddir_srcBackup->setObjectName("pushButton_adddir_srcBackup");

        horizontalLayout_2->addWidget(pushButton_adddir_srcBackup);

        pushButton_remove_srcBackup = new QPushButton(gridLayoutWidget);
        pushButton_remove_srcBackup->setObjectName("pushButton_remove_srcBackup");

        horizontalLayout_2->addWidget(pushButton_remove_srcBackup);


        vertical_srcBackup->addLayout(horizontalLayout_2);


        gridLayout->addLayout(vertical_srcBackup, 0, 0, 1, 1);

        vertical_startBackup = new QVBoxLayout();
        vertical_startBackup->setObjectName("vertical_startBackup");
        pushButton_startBackup = new QPushButton(gridLayoutWidget);
        pushButton_startBackup->setObjectName("pushButton_startBackup");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_startBackup->sizePolicy().hasHeightForWidth());
        pushButton_startBackup->setSizePolicy(sizePolicy2);
        pushButton_startBackup->setMinimumSize(QSize(0, 50));
        pushButton_startBackup->setBaseSize(QSize(0, 0));

        vertical_startBackup->addWidget(pushButton_startBackup);


        gridLayout->addLayout(vertical_startBackup, 5, 0, 1, 1);

        vertical_dstBackup = new QVBoxLayout();
        vertical_dstBackup->setObjectName("vertical_dstBackup");
        line = new QFrame(gridLayoutWidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        vertical_dstBackup->addWidget(line);

        label_dstBackup = new QLabel(gridLayoutWidget);
        label_dstBackup->setObjectName("label_dstBackup");
        label_dstBackup->setFont(font);

        vertical_dstBackup->addWidget(label_dstBackup, 0, Qt::AlignmentFlag::AlignTop);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit_dstBackup = new QLineEdit(gridLayoutWidget);
        lineEdit_dstBackup->setObjectName("lineEdit_dstBackup");
        lineEdit_dstBackup->setFont(font1);
        lineEdit_dstBackup->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit_dstBackup);

        pushButton_browse_dstBackup = new QPushButton(gridLayoutWidget);
        pushButton_browse_dstBackup->setObjectName("pushButton_browse_dstBackup");

        horizontalLayout->addWidget(pushButton_browse_dstBackup);


        vertical_dstBackup->addLayout(horizontalLayout);


        gridLayout->addLayout(vertical_dstBackup, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 400, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SiVaK File Backup", nullptr));
        label_srcBackup->setText(QCoreApplication::translate("MainWindow", "Files to backup:", nullptr));
        pushButton_addfile_srcBackup->setText(QCoreApplication::translate("MainWindow", "Add files", nullptr));
        pushButton_adddir_srcBackup->setText(QCoreApplication::translate("MainWindow", "Add directory", nullptr));
        pushButton_remove_srcBackup->setText(QCoreApplication::translate("MainWindow", "Remove selected", nullptr));
        pushButton_startBackup->setText(QCoreApplication::translate("MainWindow", "Start Backup", nullptr));
        label_dstBackup->setText(QCoreApplication::translate("MainWindow", "Backup location:", nullptr));
        pushButton_browse_dstBackup->setText(QCoreApplication::translate("MainWindow", "Browse...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
