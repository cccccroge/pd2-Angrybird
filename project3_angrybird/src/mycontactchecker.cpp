#include "mycontactchecker.h"
#include <iostream>



myContactChecker::myContactChecker()
{

}

/*void myContactChecker::BeginContact(b2Contact *contact)
{
    bodyA = contact->GetFixtureA()->GetBody();
    bodyB = contact->GetFixtureA()->GetBody();
    GameItem* itemA = (GameItem*)bodyA->GetUserData();
    char typeA = itemA->getType();
    GameItem* itemB = (GameItem*)bodyB->GetUserData();
    char typeB = itemB->getType();

    // neglect the contact between bird and ropeSec/ropePoint
    if(typeA == 'b' && typeB == 's'){
        contact->SetEnabled(false);
    }
    if(typeA == 's' && typeB == 'b'){
        contact->SetEnabled(false);
    }
    if(typeA == 'b' && typeB == 'p'){
        contact->SetEnabled(false);
    }
    if(typeA == 'p' && typeB == 'b'){
        contact->SetEnabled(false);
    }

}*/


void myContactChecker::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse)
{
    bodyA = contact->GetFixtureA()->GetBody();
    bodyB = contact->GetFixtureB()->GetBody();
    GameItem* itemA = (GameItem*)bodyA->GetUserData();
    float healthA = itemA->getHealth();
    GameItem* itemB = (GameItem*)bodyB->GetUserData();
    float healthB = itemB->getHealth();
    //char typeA = itemA->getType();
    //char typeB = itemB->getType();

    contactType = -1;

    impInfo = impulse->normalImpulses[0];
    if(impInfo < 100){
        // contactType = -1;
    }

    if(healthA > 0 && healthB < 0){
        bodyInfo_1 = bodyA;
        bodyInfo_2 = bodyB;
        contactType = 0;    //represent : one got hurt
    }

    if(healthB > 0 && healthA < 0){
        bodyInfo_1 = bodyB;
        bodyInfo_2 = bodyA;
        contactType = 0;    //represent : one got hurt
    }

    if(healthA > 0 && healthB > 0){
        bodyInfo_1 = bodyA;
        bodyInfo_2 = bodyB;
        contactType = 1;    //represent : both got hurt
    }
    /*if(typeA == 'b'){
        itemA->deleteLater();
    }
    if(typeB == 'b'){
        itemB->deleteLater();
    }*/

}
