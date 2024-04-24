#include <iostream>
#include <string>
using namespace std;

class Horse {
        string breed;
        bool sex;
        int age;

    public:
        void SetHorseBreed(string);
        void SetHorseSex(char);
        void SetHorseAge(int);
        string GetHorseBreed();
        bool GetHorseSex();
        int GetHorseAge();
};

class Race : public Horse {
        int number;
        int trace;
        float time;
        float distance;

    public:
        void SetRaceInfo(int, int, float, float);
        int GetRaceNumber();
        int GetRaceTrace();
        float GetRaceTime();
        float GetRaceDistance();
        float SpeedOfHorse();
};

void Horse::SetHorseBreed(string name) {
    this -> breed = name;
}

void Horse::SetHorseSex(char gender) {
        switch(gender) {
            case 'M': sex = 1; break;
            case 'm': sex = 1; break;
            case 'F': sex = 0; break;
            case 'f': sex = 0; break;
            default: cout << "\nInvalid value. 'M' or 'F' must be set.\n";
        }
}

void Horse::SetHorseAge(int years) {
    this -> age = years;
}

string Horse::GetHorseBreed() {
    return breed;
}

bool Horse::GetHorseSex() {
    return sex;
}

int Horse::GetHorseAge() {
    return age;
}

void Race::SetRaceInfo(int num, int trace, float seconds, float meters) {
    this -> number = num;
    this -> trace = trace;
    this -> time = seconds;
    this -> distance = meters;
}

int Race::GetRaceNumber() {
    return number;
}

int Race::GetRaceTrace() {
    return trace;
}

float Race::GetRaceTime() {
    return time;
}

float Race::GetRaceDistance() {
    return distance;
}

float Race::SpeedOfHorse() {
    return (distance/time) * 3.6;
}

int main() {

    string breed;
    char sex;
    int age;

    cout << "\t### Horse ###";
    Horse h1;
        cout << "\nEnter the horse breed name:\n";
        getline(cin, breed);        h1.SetHorseBreed(breed);

        cout << "\nEnter the horse sex (M/F):\n";
        do{ cin >> sex;     h1.SetHorseSex(sex);
        } while(sex != 'M' && sex != 'm' && sex != 'F' && sex != 'f' );

        cout << "\nEnter horse age:\n";
        cin >> age;     h1.SetHorseAge(age);



    cout << "\n\t### Horse INFO ###";
        cout << "\nBreed: " << h1.GetHorseBreed();
        cout << "\nSex: " << h1.GetHorseSex();
        cout << "\nAge: " << h1.GetHorseAge();

    cout << "\n\n\n\t### Race ###";
    int number, trace;
    float time, distance;

    Race r1;
        cout << "\nEnter the horse breed name:\n";
        cin.ignore();
        getline(cin, breed);        r1.SetHorseBreed(breed);

        cout << "\nEnter the horse sex (M/F):\n";
        do{ cin >> sex;     r1.SetHorseSex(sex);
        } while(sex != 'M' && sex != 'm' && sex != 'F' && sex != 'f' );

        cout << "\nEnter horse age:\n";
        cin >> age;     r1.SetHorseAge(age);

        cout << "\nEnter race number:\n";       cin >> number;
        cout << "\nEnter race trace:\n";        cin >> trace;
        cout << "\nEnter race time:\n";         cin >> time;
        cout << "\nEnter race distance:\n";     cin >> distance;

        r1.SetRaceInfo(number, trace, time, distance);

    cout << "\n\t### Race INFO ###";
        cout << "\nBreed: " << r1.GetHorseBreed();
        cout << "\nSex: " << r1.GetHorseSex();
        cout << "\nAge: " << r1.GetHorseAge();
        cout << "\nRace Number: " << r1.GetRaceNumber();
        cout << "\nRace Trace: " << r1.GetRaceTrace();
        cout << "\nRace Time (seconds): " << r1.GetRaceTime();
        cout << "\nRace Distance (meters): " <<  r1.GetRaceDistance();
        cout << "\nHorse Speed (km/h): " <<  r1.SpeedOfHorse();

	return 0;
}
