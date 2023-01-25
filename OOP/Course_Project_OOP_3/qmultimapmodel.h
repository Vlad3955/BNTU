//#ifndef QMULTIMAPMODEL_H
//#define QMULTIMAPMODEL_H

//#include <QAbstractTableModel>
//#include <QMultiMap>
//#include "aeroflot.h"

//class QMultiMapModel : public QAbstractTableModel
//{
//    Q_OBJECT

//public:
//    QMultiMapModel(QObject* pobj = 0);
//    int rowCount(const QModelIndex& parent = QModelIndex()) const;
//    int columnCount(const QModelIndex& parent = QModelIndex()) const;
//    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
//    void setMultiMap(QMultiMap<QString, Aeroflot*> *aerofl);
//    QVariant headerData(int nsection, Qt::Orientation orientation, int nRole = Qt::DisplayRole ) const;
//    Qt::ItemFlags flags(const QModelIndex &index) const;
//    bool insertRows (int nRow, int nCount, const QModelIndex& parent = QModelIndex());
//    bool removeRows(int nRow, int  nCount,  const QModelIndex& parent = QModelIndex());

//private:
//    QMultiMap<QString, Aeroflot*> *aerofl_;

//};

//#endif // QMULTIMAPMODEL_H
