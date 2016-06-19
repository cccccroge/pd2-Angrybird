#ifndef BIRDK_H
#define BIRDK_H

#include <bird.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <birdbig.h>

class birdK : public Bird
{
public:
    birdK(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void executeFunc();
    birdBig *bigBird;

private:
    QTimer *outsideTimer;
    b2World *outsideWorld;
    QGraphicsScene *outsideScene;

};

#endif // BIRDK_H
