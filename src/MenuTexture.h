#ifndef MENUTEXTURE_H
#define MENUTEXTURE_H
#include <SDL_ttf.h>
#include "Texture.h"
class MenuTexture : public Texture {
public:
    MenuTexture(Window* window);
    virtual ~MenuTexture();
    bool fromText(TTF_Font* font, const char* text, SDL_Color color);
};
#endif // MENUTEXTURE_H
