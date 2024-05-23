#ifndef POINT_H
#define POINT_H

class Point {
protected:
    int axe_x, axe_y;

public:
    Point(int x = 0, int y = 0) : axe_x(x), axe_y(y) {}

    void move(int deltaX, int deltaY);

    virtual void display() {
        std::cout << "Point at (" << axe_x << ", " << axe_y << ")\n";
    }

    virtual ~Point() {}
};

#endif
