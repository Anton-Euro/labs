#include <QMainWindow>
#include "itemlist.h"
#include "listviewexplorer.h"
#include "container.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void double_click_to_dir(const QModelIndex &index);
    void init_from_dir();
    void init_from_file();
    void go_back();
    void go_next();
    void export_to_json();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<ItemList> itemlist;
    QTableViewFilesModel *model;
    QVector<std::shared_ptr<Item>> history;
    int history_index;
    MyContainer<std::shared_ptr<Item>> hist;
};
