#ifndef MENUITEM_H
#define MENUITEM_H
#include "MenuTexture.h"
#include "MenuAction.h"
class MenuItem {
public:
    MenuItem(MenuAction action);
    ~MenuItem();
    bool init(TTF_Font* font, const char* text, Window* window, SDL_Color col);
    void draw(int x, int y);
    MenuAction getAction() const;
    bool isOnMe(int x, int y) const;
    int getWidth() const;
    int getHeight() const;
private:
    MenuTexture* texture;
    int lastX;
    int lastY;
    MenuAction action;
};
#endif // MENUITEM_H
