#include "birdmanager.h"


birdManager::birdManager(QTimer *timer, b2World *world, QGraphicsScene *scene)
{
    // Initialize
    birdType = 0;
    birdListCount = 0;

    // Get the information from outside
    theTimer = timer;
    theWorld = world;
    theScene = scene;

}


void birdManager::load(Bird *bird)
{
    // Move to slingshot spot and set active
    b2Body *birdBody = bird->getBody();
    birdBody->SetTransform(b2Vec2(11.76, 12.5), 0);
    // Set present bird to this bird
    presentBird = bird;
    // Tell the event filter that what type is the present loaded bird
    // so it can choose the correct func which the bird could execute
    birdType = bird->getType();
}

void birdManager::destroy(Bird *bird)
{
    // Delete present bird (rope will be deleted right after mouse release)
    bird->deleteLater();
}

void birdManager::createBirds()
{
    // Create 4 birds that later will be used
    bird_1 = new Bird(0, 6, 1, theTimer, QPixmap(":/image/bird_red.png").scaled(30,30), theWorld, theScene);
    bird_2 = new birdB(0, 7, 1, theTimer, QPixmap(":/image/bird_blue.png").scaled(30,30), theWorld, theScene);
    bird_3 = new birdK(0, 8, 1, theTimer, QPixmap(":/image/bird_black2.png").scaled(30,30), theWorld, theScene);
    bird_4 = new birdY(0, 9, 1, theTimer, QPixmap(":/image/bird_yellow.png").scaled(30,30), theWorld, theScene);
    // set nonactive
    bird_1->getBody()->SetActive(false);
    bird_2->getBody()->SetActive(false);
    bird_3->getBody()->SetActive(false);
    bird_4->getBody()->SetActive(false);
    // set present bird to bird1
    presentBird = bird_1;
}

int birdManager::getBirdListCount()
{
    return birdListCount;
}

void birdManager::setBirdListCount(int c)
{
    birdListCount = c;
}

Bird *birdManager::getPresentBird()
{
    return presentBird;
}


