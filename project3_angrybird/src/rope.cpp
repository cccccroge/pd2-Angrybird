#include "rope.h"
#include <iostream>

Rope::Rope(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene) : GameItem(world)
{
    // Body define
    b2BodyDef ropeSectionBodyDef;
    ropeSectionBodyDef.type = b2_dynamicBody;
    ropeSectionBodyDef.linearDamping = 0;
    ropeSectionBodyDef.position.Set(x,y);
    ropeSectionBodyDef.userData = this;
    // boxShape
    b2PolygonShape bodyshape;
    bodyshape.SetAsBox(w/ROPE_SECTIONS/2,h/2);
    // fixture define
    b2FixtureDef ropeSectionFixtureDef;
    ropeSectionFixtureDef.shape = &bodyshape;
    ropeSectionFixtureDef.density = 1.0f;
    ropeSectionFixtureDef.friction = 0.1f;
    ropeSectionFixtureDef.restitution = 0.1f;
    // Create Bodies with fixture
    int32 i = 0;
    for (i = 0 ; i < ROPE_SECTIONS ; i = i + 1){
        ropeBody[i] = world->CreateBody(&ropeSectionBodyDef);
        //ropeBody[i]->SetTransform(b2Vec2((w/ROPE_SECTIONS)*i,0) , 0);
        ropeBody[i]->SetAngularDamping(3);
        ropeBody[i]->CreateFixture(&ropeSectionFixtureDef);
    }
    // Set pixmap
    g_size = QSize(w/ROPE_SECTIONS, h);
    for (i = 0 ; i < ROPE_SECTIONS ; i = i + 1){
        ropePixmap[i].setPixmap(pixmap);
        ropePixmap[i].setTransformOriginPoint(ropePixmap[i].boundingRect().width()/2,ropePixmap[i].boundingRect().height()/2);
        scene->addItem(&ropePixmap[i]);
    }

    connect(timer, SIGNAL(timeout()), this,SLOT(paintMany()));

}

void Rope::paintMany()
{
    int32 i = 0;
    for (i = 0 ; i < ROPE_SECTIONS ; i = i +1){
        b2Vec2 pos = ropeBody[i]->GetPosition();
        //std::cout << g_body->GetAngle() << std::endl;
        QPointF mappedPoint;
        mappedPoint.setX((pos.x-g_size.width()/2) * g_windowsize.width()/g_worldsize.width());
        mappedPoint.setY((1.0f - (pos.y+g_size.height()/2)/g_worldsize.height()) * g_windowsize.height());
        ropePixmap[i].setPos(mappedPoint);
        //ropePixmap[i].resetTransform();
        ropePixmap[i].setRotation(-(ropeBody[i]->GetAngle()*180/3.14159));
    }
}
