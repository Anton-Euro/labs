#include "headers/mainwindow.h"
#include "ui/ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), DirList(new ItemList) {
    ui->setupUi(this);

    this->model = new QListViewExplorerModel();

    this->ui->file_view->setModel(model);
    connect(ui->init_from_dir, &QPushButton::clicked, this, &MainWindow::initFromDir);
}

void MainWindow::initFromDir() {
    QString dir = QFileDialog::getExistingDirectory(this, "Выбрать директорию");
    this->model->clearDirList();
    if (!dir.isEmpty())
    {   
        std::string path = dir.toStdString();
        std::cout << path << std::endl;
        this->model->getFolderList(dir, DirList);

    }
}

MainWindow::~MainWindow() {
    delete ui;
    delete DirList;
}
