#ifndef BIRDMANAGER_H
#define BIRDMANAGER_H

#include <bird.h>
#include <birdb.h>
#include <birdk.h>
#include <birdy.h>
#include <ropesection.h>
#include <ropepoint.h>
#include <QList>

class birdManager
{
public:
    birdManager(QTimer *timer, b2World *world, QGraphicsScene *scene);
    void load(Bird *bird);
    void destroy(Bird *bird);
    void createBirds();
    int getBirdListCount();
    void setBirdListCount(int c);
    Bird* getPresentBird();

    Bird* bird_1;
    birdB* bird_2;
    birdK* bird_3;
    birdY* bird_4;
    Bird *presentBird;

private:


    int birdListCount;
    char birdType;
    QTimer *theTimer;
    b2World *theWorld;
    QGraphicsScene *theScene;

};

#endif // BIRDMANAGER_H
