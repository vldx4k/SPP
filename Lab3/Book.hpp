#include <string>
#include <vector>
using namespace std;
class Book
{
  string title;
  string author;
  string theme;
  string publisher;
  int year;
  int pages;

    public:
    void AddBook(const char* filename);
    void DisplayBook(const char* filename);
    void UpdateBook(const char* filename);
    void FindByTheme(const char* filename);
};


void Book::AddBook(const char* filename) {
    ofstream file;
    file.open(filename, ios::app);

    if (!file.is_open()) {
        cout << "Unable to open file." << endl;
        return;
    }

    Book record;
    cout << "Enter book title: ";       getline(cin, record.title);
    cout << "Enter book author: ";      getline(cin, record.author);
    cout << "Enter book theme: ";       getline(cin, record.theme);
    cout << "Enter book publisher: ";   getline(cin, record.publisher);
    cout << "Enter publishing year: ";  cin >> record.year;
    cout << "Enter number of pages: ";  cin >> record.pages;

    file << record.title                << " "
         << record.author               << " "
         << record.theme                << " "
         << record.publisher            << " "
         << record.year                 << " "
         << record.pages                << endl;

    file.close();
    cout << "\nRecord added successfully." << endl;
}

void Book::DisplayBook(const char* filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Unable to open file." << endl;
        return;
    }

    Book record;
    cout << "\nCurrent records:" << endl;
    while (file >> record.title >> record.author >> record.theme >> record.publisher >> record.year >> record.pages) {
        cout << "\n\tTitle:\t\t"         << record.title
             << "\n\tAuthor:\t\t"        << record.author
             << "\n\tTheme:\t\t"         << record.theme
             << "\n\tPublisher:\t"       << record.publisher
             << "\n\tYear:\t\t"          << record.year
             << "\n\tPages:\t\t"         << record.pages
             << endl;
    }

    file.close();
}

void Book::UpdateBook(const char* filename) {
    fstream file(filename, ios::in | ios::out);

    if (!file.is_open()) {
        cout << "Unable to open file." << endl;
        return;
    }

    Book record;
    string targetName;
    cout << "\nEnter the name of the product to update: ";
    cin >> targetName;
    cin.ignore();

    bool found = false;
    streampos prevPos;
    while (file >> record.title >> record.author >> record.theme >> record.publisher >> record.year >> record.pages) {
        if (record.title == targetName) {
            found = true;
            cout << "Current record: " << record.title << " " << record.author
                 << " " << record.theme << " " << record.publisher << endl;
            cout << "Enter new details:" << endl;
            prevPos = file.tellg(); // save the position of the current record
            cout << "Enter new title: ";        cin >> record.title;
            cout << "Enter new author: ";       cin >> record.author;
            cout << "Enter new theme: ";        cin >> record.theme;
            cout << "Enter new publisher: ";    cin >> record.publisher;

            file.seekp(prevPos - static_cast<streampos>(sizeof(record)));
            file << record.title << " " << record.author << " "
                 << record.theme << " " << record.publisher << endl;
            break;
        }
        prevPos = file.tellg();
    }

    if (!found) {
        cout << "No book found with the title "
             << '"' << targetName << '"' << "." << endl;
    } else {
        cout  << "Record updated successfully." << endl;
    }

    file.close();
}

void Book::FindByTheme(const char* filename) {
    fstream file(filename, ios::in | ios::out);

    if (!file.is_open()) {
        cout << "Unable to open file." << endl;
        return;
    }

    Book record;
    string targetName;
    cout << "Enter the theme: ";
    cin >> targetName;
    cin.ignore();

    bool found = false;
    streampos prevPos;
    while (file >> record.title >> record.author >> record.theme >> record.publisher >> record.year >> record.pages) {
        if (record.theme == targetName) {
        found = true;
        cout << "\n\tTitle:\t\t"         << record.title
             << "\n\tAuthor:\t\t"        << record.author
             << "\n\tTheme:\t\t"         << record.theme
             << "\n\tPublisher:\t"       << record.publisher
             << "\n\tYear:\t\t"          << record.year
             << "\n\tPages:\t\t"         << record.pages
             << endl;
        }
        prevPos = file.tellg();
    }

    if (!found) {
        cout << "\nNo book found with the theme "
             << '"' << targetName << '"' << '.' << endl;
    }

    file.close();
}