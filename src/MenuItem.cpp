#include "MenuItem.h"

MenuItem::MenuItem(MenuAction action):
    action(action), texture(nullptr), lastX(-1), lastY(-1)
{}

MenuItem::~MenuItem() {
    if (texture != nullptr) {
        delete texture;
    }
}

bool MenuItem::init(TTF_Font* font, const char* text, Window* window, SDL_Color col) {
    if ((font == nullptr) || (window == nullptr)) {
        return false;
    }
    texture = new MenuTexture(window);
    bool ok = texture -> fromText(font, text, col);
    if (!ok) {
        delete texture;
        texture = nullptr;
    }
    return ok;
}

void MenuItem::draw(int x, int y) {
    if (texture == nullptr) {
        lastX = -1;
        lastY = -1;
        return;
    }
    lastX = x;
    lastY = y;
    texture -> draw(x, y);
}

MenuAction MenuItem::getAction() const {
    return action;
}

bool MenuItem::isOnMe(int x, int y) const {
    if ((lastX < 0) || (lastY < 0)) {
        return false;
    }
    if (texture == nullptr) {
        return false;
    }
    int xNext = lastX + texture -> getWidth();
    int yNext = lastY + texture -> getHeight();
    bool belowTopLeft = (lastX <= x) && (lastY <= y);
    bool aboveBottomRight = (x <= xNext) && (y <= yNext);
    return belowTopLeft && aboveBottomRight;
}

int MenuItem::getWidth() const {
    if (texture == nullptr) {
        return 0;
    }
    return (texture -> getWidth());
}

int MenuItem::getHeight() const {
    if (texture == nullptr) {
        return 0;
    }
    return (texture -> getHeight());
}
