/**
 * CS 3505:A5
 * This class is made to connect the view and model with signals and slots for the Simon game
 *
 * @author: Robert Li and Wenlin Li
 * @version: 03/14/22 1.0 implemented the method
 * @version: 03/18/22 1.1 fixed bug and added extra feature.
 */
#include "mainwindow.h"
#include <QApplication>
#include "model.h"
#include <QList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model Model;
    MainWindow window;

    QObject::connect(&window, (void (MainWindow::*)(void))&MainWindow::startGameSignal, &Model, &Model::startGame);
    QObject::connect(&Model, (void (Model::*)(int))&Model::updatePointSignal, &window, &MainWindow::setPoint);
    QObject::connect(&Model, (void (Model::*)(int,int))&Model::setProgressBarSignal, &window, &MainWindow::setProgressBar);
    QObject::connect(&Model, (void (Model::*)(QList<int>))&Model::startComputerSignal, &window, &MainWindow::startComputer);
    QObject::connect(&Model, (void (Model::*)(void))&Model::gameOverSignal, &window, &MainWindow::gameOver);
    QObject::connect(&window, (void (MainWindow::*)(int))&MainWindow::playerSignal, &Model, &Model::playersMove);
    QObject::connect(&Model, (void (Model::*)(void))&Model::redDisplaySignal, &window, &MainWindow::redDisplay);
    QObject::connect(&Model, (void (Model::*)(void))&Model::redUndisplaySignal, &window, &MainWindow::redUndisplay);
    QObject::connect(&Model, (void (Model::*)(void))&Model::blueDisplaySignal, &window, &MainWindow::blueDisplay);
    QObject::connect(&Model, (void (Model::*)(void))&Model::blueUndisplaySignal, &window, &MainWindow::blueUndisplay);
    QObject::connect(&Model, (void (Model::*)(void))&Model::startPlayerSignal, &window, &MainWindow::startPlayer);
    QObject::connect(&Model, (void (Model::*)(void))&Model::setSmileSignal, &window, &MainWindow::setSmile);

    window.show();
    return a.exec();
}
