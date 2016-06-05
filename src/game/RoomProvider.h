#ifndef ROOMPROVIDER_H
#define ROOMPROVIDER_H
#include "Room.h"
class RoomProvider {
public:
    RoomProvider();
    virtual ~RoomProvider();
    virtual bool nextRoom() = 0;
    virtual Room* getRoom() = 0;
    int getRoomWidth() const;
    int getRoomHeight() const;
protected:
    void setRoomWidth(int width);
    void setRoomHeight(int height);
private:
    int roomWidth;
    int roomHeight;
};
#endif // ROOMPROVIDER_H
