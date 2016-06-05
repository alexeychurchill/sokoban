#include "Menu.h"
#include "MenuSettings.h"
#include "MenuAction.h"
//...

Menu::Menu():
    Drawable(), font(nullptr), game(nullptr), itemsWidth(0)
{}

Menu::~Menu() {
    if (font != nullptr) {
        TTF_CloseFont(font);
    }
    for (auto itemItr = items.begin(); itemItr != items.end(); itemItr++) {
        delete (*itemItr);
    }
}

void Menu::setGame(Game* game) {
    this -> game = game;
}

int Menu::init() {
    //Window, game, font checks
    if (getWindow() == nullptr) {
        return -4;
    }
    if (game == nullptr) {
        return -4;
    }
    if (font == nullptr) {
        return -4;
    }
    //Colors
    //Bg
    colBg.r = BG_COLOR_R;
    colBg.g = BG_COLOR_G;
    colBg.b = BG_COLOR_B;
    colBg.a = 255;
    //Text
    colText.r = FONT_COLOR_R;
    colText.g = FONT_COLOR_G;
    colText.b = FONT_COLOR_B;
    colText.a = 255;
    //texture generation
    if (!generateItems()) {
        return -4;
    }
    return 0;
}

bool Menu::loadFont(const char* filename, int size) {
    font = TTF_OpenFont(filename, size);
    if (font == nullptr) {
        return false;
    }
    return true;
}

void Menu::handleMouseClick(int x, int y) {
    if (y < (getWindow() -> getHeight() - MENU_HEIGHT)) {
        return;
    }
    MenuAction action = MA_NONE;
    for (auto itemItr = items.begin(); itemItr != items.end(); itemItr++) {
        if ((*itemItr) -> isOnMe(x, y)) {
            action = (*itemItr) -> getAction();
            break;
        }
    }
    performAction(action);
}

void Menu::draw() {
    //Menu background
    SDL_SetRenderDrawColor(getWindow() -> getRenderer(),
                           colBg.r, colBg.g, colBg.b, colBg.a);
    SDL_Rect bgRect;
    bgRect.x = 0;
    bgRect.y = getWindow() -> getHeight() - MENU_HEIGHT;
    bgRect.w = getWindow() -> getWidth();
    bgRect.h = MENU_HEIGHT;
    SDL_RenderFillRect(getWindow() -> getRenderer(), &bgRect);
    //Menu items
    int xPos = (getWindow() -> getWidth() - itemsWidth) / 2;
    for (auto itemItr = items.begin(); itemItr != items.end(); itemItr++) {
        int yPos = bgRect.y + (MENU_HEIGHT - (*itemItr) -> getHeight()) / 2;
        (*itemItr) -> draw(xPos, yPos);
        xPos += (*itemItr) -> getWidth() + MENU_DISTANCE;
    }
}

bool Menu::generateItems() {
    MenuItem* temp;
    //next room item
    temp = new MenuItem(MA_NEXTLEVEL);
    if (!(temp -> init(font, "NEXT ROOM", getWindow(), colText))) {
        delete temp;
        return false;
    }
    items.push_back(temp);
    itemsWidth += temp -> getWidth();
    //restart room item
    temp = new MenuItem(MA_RESTARTLEVEL);
    if (!(temp -> init(font, "RESTART ROOM", getWindow(), colText))) {
        delete temp;
        return false;
    }
    items.push_back(temp);
    itemsWidth += temp -> getWidth();
    //quit game item
    temp = new MenuItem(MA_QUIT);
    if (!(temp -> init(font, "QUIT GAME", getWindow(), colText))) {
        delete temp;
        return false;
    }
    items.push_back(temp);
    itemsWidth += temp -> getWidth();
    itemsWidth += (items.size() - 1) * MENU_DISTANCE;
    return true;
}

void Menu::performAction(MenuAction action) {
    switch (action) {
    case MA_NEXTLEVEL:
        game -> newRoom();
        break;
    case MA_RESTARTLEVEL:
        game -> restartRoom();
        break;
    case MA_QUIT:
        game -> finish();
        break;
    }
}
