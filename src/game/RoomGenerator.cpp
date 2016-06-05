#include "RoomGenerator.h"
#include "Room.h"

RoomGenerator::RoomGenerator() {
}

void RoomGenerator::generate(int width, int height) {
}

Room* RoomGenerator::getLevel() {
    //1 - wall
    //2 - target
    //3 - box
    //4 - player
    int lw = 12, lh = 6;
    int obj[6][12] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
            {1, 0, 4, 0, 3, 0, 0, 0, 2, 3, 0, 0},
            {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        };
    //
    std::vector<GameObject*> level;
    for (int y = 0; y < lh; y++) {
        for (int x = 0; x < lw; x++) {
            Point point(x, y);
            switch (obj[y][x]) {
            case 0: {
                    Floor* floor = new Floor();
                    floor -> setPosition(point);
                    level.push_back(floor);
                    break;
                }
            case 1: {
                    Floor* floor = new Floor();
                    Wall* wall = new Wall();
                    floor -> setPosition(point);
                    wall -> setPosition(point);
                    level.push_back(floor);
                    level.push_back(wall);
                    break;
                }
            case 2: {
                    Floor* floor = new Floor();
                    Target* target = new Target();
                    floor -> setPosition(point);
                    target -> setPosition(point);
                    level.push_back(floor);
                    level.push_back(target);
                    break;
                }
            case 3: {
                    Floor* floor = new Floor();
                    Box* box = new Box();
                    floor -> setPosition(point);
                    box -> setPosition(point);
                    level.push_back(floor);
                    level.push_back(box);
                    break;
                }
            case 4: {
                    Floor* floor = new Floor();
                    Player* player = new Player();
                    floor -> setPosition(point);
                    player -> setPosition(point);
                    level.push_back(floor);
                    level.push_back(player);
                    break;
                }
            }
        }
    }
    return new Room(level, Point(2, 2));
}

void RoomGenerator::setBoxesCount(int count) {
}

void RoomGenerator::generateRoom() {
}

void RoomGenerator::putObjects() {
}
