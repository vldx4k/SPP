#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BankAccount {
    private:
        string name {};
        string surname {};
        string date {};
        float balance {};

    public:
        BankAccount(string _name, string _surname, string _date, float _balance)
            : name {_name}
            , surname {_surname}
            , date {_date}
            , balance {_balance}
        {}
        void DisplayRecord();
};

class DepositAccount : public BankAccount {
    private:
        float rate {};
        float savings {};

    public:
        DepositAccount(float r, float s, string _name, string _surname, string _date, float _balance)
            : BankAccount{_name, _surname, _date, _balance}
            , rate {r}
            , savings {s}
        {}
};

void  BankAccount::DisplayRecord() {
    cout << "Name: " << name         << '\n' <<
            "Surname: " << surname  << '\n' <<
            "Date: " << date        << '\n' <<
            "Balance: " << balance  << '\n';
}

int main() {
    int choice;
    int index = 0;
    vector<BankAccount> records;
    do{ cout << '\n';
        cout << "1. Add Record"     << '\n';
        cout << "2. Delete Record"  << '\n';
        cout << "3. View Records"   << '\n';
        cout << "4. Open Deposit"   << '\n';
        cout << "0. Exit"           << '\n';
        cin >> choice;

        switch(choice) {
            case 1: {
                string name, surname, date;
                float balance;
                cout << "\nEnter owners name: ";            cin >> name;
                cout << "\nEnter owners surname: ";         cin >> surname;
                cout << "\nEnter last operation date: ";    cin >> date;
                cout << "\nEnter balance: ";                cin >> balance;
                BankAccount newRecord(name, surname, date, balance);
                records.push_back(newRecord);
                index++ ;
                break;
                }
            case 2:
            {
                for (int i = 0; i < index; i++) {
                    cout << "\t\nRecord №" << i + 1 << '\n';
                    records[i].DisplayRecord();
                }
                int n;
                cout << "Enter record number to be deleted: "; cin >> n;
                records.erase(records.begin() + (n-1));
                index-- ;
                break;
            }
            case 3:
                for (int i = 0; i < index; i++) {
                    cout << "\t\nRecord №" << i + 1 << '\n';
                    records[i].DisplayRecord();
                }
                break;
            case 4: {
                string name, surname, date;
                float balance, rate, savings;
                cout << "\nEnter owners name: ";            cin >> name;
                cout << "\nEnter owners surname: ";         cin >> surname;
                cout << "\nEnter start date: ";             cin >> date;
                cout << "\nEnter deposit balance: ";        cin >> balance;
                cout << "\nEnter deposit rate: ";           cin >> rate;
                cout << "\nEnter deposit savings: ";        cin >> savings;
                BankAccount newRecord(name, surname, date, balance);
                records.push_back(newRecord);
                index++ ;
                break;
            }
            case 0: break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice !=0);

    return 0;
}
