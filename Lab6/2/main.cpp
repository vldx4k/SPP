#include <iostream>
#include "Vector.h"

    Vector operator+(Vector& v1, Vector& v2)
    {
        Vector res;
        res.axe_x = v1.axe_x + v2.axe_x;
        res.axe_y = v1.axe_y + v2.axe_y;
        res.axe_z = v1.axe_z + v2.axe_z;
        return res;
    }

int main() {
    Vector v1(21, 2, 3), v2(5, 1, 3);
    Vector v3 = v1 + v2;
    v3.print ();
}
