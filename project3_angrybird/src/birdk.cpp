#include "birdk.h"


birdK::birdK(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{
    birdType = 'k';

    outsideTimer = timer;
    outsideWorld = world;
    outsideScene = scene;
}

void birdK::executeFunc()
{
    // blackBird : bigger one
    // new a bigger one
    b2Vec2 V = g_body->GetLinearVelocity();
    b2Vec2 P = g_body->GetPosition();
    float32 Px = P.x;
    float32 Py = P.y;
    bigBird = new birdBig(Px, Py, 2, outsideTimer, QPixmap(":/image/bird_black2.png").scaled(60,60), outsideWorld, outsideScene);
    bigBird->getBody()->SetLinearVelocity(b2Vec2(V.x*0.5,-10));


    // delete original
    deleteLater();
}
