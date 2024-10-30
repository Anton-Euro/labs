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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QTableView *file_view;
    QPushButton *back;
    QPushButton *add_file;
    QPushButton *init_from_dir;
    QPushButton *next;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(687, 522);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        file_view = new QTableView(centralwidget);
        file_view->setObjectName("file_view");
        file_view->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        file_view->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        file_view->setShowGrid(false);
        file_view->setWordWrap(false);
        file_view->horizontalHeader()->setDefaultSectionSize(150);
        file_view->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        file_view->horizontalHeader()->setStretchLastSection(true);
        file_view->verticalHeader()->setVisible(false);

        gridLayout_2->addWidget(file_view, 1, 0, 1, 7);

        back = new QPushButton(centralwidget);
        back->setObjectName("back");
        back->setEnabled(true);

        gridLayout_2->addWidget(back, 0, 0, 1, 1);

        add_file = new QPushButton(centralwidget);
        add_file->setObjectName("add_file");

        gridLayout_2->addWidget(add_file, 0, 5, 1, 1);

        init_from_dir = new QPushButton(centralwidget);
        init_from_dir->setObjectName("init_from_dir");

        gridLayout_2->addWidget(init_from_dir, 0, 6, 1, 1);

        next = new QPushButton(centralwidget);
        next->setObjectName("next");

        gridLayout_2->addWidget(next, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "lab", nullptr));
        back->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        add_file->setText(QCoreApplication::translate("MainWindow", "add file", nullptr));
        init_from_dir->setText(QCoreApplication::translate("MainWindow", "init from dir", nullptr));
        next->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
