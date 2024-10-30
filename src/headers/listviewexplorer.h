#include "itemlist.h"
#include <QModelIndex>
#include <QAbstractTableModel>
#include <QString>
#include <QIcon>
#include <QPixmap>

class QTableViewFilesModel: public QAbstractTableModel
{
public:
    QTableViewFilesModel(std::shared_ptr<ItemList> listptr, QObject *parent=nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    void refresh();

private:
    std::shared_ptr<ItemList> itemlist;

};