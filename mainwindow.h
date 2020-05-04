#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "chess.h"
#include <QMainWindow>
#include <QMessageBox>
#include <vector>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QStateMachine>
#include <QEventTransition>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void paintEvent(QPaintEvent *event);
    int get_cell_click(){return cell_click_counter_;}
    void clear_cell_click(){cell_click_counter_ = 0;}
    QGraphicsItem *getItem() const;
    void setItem(QGraphicsItem *value);
    void animateButtons();
    void addItemListMoves(QString item);
    QGraphicsScene *Board_;
    //void clearCellsClicked(std::vector<Cell *> cellsClicked);
private slots:
    void setCellsClicked(Cell * c);

    //void CellSelectedSlot(Cell * c);

    //void DeleteCellSlot(Cell * c);

    void on_pushButtonEnterP2Name_clicked();

    void on_pushButtonEnterP1Name_clicked();

    void on_radioButtonXtremeSpeed_toggled(bool checked);

    void on_radioButtonCompSpeed_toggled(bool checked);

    void on_radioButtonSparSpeed_toggled(bool checked);

    void on_radioButtonRelaxSpeed_toggled(bool checked);

    void on_pushButtonGoodMove_clicked();

    void on_pushButtonBadMove_clicked();

    void on_pushButtonOptions_clicked();

    void on_pushButtonExit_clicked();

    void on_pushButtonPauseGame_clicked();

    void on_pushButtonNewGame_clicked();

    void on_actionQuit_triggered();

    void on_actionAbout_Chess_X_treme_triggered();

    void on_pushButtonGameTheme_clicked();

private:
    Ui::MainWindow *ui;
    // newgame button animation
    QPropertyAnimation *animation;
    // pause/options/exit buttons parallel animation group
    QPropertyAnimation *animation1;
    QPropertyAnimation *animation2;
    QPropertyAnimation *animation3;
    QParallelAnimationGroup *animationGroup;
    int cell_click_counter_ = 0;
    QGraphicsItem *item;
    QGraphicsScene *scene;
    int cell_height_;
    int cell_width_;
    int cell_count_;
    QTimer *timer_;
    Cell * cells_[8][8];
    std::vector<Cell *> cellsClicked_;
    Cell *toMove_;
    //QPixmap *toMove_Pixmap_;
    Cell *target_;
    //QPixmap *target_Pixmap_;

};
#endif // MAINWINDOW_H
