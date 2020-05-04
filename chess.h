#ifndef CHESS_H
#define CHESS_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include "ui_mainwindow.h"
#include <QStateMachine>
#include <QEventTransition>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <iostream>
#include <string>
#include <vector>
#include <QtWidgets>
#include <QObject>
#include <QColor>



class Chess : public QMainWindow
{
    Q_OBJECT
public:
    Chess();
    void BoardInit();
    //void newGame();
    //void pause();
    //void options();
    //void rules();
    std::vector<QString> piece_names{ "null", "pawn", "bishop", "knight", "castle", "queen","king" };
    std::vector<QString> player_color{ "black","white" };

private slots:
private:
    std::map<std::string, QPixmap> * piece_images_;
    //int p1_turn_;
    //int p2_turn_;
    //std::string p1_name_;
    //std::string p2_name_;
    //QVector<QString> stringVector;

};


class Cell : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    //Cell();

    Cell(int x, int y, int width, int height, int id, int cell_counter); //constructor

    void set_color(QColor color){
        color_=color;
    }
    QColor get_color() { return color_; }
    QColor get_original_color() { return original_color_; }
    void set_piece(QString piece){
        piece_=piece;
    }
    QString get_piece() { return piece_; }
    QPixmap* get_pixmap() {return piece_pixmap_;}
    void set_pixmap(QPixmap pixmap) {piece_pixmap_ = &pixmap;}

    static void updatePiece(Cell *c, QString piece);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    void updateCell(){update();}

    //QPixmap getPiecePixmap(QString piece);

    int get_x() const { return x_; }  // inline member function
    int get_y() const { return y_; }  // inline member function
    int get_width() { return width_; }
    int get_height() { return height_; }
    int get_id() const { return id_;}



//signals:
    //void increase();
    //void decrease();
    //void neighbors(int x,int y);
signals:

    void CellSelected(Cell * c);
    //void DeleteCell(Cell * c);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
  int x_;
  int y_;
  int width_ = 80;
  int height_= 80;
  int id_;
  bool init_;
  QString piece_;
  QColor color_;
  QColor original_color_;
  QPixmap img;
  QPixmap *piece_pixmap_;


};




#endif // CHESS_H
