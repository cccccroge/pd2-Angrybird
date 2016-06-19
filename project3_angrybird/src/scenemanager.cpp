#include "scenemanager.h"

sceneManager::sceneManager(QTimer *timer, b2World *world, QGraphicsScene *scene)
{
    // get information from mainwindow
    theTimer = timer;
    theWorld = world;
    theScene = scene;
}

void sceneManager::buildStartScene()
{
    // Create ground
    new Land(32, 3, 64, 6, QPixmap(":/image/ground_gray.png").scaled(960,90), theWorld, theScene);
    // Create border
    new Land(65, 32, 2, 200, QPixmap(":/image/ground_gray.png").scaled(30,960), theWorld, theScene);
    new Land(-1, 32, 2, 200, QPixmap(":/image/ground_gray.png").scaled(30,960), theWorld, theScene);
    // Create background
    new background(32, 21, 64, 30, QPixmap(":/image/background.png").scaled(960,450), theWorld, theScene);
    // Create sling shot
    new slingShot(12, 9.75f, 3, 7.5f, QPixmap(":/image/sling_shot.png").scaled(45,112.5f), theWorld, theScene);

}


void sceneManager::buildGameLevel()
{
    // Create boxes
    sceneObjectList.push_back(new box(42, 10, 3, 3, theTimer, QPixmap(":/image/box.png").scaled(45,45), theWorld, theScene));
    sceneObjectList.push_back(new box(46, 13,11, 1, theTimer, QPixmap(":/image/bar.png").scaled(165,15), theWorld, theScene));
    sceneObjectList.push_back(new box(50, 10, 3, 3, theTimer, QPixmap(":/image/box.png").scaled(45,45), theWorld, theScene));
    sceneObjectList.push_back(new box(42, 14, 3, 3, theTimer, QPixmap(":/image/box.png").scaled(45,45), theWorld, theScene));
    sceneObjectList.push_back(new box(46, 17,11, 1, theTimer, QPixmap(":/image/bar.png").scaled(165,15), theWorld, theScene));
    sceneObjectList.push_back(new box(50, 14, 3, 3, theTimer, QPixmap(":/image/box.png").scaled(45,45), theWorld, theScene));
    sceneObjectList.push_back(new box(46, 18, 3, 3, theTimer, QPixmap(":/image/box.png").scaled(45,45), theWorld, theScene));
    // Create enemies
    sceneObjectList.push_back(new enemy(46, 10, 1.5f, theTimer, QPixmap(":/image/pig_1.png").scaled(45,45), theWorld, theScene));
    sceneObjectList.push_back(new enemy(46, 14, 1.5f, theTimer, QPixmap(":/image/pig_1.png").scaled(45,45), theWorld, theScene));
    sceneObjectList.push_back(new enemy(46, 21, 1.5f, theTimer, QPixmap(":/image/pig_1.png").scaled(45,45), theWorld, theScene));

}

void sceneManager::buildWinScene()
{
    sceneObjectList.push_back(new background(32, 23, 20, 20, QPixmap(":/image/win.png").scaled(300,300), theWorld, theScene));
}

void sceneManager::buildLossScene()
{
    sceneObjectList.push_back(new background(32, 23, 20, 20, QPixmap(":/image/loss.png").scaled(300,300), theWorld, theScene));
}

void sceneManager::clearAll()
{

}



