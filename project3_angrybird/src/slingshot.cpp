#include "slingshot.h"

slingShot::slingShot(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene) : GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_size = QSize(w,h);

    // Set health and type
    g_health = -1.0f;
    g_type = 'n';
    birdType = 'n';

    // Create body
    b2BodyDef bodyDef;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    bodyDef.active = false;
    g_body = world->CreateBody(&bodyDef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w/2,h/2);
    g_body->CreateFixture(&bodyBox,9.0f);

    scene->addItem(&g_pixmap);
    paint();
}



