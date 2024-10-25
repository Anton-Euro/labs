#include "headers/listviewexplorer.h"

QListViewExplorerModel::QListViewExplorerModel(QObject *parent): QAbstractListModel(parent) {}

void QListViewExplorerModel::getFolderList(QString folderPath, ItemList *dirList)
{
    dirList->init_from_dir(folderPath.toStdString());
    dirList->print_all();
    for(int i = 0; i < dirList->itemlistt->get_len(); i++) {
        beginInsertRows(QModelIndex(), StringDirList.size(), StringDirList.size());
        if(dirList->itemlistt->get_isdir(i)) 
            StringDirList.append("[dir]"+QString::fromStdString(dirList->itemlistt->get_name(i)));
        else
            if(dirList->itemlistt->get_ext(i) != "")
                StringDirList.append("[file]"+QString::fromStdString(dirList->itemlistt->get_name(i))+"."+QString::fromStdString(dirList->itemlistt->get_ext(i)));
            else
                StringDirList.append("[file]"+QString::fromStdString(dirList->itemlistt->get_name(i)));
        endInsertRows();
        
    }
}

void QListViewExplorerModel::clearDirList()
{
    beginResetModel();
        
    this->StringDirList.clear();
        
    endResetModel();
    
}


int QListViewExplorerModel::rowCount(const QModelIndex &) const
{
    return this->StringDirList.size();
}

QVariant QListViewExplorerModel::data( const QModelIndex &index, int role ) const
{

    if (!index.isValid() || index.row() >= StringDirList.size() || role != Qt::DisplayRole) {
            return QVariant();
        }

    return StringDirList[index.row()];
}