#include <iostream>
#include <iomanip>
using namespace std;

// Function to format and display the 12-hour clock
void display12Hour(int hour, int minute, int second) {
    int displayHour = hour % 12;
    if (displayHour == 0) displayHour = 12;

    string ampm = (hour < 12) ? "AM" : "PM";

    cout << "**************************\n";
    cout << "*     12-Hour Clock      *\n";
    cout << "*     " 
         << setw(2) << setfill('0') << displayHour << ":"
         << setw(2) << setfill('0') << minute << ":"
         << setw(2) << setfill('0') << second << " " << ampm
         << "     *\n";
    cout << "**************************\n";
}

// Function to format and display the 24-hour clock
void display24Hour(int hour, int minute, int second) {
    cout << "**************************\n";
    cout << "*     24-Hour Clock      *\n";
    cout << "*     "
         << setw(2) << setfill('0') << hour << ":"
         << setw(2) << setfill('0') << minute << ":"
         << setw(2) << setfill('0') << second
         << "          *\n";
    cout << "**************************\n";
}

// Display both clocks
void displayBothClocks(int hour, int minute, int second) {
    display12Hour(hour, minute, second);
    display24Hour(hour, minute, second);
}

// Add one hour
void addHour(int &hour) {
    hour = (hour + 1) % 24;
}

// Add one minute
void addMinute(int &minute, int &hour) {
    minute++;
    if (minute == 60) {
        minute = 0;
        addHour(hour);
    }
}

// Add one second
void addSecond(int &second, int &minute, int &hour) {
    second++;
    if (second == 60) {
        second = 0;
        addMinute(minute, hour);
    }
}

// Display menu
void displayMenu() {
    cout << "\n**************************\n";
    cout << "* 1 - Add One Hour       *\n";
    cout << "* 2 - Add One Minute     *\n";
    cout << "* 3 - Add One Second     *\n";
    cout << "* 4 - Exit Program       *\n";
    cout << "**************************\n";
    cout << "Enter your choice: ";
}

int main() {
    int hour = 0;
    int minute = 0;
    int second = 0;

    int choice = 0;

    while (choice != 4) {
        displayBothClocks(hour, minute, second);
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addHour(hour);
                break;
            case 2:
                addMinute(minute, hour);
                break;
            case 3:
                addSecond(second, minute, hour);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
