/**
 * CS 3505:A5
 * This class is made for model class
 *
 * @author: Robert Li and Wenlin Li
 * @version: 03/14/22 1.0 implemented the method
 * @version: 03/18/22 1.1 fixed bug and added extra feature.
 */
#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QList>
using namespace std;

class Model : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Model The following is declaring for method.
     * @param parent
     */
    explicit Model(QObject *parent = 0);
    void nextRound();
    void getCurrentPercentage();
    void getCurrentPoint();
    void computerTurn();
    void redDisplay(int timeInterval);
    void blueDisplay(int timeInterval);
    void backToPlayer(int timeInterval);

private:
    /**
     * @brief declare varaible
     */
    int score;
    int click;
    int time;
    QList<int> computerList;
    QList<int> playerList;
    int speed;

signals:
    /**
     * @brief declare the signal
     */
    void setProgressBarSignal(int, int);
    void updatePointSignal(int score);
    void startComputerSignal();
    void gameOverSignal();
    void redDisplaySignal();
    void blueDisplaySignal();
    void redUndisplaySignal();
    void blueUndisplaySignal();
    void startPlayerSignal();
    void setSmileSignal();

public slots:

    /**
     * @brief declare for slots
     */
    void startGame();
    void playersMove(int move);
};

#endif
