#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "chess.h"
#include <QMainWindow>
#include <QMessageBox>
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

    QGraphicsItem *getItem() const;
    void setItem(QGraphicsItem *value);
    void animateButtons();
    void addItemListMoves(QString item);
    QGraphicsScene *Board_;
    void populateBoard(QGraphicsScene * board);
private slots:
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

    QGraphicsItem *item;
    QGraphicsScene *scene;
    int cell_height_;
    int cell_width_;
    int cell_count_;
    QTimer *timer;
    Cell * cells[8][8];
    //std::vector <Chess*> pieces_;

};
#endif // MAINWINDOW_H
