#include "chess.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <mainwindow.cpp>
#include <QTimer>
#include <QDebug>
#include <QPixmap>

Chess::Chess()
{
    piece_images_->insert(std::pair<std::string, QPixmap>("black_pawn", "C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_pawn.png"));
    piece_images_->insert(std::pair<std::string, QPixmap>("white_pawn", "C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_pawn.png"));


            //   pix_black_pawn("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_pawn.png");
           //    QPixmap pix_white_pawn("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_pawn.png");


}
void Chess::BoardInit(){


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

    //switch statement based on piece show piece or blank
    if (id_ > 7 && id_ < 16) {
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_pawn.png");
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), img);
    }
    else if (id_ > 47 && id_ < 56){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_pawn.png");
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), img);
    }
    else if (id_ == 0 || id_ == 7){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_castle.png");
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), img);
    }
    else if (id_ == 56 || id_ == 63){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_castle.png");
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), img);
    }
    else if (id_ == 1 || id_ == 6){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_knight.png");
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), img);
    }
    else if (id_ == 57 || id_ == 62){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_knight.png");
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), img);
    }
    else if (id_ == 2 || id_ == 5){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_bishop.png");
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), img);
    }
    else if (id_ == 58 || id_ == 61){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_bishop.png");
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), img);
    }
    else if (id_ == 3){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_king.png");
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), img);
    }
    else if (id_ == 4){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_queen.png");
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), img);
    }
    else if (id_ == 59){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_king.png");
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), img);
    }
    else if (id_ == 60){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_queen.png");
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), img);
    }
    else {
        int cell_text_x = x_ + 33;
        int cell_text_y = y_ + 33;
        QString text_cell = QString::number(id_);
        QRectF rect{static_cast<qreal>(cell_text_x), static_cast<qreal>(cell_text_y), 40, 40};
        painter->drawText(rect, text_cell);
    }
    painter->setBrush(b);
}


void Cell::pieceInit(int id)
{
    /*
    int x  = this->x_;
    int adj = 0;
    if (id > 7 && id < 16) {
        adj = id - 8;
        x = 68 + (80*adj);
        QLabel *label_pawn = new QLabel();
        //QPixmap pix_black_pawn("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_pawn.png");
        pix_->load("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_pawn.png");
        label_pawn->setText("black pawn");
        label_pawn->setGeometry(x,202,60,60);
        //pix_ = pix_black_pawn;
        label_pawn->setAlignment(Qt::AlignCenter);
        label_pawn->setFrameStyle(QFrame::NoFrame);
        pix_->scaled(label_pawn->size(),Qt::KeepAspectRatio);
        label_pawn->setPixmap(*pix_);
        label_ = label_pawn;
        //pawns use a proxy widget, but still the embed warnings appear
        //QGraphicsProxyWidget *proxy = board->addWidget(label_pawn);
        qDebug() << ("black pawn");

    }
    else if (id > 47 && id < 56){
        adj = id - 48;
        x = 68 + (80*adj);
        QLabel *label_pawn = new QLabel();
        //QPixmap pix_white_pawn("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_pawn.png");
        pix_->load("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_pawn.png");
        label_pawn->setText("white pawn");
        label_pawn->setGeometry(x,602,60,60);
        //pix_ = pix_white_pawn;
        label_pawn->setAlignment(Qt::AlignCenter);
        label_pawn->setFrameStyle(QFrame::NoFrame);
        pix_->scaled(label_pawn->size(),Qt::KeepAspectRatio);
        label_pawn->setPixmap(*pix_);
        label_ = label_pawn;
        //pawns use a proxy widget, but still the embed warnings appear
        //QGraphicsProxyWidget *proxy = board->addWidget(label_pawn);
        qDebug() << ("white pawn");
    }
*/
}











