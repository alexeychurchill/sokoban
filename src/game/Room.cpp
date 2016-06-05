#include "Room.h"

Room::Room(const std::vector<GameObject*>& levelMap, const Point& playerPosition):
    objects(levelMap)
{
    player.setPosition(playerPosition);
    //Width and height of level
    int minX = player.getPosition().getX();
    int maxX = minX;
    int minY = player.getPosition().getY();
    int maxY = minY;
    for (auto objectItr = objects.begin(); objectItr != objects.end(); objectItr++) {
        //Minimal X
        if (((*objectItr) -> getPosition()).getX() < minX) {
            minX = ((*objectItr) -> getPosition()).getX();
        }
        //Maximal X
        if (((*objectItr) -> getPosition()).getX() > maxX) {
            maxX = ((*objectItr) -> getPosition()).getX();
        }
        //Minimal Y
        if (((*objectItr) -> getPosition()).getY() < minY) {
            minY = ((*objectItr) -> getPosition()).getY();
        }
        //Maximal Y
        if (((*objectItr) -> getPosition()).getY() > maxY) {
            maxY = ((*objectItr) -> getPosition()).getY();
        }
    }
    width = maxX - minX + 1;
    height = maxY - minY + 1;
}

Room::~Room() {
    for (auto objectItr = objects.begin(); objectItr != objects.end(); objectItr++) {
        delete (*objectItr);
    }
}

void Room::movePlayerLeft() {
    movePlayer(DIR_LEFT);
}

void Room::movePlayerRight() {
    movePlayer(DIR_RIGHT);
}

void Room::movePlayerUp() {
    movePlayer(DIR_UP);
}

void Room::movePlayerDown() {
    movePlayer(DIR_DOWN);
}

bool Room::isFinished() {
    for (auto objectItr = objects.begin(); objectItr != objects.end(); objectItr++) {
        if ((*objectItr) -> getType() == OT_TARGET) {
            Target* target = dynamic_cast<Target*>(*objectItr);
            if (!(target -> isChecked())) {
                return false;
            }
        }
    }
    return true;
}

void Room::getView(std::vector<ObjectView>& view) {
    view.clear();
    //Floors
    getTypeView(OT_FLOOR, view);
    //Targets
    getTypeView(OT_TARGET, view);
    //Walls
    getTypeView(OT_WALL, view);
    //Boxes
    getTypeView(OT_BOX, view);
    //Player
    ObjectView playerView;
    playerView.point = player.getPosition();
    playerView.type = OT_PLAYER;
    view.push_back(playerView);
}

int Room::getWidth() const {
    return width;
}

int Room::getHeight() const{
    return height;
}

void Room::movePlayer(Direction direction) {
    Point nextPlayerPos = player.getPosition().neighbour(direction);
    //Check if next cell hasn't floor
    if (!hasObjectByTypeAt(OT_FLOOR, nextPlayerPos)) {
        return;
    }
    //check if next cell has wall
    if (hasObjectByTypeAt(OT_WALL, nextPlayerPos)) {
        return;
    }
    //check if next cell has box
    if (hasObjectByTypeAt(OT_BOX, nextPlayerPos)) {
        Box* box = dynamic_cast<Box*>(getObjectByTypeAt(OT_BOX, nextPlayerPos));
        //box next position
        Point nextBoxPos = (box -> getPosition()).neighbour(direction);
        //check if next cell hasn't floor
        if (!hasObjectByTypeAt(OT_FLOOR, nextBoxPos)) {
            return;
        }
        //check if next cell has another box or wall
        bool hasBox = hasObjectByTypeAt(OT_BOX, nextBoxPos);
        bool hasWall = hasObjectByTypeAt(OT_WALL, nextBoxPos);
        if (hasBox || hasWall) {
            return;
        }
        //targetS check
        //target at CURRENT BOX POSITION
        if (hasObjectByTypeAt(OT_TARGET, box -> getPosition())) {
            GameObject* go = getObjectByTypeAt(OT_TARGET, box -> getPosition());
            Target* target = dynamic_cast<Target*>(go);
            target -> uncheck();
        }
        //target at NEXT BOX POSITION
        if (hasObjectByTypeAt(OT_TARGET, nextBoxPos)) {
            GameObject* go = getObjectByTypeAt(OT_TARGET, nextBoxPos);
            Target* target = dynamic_cast<Target*>(go);
            target -> check();
        }
        box -> setPosition(nextBoxPos);
    }
    player.setPosition(nextPlayerPos);
}

void Room::getObjectsAt(const Point& point, std::vector<GameObject*>& objects) {
    objects.clear();
    auto begItr = (this -> objects).begin();
    auto endItr = (this -> objects).end();
    for (auto objectItr = begItr; objectItr != endItr; objectItr++) {
        if ((*objectItr) -> getPosition() == point) {
            objects.push_back(*objectItr);
        }
    }
}

GameObject* Room::getObjectByTypeAt(ObjectType objectType, const Point& point) {
    std::vector<GameObject*> objects;
    getObjectsAt(point, objects);
    for (auto objectItr = objects.begin(); objectItr != objects.end(); objectItr++) {
        if ((*objectItr) -> getType() == objectType) {
            return *objectItr;
        }
    }
    return nullptr;
}

bool Room::hasObjectByTypeAt(ObjectType objectType, const Point& point) {
    GameObject* gameObject = getObjectByTypeAt(objectType, point);
    if (gameObject != nullptr) {
        if (gameObject -> getType() == objectType) {
            return true;
        }
    }
    return false;
}

void Room::getTypeView(ObjectType objectType, std::vector<ObjectView>& view) {
    for (auto objectItr = objects.begin(); objectItr != objects.end(); objectItr++) {
        if ((*objectItr) -> getType() == objectType) {
            ObjectView ov;
            ov.point = (*objectItr) -> getPosition();
            ov.type = (*objectItr) -> getType();
            view.push_back(ov);
        }
    }
}
