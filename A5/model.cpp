/**
 * CS 3505:A5
 * This class is made to implement the Simon game
 *
 * @author: Robert Li and Wenlin Li
 * @version: 03/14/22 1.0 implemented the method
 * @version: 03/18/22 1.1 fixed bug and added extra feature.
 * */
#include "model.h"
#include <QTimer>
#include <iostream>

/**
 * @brief Model::Model , the constructor for model.
 * @param parent
 */
Model::Model(QObject *parent)
    : QObject{parent}
{
    time = 900;
    click = 0;
    score = 0;
    speed = 200;
    computerList.clear();
    playerList.clear();
}

/**
 * @brief Model::nextRound, random pick what color we are using for next round.
 */
void Model::nextRound(){
    bool random = rand() % 2;
    click = -1;
    time *= 0.8;
    if(time < 150)
        time = 150;
    speed *=0.8;
    if(random == true){
        computerList.append(0);
    }
    else{
        computerList.append(1);
    }
}

/**
 * @brief Model::playersMove, the method handle player's move.
 * @param move
 */
void Model::playersMove(int move){
    playerList.append(move);
    click++;

    //gamelost
        if(playerList[click] == computerList[click])
        {
            emit setProgressBarSignal(click + 1, computerList.size());
        }else{
            score = 0;
            computerList.clear();
            playerList.clear();
            emit gameOverSignal();
            return;
        }

// gain points and continue
    if(click + 1 == computerList.size()){
        score++;
        getCurrentPoint();
        emit setProgressBarSignal(1, 1);
        playerList.clear();
        nextRound();
        emit setSmileSignal();
        QTimer::singleShot(1000, this, &Model::startComputerSignal);
        QTimer::singleShot(1000, this, &Model::computerTurn);
    }
}

/**
 * @brief Model::cTurn, the method handle computer's moves.
 */
void Model::computerTurn(){
    emit setProgressBarSignal(0, 1);
    int i = 0;
    int timeInterval;
    while(i < computerList.size()){
        timeInterval = time * i + speed * i;
        if(computerList[i] == 0){
            redDisplay(timeInterval);
        }
        else if(computerList[i] == 1){
            blueDisplay(timeInterval);
        }
        i++;
    }
    timeInterval = computerList.size() * time + speed * computerList.size();
    backToPlayer(timeInterval);

}

/**
 * @brief Model::redDisplay helper for red display.
 * @param timeInterval
 */
void Model::redDisplay(int timeInterval){
    QTimer::singleShot(timeInterval, this, &Model::redDisplaySignal);
    QTimer::singleShot(timeInterval + time, this, &Model::redUndisplaySignal);
}

/**
 * @brief Model::blueDisplay, The helper for blue display.
 * @param timeInterval
 */
void Model::blueDisplay(int timeInterval){
    QTimer::singleShot(timeInterval, this, &Model::blueDisplaySignal);
    QTimer::singleShot(timeInterval + time, this, &Model::blueUndisplaySignal);
}

/**
 * @brief Model::backToPlayer, the helper to handle the player turn.
 * @param timeInterval
 */
void Model::backToPlayer(int timeInterval){
    QTimer::singleShot(timeInterval, this, &Model::startPlayerSignal);

}

/**
 * @brief Model::startGame, handle starting game.
 */
void Model::startGame(){
    time = 900;
    click = -1;
    speed= 200;
    score = 0;
    computerList.clear();
    playerList.clear();
    nextRound();
    computerTurn();
}

/**
 * @brief Model::getCurrentPoint, recursively updatew the score.
 */
void Model::getCurrentPoint(){

    emit updatePointSignal(this->score);
}
