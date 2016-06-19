#ifndef BIRDB_H
#define BIRDB_H

#include <bird.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <birdsmall.h>

class birdB : public Bird
{
public:
    birdB(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void executeFunc();
    birdSmall *smallBird;
    birdSmall *smallBird2;
    birdSmall *smallBird3;

private:
    QTimer *outsideTimer;
    b2World *outsideWorld;
    QGraphicsScene *outsideScene;

};

#endif // BIRDB_H
