//#include "qmultimapmodel.h"


//QMultiMapModel::QMultiMapModel(QObject* pobj)
//    : QAbstractTableModel(pobj), aerofl_(nullptr)
//{

//}

//int QMultiMapModel::rowCount(const QModelIndex &parent) const
//{
//    if (aerofl_)
//            return aerofl_->count();
//    return 0;
//}

//int QMultiMapModel::columnCount(const QModelIndex &parent) const
//{
//    return 3;
//}

//QVariant QMultiMapModel::data(const QModelIndex &index, int role) const
//{
//    if (!aerofl_ || !index.isValid() || index.row() >= aerofl_->count() || role != Qt::DisplayRole || role != Qt::EditRole)
//            return QVariant();

//        auto it = aerofl_->cbegin();
//        it += index.row();

//        if (index.column() == 0)
//            return it.key();
//        if (index.column() == 1)
//            return it.value()->dest;
//        if (index.column() == 2)
//            return it.value()->flight_num;

//        return QVariant();
//}

//void QMultiMapModel::setMultiMap(QMultiMap<QString, Aeroflot *> *aerofl)
//{
//    beginResetModel();
//    aerofl_ = aerofl;
//    endResetModel();
//}

//QVariant QMultiMapModel::headerData(int nSection, Qt::Orientation orientation, int nRole) const
//{
//    if (nRole != Qt::DisplayRole)
//    return QVariant();
//    return (orientation == Qt::Horizontal) ? QString("Number") :
//                                             QString::number(nSection);
//}

//Qt::ItemFlags QMultiMapModel::flags(const QModelIndex &index) const
//{
//    Qt::ItemFlags flags = QAbstractTableModel::flags(index);
//    return index.isValid() ? (flags | Qt::ItemIsEditable) : flags;

//}

//bool QMultiMapModel::insertRows(int nRow, int nCount, const QModelIndex &parent)
//{
//    if (parent.isValid())
//    return false;
//    beginInsertRows(QModelIndex(), nRow, nRow + nCount - 1);
//    for (int i = 0; i < nCount; ++i)
//    {
//       aerofl_->insert(QString(), new Aeroflot(QString(), QString()));

//    }
//    endInsertRows();
//    return true;
//}

//bool QMultiMapModel::removeRows(int nRow, int nCount, const QModelIndex &parent)
//{
//    beginRemoveRows(QModelIndex(), nRow, nRow + nCount - 1);

//    for (int i = 0; i < nCount; ++i)
//        aerofl_->remove(QString());

//    endRemoveRows();
//    return true;
//}
