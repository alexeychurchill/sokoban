#include "Drawable.h"

Drawable::Drawable():
    window(nullptr)
{}

Drawable::~Drawable() {
}

void Drawable::setWindow(Window* window) {
    this -> window = window;
}

Window* Drawable::getWindow() {
    return window;
}
