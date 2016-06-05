#include "ObjectTexture.h"
#include <SDL.h>
#include <SDL_image.h>

ObjectTexture::ObjectTexture(Window* window):
    Texture(window)
{}

ObjectTexture::~ObjectTexture() {
}

bool ObjectTexture::loadFromFile(const char* filename) {
    SDL_Surface* surface = IMG_Load(filename);
    if (surface == nullptr) {
        return false;
    }
    bool loadResult = load(surface);
    SDL_FreeSurface(surface);
    return loadResult;
}
