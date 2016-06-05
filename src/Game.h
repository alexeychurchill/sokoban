#ifndef GAME_H
#define GAME_H
#include <map>
#include <SDL.h>
#include "Drawable.h"
#include "ObjectTexture.h"
#include "game/ObjectType.h"
#include "game/Room.h"
#include "game/RoomLoader.h"
class Game : public Drawable {
public:
    Game();
    virtual ~Game();
    int init();
    bool loadTextures();
    virtual void draw();
    void handleEvent(const SDL_Event& event);
    void finish();
    bool isFinished();
    void newRoom();
    void restartRoom();
private:
    Room* room;
    RoomLoader roomLoader;
    bool finished;
    std::map<ObjectType, ObjectTexture*> textures;
};
#endif // GAME_H
