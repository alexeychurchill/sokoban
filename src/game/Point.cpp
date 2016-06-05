#include "Point.h"

Point::Point():
    x(0), y(0)
{}

Point::Point(const Point& point):
    x(point.getX()), y(point.getY())
{}

Point::Point(int x, int y):
    x(x), y(y)
{}

void Point::setX(int x) {
    this -> x = x;
}

void Point::setY(int y) {
    this -> y = y;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

Point Point::neighbour(Direction direction) {
    switch (direction) {
    case DIR_LEFT:
        return Point(x - 1, y);
        break;
    case DIR_UP:
        return Point(x, y - 1);
        break;
    case DIR_RIGHT:
        return Point(x + 1, y);
        break;
    case DIR_DOWN:
        return Point(x, y + 1);
        break;
    }
    return *this;
}

void Point::operator=(const Point& point) {
    setX(point.getX());
    setY(point.getY());
}

bool Point::operator==(const Point& point) {
    return (point.getX() == x) && (point.getY() == y);
}
