#include <iostream>

using namespace std;



void displayTime(int hour, int minute, int second) {

    cout << "Current Time: "

         << hour << ":" << minute << ":" << second << endl;

}



void addHour(int &hour) {

    hour = (hour + 1) % 24;

}



void addMinute(int &minute, int &hour) {

    minute++;

    if (minute == 60) {

        minute = 0;

        hour = (hour + 1) % 24;

    }

}



void addSecond(int &second, int &minute, int &hour) {

    second++;

    if (second == 60) {

        second = 0;

        addMinute(minute, hour);

    }

}



int displayMenu() {

    cout << "\nMenu:\n";

    cout << "1. Add Hour\n";

    cout << "2. Add Minute\n";

    cout << "3. Add Second\n";

    cout << "4. Exit\n";

    cout << "Choose an option: ";



    int choice;

    cin >> choice;

    return choice;

}



int main() {

    int hour = 0;

    int minute = 0;

    int second = 0;



    cout << "Enter starting hour (0-23): ";

    cin >> hour;



    cout << "Enter starting minute (0-59): ";

    cin >> minute;



    cout << "Enter starting second (0-59): ";

    cin >> second;



    int choice = 0;



    while (choice != 4) {

        displayTime(hour, minute, second);

        choice = displayMenu();



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

                cout << "Invalid choice.\n";

        }

    }



    return 0;

}

