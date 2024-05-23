#include <iostream>
#include "Point.h"
#include "Cursor.h"

void displayMenu() {
    std::cout << "1. Create cursor\n";
    std::cout << "2. Move cursor\n";
    std::cout << "3. Resize cursor\n";
    std::cout << "4. Change cursor color\n";
    std::cout << "5. Rotate cursor\n";
    std::cout << "6. Display cursor\n";
    std::cout << "7. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    Cursor cursor;
    int option;

    do {
        displayMenu();
        std::cin >> option;

        switch (option) {
        case 1: {
            int x, y, size;
            std::string color;
            double angle;
            std::cout << "Enter coordinates (y): ";
            std::cin >> x;
            std::cout << "Enter coordinate (y): ";
            std::cin >> y;
            std::cout << "Enter size: ";
            std::cin >> size;
            std::cout << "Enter color: ";
            std::cin >> color;
            std::cout << "Enter rotation angle: ";
            std::cin >> angle;
            cursor = Cursor(x, y, size, color, angle);
            break;
        }
        case 2: {
            int deltaX, deltaY;
            std::cout << "Enter move (deltaX): ";
            std::cin >> deltaX;
            std::cout << "Enter move (deltaY): ";
            std::cin >> deltaY;
            cursor.move(deltaX, deltaY);
            break;
        }
        case 3: {
            int newSize;
            std::cout << "Enter new size: ";
            std::cin >> newSize;
            cursor.resize(newSize);
            break;
        }
        case 4: {
            std::string newColor;
            std::cout << "Enter new color: ";
            std::cin >> newColor;
            cursor.changeColor(newColor);
            break;
        }
        case 5: {
            double newAngle;
            std::cout << "Enter new angle: ";
            std::cin >> newAngle;
            cursor.rotate(newAngle);
            break;
        }
        case 6: {
            cursor.display();
            break;
        }
        case 7: {
            std::cout << "Exiting...\n";
            break;
        }
        default: {
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    } while (option != 7);

    return 0;
}
