#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL.h>
#include "Window.h"
class Texture {
public:
    Texture(Window* window);
    virtual ~Texture();
    void drawMe(int x, int y);
    void draw(int x, int y);
    bool load(SDL_Surface* surface);
    int getWidth();
    int getHeight();
private:
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    int width;
    int height;
};
#endif // TEXTURE_H
