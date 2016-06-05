#ifndef WINDOW_H
#define WINDOW_H
#include <SDL.h>
class Window {
public:
    Window();
    ~Window();
    int init(const char* title, int width, int height);
    SDL_Renderer* getRenderer();
    void clear();
    void render();
    int getWidth();
    int getHeight();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
#endif // WINDOW_H
