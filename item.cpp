#include "item.h"

Item::Item(const QList<QVariant> &data, Item *parent)
{
    parentItem = parent;
    itemData = data;
}

Item::~Item()
{
    qDeleteAll(childItems);
}

int Item::childCount() const
{
    return childItems.count();
}

void Item::appendChild(Item *child)
{
    childItems.append(child);
}

bool Item::insertChild(int row, Item *item)
{
    if (row < 0 || row > childItems.count())
        return false;
    childItems.insert(row, item);
    return true;
}

bool Item::removeChild(int row)
{
    if (row < 0 || row >= childItems.count())
        return false;
    delete childItems.takeAt(row);
    return true;
}

Item *Item::child(int row)
{
    return childItems.value(row);
}

Item *Item::parent()
{
    return parentItem;
}

bool Item::setData(int column, const QVariant &data)
{
    if (column < 0 || column >= itemData.count())
        return false;
    itemData.replace(column, data);
    return true;
}

QVariant Item::data(int column) const
{
    return itemData.value(column);
}

int Item::row() const
{
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast<Item*>(this));
    return 0;
}

int Item::columnCount() const
{
    return itemData.count();
}

