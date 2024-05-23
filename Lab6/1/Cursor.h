#ifndef CURSOR_H
#define CURSOR_H

#include "Point.h"

class Cursor : public Point {
protected:
    int cursor_size;
    std::string cursor_color;
    double cursor_angle;

public:
    Cursor(int x = 0, int y = 0, int size = 1, const std::string& color = "black", double angle = 0)
        : Point(x, y), cursor_size(size), cursor_color(color), cursor_angle(angle) {}

    void resize(int newSize);
    void changeColor(const std::string& newColor);
    void rotate(double newAngle);

    void display() override {
        std::cout << "Cursor at (" << axe_x << ", " << axe_y << "), size: " << cursor_size << ", color: " << cursor_color << ", angle: " << cursor_angle << " degrees\n";
    }
};

#endif
