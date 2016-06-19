#ifndef ROPESECTION_H
#define ROPESECTION_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define ROPE_DENSITY 6.0f
#define ROPE_FRICTION 0.7f
#define ROPE_RESTITUTION 0.1f

class ropeSection : public GameItem
{
public:
    ropeSection(float x, float y, float w,float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // ROPESECTION_H
