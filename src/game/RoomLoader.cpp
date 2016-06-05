#include "RoomLoader.h"
#include <fstream>
#include "RoomType.h"
#include "GameObject.h"
#include "Floor.h"
#include "Target.h"
#include "Wall.h"
#include "Box.h"

RoomLoader::RoomLoader():
    RoomProvider(), room(nullptr), roomNumber(0)
{}

RoomLoader::~RoomLoader() {
    deleteRoom();
}

bool RoomLoader::nextRoom() {
    if ((roomNumber >= roomList.size())) {
        return false;
    }
    bool result = readRoom();
    roomNumber++;
    return result;
}

Room* RoomLoader::getRoom() {
    if (room == nullptr) {
        return nullptr;
    }
    std::vector<GameObject*> gameObjects;
    for (int y = 0; y < getRoomHeight(); y++) {
        for (int x = 0; x < getRoomWidth(); x++) {
            Point point(x, y);
            switch (room[y][x]) {
            case FLOOR:
                {
                    Floor* floor = new Floor();
                    floor -> setPosition(point);
                    gameObjects.push_back(floor);
                    break;
                }
            case WALL:
                {
                    Floor* floor = new Floor();
                    Wall* wall = new Wall();
                    floor -> setPosition(point);
                    wall -> setPosition(point);
                    gameObjects.push_back(floor);
                    gameObjects.push_back(wall);
                    break;
                }
            case TARGET:
                {
                    Floor* floor = new Floor();
                    Target* target = new Target();
                    floor -> setPosition(point);
                    target -> setPosition(point);
                    gameObjects.push_back(floor);
                    gameObjects.push_back(target);
                    break;
                }
            case BOX:
                {
                    Floor* floor = new Floor();
                    Box* box = new Box();
                    floor -> setPosition(point);
                    box -> setPosition(point);
                    gameObjects.push_back(floor);
                    gameObjects.push_back(box);
                    break;
                }
            case BOX_ON_TARGET:
                {
                    Floor* floor = new Floor();
                    Target* target = new Target();
                    Box* box = new Box();
                    floor -> setPosition(point);
                    target -> setPosition(point);
                    box -> setPosition(point);
                    gameObjects.push_back(floor);
                    gameObjects.push_back(target);
                    gameObjects.push_back(box);
                    break;
                }
            }
        }
    }
    return new Room(gameObjects, playerPosition);
}

bool RoomLoader::openRoomList(const char* filename) {
    std::ifstream in(filename);
    if (!in) {
        return false;
    }
    while (!in.eof()) {
        std::string fname;
        in >> fname;
        roomList.push_back(fname);
        if (in.eof()) {
            break;
        }
    }
    roomNumber = 0;
    deleteRoom();
    return true;
}

void RoomLoader::createRoom() {
    if (room != nullptr) {
        deleteRoom();
    }
    room = new char* [getRoomHeight()];
    for (int y = 0; y < getRoomHeight(); y++) {
        room[y] = new char[getRoomWidth()];
        for (int x = 0; x < getRoomWidth(); x++) {
            room[y][x] = EMPTY;
        }
    }
}

void RoomLoader::deleteRoom() {
    if (room == nullptr) {
        return;
    }
    for (int y = 0; y < getRoomHeight(); y++) {
        delete[] room[y];
    }
    delete[] room;
    room = nullptr;
}

bool RoomLoader::readRoom() {
    std::ifstream in(roomList[roomNumber].c_str());
    if (!in) {
        return false;
    }
    deleteRoom();
    int roomW, roomH;
    in >> roomW >> roomH;
    int playerX, playerY;
    in >> playerX >> playerY;
    setRoomWidth(roomW);
    setRoomHeight(roomH);
    playerPosition.setX(playerX);
    playerPosition.setY(playerY);
    createRoom();
    for (int y = 0; y < getRoomHeight(); y++) {
        for (int x = 0; x < getRoomWidth(); x++) {
            char c;
            in >> c;
            room[y][x] = c;
        }
    }
    return true;
}
