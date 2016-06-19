#ifndef BIRDBIG_H
#define BIRDBIG_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRDBIG_DENSITY 50.0f
#define BIRDBIG_FRICTION 0.5f
#define BIRDBIG_RESTITUTION 0.4f

class birdBig : public GameItem
{
public:
    birdBig(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // BIRDBIG_H
