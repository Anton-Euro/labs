#include <QMainWindow>
#include "itemlist.h"
#include "listviewexplorer.h"
#include "stack.h"

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

private:
    Ui::MainWindow *ui;
    std::shared_ptr<ItemList> itemlist;
    QTableViewFilesModel *model;
    QVector<std::shared_ptr<Item>> history;
    int history_index;
    Stack<std::shared_ptr<Item>> hist;
};
