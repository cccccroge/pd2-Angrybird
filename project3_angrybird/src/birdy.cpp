#include "birdy.h"

birdY::birdY(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{
    birdType = 'y';
}

void birdY::executeFunc()
{
    // yellowBird : speed Up
    b2Vec2 presentSpeed = this->getBody()->GetLinearVelocity();
    b2Vec2 acceleratedSpeed;
    acceleratedSpeed.x = (presentSpeed.x)*1.2f + 3.0f;
    acceleratedSpeed.y = presentSpeed.y + 2.5f;
    this->getBody()->SetLinearVelocity(acceleratedSpeed);
}

