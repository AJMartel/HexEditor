#include "my_model.h"
#include <cassert>
#include <cstdio>
BinaryViewModel::BinaryViewModel(QObject *parent,int base_,BinaryTab* tab)
    :QAbstractTableModel(parent),bdata(tab),base(base_) {
    rowsNum=bdata->size/colsNum+1;
    assert(base==2 or base==4 or  base==16 or  base==10);
    strings=new QString[bdata->size];
    unsigned char* d= (unsigned char*)bdata->data;
    for(unsigned int j=0; j<bdata->size; j++) {
        strings[j]= CharToQString(d[j]);
    }
}

int BinaryViewModel::rowCount(const QModelIndex & /*parent*/) const {
    return rowsNum;
}

int BinaryViewModel::columnCount(const QModelIndex & /*parent*/) const {
    return colsNum;
}
void BinaryViewModel::setColumnCount(int num) {
    int dt=num-colsNum;
    if(dt>0) {
        insertColumns(0,dt);
    } else {
        removeColumns(0,-dt);
    }
    dt=bdata->size/num+1-rowsNum;
    if(dt>0) {
        insertRows(0,dt);
    } else {
        removeRows(0,-dt);
    }
    rowsNum=bdata->size/num+1;
    colsNum=num;
}
bool BinaryViewModel::removeRows ( int row, int count, const QModelIndex & parent ) {
    colsNum-=count;
    beginRemoveRows(parent,row,row+count-1);
    endRemoveRows();
    return true;
}
bool BinaryViewModel::insertRows ( int row, int count, const QModelIndex & parent  ) {
    colsNum+=count;
    beginInsertRows(parent,row,row+count-1);
    endInsertRows();
    return true;
}
bool BinaryViewModel::removeColumns ( int /*column*/, int count, const QModelIndex & parent ) {
    colsNum-=count;
    beginRemoveColumns(parent,0,count-1);
    endRemoveColumns();
    return true;
}
bool BinaryViewModel::insertColumns ( int /*column*/, int count, const QModelIndex & parent  ) {
    colsNum+=count;
    beginInsertColumns(parent,0,count-1);
    endInsertColumns();
    return true;
}
QVariant BinaryViewModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int col = index.column();
    unsigned int num=row*colsNum+col;
    if (role == Qt::DisplayRole) {
        if(bdata->size<=num)return QString();
        return strings[num];
    } else if (role == Qt::ForegroundRole ) {
        for(auto p: bdata->usedBlocks) {
            if(num>=p.first and num<p.second) {
                return QColor(10,130,10);
            }
        }
    }
    return QVariant();
}
Qt::ItemFlags BinaryViewModel::flags(const QModelIndex & index) const {
    unsigned int num=index.row()*colsNum+index.column();
    if(bdata->size<num)return 0;
    return   Qt::ItemIsEditable | Qt::ItemIsEnabled ;
}
bool BinaryViewModel::setHeaderData(int section, Qt::Orientation orientation ,const QVariant& /*value*/,int /*role*/) {
    if(orientation==Qt::Horizontal and section>colsNum) {
        colsNum=section;
        rowsNum=bdata->size/colsNum;

        emit layoutChanged();
    }
    return true;
}
bool BinaryViewModel::setData(const QModelIndex & index, const QVariant & value, int role) {
    if (role == Qt::EditRole) {
        QString s=value.toString();
        int c = value.toInt();
        //printf("-----| %d\n",c%16);
        int num=index.row()*colsNum+index.column();
        bdata->data[num]=c;
        for(auto model:bdata->models) {
            model->UpdateString(num);
        }

    }
    return true;
}


QString BinaryViewModel::CharToQString(unsigned char c)  {
    if(base==2) {
        QString str;
        const char chars[2]= {'0','1'};
        for(int i=0; i<8; i++) {
            str.push_front(chars[0b00000001 & c]);
            c=c>>1;
        }
        return str;
    } else if(base==4) {
        QString str;
        for(int i=0; i<4; i++) {
            str.push_front('0'+c%4);
            c=c>>2;
        }
        return str;
    } else if(base==16) {
        QString str;
        for(int i=0; i<2; i++) {
            int a=c%16;
            if(a<10) {
                str.push_front('0'+a);
            } else {
                str.push_front('A'-10+a);
            }
            c=c>>4;
        }
        return str;
    }
    return QString::number( c,base);
}
void BinaryViewModel::UpdateString(unsigned int stringNum)  {
    if(bdata->size<stringNum)return;
    strings[stringNum]=CharToQString(bdata->data[stringNum]);
}
