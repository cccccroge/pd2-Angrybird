#ifndef BOX_H
#define BOX_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BOX_DENSITY 6.0f
#define BOX_FRICTION 0.7f
#define BOX_RESTITUTION 0.1f

class box : public GameItem
{
public:
    box(float x, float y, float w,float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void setLinearVelocity(b2Vec2 velocity);


};

#endif // BOX_H
