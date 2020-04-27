#include "chess.h"
#include "mainwindow.h"
#include <mainwindow.cpp>
#include <QTimer>

Chess::Chess()
{

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



/*
    //QGraphicsScene *scene = new QGraphicsScene();
    //QGraphicsView *view = new QGraphicsView(scene);
    //QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    //scene->addItem(item);
    //view->show();

    for(int i = 0; i < 992; i+=62)
    {
        for(int j = 0; j < 992; j+=62)
        {
            QGraphicsItem *myItem = new MapNode(0, 0, 60, 60);
            myItem->setPos(i, j);
            scene->addItem(myItem);
        }
    }
Cell::Cell(int x, int y){
        QColor color(255, 0, 0);
        //randomly assign pink (alive) with 50% probability and white (dead) with 50% probability
        if(rand() % 100 < 50) {
            color.setRgb(242, 19, 131);
            set_current_status(true);
            qDebug("count");
        }
        else{
            color.setRgb(255, 255, 255);
            set_current_status(false);
        }
        color_ = color;
        x_ = x * width; //since we are creating squares we need x and y to be more than simply a point
        y_ = y * height;
        width_ = width;
        height_ = height;
    }


}


Cell::~Cell()
{

}


void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //shift
    if(event->modifiers() == Qt::ShiftModifier)
    {
        int x = this->get_x()/30;
        int y = this->get_y()/30;
        emit neighbors(x,y);
        return;

    }


    if(event->button() == Qt::RightButton){
//        emit CellSelected(this);
        if(this->get_color() == QColor(242, 19, 131)){

            qDebug() << "Kill cell";
            this->set_color(QColor(255,255,255));
            emit decrease();
            //emit CellSelected(this);
        }
    }
    else if(event->button() == Qt::LeftButton){
        if(this->get_color() == QColor(255, 255, 255)){
            qDebug() << "Ressurect Cell";
            this->set_color(QColor(242,19,131));
            emit increase();
        }
    }
    update();
}
*/
