#ifndef CHESS_H
#define CHESS_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
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
    //void boardInit();
    //void newGame();
    //void pause();
    //void options();
    //void rules();
private slots:
private:
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
    void set_piece(std::string piece){
        piece_=piece;
    }
    std::string get_piece() { return piece_; }

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

    int get_x() const { return x_; }  // inline member function
    int get_y() const { return y_; }  // inline member function
    int get_width() { return width_; }
    int get_height() { return height_; }

//signals:
    //void increase();
    //void decrease();
    //void neighbors(int x,int y);

private:
  int x_;
  int y_;
  int width_ = 80;
  int height_= 80;
  int id_;
  std::string piece_;
  QColor color_;

protected:
  //void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

};




#endif // CHESS_H