#ifndef MENU_H
#define MENU_H
#include <vector>
#include <SDL_ttf.h>
#include "Drawable.h"
#include "Game.h"
#include "MenuTexture.h"
#include "MenuItem.h"
#include "MenuAction.h"
class Menu : public Drawable {
public:
    Menu();
    virtual ~Menu();
    void setGame(Game* game);
    int init();
    bool loadFont(const char* filename, int size);
    void handleMouseClick(int x, int y);
    virtual void draw();
private:
    bool generateItems();
    void performAction(MenuAction action);
    TTF_Font* font;
    std::vector<MenuItem*> items;
    int itemsWidth;
    SDL_Color colText;
    SDL_Color colBg;
    Game* game;
};
#endif // MENU_H
