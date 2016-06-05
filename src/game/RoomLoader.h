#ifndef ROOMLOADER_H
#define ROOMLOADER_H
#include <vector>
#include <string>
#include "RoomProvider.h"
#include "Room.h"
#include "Point.h"
class RoomLoader : public RoomProvider {
public:
    RoomLoader();
    virtual ~RoomLoader();
    virtual bool nextRoom();
    virtual Room* getRoom();
    bool openRoomList(const char* filename);
private:
    void createRoom();
    void deleteRoom();
    bool readRoom();
    char** room;
    std::vector<std::string> roomList;
    int roomNumber;
    Point playerPosition;
};
#endif // ROOMLOADER_H
