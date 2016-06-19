#include "birdb.h"

birdB::birdB(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{
    birdType = 'b';

    outsideTimer = timer;
    outsideWorld = world;
    outsideScene = scene;
}

void birdB::executeFunc()
{
    // blue bird : split to 3 small birds
    // new 3 small one
    b2Vec2 V = g_body->GetLinearVelocity();
    float32 Vx = V.x;
    float32 Vy = V.y;
    b2Vec2 P = g_body->GetPosition();
    float32 Px = P.x;
    float32 Py = P.y;
    smallBird = new birdSmall(Px, Py+1, 0.5f, outsideTimer, QPixmap(":/image/bird_blue.png").scaled(15,15), outsideWorld, outsideScene);
    smallBird->getBody()->SetLinearVelocity(V);
    smallBird2 = new birdSmall(Px, Py, 0.5f, outsideTimer, QPixmap(":/image/bird_blue.png").scaled(15,15), outsideWorld, outsideScene);
    smallBird2->getBody()->SetLinearVelocity(b2Vec2(Vx,Vy+5));
    smallBird3 = new birdSmall(Px, Py-1, 0.5f, outsideTimer, QPixmap(":/image/bird_blue.png").scaled(15,15), outsideWorld, outsideScene);
    smallBird3->getBody()->SetLinearVelocity(b2Vec2(Vx,Vy-5));

    // delete original
    deleteLater();

}
