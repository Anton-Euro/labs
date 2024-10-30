#include "headers/mainwindow.h"
#include "ui/ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), itemlist(std::make_shared<ItemList>()), history_index(-1) {
    ui->setupUi(this);

    this->model = new QTableViewFilesModel(itemlist);
    this->ui->file_view->setModel(model);

    ui->file_view->setColumnWidth(0, 200);

    connect(ui->file_view, &QTableView::doubleClicked, this, &MainWindow::double_click_to_dir);
    connect(ui->init_from_dir, &QPushButton::clicked, this, &MainWindow::init_from_dir);
    connect(ui->add_file, &QPushButton::clicked, this, &MainWindow::init_from_file);
    connect(ui->back, &QPushButton::clicked, this, &MainWindow::go_back);
    connect(ui->next, &QPushButton::clicked, this, &MainWindow::go_next);

}

void MainWindow::init_from_dir() {
    QString dir = QFileDialog::getExistingDirectory(this, "Выбрать директорию");
    if (!dir.isEmpty())
    {   
        std::string path = dir.toStdString();
        std::cout << path << std::endl;
        history_index = -1;
        history.clear();
        itemlist->init_from_dir(fs::path(path));
        model->refresh();

    }
}

void MainWindow::init_from_file() {
    QString file = QFileDialog::getOpenFileName(this, "Выбрать файл");
    if(file != "") {
        itemlist->current_dir->add_from_ptr(itemlist->init_from_file(file.toStdString()));
        model->refresh();
    }
}

void MainWindow::double_click_to_dir(const QModelIndex &index) {
    if(itemlist->current_dir->get_isdir(index.row()) == true) {
        while(history.size()-1 != history_index) history.removeLast();
        history.push_back(itemlist->current_dir);
        history_index++;
        itemlist->current_dir = itemlist->current_dir->get_ptr_from_index(index.row());
        model->refresh();
        
    }
}

void MainWindow::go_back() {
    if(!history.empty() && history_index-1 > -1) {
        if(history[history_index] != itemlist->current_dir) {
            history.push_back(itemlist->current_dir);
            history_index++;
        }
        
        itemlist->current_dir = history[--history_index];
        model->refresh();
    }
}

void MainWindow::go_next() {
    if(!history.empty() && history_index+1 < history.size()) {
        itemlist->current_dir = history[++history_index];
        model->refresh();
    }
}

MainWindow::~MainWindow() {
    delete ui;
}
