#ifndef ITEM_H
#define ITEM_H

/*  About
 *  childItems - список дочерних элементов
 *  itemData - список атрибутов элемента
 *  parentItem - указатель на элемент родителя
 *
**/

#include <QList>
#include <QVariant>

class Item
{
public:
    Item(const QList<QVariant> &data, Item *parent = 0);
    ~Item();

    int childCount() const;
    void appendChild(Item *child);
    bool insertChild(int row, Item *item);
    bool removeChild(int row);

    Item *child(int row); // возвращает потомка
    Item *parent(); // возвращает родителя

    bool setData(int column, const QVariant &data);
    QVariant data(int column) const;
    int row() const;
    int columnCount() const;


private:
    QList<Item* > childItems;
    QList<QVariant> itemData;
    Item *parentItem;
};

#endif // ITEM_H
