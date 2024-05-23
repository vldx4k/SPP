#include <iostream>
#include <cmath>
#include "Cursor.h"

    void Cursor::resize(int newSize) {
        cursor_size = newSize;
    }

    void Cursor::changeColor(const std::string& newColor) {
        cursor_color = newColor;
    }

    void Cursor::rotate(double newAngle) {
        cursor_angle = newAngle;
    }
