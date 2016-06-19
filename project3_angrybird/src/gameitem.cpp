#include "gameitem.h"

#include <iostream>

GameItem::GameItem(b2World *world):
    g_body(NULL),g_world(world)
{
    //g_body->SetUserData(this);
}

GameItem::~GameItem()
{
    g_world->DestroyBody(g_body);
}

QSizeF GameItem::g_windowsize = QSizeF();
QSizeF GameItem::g_worldsize = QSizeF();

void GameItem::setGlobalSize(QSizeF worldsize, QSizeF windowsize)
{
    g_worldsize = worldsize;
    g_windowsize = windowsize;
}

b2Body* GameItem::getBody()
{
    return g_body;
}

float GameItem::getHealth()
{
    return g_health;
}

void GameItem::setHealth(float health)
{
    g_health = health;
}

char GameItem::getType()
{
    return g_type;
}

char GameItem::getBirdType()
{
    return birdType;
}

void GameItem::setBirdType(char t)
{
    birdType = t;
}

/*QGraphicsPixmapItem GameItem::getPixmapItem()
{
    return g_pixmap;
}*/

void GameItem::paint()
{
    b2Vec2 pos = g_body->GetPosition();
    //std::cout << g_body->GetAngle() << std::endl;
    QPointF mappedPoint;
    mappedPoint.setX((pos.x-g_size.width()/2) * g_windowsize.width()/g_worldsize.width());
    mappedPoint.setY((1.0f - (pos.y+g_size.height()/2)/g_worldsize.height()) * g_windowsize.height());
    g_pixmap.setPos(mappedPoint);
    g_pixmap.resetTransform();
    g_pixmap.setRotation(-(g_body->GetAngle()*180/3.14159));
}
