#include "RoomProvider.h"

RoomProvider::RoomProvider():
    roomWidth(0), roomHeight(0)
{}

RoomProvider::~RoomProvider() {
}

int RoomProvider::getRoomWidth() const {
    return roomWidth;
}

int RoomProvider::getRoomHeight() const {
    return roomHeight;
}

void RoomProvider::setRoomWidth(int width) {
    roomWidth = width;
}

void RoomProvider::setRoomHeight(int height) {
    roomHeight = height;
}
