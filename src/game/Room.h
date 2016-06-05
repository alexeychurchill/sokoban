#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include "GameObject.h"
#include "Player.h"
#include "Wall.h"
#include "Box.h"
#include "Target.h"
#include "Floor.h"
#include "ObjectView.h"
class Room {
public:
    Room(const std::vector<GameObject*>& levelMap, const Point& playerPosition);
    ~Room();
    void movePlayerLeft();
    void movePlayerRight();
    void movePlayerUp();
    void movePlayerDown();
    bool isFinished();
    void getView(std::vector<ObjectView>& view);
    int getWidth() const;
    int getHeight() const;
private:
    void movePlayer(Direction direction);
    void getObjectsAt(const Point& point, std::vector<GameObject*>& objects);
    GameObject* getObjectByTypeAt(ObjectType objectType, const Point& point);
    bool hasObjectByTypeAt(ObjectType objectType, const Point& point);
    void getTypeView(ObjectType objectType, std::vector<ObjectView>& view);
    std::vector<GameObject*> objects;
    Player player;
    int width;
    int height;
};
#endif // ROOM_H
