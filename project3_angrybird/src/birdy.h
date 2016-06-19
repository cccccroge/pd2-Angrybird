#ifndef BIRDY_H
#define BIRDY_H

#include <bird.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

class birdY : public Bird
{
public:
    birdY(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void executeFunc();
};

#endif // BIRDY_H
