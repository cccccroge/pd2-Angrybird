#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QPushButton>
#include <QLabel>
#include <land.h>
#include <background.h>
#include <slingshot.h>
#include <box.h>
#include <enemy.h>
#include <birdmanager.h>


class sceneManager
{

public:
    sceneManager(QTimer *timer, b2World *world, QGraphicsScene *scene);
    void buildStartScene();
    void buildGameLevel();
    void buildWinScene();
    void buildLossScene();
    void clearAll(); // restart->clear and go back Game Scene
    int getScorePoint();
    void setScorePoint(int p);

    QList<QObject *> sceneObjectList;


private:
    QTimer *theTimer;
    b2World *theWorld;
    QGraphicsScene *theScene;




};

#endif // SCENEMANAGER_H
