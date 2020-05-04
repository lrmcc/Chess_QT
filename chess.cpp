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
    piece_images_->insert(std::pair<std::string, QPixmap>("black_bishop", "C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_bishop.png"));
    piece_images_->insert(std::pair<std::string, QPixmap>("black_knight", "C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_knight.png"));
    piece_images_->insert(std::pair<std::string, QPixmap>("black_castle", "C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_castle.png"));
    piece_images_->insert(std::pair<std::string, QPixmap>("black_king", "C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_king.png"));
    piece_images_->insert(std::pair<std::string, QPixmap>("black_queen", "C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_queen.png"));
    piece_images_->insert(std::pair<std::string, QPixmap>("white_pawn", "C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_pawn.png"));
    piece_images_->insert(std::pair<std::string, QPixmap>("white_bishop", "C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_bishop.png"));
    piece_images_->insert(std::pair<std::string, QPixmap>("white_knight", "C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_knight.png"));
    piece_images_->insert(std::pair<std::string, QPixmap>("white_castle", "C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_castle.png"));
    piece_images_->insert(std::pair<std::string, QPixmap>("white_king", "C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_king.png"));
    piece_images_->insert(std::pair<std::string, QPixmap>("white_queen", "C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_queen.png"));

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
    original_color_ = color;
    x_ = x * width; //since we are creating squares we need x and y to be more than simply a point
    y_ = y * height;
    width_ = width;
    height_ = height;
    init_ = true;
    id_ = id;
    qDebug() << QString::number(id);

    if (id > 7 && id < 16) {
        piece_= "black_pawn";

    }
    else if (id > 47 && id < 56){
        piece_= "white_pawn";
    }
    else if (id == 0 || id == 7){
        piece_= "black_castle";
    }
    else if (id == 56 || id == 63){
        piece_= "white_castle";
    }
    else if (id == 1 || id == 6){
        piece_= "black_knight";
    }
    else if (id == 57 || id_== 62){
        piece_= "white_knight";
    }
    else if (id == 2 || id == 5){
        piece_= "black_bishop";
    }
    else if (id == 58 || id == 61){
        piece_= "white_bishop";
    }
    else if (id == 3){
        piece_= "black_king";
    }
    else if (id == 4){
        piece_= "black_queen";
    }
    else if (id == 59){
        piece_= "white_king";
    }
    else if (id == 60){
        piece_= "white_queen";
    }
    else {
        piece_= "null";
    }

}


void Cell::updatePiece(Cell *c, QString piece){

    qDebug() << "updatePiece: cell id " << c->id_;
    qDebug() << "updatePiece: cell changing to To " << piece;
    c->piece_ = piece;
    c->updateCell();
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
    Q_UNUSED(widget)
    QString piece = piece_;
    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_));
    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->width_));

    if (piece == "black_pawn") {
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_pawn.png");
        piece_pixmap_ = &img;
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), *piece_pixmap_);
    }
    else if (piece == "white_pawn"){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_pawn.png");
        piece_pixmap_ = &img;
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), *piece_pixmap_);
    }
    else if (piece == "black_castle"){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_castle.png");
        piece_pixmap_ = &img;
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), *piece_pixmap_);
    }
    else if (piece == "white_castle"){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_castle.png");
        piece_pixmap_ = &img;
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), *piece_pixmap_);
    }
    else if (piece == "black_knight"){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_knight.png");
        piece_pixmap_ = &img;
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), *piece_pixmap_);
    }
    else if (piece == "white_knight"){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_knight.png");
        piece_pixmap_ = &img;
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), *piece_pixmap_);
    }
    else if (piece == "black_bishop"){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_bishop.png");
        piece_pixmap_ = &img;
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), *piece_pixmap_);
    }
    else if (piece == "white_bishop"){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_bishop.png");
        piece_pixmap_ = &img;
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), *piece_pixmap_);
    }
    else if (piece == "black_king"){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_king.png");
        piece_pixmap_ = &img;
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), *piece_pixmap_);
    }
    else if (piece == "black_queen"){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/black_queen.png");
        piece_pixmap_ = &img;
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), *piece_pixmap_);
    }
    else if (piece == "white_king"){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_king.png");
        piece_pixmap_ = &img;
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), *piece_pixmap_);
    }
    else if (piece == "white_queen"){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/white_queen.png");
        piece_pixmap_ = &img;
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), *piece_pixmap_);
    }
    else if (piece == "null"){
        QPixmap img("C:/Users/pbdin/OneDrive/Desktop/HW5_Chess/HW5_final_project/images/null.png");
        piece_pixmap_ = &img;
        painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), *piece_pixmap_);
    }

    //painter->drawPixmap(QRect(this->x_, this->y_, this->width_, this->width_), *piece_pixmap_);
    painter->setBrush(b);
}


void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Cell "<< QString::number(id_) << " clicked!";

    emit CellSelected(this);

    update();

}
