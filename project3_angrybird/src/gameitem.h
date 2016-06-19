#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <Box2D/Box2D.h>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QTransform>
#include <QtMath>

class GameItem : public QObject
{
    Q_OBJECT
public:
    GameItem(b2World *world);
    ~GameItem();
    static void setGlobalSize(QSizeF worldsize, QSizeF windowsize);
    b2Body* getBody();
    float getHealth();
    void setHealth(float health);
    char getType();
    char getBirdType();
    void setBirdType(char t);
    //QGraphicsPixmapItem getPixmapItem();

    QGraphicsPixmapItem g_pixmap;
    QSizeF g_size;

public slots:
    void paint();


protected:
    b2Body *g_body;
    float g_health;
    char g_type;
    char birdType;
    b2World *g_world;
    static QSizeF g_worldsize, g_windowsize;
};

#endif // GAMEITEM_H
