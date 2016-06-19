#ifndef SLINGSHOT_H
#define SLINGSHOT_H

#include <gameitem.h>
#include <QGraphicsScene>

class slingShot : public GameItem
{

public:
    slingShot(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);

};

#endif // SLINGSHOT_H
