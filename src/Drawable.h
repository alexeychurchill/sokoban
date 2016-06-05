#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "Window.h"
class Drawable {
public:
    Drawable();
    virtual ~Drawable();
    void setWindow(Window* window);
    Window* getWindow();
    virtual void draw() = 0;
private:
    Window* window;
};
#endif // DRAWABLE_H
