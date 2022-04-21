/**
 * CS 3505:A5
 * This class is made to mainwindow view the Simon game
 *
 * @author: Robert Li and Wenlin Li
 * @version: 03/14/22 1.0 implemented the method
 * @version: 03/18/22 1.1 fixed bug and added extra feature.
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model.h"

/**
 * @brief MainWindow::MainWindow, basci view window setting.
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->redButton->setStyleSheet(QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
    ui->blueButton->setStyleSheet(QString("QPushButton {background-color: rgb(50,50,200);} QPushButton:pressed {background-color: rgb(150,150,255);}"));
    ui->blueButton->setEnabled(false);
    ui->redButton->setEnabled(false);
    ui->startButton->setEnabled(true);
    setPoint(0);
    ui->progressBar->setRange(0,1);
    ui->progressBar->setValue(0);
}

/**
 * @brief MainWindow::~MainWindow, destructor.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::setPoint, initial the points for text.
 * @param score
 */
void MainWindow::setPoint(int score){
    ui->Value->setText(QString::number(score));
}

/**
 * @brief MainWindow::startComputer, handle computer turn.
 */
void MainWindow::startComputer(){
    ui->blueButton->setEnabled(false);
    ui->redButton->setEnabled(false);
    ui->startButton->setEnabled(false);
    ui->Status->setText("Computer Turn");
    ui->smileyLabel->hide();
}

/**
 * @brief MainWindow::startPlayer, handle player turn.
 */
void MainWindow::startPlayer(){
    ui->blueButton->setEnabled(true);
    ui->redButton->setEnabled(true);
    ui->startButton->setEnabled(false);
    ui->Status->setText("Your Turn");
    ui->progressBar->update();

}

/**
 * @brief MainWindow::setSmile, show the smile.
 */
void MainWindow::setSmile(){
    ui->smileyLabel->setText("☺");
    ui->smileyLabel->show();

}

/**
 * @brief MainWindow::gameOver, handle over the game.
 */
void MainWindow::gameOver(){
    ui->blueButton->setEnabled(false);
    ui->redButton->setEnabled(false);
    ui->startButton->setEnabled(true);

    ui->progressBar->setValue(0);
    setPoint(0);
    ui->smileyLabel->setText("☹");
    ui->smileyLabel->show();
    ui->Status->setText("You Lose!");

}

/**
 * @brief MainWindow::on_startButton_clicked, handle events after start the game.
 */
void MainWindow::on_startButton_clicked(){
    ui->blueButton->setEnabled(false);
    ui->redButton->setEnabled(false);
    ui->startButton->setEnabled(false);
    ui->smileyLabel->hide();
    ui->Status->setText("Game in progress!");
    emit startGameSignal();
}

/**
 * @brief MainWindow::on_redButton_clicked, handle events when red is clicked
 */
void MainWindow::on_redButton_clicked(){
   emit playerSignal(0);
}

/**
 * @brief MainWindow::on_blueButton_clicked, handle events when blue is clicke
 */
void MainWindow::on_blueButton_clicked(){
    emit playerSignal(1);
}

/**
 * @brief MainWindow::redDisplay, handle the color change once red is clicking
 */
void MainWindow::redDisplay(){
     ui->redButton->setStyleSheet(QString("QPushButton {background-color: rgb(255,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
}

/**
 * @brief MainWindow::redUndisplay, handle the color change once red is clicked
 */
void MainWindow::redUndisplay(){
     ui->redButton->setStyleSheet(QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
}

/**
 * @brief MainWindow::blueDisplay, handle the color change once blue is clicking
 */
void MainWindow::blueDisplay(){
    ui->blueButton->setStyleSheet(QString("QPushButton {background-color: rgb(50,50,255);} QPushButton:pressed {background-color: rgb(150,150,255);}"));
}

/**
 * @brief MainWindow::blueUndisplay, handle the color change once blue is clicked
 */
void MainWindow::blueUndisplay(){
    ui->blueButton->setStyleSheet(QString("QPushButton {background-color: rgb(50,50,200);} QPushButton:pressed {background-color: rgb(150,150,255);}"));
}

/**
 * @brief MainWindow::setProgressBar, handle the events about the progress bar
 * @param low
 * @param high
 */
void MainWindow::setProgressBar(int low, int high) {
    ui->progressBar->setRange(0, high);
    ui->progressBar->setValue(low);
}
