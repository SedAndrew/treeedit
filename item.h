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

    int childCount() const; // количество потомков (элементов в списке childItems)
    void appendChild(Item *child); // добавление в childItems
    bool insertChild(int row, Item *item); // вставка в childItems
    bool removeChild(int row); // удаление из childItems

    Item *child(int row); // возвращает потомка
    Item *parent(); // возвращает родителя

    bool setData(int column, const QVariant &data); // задает значения веток после изменения (flags Qt::ItemIsEditable)
    QVariant data(int column) const; // значение из строки тега по указанному номеру
    int row() const; // индекс потомка по отношению к своему родителю
    int columnCount() const; // количество атрибутов


private:
    QList<Item* > childItems;
    QList<QVariant > itemData;
    QList<QString > m_atribut;
    QList<QString > m_value;
    QList<QString > m_comments;
    QString m_text;
    Item *parentItem;
};

#endif // ITEM_H
