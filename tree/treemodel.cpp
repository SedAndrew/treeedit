#include "tree/treemodel.h"
#include "item.h"
#include <QDebug>

TreeModel::TreeModel(const QStringList &strings, QObject *parent)
    : QAbstractItemModel(parent)
{
    QList<QVariant> rootData;
    rootData << "Tree model";
    rootItem = new Item(rootData, 0);
    setupModelData(strings, rootItem);
}

TreeModel::~TreeModel()
{
    delete rootItem;
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<Item*>(parent.internalPointer())->columnCount();
    else
        return rootItem->columnCount();
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{   // вызывается при после каждого взаимодействия с ветками (наведение, снятие, перемещение)
    // возвращает элемент данных, соответствующего аргументу-индексу
    if (!index.isValid())
        return QVariant();
    if (role != Qt::DisplayRole)
        return QVariant();
    Item *item = static_cast<Item*>(index.internalPointer());

    QVariant out = item->data(index.column());
    return out;
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);
    return QVariant();
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    Item *parentItem;
    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<Item*>(parent.internalPointer());
    Item *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

bool TreeModel::insertRows(int position, int rows, const QModelIndex &parent)
{
    Item *parentItem;
    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<Item*>(parent.internalPointer());
    if (position < 0 || position > parentItem->childCount())
        return false;
    QList<QVariant> blankList;
    for (int column = 0; column < columnCount(); column++)
        blankList << QVariant("");
    beginInsertRows(parent, position, position + rows - 1);
    for (int row = 0; row < rows; row++) {
        Item *newItem = new Item(blankList, parentItem);
        if (!parentItem->insertChild(position, newItem))
            break;
    }
    endInsertRows();
    return true;
}

bool TreeModel::removeRows(int position, int rows, const QModelIndex &parent)
{
    Item *parentItem;
    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<Item*>(parent.internalPointer());
    if (position < 0 || position > parentItem->childCount())
        return false;
    beginRemoveRows(parent, position, position + rows - 1);
    for (int row = 0; row < rows; ++row) {
        if (!parentItem->removeChild(position))
            break;
    }
    endRemoveRows();
    return true;
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();
    Item *childItem = static_cast<Item*>(index.internalPointer());
    Item *parentItem = childItem->parent();
    if (parentItem == rootItem)
        return QModelIndex();
    return createIndex(parentItem->row(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    Item *parentItem;
    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<Item*>(parent.internalPointer());
    return parentItem->childCount();
}

bool TreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;
    Item *item = static_cast<Item*>(index.internalPointer());
    if (item->setData(index.column(), value))
        emit dataChanged(index, index);
    else
        return false;
    return true;
}


void TreeModel::setupModelData(const QStringList &lines, Item *parent)
{
    QList<Item*> parents;
    QList<int> indentations;
    parents << parent;
    indentations << 0;
    int number = 0;
    while (number < lines.count()) {
        int position = 0;
        while (position < lines[number].length()) {
            if (lines[number].mid(position, 1) != " ")
                break;
            position++;
        }
        QString lineData = lines[number].mid(position).trimmed();
        if (!lineData.isEmpty()) {
            // Read the column data from the rest of the line.
            QStringList columnStrings = lineData.split("\t", QString::SkipEmptyParts);
            QList<QVariant> columnData;
            for (int column = 0; column < columnStrings.count(); ++column)
                columnData << columnStrings[column];
            if (position > indentations.last()) {
                // The last child of the current parent is now the new parent
                // unless the current parent has no children.
                if (parents.last()->childCount() > 0) {
                    parents << parents.last()->child(parents.last()->childCount()-1);
                    indentations << position;
                }
            } else {
                while (position < indentations.last() && parents.count() > 0) {
                    parents.pop_back();
                    indentations.pop_back();
                }
            }
            // Append a new item to the current parent"s list of children.
            parents.last()->appendChild(new Item(columnData, parents.last()));
        }
        number++;
    }
}

