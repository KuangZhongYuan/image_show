/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_opendir;
    QListWidget *listWidget_dir;
    QLineEdit *lineEdit;
    QLabel *label_pix;
    QPushButton *pushButton_up;
    QPushButton *pushButton_down;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1093, 634);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_opendir = new QPushButton(centralwidget);
        pushButton_opendir->setObjectName(QString::fromUtf8("pushButton_opendir"));
        pushButton_opendir->setGeometry(QRect(90, 300, 93, 29));
        listWidget_dir = new QListWidget(centralwidget);
        listWidget_dir->setObjectName(QString::fromUtf8("listWidget_dir"));
        listWidget_dir->setGeometry(QRect(20, 31, 256, 261));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(310, 30, 661, 41));
        label_pix = new QLabel(centralwidget);
        label_pix->setObjectName(QString::fromUtf8("label_pix"));
        label_pix->setGeometry(QRect(310, 100, 611, 481));
        label_pix->setFrameShape(QFrame::Box);
        label_pix->setMidLineWidth(0);
        label_pix->setPixmap(QPixmap(QString::fromUtf8("../../../Images/Linda.png")));
        label_pix->setScaledContents(true);
        label_pix->setWordWrap(false);
        pushButton_up = new QPushButton(centralwidget);
        pushButton_up->setObjectName(QString::fromUtf8("pushButton_up"));
        pushButton_up->setGeometry(QRect(30, 350, 101, 31));
        pushButton_down = new QPushButton(centralwidget);
        pushButton_down->setObjectName(QString::fromUtf8("pushButton_down"));
        pushButton_down->setGeometry(QRect(150, 350, 101, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1093, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_opendir->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\347\233\256\345\275\225", nullptr));
        label_pix->setText(QString());
        pushButton_up->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\345\274\240", nullptr));
        pushButton_down->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\345\274\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
