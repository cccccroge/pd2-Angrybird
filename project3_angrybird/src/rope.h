#ifndef ROPE_H
#define ROPE_H

#define ROPE_SECTIONS 8

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

class Rope : public GameItem
{
public:
    Rope(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);

public slots:
    void paintMany();

private:
    b2Body *ropeBody[ROPE_SECTIONS];
    QGraphicsPixmapItem ropePixmap[ROPE_SECTIONS];
};

#endif // ROPE_H
