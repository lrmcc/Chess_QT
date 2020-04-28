#include "chess.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <mainwindow.cpp>
#include <QTimer>
#include <QDebug>
#include <QPixmap>

Chess::Chess()
{

}
void Chess::BoardInit(Ui::MainWindow *ui, QGraphicsScene* board){


}
/*
Chess::~Chess()
{

}
*/
//Cell::Cell(){}

Cell::Cell(int x, int y, int width, int height, int id, int cell_counter){
    QColor color(255, 0, 0);
    //randomly assign pink (alive) with 50% probability and white (dead) with 50% probability
    if(cell_counter % 2 == 0) {
        //lightSquare
        color.setRgb(240, 218, 181);
    }
    else{
        //darkSquare
        color.setRgb(181, 135, 99);
    }
    color_ = color;
    x_ = x * width; //since we are creating squares we need x and y to be more than simply a point
    y_ = y * height;
    width_ = width;
    height_ = height;
    id_ = id;
    qDebug() << QString::number(id);
}

QRectF Cell::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

QPainterPath Cell::shape() const
{
    QPainterPath path;
    path.addRect(x_, y_, width_, width_);
    return path;
}

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget) //should not have a semi colon

    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_));
    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->width_));

    int cell_text_x = x_ + 33;
    int cell_text_y = y_ + 33;

    QString text_cell = QString::number(id_);

    QRectF rect{static_cast<qreal>(cell_text_x), static_cast<qreal>(cell_text_y), 40, 40};
    painter->drawText(rect, text_cell);
    painter->setBrush(b);

}


