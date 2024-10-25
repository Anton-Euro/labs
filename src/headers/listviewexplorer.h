#include "itemlist.h"
#include <QModelIndex>
#include <QAbstractListModel>
#include <QString>
#include <QVector>

class QListViewExplorerModel: public QAbstractListModel
{
public:
    QListViewExplorerModel(QObject *parent=nullptr);
    int rowCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;

    void getFolderList(QString folderPath, ItemList *dirList);
    void clearDirList();

private:
    QVector<QString> StringDirList;

};