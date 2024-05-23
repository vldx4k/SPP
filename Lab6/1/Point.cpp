#include <iostream>
#include <cmath>
#include "Point.h"

    void Point::move(int deltaX, int deltaY) {
        axe_x += deltaX;
        axe_y += deltaY;
    }
