#include "Texture.h"

Texture::Texture(Window* window):
    texture(nullptr), renderer(nullptr),
    width(0), height(0)
{
    renderer = window -> getRenderer();
}

Texture::~Texture() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
}

void Texture::draw(int x, int y) {
    if (renderer == nullptr) {
        return;
    }
    if (texture == nullptr) {
        return;
    }
    SDL_Rect rect = {x, y, width, height};
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

bool Texture::load(SDL_Surface* surface) {
    if (surface == nullptr) {
        return false;
    }
    if (renderer == nullptr) {
        return false;
    }
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
    width = surface -> w;
    height = surface -> h;
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
        return false;
    }
    return true;
}

int Texture::getWidth() {
    return width;
}

int Texture::getHeight() {
    return height;
}
