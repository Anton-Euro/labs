#include "headers/listviewexplorer.h"

QTableViewFilesModel::QTableViewFilesModel(std::shared_ptr<ItemList> listptr, QObject *parent): itemlist(listptr), QAbstractTableModel(parent) {}

void QTableViewFilesModel::refresh() {
    beginResetModel();
    endResetModel();
} 


int QTableViewFilesModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;
    return itemlist->current_dir->get_len();
}

int QTableViewFilesModel::columnCount(const QModelIndex &parent) const {
    return 4;
}

QVariant QTableViewFilesModel::data(const QModelIndex &index, int role) const {
    if(!index.isValid() || index.row() >= itemlist->current_dir->get_len()) {
        return QVariant();
    }
    if (role == Qt::CheckStateRole || role == Qt::DecorationRole) {
        if(index.column() == 0 && role == Qt::DecorationRole) {
            if(itemlist->current_dir->get_isdir(index.row()) == true) {
                return QIcon(QPixmap(":/static/folder.png"));
            } else {
                return QIcon(QPixmap(":/static/file.png"));
            }
            
        }
        return QVariant();
    }

    if (role == Qt::TextAlignmentRole) {
        return Qt::AlignVCenter;
    }

    std::unique_ptr<FileMeta> file_meta = itemlist->current_dir->get_from_index(index.row());

    switch(index.column()) {
        case 0: {
            if(file_meta->file_ext != "") {
                return QString::fromStdString(file_meta->name+"."+file_meta->file_ext);
            } else {
                return QString::fromStdString(file_meta->name);
            }
            
        }
        case 1: {
            if(itemlist->current_dir->get_isdir(index.row()) == true) {
                return QString::fromStdString("--");
            } else {
                return QString::fromStdString(file_meta->size_to_print(file_meta->size));
            }
        }
        case 2: return QString::fromStdString(file_meta->timepoint_to_string(file_meta->created_time));
        case 3: return QString::fromStdString(file_meta->timepoint_to_string(file_meta->modified_time));
        default: return QVariant();
    }
}

QVariant QTableViewFilesModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal) {
        return QVariant();
    }
    
    switch (section) {
        case 0: return QStringLiteral("Name");
        case 1: return QStringLiteral("Size");
        case 2: return QStringLiteral("Date Created");
        case 3: return QStringLiteral("Date Modified");
        default: return QVariant();
    }
}