#include <iostream>
#include <fstream>
#include <string>
#include <Book.hpp>
using namespace std;

void WaitEnter() {
    cout << "\nPress Enter to continue...";
    while (std::cin.get ()!='\n');
}

int main() {
    Book b;
    const char* filename = "book_database.txt";
    int choice;

    do {
        cout << "\n\n###\tMenu\t###\n" ;
        cout << "\n1. Display Records"    << endl;
        cout <<   "2. Add Record"         << endl;
        cout <<   "3. Update Record"      << endl;
        cout <<   "4. Find Record"      << endl;
        cout <<   "0. Exit"               << endl;
        cout <<   "\nEnter your choice: ";

        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: b.DisplayBook(filename); WaitEnter(); break;
            case 2: b.AddBook(filename);                  break;
            case 3: b.UpdateBook(filename);               break;
            case 4: b.FindByTheme(filename); WaitEnter(); break;
            case 0: break;
            default: cout << "\nInvalid choice. Please try again." << endl;
        }
    } while(choice != 0);

    return 0;
}
