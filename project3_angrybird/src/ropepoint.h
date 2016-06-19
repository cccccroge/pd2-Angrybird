#ifndef ROPEPOINT_H
#define ROPEPOINT_H

#include <gameitem.h>
#include <QGraphicsScene>

class ropePoint : public GameItem
{
public:
    ropePoint(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // ROPEPOINT_H
