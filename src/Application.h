#ifndef APPLICATION_H
#define APPLICATION_H
#include "AppSettings.h"
#include "Window.h"
#include "Game.h"
#include "Menu.h"
class Application {
public:
    Application();
    int init();
    int run();
    int gameLoop();
private:
    Menu menu;
    Game game;
    Window window;
};
#endif // APPLICATION_H
