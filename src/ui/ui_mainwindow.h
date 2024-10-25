/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QListView *file_view;
    QPushButton *back;
    QPushButton *next;
    QPushButton *init_from_dir;
    QPushButton *add_file;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(687, 522);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        file_view = new QListView(centralwidget);
        file_view->setObjectName("file_view");

        gridLayout_2->addWidget(file_view, 1, 0, 1, 14);

        back = new QPushButton(centralwidget);
        back->setObjectName("back");
        back->setEnabled(true);

        gridLayout_2->addWidget(back, 0, 0, 1, 1);

        next = new QPushButton(centralwidget);
        next->setObjectName("next");

        gridLayout_2->addWidget(next, 0, 1, 1, 1);

        init_from_dir = new QPushButton(centralwidget);
        init_from_dir->setObjectName("init_from_dir");

        gridLayout_2->addWidget(init_from_dir, 0, 13, 1, 1);

        add_file = new QPushButton(centralwidget);
        add_file->setObjectName("add_file");

        gridLayout_2->addWidget(add_file, 0, 12, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "lab", nullptr));
        back->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        next->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        init_from_dir->setText(QCoreApplication::translate("MainWindow", "init from dir", nullptr));
        add_file->setText(QCoreApplication::translate("MainWindow", "add file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
