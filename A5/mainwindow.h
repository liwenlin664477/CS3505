/**
 * CS 3505:A5
 * This class is view for model class
 *
 * @author: Robert Li and Wenlin Li
 * @version: 03/14/22 1.0 implemented the method
 * @version: 03/18/22 1.1 fixed bug and added extra feature.
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow get pointer
     * @param parent
     */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    /**
     * The following code declare the slots.
     *
     */
    void setPoint(int score);
    void startComputer();
    void startPlayer();
    void gameOver();
    void on_startButton_clicked();
    void on_redButton_clicked();
    void on_blueButton_clicked();
    void redDisplay();
    void redUndisplay();
    void blueDisplay();
    void blueUndisplay();
    void setProgressBar(int, int);
    void setSmile();

signals:

    /**
     * @brief set up the signals
     */
    void playerTurn();
    void startGameSignal();
    void playerSignal(int number);

private:
    /**
     * @brief set up the ui.
     */
    Ui::MainWindow *ui;
};
#endif
