#include "Window.h"

Window::Window():
    window(nullptr), renderer(nullptr)
{}

Window::~Window() {
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
}

int Window::init(const char* title, int width, int height) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (window == nullptr) {
        return -2;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        return -2;
    }
    return 0;
}

SDL_Renderer* Window::getRenderer() {
    return renderer;
}

void Window::clear() {
    if (renderer != nullptr) {
        unsigned char r, g, b, a;
        SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, r, g, b, a);
    }
}

void Window::render() {
    if (renderer != nullptr) {
        SDL_RenderPresent(renderer);
    }
}

int Window::getWidth() {
    if (window != nullptr) {
        int w;
        SDL_GetWindowSize(window, &w, nullptr);
        return w;
    }
    return -1;
}

int Window::getHeight() {
    if (window != nullptr) {
        int h;
        SDL_GetWindowSize(window, nullptr, &h);
        return h;
    }
    return -1;
}
