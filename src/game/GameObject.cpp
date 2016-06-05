#include "GameObject.h"

GameObject::GameObject() {
}

GameObject::~GameObject() {
}

ObjectType GameObject::getType() {
    return type;
}

Point GameObject::getPosition() {
    return position;
}

void GameObject::setPosition(const Point& point) {
    position = point;
}

void GameObject::setType(ObjectType type) {
    this -> type = type;
}
