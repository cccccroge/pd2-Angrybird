#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <QKeyEvent>
#include <iostream>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include <gameitem.h>
#include <mycontactchecker.h>
#include <QGraphicsPixmapItem>
#include <birdmanager.h>
#include <scenemanager.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
    void buildStartButton();
    void buildGameUi();
    void buildEndButton();
    void handleContact();

signals:
    // Signal for closing the game
    void quitGame();
public slots:
    void updateScorePonit();
    void updateBirdLeft();
    void onStartButton();
    void onRestartButton();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QTimer timer;

    b2Joint *birdJoint;

    int checkRelease;
    int mousePress;
    int startPress;
    int spacePress;
    int spacePress2;
    int scorePoint;
    int birdLeft;
    int pigLeft;
    bool loadable;

    myContactChecker* myContactListener;
    sceneManager* mySceneManager;
    birdManager* myBirdManager;

    QPushButton *startButton;
    QPushButton *quitButton;
    QLabel *scoreBoardPoints;
    QLabel *birdLeftNumbers;
    QGraphicsPixmapItem *themePixmapItem;

    QList<QObject*> otherSceneObjectList;

};

#endif // MAINWINDOW_H
