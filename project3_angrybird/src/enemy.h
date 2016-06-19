#ifndef ENEMY_H
#define ENEMY_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define PIG_DENSITY 5.0f
#define PIG_FRICTION 0.7f
#define PIG_RESTITUTION 0.3f

class enemy : public GameItem
{
public:
    enemy(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // ENEMY_H
