#ifndef ROOMGENERATOR_H
#define ROOMGENERATOR_H
#include "Room.h"
class RoomGenerator {
public:
    RoomGenerator();
    void generate(int width, int height);
    Room* getLevel();
    void setBoxesCount(int count);
private:
    void generateRoom();
    void putObjects();
    int levelWidth;
    int levelHeight;
    int boxesCount;
    int wallTemplates[17][5][5];
};
#endif // ROOMGENERATOR_H
