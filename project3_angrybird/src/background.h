#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <gameitem.h>
#include <QGraphicsScene>


class background : public GameItem
{
public:
    background(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // BACKGROUND_H
