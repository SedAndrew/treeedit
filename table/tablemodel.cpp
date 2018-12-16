#include "tablemodel.h"

TableModel::TableModel(int rows, int columns, QObject *parent)
{

}

TableModel::~TableModel()
{

}

int TableModel::rowCount(const QModelIndex &parent) const
{

}

int TableModel::columnCount(const QModelIndex &parent) const
{

}

QVariant TableModel::data(const QModelIndex &index, int role) const
{

}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{

}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{

}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

}

bool TableModel::insertRows(int position, int rows, const QModelIndex &parent)
{

}

bool TableModel::insertColumns(int position, int columns, const QModelIndex &parent)
{

}

bool TableModel::removeRows(int position, int rows, const QModelIndex &parent)
{

}

bool TableModel::removeColumns(int position, int columns, const QModelIndex &parent)
{

}
