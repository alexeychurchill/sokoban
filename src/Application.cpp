#include "Application.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "MenuSettings.h"

Application::Application()
{}

int Application::init() {
    //SDL Init
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return -1;
    }
    //SDL_image init
    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        return -1;
    }
    //SDL_ttf init
    if (TTF_Init() != 0) {
        return -1;
    }
    //Window
    if (window.init(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT) != 0) {
        return -2;
    }
    //Game
    game.setWindow(&window);
    if (game.init() != 0) {
        return -3;
    }
    //Menu
    menu.setWindow(&window);
    menu.setGame(&game);
    if (!menu.loadFont(FONT_FILENAME, FONT_SIZE)) {
        return -4;
    }
    if (menu.init() != 0) {
        return -4;
    }
    return 0;
}

int Application::run() {
    int code = init();
    if (code != 0) {
        return code;
    }
    code = gameLoop();
    return code;
}

int Application::gameLoop() {
    while (!game.isFinished()) {
        SDL_Event e;
        while (SDL_PollEvent(&e) && (!game.isFinished())) {
            switch (e.type) {
            case SDL_QUIT:
                game.finish();
                break;
            case SDL_KEYDOWN:
                game.handleEvent(e);
                break;
            case SDL_MOUSEBUTTONDOWN:
                menu.handleMouseClick(e.button.x, e.button.y);
                break;
            }
        }
        //...
        window.clear();
        game.draw();
        menu.draw();
        window.render();
        SDL_Delay(1000 / FPS_LIMIT);
    }
    return 0;
}
