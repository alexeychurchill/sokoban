#ifndef POINT_H
#define POINT_H
#include "Direction.h"
class Point {
public:
    Point();
    Point(const Point& point);
    Point(int x, int y);
    void setX(int x);
    void setY(int y);
    int getX() const;
    int getY() const;
    Point neighbour(Direction direction);
    void operator=(const Point& point);
    bool operator==(const Point& point);
private:
    int x;
    int y;
};
#endif // POINT_H
