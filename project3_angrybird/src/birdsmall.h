#ifndef BIRDSMALL_H
#define BIRDSMALL_H


#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRDSMALL_DENSITY 100.0f
#define BIRDSMALL_FRICTION 0.5f
#define BIRDSMALL_RESTITUTION 0.4f

class birdSmall : public GameItem
{
public:
    birdSmall(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // BIRDSMALL_H
