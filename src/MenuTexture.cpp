#include "MenuTexture.h"
#include <algorithm>

MenuTexture::MenuTexture(Window* window):
    Texture(window)
{}

MenuTexture::~MenuTexture() {
}

bool MenuTexture::fromText(TTF_Font* font, const char* text, SDL_Color color) {
    if (font == nullptr) {
        return false;
    }
    SDL_Surface* surface = TTF_RenderText_Blended(font, text, color);
    if (surface == nullptr) {
        return false;
    }
    bool result = load(surface);
    SDL_FreeSurface(surface);
    return result;
}
