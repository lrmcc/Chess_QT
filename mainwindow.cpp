
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


    Board_ = new QGraphicsScene;
    Board_->setSceneRect(0, 0, 720, 720);

    QGraphicsView * grid_view = ui->graphicsViewBoard;
    grid_view->setScene(Board_);

    QColor bg_color(83, 89, 94);
    grid_view->setBackgroundBrush(QBrush(bg_color, Qt::SolidPattern));

    QColor dark_cell_(181, 135, 99);
    QColor light_cell_(240, 218, 181);
    //build the board
    int cell_count = 0;
    int cell_id = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            Cell * item = new Cell(j, i, 80, 80,cell_id, cell_count);
            cells_[i][j] = item;
            connect(item, &Cell::CellSelected, this, &MainWindow::setCellsClicked);
            //connect(item, &Cell::DeleteCell, this, &MainWindow::DeleteCellSlot);
            Board_->addItem(item);
            cell_count++;
            cell_id++;
            if (cell_count == 8 || cell_count == 17 || cell_count == 26|| cell_count == 35|| cell_count == 44|| cell_count == 53|| cell_count == 62){
                cell_count++;
            }
        }
    }

    //start the game
        //Chess * game = new Chess()

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::addItemListMoves(QString item){
    ui->listWidgetMoves->addItem(item);
}

void MainWindow::setCellsClicked(Cell * c){
    int vec_size = cellsClicked_.size();
    qDebug() << "vec_size" << QString::number(vec_size);
    cell_click_counter_++;
    int num_clicks = get_cell_click();
    qDebug() << "num_clicks" << QString::number(num_clicks);

    Cell *temp;


    if (num_clicks == 1){
        cellsClicked_.push_back(c);
        qDebug() << "Cell "<< QString::number(c->get_id()) << " to move";
        QColor highlight(226, 240, 29);
        c->set_color(highlight);

    }
    else if (num_clicks == 2 ){
        cellsClicked_.push_back(c);
        qDebug() << "Target Cell "<< QString::number(c->get_id()) << " if legal move";
        QColor highlight(245, 66, 129);
        c->set_color(highlight);
        target_ = c;

    }
    else if (num_clicks > 2){
        int target_id = target_->get_id();
        qDebug() << "Prev cell: " << QString::number(target_id);
        int curr_id = c->get_id();
        qDebug() << "Curr cell: " << QString::number(curr_id);

        if (curr_id == target_id){
            for (auto i = cellsClicked_.begin(); i != cellsClicked_.end(); ++i){
                temp = *i;
                temp->set_color(temp->get_original_color());
                temp->updateCell();
            }
            cellsClicked_.clear();
            num_clicks = 0;
            clear_cell_click();
        }

    }
    else{

    }
    vec_size = cellsClicked_.size();
    qDebug() << "vec_size" << QString::number(vec_size);

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

    QColor side_color(240, 235, 218);

    QGraphicsRectItem* item1 = new QGraphicsRectItem(640,0,80,80);
    QGraphicsRectItem* item2 = new QGraphicsRectItem(640,80,80,80);
    QGraphicsRectItem* item3 = new QGraphicsRectItem(640,160,80,80);
    QGraphicsRectItem* item4 = new QGraphicsRectItem(640,240,80,80);
    QGraphicsRectItem* item5 = new QGraphicsRectItem(640,320,80,80);
    QGraphicsRectItem* item6 = new QGraphicsRectItem(640,400,80,80);
    QGraphicsRectItem* item7 = new QGraphicsRectItem(640,480,80,80);
    QGraphicsRectItem* item8 = new QGraphicsRectItem(640,560,80,80);

    QGraphicsRectItem* item9 = new QGraphicsRectItem(0,640,80,80);
    QGraphicsRectItem* item10 = new QGraphicsRectItem(80,640,80,80);
    QGraphicsRectItem* item11 = new QGraphicsRectItem(160,640,80,80);
    QGraphicsRectItem* item12 = new QGraphicsRectItem(240,640,80,80);
    QGraphicsRectItem* item13 = new QGraphicsRectItem(320,640,80,80);
    QGraphicsRectItem* item14 = new QGraphicsRectItem(400,640,80,80);
    QGraphicsRectItem* item15 = new QGraphicsRectItem(480,640,80,80);
    QGraphicsRectItem* item16 = new QGraphicsRectItem(560,640,80,80);
    QGraphicsRectItem* item17 = new QGraphicsRectItem(640,640,80,80);


    item1->setBrush(QBrush(side_color));
    item2->setBrush(QBrush(side_color));
    item3->setBrush(QBrush(side_color));
    item4->setBrush(QBrush(side_color));
    item5->setBrush(QBrush(side_color));
    item6->setBrush(QBrush(side_color));
    item7->setBrush(QBrush(side_color));
    item8->setBrush(QBrush(side_color));
    item9->setBrush(QBrush(side_color));
    item10->setBrush(QBrush(side_color));
    item11->setBrush(QBrush(side_color));
    item12->setBrush(QBrush(side_color));
    item13->setBrush(QBrush(side_color));
    item14->setBrush(QBrush(side_color));
    item15->setBrush(QBrush(side_color));
    item16->setBrush(QBrush(side_color));
    item17->setBrush(QBrush(side_color));

    Board_->addItem(item1);
    Board_->addItem(item2);
    Board_->addItem(item3);
    Board_->addItem(item4);
    Board_->addItem(item5);
    Board_->addItem(item6);
    Board_->addItem(item7);
    Board_->addItem(item8);
    Board_->addItem(item9);
    Board_->addItem(item10);
    Board_->addItem(item11);
    Board_->addItem(item12);
    Board_->addItem(item13);
    Board_->addItem(item14);
    Board_->addItem(item15);
    Board_->addItem(item16);
    Board_->addItem(item17);

    QGraphicsTextItem *text1 = Board_->addText("H");
    text1->setPos(656, 8);
    text1->setScale(3);
    QGraphicsTextItem *text2 = Board_->addText("G");
    text2->setPos(656, 88);
    text2->setScale(3);
    QGraphicsTextItem *text3 = Board_->addText("F");
    text3->setPos(656, 168);
    text3->setScale(3);
    QGraphicsTextItem *text4 = Board_->addText("E");
    text4->setPos(656, 248);
    text4->setScale(3);
    QGraphicsTextItem *text5 = Board_->addText("D");
    text5->setPos(656, 328);
    text5->setScale(3);
    QGraphicsTextItem *text6 = Board_->addText("C");
    text6->setPos(656, 408);
    text6->setScale(3);
    QGraphicsTextItem *text7 = Board_->addText("B");
    text7->setPos(656, 488);
    text7->setScale(3);
    QGraphicsTextItem *text8 = Board_->addText("A");
    text8->setPos(656, 568);
    text8->setScale(3);

    QGraphicsTextItem *text9 = Board_->addText("1");
    text9->setPos(16,648);
    text9->setScale(3);
    QGraphicsTextItem *text10 = Board_->addText("2");
    text10->setPos(96,648);
    text10->setScale(3);
    QGraphicsTextItem *text11 = Board_->addText("3");
    text11->setPos(176,648);
    text11->setScale(3);
    QGraphicsTextItem *text12 = Board_->addText("4");
    text12->setPos(256,648);
    text12->setScale(3);
    QGraphicsTextItem *text13 = Board_->addText("5");
    text13->setPos(336,648);
    text13->setScale(3);
    QGraphicsTextItem *text14 = Board_->addText("6");
    text14->setPos(416,648);
    text14->setScale(3);
    QGraphicsTextItem *text15 = Board_->addText("7");
    text15->setPos(496,648);
    text15->setScale(3);
    QGraphicsTextItem *text16 = Board_->addText("8");
    text16->setPos(576,648);
    text16->setScale(3);

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
