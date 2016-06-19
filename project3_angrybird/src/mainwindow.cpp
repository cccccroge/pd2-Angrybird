#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);

    // initialize value
    scorePoint = 0;
    birdLeft = 4;
    pigLeft = 3;
    checkRelease = 0;
    mousePress = 0;
    startPress = 0;
    spacePress = 0;
    spacePress2 = 0;
    loadable = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // play music
    QMediaPlayer *player = new QMediaPlayer();
    player->setMedia(QUrl("qrc:/sound/Fight.mp3"));
    player->setVolume(60);
    player->play();

    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,960,540);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff );
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Create self listener and set to the world
    myContactListener = new myContactChecker();
    world->SetContactListener(myContactListener);
    // Setting Size
    GameItem::setGlobalSize(QSizeF(64,36), QSizeF(960,540));

    // Create manager
    mySceneManager = new sceneManager(&timer,world,scene);
    myBirdManager = new birdManager(&timer,world,scene);

    // Game process
    // set up start page
    mySceneManager->buildStartScene();
    this->buildStartButton();
    // wait user to click play button
    // go see 'onStartButton'(1st)

    //mySceneManager->buildLossScene();
    //this->buildEndButton();

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);

}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    //char presentBirdType = myBirdManager->presentBird->getBirdType();

    if(event->type() == QEvent::MouseButtonPress && startPress == 1)
    {
        char presentBirdType = myBirdManager->presentBird->getBirdType();
        if (mousePress == 0  && presentBirdType == 'r'){
            // active the bird
            myBirdManager->bird_1->getBody()->SetActive(true);
            // ignore gravity
            myBirdManager->bird_1->getBody()->SetGravityScale(0);
            mousePress = 1;
            checkRelease = 0;
        }
        if (mousePress == 0  && presentBirdType == 'b'){
            myBirdManager->bird_2->getBody()->SetActive(true);
            myBirdManager->bird_2->getBody()->SetGravityScale(0);
            mousePress = 1;
            checkRelease = 0;
        }
        if (mousePress == 0  && presentBirdType == 'k'){
            myBirdManager->bird_3->getBody()->SetActive(true);
            myBirdManager->bird_3->getBody()->SetGravityScale(0);
            mousePress = 1;
            checkRelease = 0;
        }
        if (mousePress == 0  && presentBirdType == 'y'){
            myBirdManager->bird_4->getBody()->SetActive(true);
            myBirdManager->bird_4->getBody()->SetGravityScale(0);
            mousePress = 1;
            checkRelease = 0;
        }
    }
    if(event->type() == QEvent::MouseMove && startPress == 1)
    {
        char presentBirdType = myBirdManager->presentBird->getBirdType();
        // Move bird according to bird position
        if (mousePress == 1 && presentBirdType == 'r'){
            QMouseEvent *mouse =  (QMouseEvent*)event;
            // transform global QT cordinate to local b2 cordinate
            float32 moveX = mouse->localPos().x()/15;
            float32 moveY = (mouse->localPos().y()*(-1)+540)/15;
            myBirdManager->bird_1->getBody()->SetTransform(b2Vec2(moveX,moveY),0);
        }
        if (mousePress == 1 && presentBirdType == 'b'){
            QMouseEvent *mouse =  (QMouseEvent*)event;
            float32 moveX = mouse->localPos().x()/15;
            float32 moveY = (mouse->localPos().y()*(-1)+540)/15;
            myBirdManager->bird_2->getBody()->SetTransform(b2Vec2(moveX,moveY),0);
        }
        if (mousePress == 1 && presentBirdType == 'k'){
            QMouseEvent *mouse =  (QMouseEvent*)event;
            float32 moveX = mouse->localPos().x()/15;
            float32 moveY = (mouse->localPos().y()*(-1)+540)/15;
            myBirdManager->bird_3->getBody()->SetTransform(b2Vec2(moveX,moveY),0);
        }
        if (mousePress == 1 && presentBirdType == 'y'){
            QMouseEvent *mouse =  (QMouseEvent*)event;
            float32 moveX = mouse->localPos().x()/15;
            float32 moveY = (mouse->localPos().y()*(-1)+540)/15;
            myBirdManager->bird_4->getBody()->SetTransform(b2Vec2(moveX,moveY),0);
        }
    }
    if(event->type() == QEvent::MouseButtonRelease && startPress == 1)
    {
        char presentBirdType = myBirdManager->presentBird->getBirdType();
        if (checkRelease == 0 && presentBirdType == 'r'){
            // restore the gravity
            myBirdManager->bird_1->getBody()->SetGravityScale(1);
            // get bird pos
            int32 birdPosX = myBirdManager->bird_1->getBody()->GetPosition().x;
            int32 birdPosY = myBirdManager->bird_1->getBody()->GetPosition().y;
            // volicity = k * (slingshot center-pos)
            myBirdManager->bird_1->setLinearVelocity(b2Vec2( (11.76-birdPosX)*3, (12.5-birdPosY)*3) );
            mousePress = 0;
            checkRelease = 1;
            // load next bird
            // 2nd : run bird manager process
            myBirdManager->load(myBirdManager->bird_2);
            birdLeft -= 1;


        }
        if (checkRelease == 0 && presentBirdType == 'b'){
            myBirdManager->bird_2->getBody()->SetGravityScale(1);
            int32 birdPosX = myBirdManager->bird_2->getBody()->GetPosition().x;
            int32 birdPosY = myBirdManager->bird_2->getBody()->GetPosition().y;
            myBirdManager->bird_2->setLinearVelocity(b2Vec2( (11.76-birdPosX)*3, (12.5-birdPosY)*3) );
            mousePress = 0;
            checkRelease = 1;
            // load next bird
            // 3nd : run bird manager process
            myBirdManager->load(myBirdManager->bird_3);
            birdLeft -= 1;

        }
        if (checkRelease == 0 && presentBirdType == 'k'){
            myBirdManager->bird_3->getBody()->SetGravityScale(1);
            int32 birdPosX = myBirdManager->bird_3->getBody()->GetPosition().x;
            int32 birdPosY = myBirdManager->bird_3->getBody()->GetPosition().y;
            myBirdManager->bird_3->setLinearVelocity(b2Vec2( (11.76-birdPosX)*3, (12.5-birdPosY)*3) );
            mousePress = 0;
            checkRelease = 1;
            // load next bird
            // 4nd : run bird manager process
            myBirdManager->load(myBirdManager->bird_4);
            birdLeft -= 1;
        }
        if (checkRelease == 0 && presentBirdType == 'y'){
            myBirdManager->bird_4->getBody()->SetGravityScale(1);
            int32 birdPosX = myBirdManager->bird_4->getBody()->GetPosition().x;
            int32 birdPosY = myBirdManager->bird_4->getBody()->GetPosition().y;
            myBirdManager->bird_4->setLinearVelocity(b2Vec2( (11.76-birdPosX)*3, (12.5-birdPosY)*3) );
            mousePress = 0;
            checkRelease = 1;
            // to execute last bird function sucessfully
            // set the bird type to virtual type 'v'
            myBirdManager->presentBird->setBirdType('v');
            birdLeft -= 1;
            if(pigLeft > 0){
                mySceneManager->buildLossScene();
                this->buildEndButton();
            }
        }
    }
    if(event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if(keyEvent->key() == Qt::Key_Space) {

            char presentBirdType = myBirdManager->presentBird->getBirdType();
            if(presentBirdType == 'r'){
                // execute bird functionality depend on present bird type
                myBirdManager->bird_1->executeFunc();
            }
            if(presentBirdType == 'b'){
                myBirdManager->bird_1->executeFunc();
            }
            if(presentBirdType == 'k' && spacePress == 0){
                myBirdManager->bird_2->executeFunc();
                spacePress = 1;
            }
            if(presentBirdType == 'y' && spacePress2 == 0){
                myBirdManager->bird_3->executeFunc();
                spacePress2 = 1;
            }
            if(presentBirdType == 'v'){
                myBirdManager->bird_4->executeFunc();
            }

        }
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::buildStartButton()
{
    // Create theme pic
    themePixmapItem = new QGraphicsPixmapItem();
    themePixmapItem->setPixmap(QPixmap(":/image/theme.png"));
    themePixmapItem->setPos(210,50);
    scene->addItem(themePixmapItem);

    // Create start button
    startButton = new QPushButton();
    startButton->setText("PLAY");
    startButton->setFlat(true);
    startButton->setAutoFillBackground(true);
    startButton->setGeometry(QRect(430, 320, 100, 35));
    scene->addWidget(startButton);
    otherSceneObjectList.push_back(startButton);

    // Create quit button
    quitButton = new QPushButton();
    quitButton->setText("QUIT");
    quitButton->setFlat(true);
    quitButton->setAutoFillBackground(true);
    quitButton->setGeometry(QRect(430, 375, 100, 35));
    scene->addWidget(quitButton);
    otherSceneObjectList.push_back(quitButton);

    // connect startButton
    // delete button and call buildGameScene
    connect(startButton, SIGNAL(clicked()), this,SLOT(onStartButton()));

    // connect quitButton
    // cout something
    connect(quitButton, SIGNAL(clicked()), this,SLOT(QUITSLOT()));
}

void MainWindow::buildGameUi()
{
    // Create score board
    QLabel *scoreBoard = new QLabel();
    //scoreBoard->setAttribute(Qt::WA_TranslucentBackground);
    scoreBoard->setAlignment(Qt::AlignCenter);
    scoreBoard->setText("<font color='white'>SCORE</font>");
    QFont *font = new QFont();
    font->setPointSizeF(18);
    font->setBold(true);
    font->setFamily(QString("Adobe Devanagari"));
    scoreBoard->setFont(*font);
    scoreBoard->setGeometry(QRect(20,20,120,30));
    scene->addWidget(scoreBoard);
    otherSceneObjectList.push_back(scoreBoard);

    // score points
    scoreBoardPoints = new QLabel();
    scoreBoard->setAttribute(Qt::WA_TranslucentBackground);
    scoreBoardPoints->setNum(this->scorePoint);
    scoreBoardPoints->setFont(*font);
    scoreBoardPoints->setGeometry(QRect(200,20,90,30));
    scene->addWidget(scoreBoardPoints);
    otherSceneObjectList.push_back(scoreBoardPoints);
    // add timer to update
    connect(&timer, SIGNAL(timeout()), this,SLOT(updateScorePonit()));

    // Create birdleft board
    QLabel *birdLeftBoard = new QLabel();
    birdLeftBoard->setAttribute(Qt::WA_TranslucentBackground);
    birdLeftBoard->setAlignment(Qt::AlignCenter);
    birdLeftBoard->setText("<font color='white'>BIRD LEFT</font>");
    birdLeftBoard->setFont(*font);
    birdLeftBoard->setGeometry(QRect(20,50,150,30));
    scene->addWidget(birdLeftBoard);
    otherSceneObjectList.push_back(birdLeftBoard);

    // bird left num
    birdLeftNumbers = new QLabel();
    //scoreBoard->setAttribute(Qt::WA_TranslucentBackground);
    birdLeftNumbers->setNum(this->scorePoint);
    birdLeftNumbers->setFont(*font);
    birdLeftNumbers->setGeometry(QRect(200,50,90,30));
    scene->addWidget(birdLeftNumbers);
    otherSceneObjectList.push_back(birdLeftNumbers);
    // add timer to update
    connect(&timer, SIGNAL(timeout()), this,SLOT(updateBirdLeft()));
}

void MainWindow::buildEndButton()
{
    // Create restart button
    startButton = new QPushButton();
    startButton->setText("RESTART");
    startButton->setFlat(true);
    startButton->setAutoFillBackground(true);
    startButton->setGeometry(QRect(430, 335, 100, 35));
    scene->addWidget(startButton);
    otherSceneObjectList.push_back(startButton);

    // Create quit button
    quitButton = new QPushButton();
    quitButton->setText("QUIT");
    quitButton->setFlat(true);
    quitButton->setAutoFillBackground(true);
    quitButton->setGeometry(QRect(430, 390, 100, 35));
    scene->addWidget(quitButton);
    otherSceneObjectList.push_back(quitButton);

    // connect restartButton
    // delete button and call buildGameScene
    connect(startButton, SIGNAL(clicked()), this,SLOT(onRestartButton()));

    // connect quitButton
    // cout something
    connect(quitButton, SIGNAL(clicked()), this,SLOT(QUITSLOT()));
}

void MainWindow::handleContact()
{
    // One hurt

    if(myContactListener->contactType == 0){
        // set health
        GameItem* item = (GameItem*)myContactListener->bodyInfo_1->GetUserData();
        float healthLeft = (item->getHealth()) - (myContactListener->impInfo);
        item->setHealth(healthLeft);
        // add score
        scorePoint += (myContactListener->impInfo)*3;
        // change image and delete if no health
        if(item->getType() == 'o'){   // for obstacle(boxes)

            if(healthLeft >=300 && healthLeft < 600){
                QPixmap *Pixmap_box2 = new QPixmap(QPixmap(":/image/box_2.png").scaled(45,45));
                item->g_pixmap.setPixmap(*Pixmap_box2);
                if(item->g_size == QSize(11,1)){
                    QPixmap *Pixmap_bar2 = new QPixmap(QPixmap(":/image/bar_2.png").scaled(165,15));
                    item->g_pixmap.setPixmap(*Pixmap_bar2);
                }
            }
            if(healthLeft >=0 && healthLeft < 300){
                QPixmap *Pixmap_box3 = new QPixmap(QPixmap(":/image/box_3.png").scaled(45,45));
                item->g_pixmap.setPixmap(*Pixmap_box3);
                if(item->g_size == QSize(11,1)){
                    QPixmap *Pixmap_bar3 = new QPixmap(QPixmap(":/image/bar_3.png").scaled(165,15));
                    item->g_pixmap.setPixmap(*Pixmap_bar3);
                }
            }
            if(healthLeft < 0){
                scene->removeItem(&(item->g_pixmap));
                item->getBody()->DestroyFixture(item->getBody()->GetFixtureList());
            }
        }
        if(item->getType() == 'e'){   //for enemy(pigs)

            if(healthLeft >=300 && healthLeft < 600){
                QPixmap *Pixmap_pig2 = new QPixmap(QPixmap(":/image/pig_2.png").scaled(45,45));
                item->g_pixmap.setPixmap(*Pixmap_pig2);
            }
            if(healthLeft >=0 && healthLeft < 300){
                QPixmap *Pixmap_pig3 = new QPixmap(QPixmap(":/image/pig_3.png").scaled(45,45));
                item->g_pixmap.setPixmap(*Pixmap_pig3);
            }
            if(healthLeft < 0){
                scene->removeItem(&(item->g_pixmap));
                item->getBody()->DestroyFixture(item->getBody()->GetFixtureList());
                pigLeft -= 1;
                if(pigLeft == 0){
                    mySceneManager->buildWinScene();
                    this->buildEndButton();
                }
            }
        }
    }


    // Two hurt

    if(myContactListener->contactType == 1){
        // set health
        GameItem* item1 = (GameItem*)myContactListener->bodyInfo_1->GetUserData();
        GameItem* item2 = (GameItem*)myContactListener->bodyInfo_2->GetUserData();
        float healthLeft1 = (item1->getHealth()) - (myContactListener->impInfo);
        item1->setHealth(healthLeft1);
        float healthLeft2 = (item2->getHealth()) - (myContactListener->impInfo);
        item2->setHealth(healthLeft2);
        // add score
        scorePoint += (myContactListener->impInfo)*6;
        // change image and delete if no health
        if(item1->getType() == 'o' && item2->getType() == 'e'){

            if(healthLeft1 >=300 && healthLeft1 < 600){
                QPixmap *Pixmap_box2 = new QPixmap(QPixmap(":/image/box_2.png").scaled(45,45));
                item1->g_pixmap.setPixmap(*Pixmap_box2);
                if(item1->g_size == QSize(11,1)){
                    QPixmap *Pixmap_bar2 = new QPixmap(QPixmap(":/image/bar_2.png").scaled(165,15));
                    item1->g_pixmap.setPixmap(*Pixmap_bar2);
                }
            }
            if(healthLeft1 >=0 && healthLeft1 < 300){
                QPixmap *Pixmap_box3 = new QPixmap(QPixmap(":/image/box_3.png").scaled(45,45));
                item1->g_pixmap.setPixmap(*Pixmap_box3);
                if(item1->g_size == QSize(11,1)){
                    QPixmap *Pixmap_bar3 = new QPixmap(QPixmap(":/image/bar_3.png").scaled(165,15));
                    item1->g_pixmap.setPixmap(*Pixmap_bar3);
                }
            }
            if(healthLeft1 < 0){
                scene->removeItem(&(item1->g_pixmap));
                item1->getBody()->DestroyFixture(item1->getBody()->GetFixtureList());
            }
            if(healthLeft2 >=300 && healthLeft2 < 600){
                QPixmap *Pixmap_pig2 = new QPixmap(QPixmap(":/image/pig_2.png").scaled(45,45));
                item2->g_pixmap.setPixmap(*Pixmap_pig2);
            }
            if(healthLeft2 >=0 && healthLeft2 < 300){
                QPixmap *Pixmap_pig3 = new QPixmap(QPixmap(":/image/pig_3.png").scaled(45,45));
                item2->g_pixmap.setPixmap(*Pixmap_pig3);
            }
            if(healthLeft2 < 0){
                scene->removeItem(&(item2->g_pixmap));
                item2->getBody()->DestroyFixture(item2->getBody()->GetFixtureList());
                pigLeft -= 1;
                if(pigLeft == 0){
                    mySceneManager->buildWinScene();
                    this->buildEndButton();
                }
            }
        }

        if(item2->getType() == 'o' && item1->getType() == 'e'){

            if(healthLeft2 >=300 && healthLeft2 < 600){
                QPixmap *Pixmap_box2 = new QPixmap(QPixmap(":/image/box_2.png").scaled(45,45));
                item2->g_pixmap.setPixmap(*Pixmap_box2);
                if(item2->g_size == QSize(11,1)){
                    QPixmap *Pixmap_bar2 = new QPixmap(QPixmap(":/image/bar_2.png").scaled(165,15));
                    item2->g_pixmap.setPixmap(*Pixmap_bar2);
                }
            }
            if(healthLeft2 >=0 && healthLeft2 < 300){
                QPixmap *Pixmap_box3 = new QPixmap(QPixmap(":/image/box_3.png").scaled(45,45));
                item2->g_pixmap.setPixmap(*Pixmap_box3);
                if(item2->g_size == QSize(11,1)){
                    QPixmap *Pixmap_bar3 = new QPixmap(QPixmap(":/image/bar_3.png").scaled(165,15));
                    item2->g_pixmap.setPixmap(*Pixmap_bar3);
                }
            }
            if(healthLeft2 < 0){
                scene->removeItem(&(item2->g_pixmap));
                item2->getBody()->DestroyFixture(item2->getBody()->GetFixtureList());
            }
            if(healthLeft1 >=300 && healthLeft1 < 600){
                QPixmap *Pixmap_pig2 = new QPixmap(QPixmap(":/image/pig_2.png").scaled(45,45));
                item1->g_pixmap.setPixmap(*Pixmap_pig2);
            }
            if(healthLeft1 >=0 && healthLeft1 < 300){
                QPixmap *Pixmap_pig3 = new QPixmap(QPixmap(":/image/pig_3.png").scaled(45,45));
                item1->g_pixmap.setPixmap(*Pixmap_pig3);
            }
            if(healthLeft1 < 0){
                scene->removeItem(&(item1->g_pixmap));
                item1->getBody()->DestroyFixture(item1->getBody()->GetFixtureList());
                pigLeft -= 1;
                if(pigLeft == 0){
                    mySceneManager->buildWinScene();
                    this->buildEndButton();
                }
            }
        }
    }

}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
    handleContact();
}

void MainWindow::QUITSLOT()
{
    std::cout << "Quit Game Signal receive !" << std::endl ;
    this->close();
}

void MainWindow::updateScorePonit()
{
    scoreBoardPoints->setNum(this->scorePoint);
}

void MainWindow::updateBirdLeft()
{
    birdLeftNumbers->setNum(this->birdLeft);
}

void MainWindow::onStartButton()
{
    // destroy buttons
    startButton->deleteLater();
    quitButton->deleteLater();
    // remove theme pic
    scene->removeItem(themePixmapItem);
    // setup ui and build level
    this->buildGameUi();
    mySceneManager->buildGameLevel();
    // run bird manager process
    myBirdManager->createBirds();
    myBirdManager->load(myBirdManager->bird_1);
    // tell filter the mousePress is not a startButton clicked
    startPress = 1;
}

void MainWindow::onRestartButton()
{
    // destroy buttons
    startButton->deleteLater();
    quitButton->deleteLater();

    // destroy win/loss object
    // clear level
    for(int i=0 ; i < mySceneManager->sceneObjectList.size() ; i++){
        mySceneManager->sceneObjectList[i]->deleteLater();
    }
    mySceneManager->sceneObjectList.clear();

    // clear bird


    // reset value
    scorePoint = 0;
    birdLeft = 4;
    pigLeft = 3;
    checkRelease = 0;
    mousePress = 0;
    startPress = 0;

    // setup again
    mySceneManager->buildGameLevel();
    // run bird manager process
    myBirdManager->createBirds();
    myBirdManager->load(myBirdManager->bird_1);
    // tell filter the mousePress is not a startButton clicked
    startPress = 1;
}
