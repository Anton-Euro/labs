#include <QMainWindow>
#include "itemlist.h"
#include "listviewexplorer.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void initFromDir();

private:
    Ui::MainWindow *ui;
    ItemList *DirList;
    Item *cur_pos;

    QListViewExplorerModel *model;
};
