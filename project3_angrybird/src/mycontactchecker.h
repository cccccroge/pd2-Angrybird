#ifndef MYCONTACTCHECKER_H
#define MYCONTACTCHECKER_H

#include <Box2D/Box2D.h>
#include <gameitem.h>

class myContactChecker : public b2ContactListener
{
public:
    myContactChecker();
    /*void BeginContact(b2Contact *contact);*/
    void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse);

//private:
    b2Body *bodyA;
    b2Body *bodyB;
    b2Body *bodyInfo_1;
    b2Body *bodyInfo_2;
    float impInfo;
    int contactType = -1;
};

#endif // MYCONTACTCHECKER_H
