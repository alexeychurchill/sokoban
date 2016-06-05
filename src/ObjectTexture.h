#ifndef OBJECTTEXTURE_H
#define OBJECTTEXTURE_H
#include "Texture.h"
class ObjectTexture : public Texture {
public:
    ObjectTexture(Window* window);
    virtual ~ObjectTexture();
    bool loadFromFile(const char* filename);
private:
    //...
};
#endif // OBJECTTEXTURE_H
