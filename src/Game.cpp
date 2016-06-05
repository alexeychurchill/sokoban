#include "Game.h"
#include "Textures.h"
#include "GameSettings.h"

Game::Game():
    Drawable(), finished(false), room(nullptr)
{}

Game::~Game() {
}

int Game::init() {
    if (getWindow() == nullptr) {
        return -3;
    }
    if (!loadTextures()) {
        return -4;
    }
    if (!roomLoader.openRoomList(ROOM_LIST_FILE)) {
        return -4;
    }
    newRoom();
    return 0;
}

bool Game::loadTextures() {
    //Floor
    ObjectTexture* floorTexture = new ObjectTexture(getWindow());
    if (!(floorTexture -> loadFromFile(FLOOR_TEXTURE))) {
        delete floorTexture;
        return false;
    }
    textures.insert(std::make_pair(OT_FLOOR, floorTexture));
    //Target
    ObjectTexture* targetTexture = new ObjectTexture(getWindow());
    if (!(targetTexture -> loadFromFile(TARGET_TEXTURE))) {
        delete targetTexture;
        return false;
    }
    textures.insert(std::make_pair(OT_TARGET, targetTexture));
    //Wall
    ObjectTexture* wallTexture = new ObjectTexture(getWindow());
    if (!(wallTexture -> loadFromFile(WALL_TEXTURE))) {
        delete wallTexture;
        return false;
    }
    textures.insert(std::make_pair(OT_WALL, wallTexture));
    //Box
    ObjectTexture* boxTexture = new ObjectTexture(getWindow());
    if (!(boxTexture -> loadFromFile(BOX_TEXTURE))) {
        delete boxTexture;
        return false;
    }
    textures.insert(std::make_pair(OT_BOX, boxTexture));
    //Player
    ObjectTexture* playerTexture = new ObjectTexture(getWindow());
    if (!(playerTexture -> loadFromFile(PLAYER_TEXTURE))) {
        delete playerTexture;
        return false;
    }
    textures.insert(std::make_pair(OT_PLAYER, playerTexture));
    return true;
}

void Game::draw() {
    if (room == nullptr) {
        return;
    }
    //drawing start point
    int x0 = (getWindow() -> getWidth() - (room -> getWidth()) * CELL_WIDTH) / 2;
    int y0 = (getWindow() -> getHeight() - (room -> getHeight()) * CELL_HEIGHT) / 2;
    std::vector<ObjectView> view;
    room -> getView(view);
    for (auto ovItr = view.begin(); ovItr != view.end(); ovItr++) {
        int x = (ovItr -> point).getX() * CELL_WIDTH + x0;
        int y = (ovItr -> point).getY() * CELL_HEIGHT + y0;
        ObjectTexture* tex = textures[ovItr -> type];
        tex -> draw(x, y);
    }
}

void Game::handleEvent(const SDL_Event& event) {
    if (event.type != SDL_KEYDOWN) {
        return;
    }
    if (room == nullptr) {
        return;
    }
    if (room -> isFinished()) {
        newRoom();
        return;
    }
    switch (event.key.keysym.sym) {
    case SDLK_LEFT:
        room -> movePlayerLeft();
        break;
    case SDLK_RIGHT:
        room -> movePlayerRight();
        break;
    case SDLK_UP:
        room -> movePlayerUp();
        break;
    case SDLK_DOWN:
        room -> movePlayerDown();
        break;
    }
}

void Game::finish() {
    if (room != nullptr) {
        delete room;
        room = nullptr;
    }
    finished = true;
}

bool Game::isFinished() {
    return finished;
}

void Game::newRoom() {
    if (room != nullptr) {
        delete room;
        room = nullptr;
    }
    roomLoader.nextRoom();
    room = roomLoader.getRoom();
}

void Game::restartRoom() {
    if (room != nullptr) {
        delete room;
        room = nullptr;
    }
    room = roomLoader.getRoom();
}
