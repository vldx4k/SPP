#ifndef VECTOR_H
#define VECTOR_H

class Vector {
    private:
        float axe_x, axe_y, axe_z;
    public:
        Vector(float x = 0, float y = 0, float z = 0)
        : axe_x(x), axe_y(y), axe_z(z) {};
        friend Vector operator+(Vector& v1, Vector& v2);

        void print() {
        std::cout << "\n( " << axe_x << ", " << axe_y << ", " << axe_z << " )\n";
        }
};

#endif
