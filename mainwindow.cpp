
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chess.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioButtonCompSpeed->setChecked(true);
    animateButtons();

    // scene = new QGraphicsScene(this);
    // ui->graphicsViewBoard->setScene(scene);

    Board_ = new QGraphicsScene;
    Board_->setSceneRect(0, 0, 720, 720);
    QGraphicsView * grid_view = ui->graphicsViewBoard;
    grid_view->setScene(Board_);
    QColor dark_cell_(181, 135, 99);
    QColor light_cell_(240, 218, 181);
    //build the board
    int cell_count = 0;
    int cell_id = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            Cell * item = new Cell(j, i, 80, 80,cell_id, cell_count);
            cells[i][j] = item;
            Board_->addItem(item);
            cell_count++;
            cell_id++;
            if (cell_count == 8 || cell_count == 17 || cell_count == 26|| cell_count == 35|| cell_count == 44|| cell_count == 53|| cell_count == 62){
                cell_count++;
            }
        }
    }




}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::addItemListMoves(QString item){
    ui->listWidgetMoves->addItem(item);
}
void MainWindow::animateButtons()
{
    animation = new QPropertyAnimation(ui->pushButtonNewGame, "geometry");
    animation->setDuration(10000);
    animation->setStartValue(QRect(0,11,50,25));
    animation->setEndValue(QRect(292,11,150,35));
    animation->start();
    QEasingCurve curve;
    curve.setType(QEasingCurve::OutBounce);
    animation->setEasingCurve(curve);
    curve.setAmplitude(2.00);
    curve.setOvershoot(2.00);
    curve.setPeriod(1.50);
    animation->start();

    animation1 = new QPropertyAnimation(ui->pushButtonPauseGame, "geometry");
    animation1->setDuration(10000);
    animation1->setStartValue(QRect(750,11,50,10));
    animation1->setEndValue(QRect(450,17,115,24));

    animation2 = new QPropertyAnimation(ui->pushButtonOptions, "geometry");
    animation2->setDuration(10000);
    animation2->setStartValue(QRect(850,11,50,10));
    animation2->setEndValue(QRect(575,17,115,24));

    animation3 = new QPropertyAnimation(ui->pushButtonExit, "geometry");
    animation3->setDuration(10000);
    animation3->setStartValue(QRect(950,11,50,10));
    animation3->setEndValue(QRect(700,17,115,24));

    animationGroup = new QParallelAnimationGroup;
    animationGroup->addAnimation(animation1);
    animationGroup->addAnimation(animation2);
    animationGroup->addAnimation(animation3);
    animationGroup->start();
}

void MainWindow::paintEvent(QPaintEvent *event)
{

    // end of rows
    Board_->addRect(640,0,80,80);
    Board_->addRect(640,80,80,80);
    Board_->addRect(640,160,80,80);
    Board_->addRect(640,240,80,80);
    Board_->addRect(640,320,80,80);
    Board_->addRect(640,400,80,80);
    Board_->addRect(640,480,80,80);
    Board_->addRect(640,560,80,80);
    //bottom row
    Board_->addRect(0,640,80,80);
    Board_->addRect(80,640,80,80);
    Board_->addRect(160,640,80,80);
    Board_->addRect(240,640,80,80);
    Board_->addRect(320,640,80,80);
    Board_->addRect(400,640,80,80);
    Board_->addRect(480,640,80,80);
    Board_->addRect(560,640,80,80);
    Board_->addRect(640,640,80,80);

}

void MainWindow::on_pushButtonEnterP1Name_clicked()
{
    QString nameText = ui->lineEditEnterP1Name->text();
    ui->labelP1Name->setText(nameText);
}

void MainWindow::on_pushButtonEnterP2Name_clicked()
{
    QString nameText = ui->lineEditEnterP2Name->text();
    ui->labelP2Name->setText(nameText);
}



void MainWindow::on_radioButtonXtremeSpeed_toggled(bool checked)
{
    ui->labelCurrentSpeed->setText("Xtreme");
}

void MainWindow::on_radioButtonCompSpeed_toggled(bool checked)
{
    ui->labelCurrentSpeed->setText("Competetion");
}

void MainWindow::on_radioButtonSparSpeed_toggled(bool checked)
{
    ui->labelCurrentSpeed->setText("Spar");
}

void MainWindow::on_radioButtonRelaxSpeed_toggled(bool checked)
{
    ui->labelCurrentSpeed->setText("Relax");
}

void MainWindow::on_pushButtonGoodMove_clicked()
{
    QListWidgetItem *item = ui ->listWidgetMoves->currentItem();
    item->setBackgroundColor(Qt::green);
}

void MainWindow::on_pushButtonBadMove_clicked()
{
    QListWidgetItem *item = ui ->listWidgetMoves->currentItem();
    item->setBackgroundColor(Qt::red);
}

void MainWindow::on_pushButtonOptions_clicked()
{
    QMessageBox::information(this, "Options Menu", "Customize Here");
}

void MainWindow::on_pushButtonExit_clicked()
{
    QMessageBox::warning(this, "Exit Button", "Thanks for playing");
}

void MainWindow::on_pushButtonPauseGame_clicked()
{
    QMessageBox::about(this, "Pause Button", "Currently paused!");
}

void MainWindow::on_pushButtonNewGame_clicked()
{
    QMessageBox::question(this, "New Game Button", "Start a new game? ",
                          QMessageBox::Yes | QMessageBox::No);
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_Chess_X_treme_triggered()
{
    QMessageBox::information(this,"About Chess X-treme", "Authors: Luke McConnell and Joe Falbo");
}

void MainWindow::on_pushButtonGameTheme_clicked()
{
    ui->labelGameTheme->setText(ui->comboBoxTheme->currentText());
}

QGraphicsItem *MainWindow::getItem() const
{
    return item;
}

void MainWindow::setItem(QGraphicsItem *value)
{
    item = value;
}
