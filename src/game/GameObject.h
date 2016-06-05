#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "ObjectType.h"
#include "Point.h"
class GameObject {
public:
    GameObject();
    virtual ~GameObject();
    ObjectType getType();
    Point getPosition();
    void setPosition(const Point& point);
protected:
    void setType(ObjectType type);
private:
    ObjectType type;
    Point position;
};
#endif // GAMEOBJECT_H
